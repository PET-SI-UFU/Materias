:- module(
       usuário_função,
       [ carrega_tab/1,
         usuário_função/5,
         insere/3,
         remove/1,
         atualiza/3]
   ).

:- use_module(library(persistency)).

:- use_module(chave, []).

:- use_module(usuário, []).
:- use_module(função, []).


:- persistent
   usuário_função(
       usuário_função_id:positive_integer,
       usuário_id:positive_integer,
       função_id:positive_integer,
       data_cad:constant,
       data_mod:constant
   ).

%% :- initialization(
%%        ( db_attach('./tabelas/tbl_usuários_funções.pl', []),
%%          at_halt(db_sync(gc(always)))
%%        )).

:- initialization( at_halt(db_sync(gc(always))) ).

carrega_tab(ArqTabela):-
    db_attach(ArqTabela, []).



verifica_inserção(Usuário_id, Função_id):-
    usuário:usuário(Usuário_id, _, _, _, _, _), % usuário existe
    função:função(Função_id, _, _, _),          % função existe
    !.


insere(Id, Usuário_id, Função_id):-
    chave:pk(usuário_função, Id),
    with_mutex(usuário_função,
               ( verifica_inserção(Usuário_id, Função_id),
                 get_time(T),
                 Data_Cad = T,
                 Data_Mod = T,
                 assert_usuário_função(Id,
                                       Usuário_id,
                                       Função_id,
                                       Data_Cad,
                                       Data_Mod
                                      ))),
    !.

insere(-1, Usuário_id, Função_id):-
    format('Usuário ~d ou função ~d inexistente.', [Usuário_id, Função_id]).


remove(Id):-
    with_mutex(usuário_função,
               retractall_usuário_função(Id,
                                         _Usuário_id,
                                         _Função_id,
                                         _Data_Cad,
                                         _Data_Mod)).


atualiza(Id, Usuário_id, Função_id):-
    with_mutex(usuário_função,
               (retract_usuário_função(Id,
                                       _Usuário_id,
                                       _Função_id,

                                       Data_Cad,
                                       _Data_Mod),
                get_time(T),
                Data_Mod = T,
                assert_usuário_função(Id,
                                      Usuário_id,
                                      Função_id,
                                      Data_Cad,
                                      Data_Mod))).
