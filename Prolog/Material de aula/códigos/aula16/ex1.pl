:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/html_write)).

servidor(Porta) :-
    http_server(http_dispatch, [port(Porta)]).

:- http_handler(root(.), home , []).

home(_Pedido) :-
    reply_html_page(
        [title('Exemplos')],
        [ div(class(container),
              [ h1('Exemplos com SWI-Prolog'),
                h2(class(['my-5', 'text-center'], 'Exemplo 1')),
                div(class(row),
                    [ div(class('col-md-8'), 'Conteúdo Principal'),
                      div(class('col-md-4'), 'Barra Lateral')])
              ])]).
