:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).

servidor(Porta) :-
    http_server(http_dispatch, [port(Porta)]).

:- multifile http:location/3.
:- dynamic   http:location/3.

http:location(arquivos, '/arquivos', []).

:- http_handler(arquivos(texto), arquivo_estático , []).

arquivo_estático(_Pedido):-
    format('Content-type: text/plain~n~n'),
    format('Alguma dia eu enviarei o arquivo~n').

:- http_handler(root(Língua), bem_vindo(Língua) , []).

bem_vindo(Língua, _Pedido) :-
    format('Content-type: text/plain~n~n'),
    cumprimento(Língua, Cumprimento),
    format('~w~n', Cumprimento).

cumprimento('',      'Oi Mundo!'):- !.
cumprimento(deutsche, 'Hallo Welt!'):- !.
cumprimento(espanol,  '¡Hola Mundo!'):- !.
cumprimento(english,  'Hello, world!'):- !.
cumprimento(francais, 'Bonjour le monde!'):- !.
cumprimento(latim,    'Salve orbis terrarum.'):- !.
cumprimento(Língua,    Desconhecida):-
    format(atom(Desconhecida),
           '~w: é uma língua desconhecida!', [Língua]).
