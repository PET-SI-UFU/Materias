:- module(pg_entrada,
          [
              entrada/1
          ]).

/* html//1, reply_html_page  */
:- use_module(library(http/html_write)).
/* html_requires  */
:- use_module(library(http/html_head)).


entrada(_) :-
    reply_html_page(
        bootstrap5,
        [ title('Universidade Mágica')],
        [ \html_requires(css('custom.css')),
          \navegação('menu-topo'),
          \propaganda
        ]
    ).

propaganda -->
    html(div([ class='container-fluid' ],
             div([ id='propaganda',
                   class='py-5 text-center block block-1'],
                 [ div(class('py-5'), \diamante),
                   h1(class('py-5'), 'UniMagia'),
                   h2(class('py-5'), 'Uma universidade mágica!'),
                   p(class(lead),
                     [ 'Venha para a Universide Mágica, aqui você não precisa',
                       ' estudar em casa, fazer trabalhos, listas de exercícios',
                       ' e estudar para provas.']),
                   p(class(lead),
                     [ 'Basta assistir as aulas e, com nossos professores incríveis, você entenderá tudo com extrema facilidade, como num passe de mágica.'
                     ]),
                   p(class(lead),
                     ['Se desejar, vocé nem precisará prestar atenção às aulas e poderá usar o celular para assistir ao último vídeo engraçado que saiu no Youtube ou acessar suas redes sociais preferidas para ver o que há de novo.']),
                   p(class(lead), 'Magia pura!')]))).
