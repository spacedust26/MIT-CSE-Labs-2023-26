--PROCEDURES, FUNCTIONS & PACKAGES
--Lab exercises

--Procedures:
--1. Write a procedure to display a message “Good Day to You”.
set serveroutput on;
create or replace procedure message is
begin
  dbms_output.put_line('Good day to you');
end;
/

declare
begin
  message;
end;
/

--2. Based on the University Database Schema in Lab 2, write a procedure which takes the dept_name as input parameter and lists all the instructors associated with the department as well as list all the courses offered by the department. Also, write an anonymous block with the procedure call.
create or replace procedure lists(dept instructor.dept_name%type) is
  cursor c1 is select name from instructor where dept_name = dept;
  cursor c2 is select title from course where dept_name = dept;
begin
  dbms_output.put_line('-----Instructors: ');
  for temp in c1 loop
    dbms_output.put_line(temp.name);
  end loop;
  dbms_output.put_line('-----Courses: ');
  for temp in c2 loop
    dbms_output.put_line(temp.title);
  end loop;
end;
/

declare
  dept instructor.dept_name%type;
begin
  dept := '&dept_name';
  lists(dept);
end;
/

--3. Based on the University Database Schema in Lab 2, write a Pl/Sql block of code that lists the most popular course (highest number of students take it) for each of the departments. It should make use of a procedure course_popular which finds the most popular course in the given department.
create or replace procedure course_popular(dept course.dept_name%type) is
  cursor c is select takes.course_id , count(distinct takes.id) as num from takes join course on takes.course_id = course.course_id where course.dept_name = dept group by takes.course_id;
  maxnum int := 0;
  cmax course.course_id%type;
begin
  for temp in c loop
    if temp.num > maxnum then
      maxnum := temp.num;
      cmax := temp.course_id;
    end if;
  end loop;
  DBMS_OUTPUT.PUT_LINE('Most popular course in ' || dept || ' is: ' || cmax || ' with ' || maxnum || ' students.');
end;
/

declare
  cursor c1 is select dept_name from department;
begin
  for temp in c1 loop
    course_popular(temp.dept_name);
  end loop;
end;
/

--4. Based on the University Database Schema in Lab 2, write a procedure which takes the dept-name as input parameter and lists all the students associated with the department as well as list all the courses offered by the department. Also, write an anonymous block with the procedure call
create or replace procedure list(dept department.dept_name%type) is
  cursor c1 is select name from student where dept_name = dept;
  cursor c2 is select title from course where dept_name = dept;
begin
  dbms_output.put_line('-----Students: ');
  for temp in c1 loop
    dbms_output.put_line(temp.name);
  end loop;
  dbms_output.put_line('-----Courses: ');
  for temp in c2 loop
    dbms_output.put_line(temp.title);
  end loop;
end;
/

declare
  cursor c1 is select dept_name from department;
begin
  for temp in c1 loop
    list(temp.dept_name);
  end loop;
end;
/

--Functions:
--5. Write a function to return the Square of a given number and call it from an anonymous block.
create or replace function square_num(num number) return number as
  ans number;
begin
  ans := num * num;
  return ans;
end;
/

declare
  num number;
  ans number;
begin
  num := '&Number';
  ans := square_num(num);
  dbms_output.put_line('Square of the number is: ' || ans);
end;
/

--6. Based on the University Database Schema in Lab 2, write a Pl/Sql block of code that lists the highest paid Instructor in each of the Department. It should make use of a function department_highest which returns the highest paid Instructor for the given branch.
create or replace function department_highest(dept instructor.dept_name%type) return instructor.name%type as
  cursor c is select * from instructor where dept_name = dept;
  maxsal instructor.salary%type := 0;
  iname instructor.name%type;
begin
  for temp in c loop
    if temp.salary > maxsal then
      maxsal := temp.salary;
      iname := temp.name;
    end if;
  end loop;
return iname;
end;
/

declare
  cursor c is select dept_name from department;
  iname instructor.name%type;
begin
  for temp in c loop
    iname := department_highest(temp.dept_name);
    dbms_output.put_line(temp.dept_name || ' - ' || iname);
  end loop;
end;
/

--Packages:
--7. Based on the University Database Schema in Lab 2, create a package to include the following:
--a) A named procedure to list the instructor_names of given department
--b) A function which returns the max salary for the given department
--c) Write a PL/SQL block to demonstrate the usage of above package components

create or replace package p1 as
  procedure list_names(dept instructor.dept_name%type);
  function max_salary(dept instructor.dept_name%type) return instructor.salary%type;
end p1;
/

create or replace package body p1 as
  procedure list_names(dept instructor.dept_name%type) is 
    cursor c1 is select * from instructor where dept_name = dept;
  begin
    for temp in c1 loop
      dbms_output.put_line(temp.name);
    end loop;
  end;

  function max_salary(dept instructor.dept_name%type) return instructor.salary%type as
  cursor c2 is select * from instructor where dept_name = dept;
  maxsal instructor.salary%type := 0;
  begin
    for temp in c2 loop
      if temp.salary > maxsal then
        maxsal := temp.salary;
      end if;
    end loop;
  return maxsal;
  end;
end p1;
/

declare
  dept instructor.dept_name%type;
  num instructor.salary%type;
begin
  dept := '&dept_name';
  p1.list_names(dept);
  num := p1.max_salary(dept);
  dbms_output.put_line('Maximum salary: ' ||num);
end;
/

--Parameter Modes: IN, OUT, IN OUT
--8. Write a PL/SQL procedure to return simple and compound interest (OUT parameters) along with the Total Sum (IN OUT) i.e. Sum of Principle and Interest taking as input the principle, rate of interest and number of years (IN parameters). Call this procedure from an anonymous block.
create or replace procedure interest(simple_interest out number, compound_interest out number, total_sum in out number, principal in number, rate_of_interest in number, years in number) is
begin
  simple_interest := (principal * years * rate_of_interest) / 100;
  compound_interest := principal * power((1 + (rate_of_interest/100)), years) - principal;
  total_sum := simple_interest + compound_interest + principal;
end;
/

declare
  p number;
  t number;
  r number;
  si number;
  ci number;
  ts number := 0;
begin
  p := '&principle_amount';
  t := '&time';
  r := '&rate_of_interest';
  interest(si,ci,ts,p,r,t);
  dbms_output.put_line('SI: ' || si);
  dbms_output.put_line('CI: ' || ci);
  dbms_output.put_line('Total sum: '|| ts);
end;
/