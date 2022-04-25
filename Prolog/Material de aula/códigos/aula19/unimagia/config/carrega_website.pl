% Configuração do servidor


% Carrega o servidor e as rotas

:- load_files([ servidor,
                rotas
              ],
              [ silent(true),
                if(not_loaded) ]).

% Inicializa o servidor para ouvir a porta 8000
:- initialization( servidor(8000) ).


% Carrega o frontend

:- load_files([ gabarito(bootstrap5),  % gabarito usando Bootstrap 5
                gabarito(boot5rest),   % Bootstrap 5 com API REST
                frontend(icones),      % Ícones do Bootstrap 5
                frontend(menu_topo),   % Menu de navegação do site
                frontend(pg_entrada),     % Página inicial
                frontend(pg_login),       % Página de login
                frontend(pg_cadastro),    % Página de cadastro
                frontend(pg_bookmark),
                frontend(pg_usuário),
                frontend(pg_administrador),
                frontend(pg_professor),
                frontend(pg_estudante)
              ],
              [ silent(true),
                if(not_loaded),
                imports([])
              ]).


% Carrega o backend


:- load_files([ % API REST
                api1(bookmarks),
                api1(usuários),
                % Validação do login e senha
                backend(logins)
              ],
              [ silent(true),
                if(not_loaded) ]).
