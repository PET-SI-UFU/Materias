:-module(
	funcionário,%nome do módulo
	[%aqui são colocados os predicados a serem exportados no formato funtor/aridade]).

%importa a biblioteca persistency
:use_module(library(persistency)).

%esquema da relação
:-persistent
  funcionário(matrícula:positive_integer,
	      nome:atom,
	      departamento:nonneg,
	      matrícula_gerente:positive_integer).

%Anexa o arquivo que servirá como armazém de fatos
:-initialization(db_attach('tbl_funcionário.pl',[])).

%A diretiva persistent//1 expande cada declaração em quatro predicados

insere(MatFunc, Nome, Departamento, Salário, MatrículaGerente):-
	%with mutex evita que dois ou mais processos tenham acesso simultâneo a um recurso compartilhado
	with mutex(funcionário,
		   assert_funcionário(MatFunc, Nome, Departamento,Salário, MatrículaGerente)).

remove(MatFunc, Nome, Departamento, Salário, MatrículaGerente):-
	with mutex(funcionário,
		   retract_funcionário(MatFunc, Nome, Departamento,Salário, MatrículaGerente)).

atualiza(MatFunc, Nome, Departamento, Salário, MatrículaGerente):-
	with mutex(funcionário,
		   (retractall_funcionário(MatFunc, Nome, Departamento,Salário, MatrículaGerente),
		    assert_funcionário(MatFunc,Nome,Departamento,Salário,MatrículaGerente))).

%Sempre atualizar no disco as alterações feitas.
sincroniza:-
	db_sync(gc(always)).


