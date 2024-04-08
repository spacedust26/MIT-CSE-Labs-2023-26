--Lab5 ER model and sql
--Lab exercises

--1)Retrieve the birth date and address of the employee(s) whose name is ‘John B. Smith’. Retrieve the name and address of all employees who work for the ‘Research’ department.
select fname, minit, lname, bdate, address from employee where fname = 'John' and minit = 'B' and lname = 'Smith';

select fname, minit, lname, address from employee, department where employee.dno = department.dnumber and dname = 'Research';

--2)For every project located in ‘Stanford’, list the project number, the controlling department number, and the department manager’s last name, address, and birth date.
select pnumber, dnum, lname, address, bdate from project, employee, department where plocation = 'Stafford' and dnum = dnumber and mgr_ssn = ssn;

--3)For each employee, retrieve the employee’s first and last name and the first and last name of his or her immediate supervisor.
select t.lname supervisor_lname, t.fname supervisor_fname , s.lname employee_lname, s.fname employee_fname from employee t, employee s where t.ssn = s.super_ssn;

--4)Make a list of all project numbers for projects that involve an employee whose last name is ‘Smith’, either as a worker or as a manager of the department that controls the project.
select pnumber from project, employee, works_on where pnumber = pno and essn = ssn and lname='Smith';

--5)Show the resulting salaries if every employee working on the ‘ProductX’ project is given a 10 percent raise.
update employee set salary = 1.1*salarywhere ssn in (select essn from works_on, project
where pno = pnumber and pname = 'ProductX');

select fname, salary from employee where ssn in(select essn from works_on, project where pno = pnumber and pname = 'ProductX');

--6)Retrieve a list of employees and the projects they are working on, ordered by department and, within each department, ordered alphabetically by last name, then first name.
Select fname, lname, employee.dno, pname, project.pnumber from employee, project, works_on where works_on.pno=project.pnumber and works_on.essn=employee.ssn order by employee.dno, fname, lname;

--7)Retrieve the name of each employee who has a dependent with the same first name and is the same sex as the employee.
select fname, minit, lname from employee, dependent where employee.fname = dependent_name and employee.sex = dependent.sex;

--8)Retrieve the names of employees who have no dependents.
select fname from employee where ssn not in(select essn from dependent);

--9)List the names of managers who have at least one dependent.
select distinct fname from employee, department, dependent where ssn = mgr_ssn and essn = ssn;

--10)Find the sum of the salaries of all employees, the maximum salary, the minimum salary, and the average salary.
select sum(salary), max(salary), min(salary), avg(salary)from employee;

--11)For each project, retrieve the project number, the project name, and the number of employees who work on that project.
select pnumber, pname, count (*) from project, works_on where pnumber = pno group by pnumber, pname;

--12)For each project on which more than two employees work, retrieve the project number, the project name, and the number of employees who work on the project.
select pnumber, pname, count (*)from project, works_on where pnumber = pno group by pnumber, pname having count(*)>2;

--13)For each department that has more than five employees, retrieve the department number and the number of its employees who are making more than 40,000.
select dno, count(*) from department, employee where dnumber = dno and salary >40000 and dnumber in (select dno from employee group by dno having count(*) > 2) group by dno;