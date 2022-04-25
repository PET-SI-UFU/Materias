/*Programa principal*/

:-load_files(
	[funcionario,departamento],
	[if(not_loaded),%só carrega o módulo uma vez
			%carrega o módulo sem imprimir mensagem
	silent(true)
	]).

junta(MatFunc, NomeF, NumDeptoF, Salário, MatGerenteF, NumDeptoF, NomeDepD, MatGerenteD):-
	funcionário(MatFunc, Nome, NumDepto, Salário, MatGerente),
	departamento(NumDeptoF, NomeDepD, MatGerenteD).
	