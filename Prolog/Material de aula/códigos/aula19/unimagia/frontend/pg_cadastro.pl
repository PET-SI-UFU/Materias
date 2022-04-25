:- module(
       pg_cadastro,
       [ cadastro/1 ]).

/* html//1, reply_html_page  */
:- use_module(library(http/html_write)).
/* html_requires  */
:- use_module(library(http/html_head)).

cadastro(_) :-
    apelido_rota(api1(usuarios), RotaDeCadastro),
    reply_html_page(
        boot5rest,
        [ title('Cadastro de usuário')],
        [ \html_requires(css('custom.css')),
          \html_requires(css('login.css')),
          \html_requires(js('comum.js')),
          \navegação('menu-topo'),
          \form_cadastro(RotaDeCadastro)
        ]
    ).

form_cadastro(RotaDeCadastro) -->
    html(main(class('py-5'),
              section(class('container login py-5'),
                      div(class('row g-0'),
                          [div(class('col-lg-6'),
                               img([ class('img-fluid'),
                                     alt('Universidade'),
                                     src('img/universidade.jpg')],[])),
                           div(class('col-lg-6 text-center py-5'),
                               [ h1('Cadastro'),
                                 \formulário_cadastro(RotaDeCadastro),
                                 p(['Já possui conta? ',
                                    a([ href('/login'),
                                        class([ 'primary-link',
                                                'text-decoration-none' ])],
                                      'Entrar')])
                               ])])))
        ).

formulário_cadastro(RotaDeCadastro) -->
    html(form([ class('p-3 rounded'),
                onsubmit("redirecionaResposta( event, '/login' )"),
                method('POST'),
                action(RotaDeCadastro)],
              [ \método_de_envio('POST'),
                \mensagem,
                \campo(nome,  'Nome',   text),
                \campo(email, 'E-mail', email),
                \campo(senha, 'Senha',  password),
                input([type(hidden), name(função), value(estudante)]),
                \enviar_ou_cancelar('/')
               ])).


mensagem -->
    html(div([ class('alert alert-danger visually-hidden'), role(alert)], ' ')).

campo(Nome, Rótulo, Tipo) -->
    html(div(class('form-row py-3'),
             div(class('offset-1 col-lg-10'),
             input([ class('entrada px-2'),
                     name(Nome),
                     type(Tipo),
                     placeholder(Rótulo)])))).

seleção(Nome) -->
    html(div(class('mx-auto py-3 w-50'),
                   select([class('form-select border-0 mb-3'),
                           name(Nome),
                           'aria-label'('Seleciona tipo do usuário')],
                          [ option([ selected(selected), value('')],
                                  'Selecione o tipo de usuário:'),
                            option(value(user), 'User'),
                            option(value(admin), 'Admin')]))).

método_de_envio(Método) -->
    html(input([type(hidden), name('_método'), value(Método)])).


enviar_ou_cancelar(RotaDeRetorno) -->
    html(div([ class('btn-group'), role(group), 'aria-label'('Enviar ou cancelar')],
             [ button([ type(submit),
                        class('btn btn-outline-primary')], 'Enviar'),
               a([ href(RotaDeRetorno),
                   class('ms-3 btn btn-outline-danger')], 'Cancelar')
            ])).
