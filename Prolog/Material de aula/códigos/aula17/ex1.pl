:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/html_write)).

% html_requires está aqui
:- use_module(library(http/html_head)).

% serve_files_in_directory está aqui
:- use_module(library(http/http_server_files)).

% http_read_data está aqui
:- use_module(library(http/http_client)).

servidor(Porta) :-
    http_server(http_dispatch, [port(Porta)]).



% Liga a rota ao tratador
:- http_handler(root(.), formulário , []).



formulário(_Pedido) :-
	reply_html_page(
	    title('Demonstração de POST'),
	    [ form([ action='/receptor', method='POST'],
	           [ p([],
	               [ label([for=name],'Nome:'),
		             input([name=name, type=textarea]) ]),
		         p([],
		           [ label([for=email],'Email:'),
		             input([name=email, type=textarea]) ]),
		         p([],
		           input([name=submit, type=submit, value='Enviar'],
                         []))
	           ])]).

:- http_handler('/receptor', recebe_formulário(Method),
                [ method(Method),
                  methods([post]) ]).

recebe_formulário(post, Pedido) :-
    http_read_data(Pedido, Dados, []),
    format('Content-type: text/html~n~n', []),
	format('<p>', []),
    portray_clause(Dados), % escreve os dados do corpo
	format('</p><p>========~n', []),
	portray_clause(Pedido), % escreve o pedido todo
	format('</p>').
