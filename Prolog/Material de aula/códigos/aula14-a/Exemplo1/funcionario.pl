/*Funcionário
	MatFunc, Nome, NumDepto, Salário, MatGerente
*/

:-dynamic funcionário/5

funcionário(13, 'Marcelo', 0, 3000, 19).
funcionário(21, 'Joana', 1, 2000, 13).
funcionário(35, 'Bruno', 1, 2200, 21).
funcionário(38, 'Wagner', 1, 1600, 35).
funcionário(43, 'Sílvia', 2, 2500, 13).
funcionário(89, 'Márcia', 1, 2300, 35).
funcionário(42, 'Mirela', 1, 1700, 35).

%Exemplo de consultas

/*
	Gerar todas as tuplas para os funcionários do
	departamento 1 que ganhem acima de 2100
*/

seleciona(MatFunc, Nome, NumDepto, Salário, MatGerente):-
	funcionário(MatFunc, Nome, NumDepto, Salário, MatGerente),
	NumDepto = 1, Salário > 2100.

projeta(Nome, MatFunc, Salário):-
	funcionário(MatFunc, Nome, _NumDepto, Salário, _MatGerente).

sel_depois_proj(Nome, MatFunc, Salário):-
	funcionário(MatFunc, Nome, 1, Salário, _MatGerente),
	Salário > 2100.



