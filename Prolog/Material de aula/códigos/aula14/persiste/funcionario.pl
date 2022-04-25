:- module(
       funcionário,
       [ funcionário/5 ]
   ).

:- use_module(library(persistency)).

:- persistent
   funcionário(matrícula:positive_integer,
               nome:atom,
               departamento:nonneg,
               salário:positive_integer,
               matrícula_gerente:positive_integer).

:- initialization(db_attach('tbl_funcionário.pl', [])).

insere(MatFunc, Nome, Departamento, Salário, MatrículaGerente):-
    with_mutex(funcionário,
               assert_funcionário(MatFunc, Nome, Departamento,
                                  Salário, MatrículaGerente)).

remove(MatFunc):-
    with_mutex(funcionário,
               retract_funcionário(MatFunc, _Nome, _Departamento,
                                   _Salário, _MatrículaGerente)).

atualiza(MatFunc, Nome, Departamento, Salário, MatrículaGerente):-
    with_mutex(funcionário,
               ( retractall_funcionário(MatFunc, _Nome, _Departamento,
                                        _Salário, _MatrículaGerente),
                 assert_funcionário(MatFunc, Nome, Departamento,
                                    Salário, MatrículaGerente)) ).

sincroniza :-
    db_sync(gc(always)).
