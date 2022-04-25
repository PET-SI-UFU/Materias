%Vesão 1

principal(Arquivo):-
	open(Arquivo,read,F),  %abro um arquivo para leitura
	leiaPalavra(F, Palavra),
	close(F),
	write(Palavra), nl.

leiaPalavra(Fluxo,Palavra):- 					%Fluxo pode ser considerado como um ponteiro
	get_code(Fluxo,Caracter), 				%Lê o próximo caracter
	verificaELeiaResto(Caracter,Caracteres,Fluxo),		%Volta uma lista de caracteres
	atom_codes(Palavra,Caracteres).				%Pega a lista de códigos dos caracteres e transforma em um átomo(palavra).

verificaELeiaResto(10,[],_):-!.					%10 é o código do ENTER na tabela ASCII.
verificaELeiaResto(32,[],_):-!.					%32 é o BACKSPACE
verificaELeiaResto(-1,[],_):-!.					%-1 é o código que o Prolog volta ao chegar no final do arquivo.
verificaELeiaResto(Caracter,[Caracter|Caracteres],F):-		%Coloca o caracter na cabeça da lista
	get_code(F,ProxCaracter),				%Leio o resto do arquivo
	verificaELeiaResto(ProxCaracter,Caracteres,F).		%Chamada recursiva.

%Versão 2

principal(Arquivo):-
	open(Arquivo,read,F),  %abro um arquivo para leitura
	leiaPalavras(F, Palavra),
	close(F),
	write(Palavra), nl.

leiaPalavras(F,[]):-						%Se estiver no final do arquivo.
	at_end_of_stream(F),!.

leiaPalavras(F,[Palavra|Palavras]):-				
	leiaPalavra(F,Palavra),
	leiaPalavras(F,Palavras).

leiaPalavra(Fluxo,Palavra):- 					%Fluxo pode ser considerado como um ponteiro
	get_code(Fluxo,Caracter), 				%Lê o próximo caracter
	verificaELeiaResto(Caracter,Caracteres,Fluxo),		%Volta uma lista de caracteres
	atom_codes(Palavra,Caracteres).				%Pega a lista de códigos dos caracteres e transforma em um átomo(palavra).

verificaELeiaResto(10,[],_):-!.					%10 é o código do ENTER na tabela ASCII.
verificaELeiaResto(32,[],_):-!.					%32 é o BACKSPACE
verificaELeiaResto(-1,[],_):-!.					%-1 é o código que o Prolog volta ao chegar no final do arquivo.
verificaELeiaResto(Caracter,[Caracter|Caracteres],F):-		%Coloca o caracter na cabeça da lista
	get_code(F,ProxCaracter),				%Leio o resto do arquivo
	verificaELeiaResto(ProxCaracter,Caracteres,F).		%Chamada recursiva.


