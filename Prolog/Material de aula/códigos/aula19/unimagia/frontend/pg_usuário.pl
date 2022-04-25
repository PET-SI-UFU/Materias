:- module(
       pg_usuário,
       [
         cadastro/1,
         editar/2,
         escolha//4
       ]).

/* html//1, reply_html_page  */
:- use_module(library(http/html_write)).
/* html_requires  */
:- use_module(library(http/html_head)).


/* Página de cadastro de bookmark */
cadastro(Pedido):-
    (memberchk(referer(RotaDeRetorno), Pedido) ; RotaDeRetorno = '/' ),
    reply_html_page(
        boot5rest,
        [ title('Usuários')],
        [ div(class(container),
              [ \html_requires(js('comum.js')),
                h1('Meus usuários'),
                \form_cadastro(RotaDeRetorno)
              ]) ]).

form_cadastro(RotaDeRetorno) -->
    html(form([ id('usuario-form'),
                onsubmit("redirecionaResposta( event, '~w' )" - RotaDeRetorno),
                action('/api/v1/usuarios/') ],
              [ \método_de_envio('POST'),
                \campo(nome, 'Nome', text),
                \campo(email, 'E-mail', email),
                \campo(senha, 'Senha', password),
                \escolha(função, 'Função',
                         [ estudante:'Estudante',
                           prof:'Professor',
                           admin:'Administrador' ],
                        estudante),
                \enviar_ou_cancelar(RotaDeRetorno)
              ])).


enviar_ou_cancelar(RotaDeRetorno) -->
    html(div([ class('btn-group pt-3'), role(group), 'aria-label'('Enviar ou cancelar')],
             [ button([ type(submit),
                        class('btn btn-outline-primary')], 'Enviar'),
               a([ href(RotaDeRetorno),
                   class('ms-3 btn btn-outline-danger')], 'Cancelar')
            ])).


escolha(Nome, Rótulo, Opções, PréEscolha) -->
    { enumera_opções(Nome, 1, PréEscolha , Opções, Botões)  },
    html(fieldset([], [ legend(Rótulo) | Botões ])).

%% opções_de_escolha(Nome, Opções, PréEscolha, Botões_de_Rádio) :-
%%     enumera_opções(Nome, 1, Opções, PréEscolha, Botões_de_Rádio).

enumera_opções(Nome, Contador, PréEscolha, [Opção | Opções], [Botão|Botões]):-
    opção(Nome, Opção, Contador, PréEscolha, Botão),
    NovoContador is Contador + 1,
    !,
    enumera_opções(Nome, NovoContador, PréEscolha, Opções, Botões).
enumera_opções(_, _, _, [], []).


opção(Nome, Valor:Rótulo, Contador, PréEscolha, Botão):-
    Valor = PréEscolha, !,
    atom_concat(Nome,Contador, Id),
    Botão = div(class('form-check'),
                [ input([ class('form-check-input'),
                          type(radio),
                          name(Nome),
                          id(Id),
                          value(Valor),
                          checked
                        ]),
                  label([ class('form-check-label'), for(Id) ], Rótulo)
                ]).

opção(Nome, Valor:Rótulo, Contador, _PréEscolha, Botão):-
    atom_concat(Nome,Contador, Id),
    Botão = div(class('form-check'),
                [ input([ class('form-check-input'),
                          type(radio),
                          name(Nome),
                          id(Id),
                          value(Valor)
                        ]),
                  label([ class('form-check-label'), for(Id) ], Rótulo)
                ]).


campo(Nome, Rótulo, Tipo) -->
    html(div(class('mb-3'),
             [ label([ for(Nome), class('form-label') ], Rótulo),
               input([ type(Tipo), class('form-control'),
                       id(Nome), name(Nome)])
             ] )).



/* Página para edição (alteração) de um bookmark  */

editar(AtomId, Pedido):-
    (memberchk(referer(RotaDeRetorno), Pedido) ; RotaDeRetorno = '/' ),
    atom_number(AtomId, Usuário_ID),
    ( usuário:usuário(Usuário_ID, Nome, Email, _Senha, _, _),
      usuário_função:usuário_função(_, Usuário_ID, Função_ID, _, _),
      função:função(Função_ID, Função, _, _)
    ->
    reply_html_page(
        boot5rest,
        [ title('Bookmarks')],
        [ div(class(container),
              [ \html_requires(js('comum.js')),
                h1('Meus usuários'),
                \form_edição(Usuário_ID, Nome, Email, Função, RotaDeRetorno)
              ]) ])
    ; throw(http_reply(not_found(Usuário_ID)))
    ).


form_edição(Usuário_ID, Nome, Email, Função, RotaDeRetorno) -->
    html(form([ id('usuario-form'),
                onsubmit("redirecionaResposta( event, '~w' )" - RotaDeRetorno),
                action('/api/v1/usuarios/~w' - Usuário_ID) ],
              [ \método_de_envio('PUT'),
                \campo_não_editável(id, 'Id', text, Usuário_ID),
                \campo(nome,  'Nome',   text,  Nome),
                \campo(email, 'E-mail', email, Email),
                \campo(senha, 'Senha',  password, ''),
                \escolha(função, 'Função',
                         [ estudante:'Estudante',
                           prof:'Professor',
                           admin:'Administrador' ],
                         Função
                        ),
                \enviar_ou_cancelar(RotaDeRetorno)
              ])).


campo(Nome, Rótulo, Tipo, Valor) -->
    html(div(class('mb-3'),
             [ label([ for(Nome), class('form-label')], Rótulo),
               input([ type(Tipo), class('form-control'),
                       id(Nome), name(Nome), value(Valor)])
             ] )).

campo_não_editável(Nome, Rótulo, Tipo, Valor) -->
    html(div(class('mb-3 w-25'),
             [ label([ for(Nome), class('form-label')], Rótulo),
               input([ type(Tipo), class('form-control'),
                       id(Nome),
                       % name(Nome),%  não é para enviar o id
                       value(Valor),
                       readonly ])
             ] )).

método_de_envio(Método) -->
    html(input([type(hidden), name('_método'), value(Método)])).
