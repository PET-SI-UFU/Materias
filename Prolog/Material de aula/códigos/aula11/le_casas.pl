/*
VERSÃO 1

principal:-
	open('casas.txt',read,F),
	read(F,C1),
	read(F,C2),  
	read(F,C3),
	read(F,C4),
	close(F),
	write([C1,C2,C3,C4]), nl.
*/

principal:-
	open('casas.txt',read,F),
	leiaCasas(F, Casas),
	close(F),
	write(Casas),nl.
	
leiaCasas(F,[]):-
	at_end_of_stream(F),!.
	
leiaCasas(F,[X|L]):-
	\+at_end_of_stream(F),!,
	read(F,X),
	leiaCasas(F,L).
	
