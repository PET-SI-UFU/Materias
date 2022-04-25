:- module(
       usuários,
       [
           usuários/3
       ]
   ).
/* http_parameters   */
:- use_module(library(http/http_parameters)).
/* http_reply        */
:- use_module(library(http/http_header)).
/* reply_json_dict   */
:- use_module(library(http/http_json)).


:- use_module(bd(usuário), []).
:- use_module(bd(função), []).
:- use_module(bd(usuário_função), []).

/*
   GET api/v1/usuarios/
   Retorna uma lista com todos os usuários.
*/
usuários(get, '', _Pedido):- !,
    envia_tabela.

/*
   GET api/v1/usuarios/Id
   Retorna o usuário com Id 1 ou erro 404 caso o usuário não
   seja encontrado.
*/
usuários(get, AtomId, _Pedido):-
    atom_number(AtomId, Id),
    !,
    envia_tupla(Id).

/*
   POST api/v1/usuarios
   Adiciona um novo usuário. Os dados deverão ser passados no corpo da
   requisição no formato JSON. Por default, o usuário possui a funçao
   estudante

   Um erro 400 (BAD REQUEST) deve ser retornado caso algo dê errado
*/
usuários(post, _, Pedido):-
    http_read_json_dict(Pedido, Dados),
    !,
    insere_tupla(Dados).

/*
  PUT api/v1/usuarios/Id
  Atualiza o usuário com o Id informado.
  Os dados são passados no corpo do pedido no formato JSON.
*/
usuários(put, AtomId, Pedido):-
    atom_number(AtomId, Id),
    http_read_json_dict(Pedido, Dados),
    !,
    atualiza_tupla(Dados, Id).
/*
   DELETE api/v1/usuarios/Id
   Apaga o bookmark com o Id informado
*/
usuários(delete, AtomId, _Pedido):-
    atom_number(AtomId, Usuário_ID),
    !,
    usuário:remove(Usuário_ID),
    throw(http_reply(no_content)).

/* Se algo ocorrer de errado, a resposta de método não
   permitido será retornada.
 */

usuários(Método, Id, _Pedido) :-
    throw(http_reply(method_not_allowed(Método, Id))).


insere_tupla( _{ nome:Nome, email:Email, senha:Senha, função:StrFun }):-
    ( usuário:insere(Usuário_ID, Nome, Email, Senha),
      atom_string(Função, StrFun),
      função:função(Função_ID, Função, _, _),
      usuário_função:insere(_, Usuário_ID, Função_ID)
    )
    -> envia_tupla(Usuário_ID)
    ;  throw(http_reply(bad_request('Email já cadastrado'))).

atualiza_tupla( _{ nome:Nome, email:Email, senha:Senha, função:StrFun}, Usuário_ID):-
    ( atom_string(Função, StrFun),
      função:função(Função_ID, Função, _, _),
      usuário_função:usuário_função(UF_ID, Usuário_ID, _, _, _),
      usuário:atualiza(Usuário_ID, Nome, Email),
      usuário:atualiza_senha(Usuário_ID, Senha),
      usuário_função:atualiza(UF_ID, Usuário_ID, Função_ID)
    )
    -> envia_tupla(Usuário_ID)
    ;  throw(http_reply(not_found(Usuário_ID))).

envia_tupla(Id):-
    usuário:usuário(Id, Nome, Email, _Senha, Data_Cad, Data_Mod)
    -> reply_json_dict( _{ id:Id, nome:Nome, email:Email,
                           data_cad: Data_Cad, data_mod: Data_Mod} )
    ;  throw(http_reply(not_found(Id))).


envia_tabela :-
    findall( _{ id:Id, nome:Nome, email:Email,
                data_cad: Data_Cad, data_mod: Data_Mod },
             usuário:usuário(Id, Nome, Email, _Senha, Data_Cad, Data_Mod),
            Tuplas ),
    reply_json_dict(Tuplas).
