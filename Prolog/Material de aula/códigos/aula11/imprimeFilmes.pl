% Este é o arquivo:  imprimeFilmes.pl

:-module(imprimeFilmes,[imprimeFilmes/1]).

imprimeFilmes(Diretor):-
	setof(Filme,direcao(Diretor,Filme),Lista),exibeLista(Lista).

exibeLista([]):- nl.
exibeLista([X|L]):-
	write(X),
	nl,
	exibeLista(L).
