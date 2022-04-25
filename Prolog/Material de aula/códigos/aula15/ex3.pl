:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).

servidor(Porta) :-
    http_server(http_dispatch, [port(Porta)]).

:- http_handler(root(.),        oi,      []).
:- http_handler(root(deutsche), hallo,   []).
:- http_handler(root(espanol),  hola,    []).
:- http_handler(root(english),  hi,      []).
:- http_handler(root(francais), bonjour, []).
:- http_handler(root(latim),    salve,   []).

oi(_Pedido) :-
    format('Content-type: text/plain~n~n'),
    format('Oi Mundo!~n').

hallo(_Pedido) :-
    format('Content-type: text/plain~n~n'),
    format('Hallo Welt!~n').

hola(_Pedido) :-
    format('Content-type: text/plain~n~n'),
    format('¡Hola Mundo!~n').

hi(_Pedido) :-
    format('Content-type: text/plain~n~n'),
    format('Hello, world!~n').

bonjour(_Pedido) :-
    format('Content-type: text/plain~n~n'),
    format('Bonjour le monde!~n').

salve(_Pedido) :-
    format('Content-type: text/plain~n~n'),
    format('Salve orbis terrarum.~n').
