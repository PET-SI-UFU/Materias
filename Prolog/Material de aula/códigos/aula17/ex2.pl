:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/html_write)).

/* http_parameters está aqui */
:- use_module(library(http/http_parameters)).

servidor(Porta) :-
    http_server(http_dispatch, [port(Porta)]).



% Liga a rota ao tratador
:- http_handler(root(.), home , []).

/*
  No navegador use:
   localhost:8000/?id=12&nome=Gal+Costa&prof=cantora
   localhost:8000/?id=12&nome=Gal+Costa&prof=cantora&idade=74
*/

home(Pedido) :-
	reply_html_page( title('Demonstração de GET'),
		           [ \página(Pedido) ]).

página(Pedido) -->
    {
        /* É preciso tratar a exceção, pois http_parameters gera uma
           uma exceção caso um parâmetro seja inválido */
        catch(
            http_parameters(Pedido,
                            [ % id dever ser um inteiro
                                id(Id,          [integer]),
                                nome(Nome,      [string]),
                                prof(Profissão, [string]),
                              /* Se o parâmetro idade estiver
                                 ausente, Idade não ficará ligada
                               */
                                idade(Idade,    [optional(true),integer]),
                              /* Se o parâmetro nacionalidade estiver
                                 ausente, assuma o valor default.
                              */
                                nacionalidade(Nac, [default(brasileira)])
                            ]),
            _E,
            fail ),
        !,
        % Verifica se a idade foi informada
        (var(Idade) -> Idade = 'desconhecida' ; true)
    },
    html([ h1('Resposta do servidor para o GET'),
           p('Os parâmetros recebidos foram:'),
           p('Id é ~w' - Id),
           p('Nome é ~w' - Nome),
           p('Profissão é ~w'- Profissão),
           p('Idade é ~w' - Idade),
           p('Nacionalidade é ~w'- Nac)
         ]).

/* Essa página será exibida em caso de erro de validação
   de algum parâmetro */
página(_Pedido) -->
    html([ h1('Erro'),
           p('Algum parâmetro não é válido')
         ]).
