--DROP SCHEMA company CASCADE;
CREATE SCHEMA company;
SET search_path TO company;
CREATE TABLE employee  (
	fname varchar  (15)  not null,
        minit char,
	lname varchar (15)  not null,
        ssn char(9)  not null,
        bdate date,
	address varchar(30),
        sex char CHECK (sex IN ('M', 'F')),
	salary DECIMAL(10, 2),
        superssn char(9),
	dno int not null,
        primary key (ssn),
	CONSTRAINT emp_superssn FOREIGN KEY (superssn)
	   REFERENCES employee(ssn) DEFERRABLE
);
CREATE TABLE department  (
	dname varchar(15)  not null,
        dnumber int not null,
	mgrssn char(9),
        mgrstartdate date,
	primary key  (dnumber),
        foreign key  (mgrssn) REFERENCES employee(ssn));
CREATE TABLE dependent (
	essn char (9)  not null,
	dependent_name varchar  (30) not null,
       	sex char,
	bdate date,
       relationship varchar(15),
       primary key  (essn,  dependent_name),
       foreign key  (essn)  REFERENCES employee(ssn)
);
ALTER TABLE employee
	ADD CONSTRAINT emp_dno FOREIGN KEY (dno)
	REFERENCES department(dnumber)  DEFERRABLE;

CREATE TABLE dept_locations (
	dnumber int not null,
        dlocation varchar(15),
        foreign key (dnumber) REFERENCES department(dnumber)
);
CREATE TABLE project  (
	pname varchar(20),
     	pnumber int not null,
	plocation varchar(15),
     	dnum int,
     	primary key (pnumber),
     	foreign key (dnum)  REFERENCES department(dnumber)
);
CREATE TABLE works_on   (
	essn char(9) not null,
        pno int not null,
	hours decimal(4,2),
       	foreign key  (essn) REFERENCES employee(ssn),
       	foreign key  (pno)  REFERENCES project(pnumber)
);
