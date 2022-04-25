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
    html([ h1('Demonstração do Mailman'),
           div(\menu_de_navegação),
           p('O corpo vai aqui')
         ]).

menu_de_navegação -->
    {
        findall(Nome, item(Nome, _), NomesBotões),
	    maplist(item_topo, NomesBotões, BotõesTopo)
    },
    html(BotõesTopo).

item('Início', '/home').
item('Sobre',  '/sobre').
item('Vendas', '/vendas').

item_topo(Nome, a([href=Link, class=topo], Nome)) :-
	item(Nome, Link).
