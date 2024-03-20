drop table employee;
drop table employee1;

--1.Create a table employee with ( emp_no, emp_name, emp_address)
create table employee(
  emp_no int,
  emp_name varchar(20),
  emp_address varchar(25)
);

--2.Insert five employees information.
insert into employee values(1, 'Harry', 'Manipal');
insert into employee values(2, 'Hermione', 'Manipal');
insert into employee values(3, 'Ron', 'Manglore');
insert into employee values(4, 'Hagrid', 'Manipal');
insert into employee values(5, 'Malfoy', 'Manglore');

--3.Display names of all employees.
select emp_name from employee;

--4.Display all the employees from ‘MANIPAL’.
select emp_name from employee where emp_address = 'Manipal';

--5.Add a column named salary to employee table.
alter table employee add(salary numeric(8,2));

--6.Assign the salary for all employees.
update employee set salary = 1000 where emp_no = 1;
update employee set salary = 2000 where emp_no = 2;
update employee set salary = 3000 where emp_no = 3;
update employee set salary = 500 where emp_no = 4;
update employee set salary = 5000 where emp_no = 5;

--7.View the structure of the table employee using describe.
describe employee;

--8.Delete all the employees from ‘MANGALORE’
delete from employee where emp_address = 'Manglore';

--9.Rename employee as employee1. 
rename employee to employee1;

--10.Drop the table employee1.
drop table employee1;