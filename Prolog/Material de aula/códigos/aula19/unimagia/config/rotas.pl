% http_handler, http_reply_file
:- use_module(library(http/http_dispatch)).

% http:location
:- use_module(library(http/http_path)).

:- ensure_loaded(caminhos).

% Converte um apelido em rota.
% Ex:
% ? - apelido_rota(api1(usuarios), Rota).
% Rota = '/api/v1/usuarios/'

apelido_rota(Apelido, RotaCompleta):-
   http_absolute_location(Apelido, Rota, []),
   atom_concat(Rota, '/', RotaCompleta).

/***********************************
 *                                 *
 *      Rotas do Servidor Web      *
 *                                 *
 ***********************************/

:- multifile http:location/3.
:- dynamic   http:location/3.

%% http:location(Apelido, Rota, Opções)
%      Apelido é como será chamada uma Rota do servidor.
%      Os apelidos css, icons e js já estão definidos na
%      biblioteca http/http_server_files, os demais precisam
%      ser definidos.

http:location(img, root(img), []).
http:location(api, root(api), []).
http:location(api1, api(v1), []).
http:location(webfonts, root(webfonts), []).

/**************************
 *                        *
 *      Tratadores        *
 *                        *
 **************************/

% Recursos estáticos
:- http_handler( css(.),
                 serve_files_in_directory(dir_css), [prefix]).
:- http_handler( img(.),
                 serve_files_in_directory(dir_img), [prefix]).
:- http_handler( js(.),
                 serve_files_in_directory(dir_js),  [prefix]).
:- http_handler( webfonts(.),
                 serve_files_in_directory(dir_webfonts), [prefix]).
:- http_handler( '/favicon.ico',
                 http_reply_file(dir_img('favicon.ico'), []),
                 []).

% Rotas do Frontend

%% A página inicial
:- http_handler( root(.), pg_entrada:entrada, []).

%% A página de login
:- http_handler( root(login), pg_login:login, [ id(login) ]).


%% A página de cadastro de novos usuários
:- http_handler( root(cadastro), pg_cadastro:cadastro, []).

%% Páginas de usuários
:- http_handler(root(admin/Id), pg_administrador:entrada(Id),
                []).

:- http_handler(root(prof/Id),   pg_professor:entrada(Id),
                []).

:- http_handler(root(estudante/Id), pg_estudante:entrada(Id),
                []).


%% A página de cadastro de novos bookmarks
:- http_handler( root(bookmark), pg_bookmark:cadastro, []).

%% A página para edição de um bookmark existente
:- http_handler( root(bookmark/editar/Id), pg_bookmark:editar(Id), []).

%% A página de cadastro de novos usuários
:- http_handler( root(usuario), pg_usuário:cadastro, []).

%% A página para edição de um usuário existente
:- http_handler( root(usuario/editar/Id), pg_usuário:editar(Id), []).



% Rotas do Backend

%% Validação de login
:- http_handler( root(valida_login), logins:valida(Método),
                 [ method(Método) ]).


%% Rotas da API

%%% Bookmarks
:- http_handler( api1(bookmarks/Id), bookmarks:bookmarks(Método, Id),
                 [ method(Método),
                   methods([ get, post, put, delete ]) ]).

%%% Usuários
:- http_handler( api1(usuarios/Id), usuários:usuários(Método, Id),
                 [ method(Método),
                   methods([ get, post, put, delete ]) ]).
                   
                   
:-http_handler(api1(dentist), dentist(Metodo),
                 [method(Metodo),               methods([post])]).                   
                   

                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
