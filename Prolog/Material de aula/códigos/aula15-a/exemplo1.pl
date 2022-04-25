:-use_module(library(http/thread_httpd)). %Para usar o servidor web em Prolog
:-use_module(library(http/http_dispatch)).

servidor(Porta):-
	http_server(http_dispatch, [port(Porta)]). %Porta é um endereço virtual
	
:-http_handler(/,oi,[]). %http_handler(Rota,Tratador,Opções)

%Devolve a resposta para a rota
oi(_Pedido):-
	format('Content-type: text/plain~n~n'), %Padrão do Prolog
	format('Oi Mundo!~n'). %~n é equivalente ao nl
