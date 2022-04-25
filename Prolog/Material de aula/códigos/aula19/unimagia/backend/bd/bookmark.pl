:- module(
       bookmark,
       [ carrega_tab/1,
         bookmark/3,
         insere/3,
         remove/1,
         atualiza/3 ]).

:- use_module(library(persistency)).

:- use_module(chave, []).

:- persistent
   bookmark( id:positive_integer, % chave primária
             título:string,
             url:string ).


:- initialization( at_halt(db_sync(gc(always))) ).

carrega_tab(ArqTabela):-
    db_attach(ArqTabela, []).


insere(Id, Título, URL):-
    chave:pk(bookmark, Id),
    with_mutex(bookmark,
               assert_bookmark(Id, Título, URL)).

remove(Id):-
    with_mutex(bookmark,
               retractall_bookmark(Id, _Título, _URL)).


atualiza(Id, Título, URL):-
    with_mutex(bookmark,
               ( retract_bookmark(Id, _TítAntigo, _URLAntiga),
                 assert_bookmark(Id, Título, URL)) ).
