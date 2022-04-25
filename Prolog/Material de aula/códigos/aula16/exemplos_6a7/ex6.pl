:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/html_write)).

% html_requires está aqui
:- use_module(library(http/html_head)).

% serve_files_in_directory está aqui
:- use_module(library(http/http_server_files)).

servidor(Porta) :-
    http_server(http_dispatch, [port(Porta)]).


% Localização dos diretórios no sistema de arquivos
:- multifile user:file_search_path/2.
user:file_search_path(dir_css, 'css').
user:file_search_path(dir_js,  'js').


% Liga as rotas aos respectivos diretórios
:- http_handler(css(.),
                serve_files_in_directory(dir_css), [prefix]).
:- http_handler(js(.),
                serve_files_in_directory(dir_js), [prefix]).

% Liga a rota ao tratador
:- http_handler(root(.), home , []).


home(_Pedido) :-
    reply_html_page(
        [ title('Bootstrap 5 básico')],
        [ \página ]).

página -->
    html([ \html_post(head,
                      [ meta([name(viewport),
                              content('width=device-width, initial-scale=1')])]),
           \html_root_attribute(lang,'pt-br'),
           \html_requires(css('estilo.css')),
           \html_requires(css('bootstrap.min.css')),

           h1('Bootstrap 5'),

           script([ src('js/bootstrap.bundle.min.js'),
                    type('text/javascript')], [])
         ]).
