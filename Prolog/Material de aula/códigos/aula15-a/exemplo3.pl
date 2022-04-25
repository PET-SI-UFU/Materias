:- multifile http:location/3. %Criando novos caminhos abstratos
:- dynamic http:location/3. 

http:location(arquivos, '/arqs', []).

:- http_handler(arquivos(texto), arquivo_estático , []).

arquivo_estático(_Pedido):-
	format('Content-type: text/plain~n~n'),
	format('Alguma dia eu enviarei o arquivo~n').


