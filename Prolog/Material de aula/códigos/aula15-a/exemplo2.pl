:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).

servidor(Porta) :-
	http_server(http_dispatch, [port(Porta)]).
	
:- http_handler(root(Língua), bem_vindo(Língua) , []). %Recebemos a rota como uma variável

bem_vindo(Língua, _Pedido) :-
	format('Content-type: text/plain~n~n'),
	cumprimento(Língua, Cumprimento),
	format('~w~n', Cumprimento).

cumprimento('','Oi Mundo!'):- !.
cumprimento(deutsche, 'Hallo Welt!'):- !.
cumprimento(espanol, 'Hola Mundo!'):- !.
cumprimento(english, 'Hello, world!'):- !.
cumprimento(francais, 'Bonjour le monde!'):- !.
cumprimento(latim,'Salve orbis terrarum.'):- !.
cumprimento(Língua,Desconhecida):-
	format(atom(Desconhecida),
	'~w: é uma língua desconhecida!', [Língua]).
