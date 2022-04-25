:- module(
       pg_administrador,
       [ entrada/2 ]).

/* html//1, reply_html_page  */
:- use_module(library(http/html_write)).
/* html_requires  */
:- use_module(library(http/html_head)).

:- use_module(bd(bookmark), []).
:- use_module(tabela_bookmarks).
:- use_module(tabela_usuários).

entrada(Usuário_ID, _Pedido) :-
    apelido_rota(root(admin/Usuário_ID), RotaDeRetorno),
    reply_html_page(
        boot5rest,
        [ title('Página do Administrador')],
        [ \html_requires(css('custom.css')),
          \html_requires(css('entrada.css')),
          \html_requires(js('bookmark.js')),
          \navegação('menu-topo'),
          \título_da_página('Página do Administrador'),
          \tab_bookmarks(RotaDeRetorno),
          \tab_usuários(RotaDeRetorno)
        ]
    ).


título_da_página(Título) -->
    html( div( class('container py-5'),
               div(class('d-flex'),
                   div(class('text-center align-items-center w-100 py-4'),
                       h1('display-3', Título))))).
