--LAB2 - Integrity Constraint in SQL
--Lab Exercises
drop table Department;
drop table Employee;

--1. Create Employee table with following constraints: Make EmpNo as Primary key. Do not allow EmpName, Gender, Salary and Address to have null values. Allow Gender to have one of the two values: ‘M’, ‘F’
create table Employee(
  EmpNo int primary key,
  EmpName varchar(25) not null,
  Gender char(1) not null,
  Salary numeric(10,2) not null,
  Address varchar(25) not null,
  DNo int,
  check(gender in('M','F'))
);

--2.Create Department table with following: Make DeptNo as Primary key Make DeptName as candidate key
create table Department(
  DeptNo int primary key,
  DeptName varchar(20) unique,
  Location varchar(25)
);

--3.Make DNo of Employee as foreign key which refers to DeptNo of Department.
alter table Employee add constraint fkdno foreign key(DNo) references Department;

--4.Insert few tuples into Employee and Department which satisfies the above constraints
insert into Department values(101, 'Cyber_Crime', 'India');
insert into Department values(102, 'Drama', 'Germany');
insert into Department values(103, 'Arts', 'Venice');
insert into Department values(104, 'AI', 'Texas');

insert into Employee values(1, 'Gru', 'M', 96000, 'India', 101);
insert into Employee values(2, 'Kevin', 'M', 50000, 'Venice', 103);
insert into Employee values(3, 'Madge', 'F', 80000, 'Texas', 104);
insert into Employee values(4, 'Stuart', 'M', 30000, 'Germany', 102);

--5.Try  to  insert  few  tuples  into  Employee  and  Department  which  violates  some  of  the above constraints
insert into Department values(104, 'Fashion_Design', 'Mexico'); --violates primary key constarint
insert into Department values(105, 'AI', 'Antigua');--violates unique dept name constraint
insert into Employee values(5, 'Stacey', 'L', 50000, 'Germany', 102); --violates restriction set on gender

--6.Try to modify/delete a tuple which violates a constraint
delete from Department where DeptNo = 104; --violates foreign key constraint
update Employee set gender = 'G' where EmpNo = 1;--violates restriction set on gender

--7.Modify the foreign key constraint of Employee table such that whenever a department tuple is deleted, the employees belonging to that department will also be deleted
alter table Employee drop constraint fkdno;
alter table Employee add constraint fkdno foreign key(DNo) references Department on delete cascade;

-- Naming Constraints:
--8.Create a named constraint to set the default salary to 10000 and test the constraint by inserting a new record. 
alter table Employee modify(constraint defsalary salary default 10000);
insert into Employee(EmpNo, EmpName, Gender, Address) values(5, 'Minion', 'M', 'India');
select * from Employee;

-- Retrieving records from a table:
--9.List all Students with names and their department names.
select name, dept_name from student;

--10.List all instructors in CSE department.
select * from instructor where dept_name = 'Comp. Sci.';

--11.Find the names of courses in CSE department which have 3 credits
select title from course where dept_name = 'Comp. Sci.' and credits = 3;

--12.For the student with ID 12345 (or any other value), show all course-id and title of all courses registered for by the student.
select course_id, title from course natural join takes where id = '12345';

--13.List all the instructors whose salary is in between 40000 and 90000.
select * from instructor where salary between 40000 and 90000;

--Retrieving records from multiple tables:
--14.Display the IDs of all instructors who have never taught a course.
select id from instructor where id not in (select id from teaches);

--15.Find the student names, course names, and the year, for all students those who have attended classes in room-number 303.
select name, title, takes.year from student join takes on student.id = takes.id join section on takes.course_id = section.course_id join course on takes.course_id = course.course_id where section.room_number = 303;

-- Rename and Tuple Variables (Use as in select and from):
--16.For all students who have opted courses in 2015, find their names and course id’s with the attribute course title replaced by c-name
select name, takes.course_id , title c_name from student, course, takes where student.id = takes.id and course.course_id = takes.course_id and year = 2015;

--17.Find the names of all instructors whose salary is greater than the salary of at least one instructor of CSE department and salary replaced by inst-salary.
select name, salary inst_salary from instructor where salary > some(select salary from instructor where dept_name = 'Comp. Sci.');
--or
select name, salary inst_salary from instructor where salary > (select min(salary) from instructor where dept_name = 'Comp. Sci.');

-- String Operations (Use %, _, LIKE):
--18.Find the names of all instructors whose department name includes the substring ‘ch’.
select name from instructor where dept_name like '%ic%';

--Built-in Functions:
--19.List the student names along with the length of the student names
select name , length(name) from student;

--20.List the department names and 3 characters from 3rd position of each department name
select dept_name, substr(dept_name,3,3) from department;

--21.List the instructor names in upper case.
select upper(name) from instructor;

--22.Replace NULL with value1(say 0) for a column in any of the table
select id, course_id , nvl(grade, 0) from takes where id = '98988';

--23.Display the salary and salary/3 rounded to nearest hundred from Instructor
select salary , round(salary/3, -2) from instructor;

--24.Display the birth date of all the employees in the following format:‘DD-MON-YYYY’‘DD-MON-YY’‘DD-MM-YY
alter table Employee add(dob Date);

update Employee set dob = '01-Jan-2001' where EmpNo = 1;
update Employee set dob = '2-Feb-2002' where EmpNo = 2;
update Employee set dob = '3-Mar-2003' where EmpNo = 3;
update Employee set dob = '4.Apr.2004' where EmpNo = 4;

select to_char(dob,'DD-Mon-YYYY') from employee;
select to_char(dob,'DD-Mon-YY') from employee;
select to_char(dob,'DD-MM-YY') from employee;

--25. List the employee names and the year (fully spelled out) in which they are born ‘YEAR’, ‘Year’, ‘year’
select EmpName, to_char(dob,'YEAR') from employee;
select EmpName, to_char(dob,'Year') from employee;
select EmpName, to_char(dob,'year') from employee;

--Additonal Exercises

--1. Modify the employee table to check the salary of every employee to be greater than 5000
alter table employee add constraint sal_check check(salary > 5000);

--2. Find the quarter of year from the given date.
select to_char(sysdate, 'Q') as qtr from  dual;

--3. Convert seconds to hours, minutes and seconds format.
select to_char(to_date(10000,'sssss'),'hh24:mi:ss') from dual;

--4. Find the week of the year from the given date.
select to_char(date '2024-04-08', 'iw') as week_of_year from dual;

-- 5. Find the names of all departments with instructor, and remove duplicates.
select distinct dept_name from instructor;

--6. For all instructors who have taught some course, find their names and the course ID of the courses they taught.
select distinct name, course_id from instructor, teaches where instructor.id = teaches.id;

--7. Find all the instructors with the courses they taught.
select distinct name, course_id from instructor, teaches where instructor.id = teaches.id;

--8. List all the students with student name, department name, advisor name and the number of courses registered.
select s.name, s.dept_name, i.name , count(t.course_id) num from student s join advisor a on s.id = a.s_id join instructor i on i.id = a.i_id join takes t on s.id = t.id group by s.name, s.dept_name, i.name;