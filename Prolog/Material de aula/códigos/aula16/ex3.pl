:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/html_write)).

servidor(Porta) :-
    http_server(http_dispatch, [port(Porta)]).

:- http_handler(root(.), home , []).

home(_Pedido) :-
    reply_html_page(
        estilo_topo,   %define o estilo da página
        [ title('Exemplos')],
        [ \página ]).

página -->
    html([ h2('Cabeçalho específico da página'),
           p('com estilização')]).

:- multifile
       user:body//2.

% Corpo será incluído
user:body(estilo_topo, Corpo) -->
        html(body([ div(id(topo), h1('O Site da Página Web Simples')),
                    div(id(conteudo), Corpo)
                  ])).
