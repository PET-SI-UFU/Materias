:- module(
       tabela_usuários,
       [
           tab_usuários//1
       ]
   ).

/* html//1, reply_html_page  */
:- use_module(library(http/html_write)).
/* html_requires  */
:- use_module(library(http/html_head)).

:- use_module(bd(usuário), []).

tab_usuários(RotaDeRetorno) -->
    html(div(class('container-fluid py-2'),
             [ \tabela(RotaDeRetorno) ]
            )).


cabeça_da_tabela(Título, Link) -->
    html( div(class('d-flex p-1'),
              [ div(class('me-auto'), h2(b(Título))),
                div(class(''),
                    a([ href(Link), class('btn btn-primary')],
                      'Novo'))
              ]) ).


tabela(RotaDeRetorno) -->
    html(div(class('row justify-content-center'),
             div( class('col-md-8'),
                  [ \cabeça_da_tabela('Usuários', '/usuario'),
                    table(class('table table-striped table-responsive-md'),
                        [ \cabeçalho,
                          tbody(\corpo_tabela(RotaDeRetorno))
                        ])]))).

%% tabela -->
%%     html(div(class('table-responsive-md'),
%%              table(class('table table-striped w-100'),
%%                    [ \cabeçalho,
%%                      tbody(\corpo_tabela)
%%                    ]))).

cabeçalho -->
    html(thead(tr([ th([scope(col)], '#'),
                    th([scope(col)], 'Nome'),
                    th([scope(col)], 'E-mail'),
                    th([scope(col)], 'Ações')
                  ]))).

corpo_tabela(RotaDeRetorno) -->
    {
        findall( tr([th(scope(row), Id), td(Nome), td(Email), td(Ações)]),
                 linha(Id, Nome, Email, Ações, RotaDeRetorno),
                 Linhas )
    },
    html(Linhas).


linha(Id, Nome, Email, Ações, RotaDeRetorno):-
    usuário:usuário(Id, Nome, Email, _Senha, _Data_Cad, _Dat_Mod),
    ações(Id, RotaDeRetorno, Ações).


ações(Id, RotaDeRetorno, Campo):-
    Campo = [ a([ class('text-success'), title('Alterar'),
                  href('/usuario/editar/~w' - Id),
                  'data-toggle'(tooltip)],
                [ \lápis ]),
              a([ class('text-danger ms-2'), title('Excluir'),
                  href('/api/v1/usuarios/~w' - Id),
                  onClick("apagar( event, '~w' )" - RotaDeRetorno),
                  'data-toggle'(tooltip)],
                [ \lixeira ])
            ].
