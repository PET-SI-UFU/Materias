:- module(
       usuário,
       [ carrega_tab/1,
         usuário/6,
         insere/4,
         remove/1,
         atualiza/3,
         atualiza_senha/2,
         senha_válida/4
       ]
   ).

:- use_module(library(persistency)).
:- use_module(library(crypto)).

:- use_module(chave, []).

:- persistent
   usuário(
       usuário_id:positive_integer,
       nome:string,
       email:string,
       senha:atom,
       data_cad:constant,
       data_mod:constant
   ).

:- initialization( at_halt(db_sync(gc(always))) ).

carrega_tab(ArqTabela):-
    db_attach(ArqTabela, []).

insere( Id,
        Nome,
        Email,
        Senha ):-
    chave:pk(usuário, Id),
    with_mutex(usuário,
               ( get_time(T),
                 Data_Cad = T,
                 Data_Mod = T,
                 crypto_password_hash(Senha,Hash),
                 assert_usuário(Id,
                                Nome,
                                Email,
                                Hash,
                                Data_Cad,
                                Data_Mod))).

remove(Id):-
    with_mutex(usuário,
               retractall_usuário(Id,
                                  _Nome,
                                  _Email,
                                  _Hash,
                                  _Data_Cad,
                                  _Data_Mod)).


atualiza(Id, Nome, Email):-
    with_mutex(usuário,
               (retract_usuário(Id,
                                _NomeAntigo,
                                _EmailAntigo,
                                Hash,
                                Data_Cad,
                                _Data_Mod),
                get_time(T),
                Data_Mod = T,
                assert_usuário(Id,
                               Nome,
                               Email,
                               Hash,
                               Data_Cad,
                               Data_Mod))).

atualiza_senha(Id, Senha):-
    with_mutex(usuário,
               (retract_usuário(Id,
                                Nome,
                                Email,
                                _HashAntigo,
                                Data_Cad,
                                _Data_Mod),
                get_time(T),
                Data_Mod = T,
                crypto_password_hash(Senha,Hash),
                assert_usuário(Id,
                               Nome,
                               Email,
                               Hash,
                               Data_Cad,
                               Data_Mod))).


% Verifica se a senha para um usuário com o dado e-mail é válida.
% Para o teste ter sucesso tanto a senha quanto o hash devem
% estar ligados a valores e o hash da Senha deve ser comparável
% ao armazenado anteriormente.

senha_válida(Email, Senha, Id, Nome):-
    usuário(Id, Nome, Email, Hash, _Data_Cad, _Data_Mod),
    !,
    crypto_password_hash(Senha,Hash).










