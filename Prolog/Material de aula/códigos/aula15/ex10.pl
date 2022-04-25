:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/html_write)).

servidor(Porta) :-
    http_server(http_dispatch, [port(Porta)]).

:- http_handler(root(.), bem_vindo , []).

bem_vindo(_Pedido) :-
    reply_html_page(
        [title('Bem-vindo')],
        [ h1('Uma página web simples'),
          p('com algum texto.') ]).
