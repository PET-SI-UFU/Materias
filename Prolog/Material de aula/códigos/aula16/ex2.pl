:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/html_write)).

servidor(Porta) :-
    http_server(http_dispatch, [port(Porta)]).

:- http_handler(root(.), home , []).

home(_Pedido) :-
    reply_html_page(
        [ title('Exemplos')],
        [ \página ]).

página -->
    html([ div(class(container),
               [ h1('Exemplos de inclusão com SWI-Prolog'),
                 \exemplo1,
                 \exemplo2
               ])
         ]).


exemplo1 -->
    html([h2(class("my-5 text-center"),'Exemplo 1'),
          div(class("container my-5"),
              div(class(row),
                  [div(class('col-md-8'), 'Conteúdo Principal'),
                   div(class('col-md-4'), 'Barra Lateral')]))]).


exemplo2 -->
    html([h2(class("my-5 text-center"),'Exemplo 2'),
          div(class("container"),
              div(class(row),
                  [div(class('col-md-8 text-center'),
                       ['Cabeçalho',
                        div(class="row text-center",
                            [div(class="col-md-6",
                                 ['Artigo',
                                  p('Texto do artigo 1.')]),
                             div(class="col-md-6",
                                 ['Artigo',
                                  p('Texto do artigo 2.')]),
                             span('Rodapé')])]),
                   div(class('col-md-4'), 'Barra Lateral')]))]).
