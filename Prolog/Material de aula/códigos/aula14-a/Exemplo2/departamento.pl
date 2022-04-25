:-module(
	departamento,
	[departamento/3]).

:- use_module(library(persistency)).

:-persistent
  departamento( número: nonneg,
		nome:atom,
		matrícula_gerente:positive_integer ).

:-initialization(db_attach('tbl_departamento.pl',[])).

insere(Número, Nome, MatrículaGerente):-
	with_mutex(departamento,
		   assert_departamento(Número,Nome,MatrículaGerente)).

remove(Número):-
	with_mutex(departamento,
		   retract_departamento(Número,_Nome,_MatrículaGerente)).

atualiza(Número, Nome, MatrículaGerente):-
	with_mutex(departamento,
		   (retractall_departamento(Número,_Nome,_MatrículaGerente),
	           asssert_departamento(Número,_Nome,_MatrículaGerente))).
sincroniza:-
	db_sync(gc(always)).
