:- module(
       função,
       [ carrega_tab/1,
         função/4,
         insere/2,
         remove/1,
         atualiza/2
       ]
   ).

:- use_module(library(persistency)).

:- use_module(chave, []).

:- persistent
   função(
       função_id:positive_integer,
       função:oneof([admin,prof,estudante]),
       data_cad:constant,
       data_mod:constant
   ).


:- initialization( at_halt(db_sync(gc(always))) ).

carrega_tab(ArqTabela):-
    db_attach(ArqTabela, []).


insere(Id, Função):-
    chave:pk(função, Id),
    with_mutex(função,
               ( get_time(T),
                 Data_Cad = T,
                 Data_Mod = T,
                 assert_função(Id,
                               Função,
                               Data_Cad,
                               Data_Mod
                              ))).

remove(Id):-
    with_mutex(função,
               retractall_função(Id,
                                 _Função,
                                 _Data_Cad,
                                 _Data_Mod)).


atualiza(Id, Função):-
    with_mutex(função,
               (retract_função(Id,
                               _FunçãoAntiga,
                               Data_Cad,
                               _Data_Mod),
                get_time(T), % data e hora desse instante
                Data_Mod = T,
                assert_função(Id,
                              Função,
                              Data_Cad,
                              Data_Mod))).
