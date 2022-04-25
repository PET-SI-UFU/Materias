-- Listar a data de nascimento e o endereço dos empregados com nome: John B Smith
select bdate, adress
    from employee
    where fname = "John" and minit = 'B' and lname = "Smith"