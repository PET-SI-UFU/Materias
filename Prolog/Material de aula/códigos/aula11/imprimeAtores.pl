% Este é o arquivo:  imprimeAtores.pl

:-module(imprimeAtores,[imprimeAtores/1]).

imprimeAtores(Filme):-
	setof(Ator,elenco(Ator,Filme),Lista),exibeLista(Lista).
	
exibeLista([]):- nl.
exibeLista([X|L]):-
	write(X), 
	tab(1), 
	exibeLista(L).
