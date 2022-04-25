:- module(
       pg_login,
       [ login/1 ]).

/* html//1, reply_html_page  */
:- use_module(library(http/html_write)).
/* html_requires  */
:- use_module(library(http/html_head)).

login(_) :-
    reply_html_page(
        boot5rest,
        [ title('Login')],
        [ \html_requires(css('custom.css')),
          \html_requires(css('login.css')),
          \navegação('menu-topo'),
          \form_login
        ]
    ).

form_login -->
    html(main(class('py-5'),
              section(class('container login py-5'),
                      div(class('row g-0'),
                          [div(class('col-lg-6'),
                               img([class('img-fluid'),alt('Universidade'),src('img/universidade.jpg')],[])),
                           div(class('col-lg-6 text-center py-5'),
                               [ h1('Login'),
                                 \formulário_login,
                                 p(['Ainda não possui uma conta? ',
                                    a([ href('/cadastro'),
                                        class([ 'primary-link',
                                                'text-decoration-none'])],
                                      'Cadastre-se')])
                               ])])))
        ).

formulário_login -->
    html(form([ class('p-3 rounded'),
                method('POST'),
                action('/valida_login')],
              [ \mensagem,
                \campo(email, 'E-mail', email),
                \campo(senha,'Senha', password),
                \seleção(função),
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
                           'aria-label'('Selecione tipo do usuário')],
                          [ option([ selected(selected), value('')],
                                  'Tipo de usuário:'),
                            option( value(admin),     'Administrador'),
                            option( value(estudante), 'Estudante'),
                            option( value(prof),      'Professor')
                          ]))).

método_de_envio(Método) -->
    html(input([type(hidden), name('_método'), value(Método)])).


enviar_ou_cancelar(RotaDeRetorno) -->
    html(div([ class('btn-group'), role(group), 'aria-label'('Enviar ou cancelar')],
             [ button([ type(submit),
                        class('btn btn-outline-primary')], 'Enviar'),
               a([ href(RotaDeRetorno),
                   class('ms-3 btn btn-outline-danger')], 'Cancelar')
            ])).
