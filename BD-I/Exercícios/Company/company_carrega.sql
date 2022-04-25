/* ============================================================ */
/*   Database SCHEMA:  company                                  */
/*   DBMS name:        Postgresql 7.3                           */
/* ============================================================ */
BEGIN TRANSACTION;
SET CONSTRAINTS ALL DEFERRED;
SET SEARCH_PATH TO company; -- DEFINE ESQUEMA DEFAULT
INSERT INTO  employee
	VALUES ('James', 'E', 'Borg', '888665555',
		DATE '1937-11-10', '450 Stone, Houston, TX',
		'M', 55000, null, 1);
INSERT INTO  employee
	VALUES ('Franklin', 'T', 'Wong', '333445555',
		DATE '1955-12-08', '638 Voss, Houston, TX',
		'M', 40000, '888665555', 5);
INSERT INTO  employee
	VALUES ('John', 'B', 'Smith', '123456789',
		DATE '1965-01-09', '731 Fondren, Houston, TX',
		'M', 30000, '333445555', 5);
INSERT INTO  employee
	VALUES ('Alicia', 'J', 'Zelaya', '999887777',
		DATE '1968-07-19', '3321 Castle, Spring, TX',
		'F', 25000, '987654321', 4);
INSERT INTO  employee
	VALUES ('Jennifer', 'S', 'Wallace', '987654321',
		DATE '1941-06-20', '291 Berry, Bellaire,TX',
		'F', 43000, '888665555', 4);
INSERT INTO  employee
	VALUES ('Ramesh', 'K', 'Narayan', '666884444',
		DATE '1962-09-15', '975 Fire Oak, Humble, TX',
		'M', 38000, '333445555', 5);
INSERT INTO  employee
	VALUES ('Joyce', 'A', 'English', '453453453',
		DATE '1972-07-31', '5631 Rice, Houston,TX',
		'F', 25000, '333445555', 5);
INSERT INTO  employee
	VALUES ('Ahmad', 'V', 'Jabbar', '987987987',
		DATE '1969-03-29', '980 Dallas, Houston, TX',
		'M', 25000, '987654321', 4);

INSERT INTO  department
	VALUES ('Research', 5, '333445555', DATE '1988-05-22');
INSERT INTO  department
	VALUES ('Administration', 4, '987654321', DATE '1995-01-01');
INSERT INTO  department
	VALUES ('Headquarters', 1, '888665555', DATE '1981-06-19');


INSERT INTO  dept_locations VALUES (1, 'Houston');
INSERT INTO  dept_locations VALUES (4, 'Stafford');
INSERT INTO  dept_locations VALUES (5, 'Bellaire');
INSERT INTO  dept_locations VALUES (5, 'Sugarland');
INSERT INTO  dept_locations VALUES (5, 'Houston');

INSERT INTO  project VALUES ('ProductX',  1, 'Bellaire', 5);
INSERT INTO  project VALUES ('ProductY',  2, 'Sugarland', 5);
INSERT INTO  project VALUES ('ProductZ',  3, 'Houston', 5);
INSERT INTO  project VALUES ('Computerization', 10, 'Stafford', 4);
INSERT INTO  project VALUES ('Reorganization',  20, 'Houston', 1);
INSERT INTO  project VALUES ('Newbenefits',     30, 'Stafford', 4);

INSERT INTO  works_on VALUES ('123456789',  1, 32.5);
INSERT INTO  works_on VALUES ('123456789',  2,  7.5);
INSERT INTO  works_on VALUES ('666884444',  3, 40.0);
INSERT INTO  works_on VALUES ('453453453',  1, 20.0);
INSERT INTO  works_on VALUES ('453453453',  2, 20.0);
INSERT INTO  works_on VALUES ('333445555',  2, 10.0);
INSERT INTO  works_on VALUES ('333445555',  3, 10.0);
INSERT INTO  works_on VALUES ('333445555', 10, 10.0);
INSERT INTO  works_on VALUES ('333445555', 20, 10.0);
INSERT INTO  works_on VALUES ('999887777', 30, 30.0);
INSERT INTO  works_on VALUES ('999887777', 10, 10.0);
INSERT INTO  works_on VALUES ('987987987', 10, 35.0);
INSERT INTO  works_on VALUES ('987987987', 30,  5.0);
INSERT INTO  works_on VALUES ('987654321', 30, 20.0);
INSERT INTO  works_on VALUES ('987654321', 20, 15.0);
INSERT INTO  works_on VALUES ('888665555', 20, null);

INSERT INTO  dependent VALUES ('333445555',  'Alice', 'F', DATE '1986-04-05', 'DAUGHTER');
INSERT INTO  dependent VALUES ('333445555',  'Theodore', 'M', DATE '1983-10-25', 'SON');
INSERT INTO  dependent VALUES ('333445555',  'Joy', 'F', DATE '1958-05-03', 'SPOUSE');
INSERT INTO  dependent VALUES ('987654321',  'Abner', 'M', DATE '1942-02-28', 'SPOUSE');
INSERT INTO  dependent VALUES ('123456789',  'Michael', 'M', DATE '1988-01-04', 'SON');
INSERT INTO  dependent VALUES ('123456789',  'Alice', 'F', DATE '1988-12-30', 'DAUGHTER');
INSERT INTO  dependent VALUES ('123456789',  'Elizabeth', 'F', DATE '1967-05-05', 'SPOUSE');

END TRANSACTION;
