--PL/SQL Basics

--Use a table StudentTable(RollNo, GPA) and populate the table with {(1, 5.8); (2, 6.5); (3, 3.4); (4,7.8); (5, 9.5)} unless a different DB schema is explicitly specified. 
--1. Write a PL/SQL block to display the GPA of given student.
set serveroutput on;

drop table StudentTable;

create table StudentTable(
  RollNo int,
  GPA float
);

insert into StudentTable values(1, 5.8);
insert into StudentTable values(2, 6.5);
insert into StudentTable values(3, 3.4);
insert into StudentTable values(4, 7.8);
insert into StudentTable values(5, 9.5);

declare
  roll StudentTable.RollNo%type;
  gpa StudentTable.GPA%type;
begin
  roll := '&Roll_Number';
  select GPA into gpa from StudentTable where RollNo = roll;
  dbms_output.put_line('GPA of the student is: ' || gpa);
end;
/

--Usage of IF - THEN
--2. Write a PL/SQL block to display the letter grade(0-4: F; 4-5: E; 5-6: D; 6-7: C; 7-8: B; 8-9: A; 9-10: A+} of given student.

declare
  roll StudentTable.RollNo%type;
  gpa StudentTable.GPA%type;
  grade char(2);
begin
  roll := '&Roll_number';
  select GPA into gpa from StudentTable where RollNo = roll;
  if gpa between 0 and 4 then
    grade := 'F';
  elsif gpa between 4 and 5 then
    grade := 'E';
  elsif gpa between 5 and 6 then
    grade := 'D';
  elsif gpa between 6 and 7 then
    grade := 'C';
  elsif gpa between 7 and 8 then
    grade := 'B';
  elsif gpa between 8 and 9 then
    grade := 'A';
  elsif gpa between 9 and 10 then
    grade := 'A+';
  else 
    grade := 'NA';
  end if;
  dbms_output.put_line('Letter grade of the student is: ' || grade);
end;
/
    
--3. Input the date of issue and date of return for a book. Calculate and display the fine with the appropriate message using a PL/SQL block. The fine is charged as per the table 8.1: 
--Late period Fine
--7 days NIL
-- 8 – 15 days Rs.1/day
-- 16 - 30 days Rs. 2/ day
-- After 30 days Rs. 5.00
-- Table 8.1

declare
  issue_date date;
  return_date date;
  days number;
  fine number;
begin
  issue_date := '&issue_date';
  return_date := '&return_date';
  days := to_date(return_date, 'dd/mm/yy') - to_date(issue_date, 'dd/mm/yy');
  if days <= 7 then
    fine := 0;
  elsif days>=8 and days<=15 then
    fine := (7 * 0) + (days - 7) * 1;
  elsif days>=16 and days<=30 then
    fine := (7 * 0) + (8 * 1) + ((days - 15) * 2);
  else 
    fine := (7 * 0) + (8 * 1) + (15 * 2) + ((days - 30) * 5);
  end if;
  dbms_output.put_line('Fine to be paid: ' || fine);
end;
/

--Simple LOOP
--4. Write a PL/SQL block to print the letter grade of all the students(RollNo: 1 - 5).
declare
  gpa StudentTable.GPA%type;
  grade char(2);
  i int;
begin
  i := 1;
  loop
    select GPA into gpa from StudentTable where RollNo = i;
    if gpa between 0 and 4 then
      grade := 'F';
    elsif gpa between 4 and 5 then
      grade := 'E';
    elsif gpa between 5 and 6 then
      grade := 'D';
    elsif gpa between 6 and 7 then
      grade := 'C';
    elsif gpa between 7 and 8 then
      grade := 'B';
    elsif gpa between 8 and 9 then
      grade := 'A';
    elsif gpa between 9 and 10 then
      grade := 'A+';
    else 
      grade := 'NA';
    end if;
    dbms_output.put_line('Roll number ' || i || ' : ' || grade);
    i := i + 1;
    if(i > 5) then exit;
    end if;
  end loop;
end;
/

--Usage of WHILE
--5. Alter StudentTable by appending an additional column LetterGrade Varchar2(2). Then write a PL/SQL block to update the table with letter grade of each student.

alter table StudentTable add (LetterGrade varchar2(2));

declare
  gpa StudentTable.GPA%type;
  grade char(2);
  i int;
begin
  i := 1;
  while i < 6 loop
    select GPA into gpa from StudentTable where RollNo = i;
    if gpa between 0 and 4 then
      grade := 'F';
    elsif gpa between 4 and 5 then
      grade := 'E';
    elsif gpa between 5 and 6 then
      grade := 'D';
    elsif gpa between 6 and 7 then
      grade := 'C';
    elsif gpa between 7 and 8 then
      grade := 'B';
    elsif gpa between 8 and 9 then
      grade := 'A';
    elsif gpa between 9 and 10 then
      grade := 'A+';
    else 
      grade := 'NA';
    end if;
    update StudentTable set LetterGrade = grade where RollNo = i;
    i := i + 1;
  end loop;
end;
/

--Usage of FOR
--6. Write a PL/SQL block to find the student with max. GPA without using aggregate function
declare
  gpa StudentTable.GPA%type;
  roll int;
  maxgpa float;
  i int;
begin
  maxgpa := 0;
  for i in 1..5 loop
    select GPA into gpa from StudentTable where RollNo = i;
    if gpa > maxgpa then
      maxgpa := gpa;
      roll := i;
    end if;
  end loop;
  dbms_output.put_line('Student with roll number '|| roll || ' has the max GPA of ' || maxgpa);
end;
/

--Usage of GOTO
--7. Implement lab exercise 4 using GOTO. 
declare
  gpa StudentTable.GPA%type;
  grade char(2);
  i int := 1;
begin
    <<start_part>>
    select GPA into gpa from StudentTable where RollNo = i;
    if gpa between 0 and 4 then
      grade := 'F';
    elsif gpa between 4 and 5 then
      grade := 'E';
    elsif gpa between 5 and 6 then
      grade := 'D';
    elsif gpa between 6 and 7 then
      grade := 'C';
    elsif gpa between 7 and 8 then
      grade := 'B';
    elsif gpa between 8 and 9 then
      grade := 'A';
    elsif gpa between 9 and 10 then
      grade := 'A+';
    else 
      grade := 'NA';
    end if;
    dbms_output.put_line('Roll number ' || i || ' : ' || grade);
    i := i + 1;
    if(i < 6) then goto start_part;
    end if;
end;
/

--Exception Handling
--8. Based on the University database schema, write a PL/SQL block to display the details of the Instructor whose name is supplied by the user. Use exceptions to show appropriate error message for the following cases:
--a. Multiple instructors with the same name
--b. No instructor for the given name
declare
  iname instructor.name%type;
  details instructor%rowtype;
begin
  iname := '&Instructor_Name';
  select name into iname from instructor where name = iname;
  select * into details from instructor where name = iname;
  dbms_output.put_line('Found');
  dbms_output.put_line('ID: ' || details.id || ' Name: ' || details.name || ' Dept-name: ' || details.dept_name || ' Salary: ' || details.salary);
exception
  when dup_val_on_index then 
    dbms_output.put_line('Multiple instructors with same name');
  when no_data_found then
    dbms_output.put_line('No instructors for the given name');
end;
/

--Additional Exercises

--Usage of IF-THEN
--1. Write a PL/SQL block to find out if a year is a leap year
declare
  yr int;
begin
  yr := '&year';
  if yr mod 4 = 0 then
    if yr mod 100 = 0 then 
      dbms_output.put_line('Not a leap year');
    else
      dbms_output.put_line('Leap year');
    end if;
  else 
    dbms_output.put_line('Not a leap year');
  end if;
end;
/

--2. You went to a video store and rented DVD that is due in 3 days from the rental date. Input the rental date, rental month and rental year. Calculate and print the return date, return month, and return year.
declare
  rental_date date;
  return_date date;
begin
  rental_date := '&rental_date';
  return_date := to_date(rental_date,'dd/mm/yy') + 3;
  dbms_output.put_line('Return date: '|| return_date);
end;
/

--Simple loop
--3. Write a simple loop such that message is displayed when a loop exceeds a particular value.
declare
  message varchar2(20) := 'Exceeded value: ';
  i int := 0;
begin
  loop
  if i > 5 then
    dbms_output.put_line(message || i);
    exit;
  end if;
  i := i + 1;
  end loop;
end;
/

--4. Write a PL/SQL block to print all odd numbers between 1 and 10.
declare
  i int := 1;
begin
  dbms_output.put_line('Odd numbers between 1 to 10: ');
  loop
    if i mod 2 != 0 then
      dbms_output.put_line(i);
    end if;
    i:= i + 1;
    if(i > 10) then exit;
    end if;
  end loop;
end;
/

--Usage of while
--5. Write a PL/SQL block to reverse a given string.
declare
  string varchar(20);
  rev_string varchar(20):= '';
  str_len int;
  i int := 0;
begin
  string := '&string';
  str_len := length(string);
  while i < str_len loop
    rev_string := substr(string, i + 1 , 1 )|| rev_string;
    i := i + 1;
  end loop;
  dbms_output.put_line('Original String: ' || string);
  dbms_output.put_line('Reversed string: '|| rev_string);
end;
/

--Usage of FOR
--6. Write a PL/SQL block of code for inverting a number 5639 or 9365.
declare 
  num int := 5639;
  i int;
  rev int := 0;
begin
  for i in 0..3 loop
    rev := (rev * 10) + (num mod 10);
    num := trunc(num / 10);
  end loop;
  dbms_output.put_line('Reversed number: ' || rev);
end;
/

--Usage of GOTO
--7. Write a PL/SQL block of code to achieve the following: if the price of Product ‘p00001’ is less than 4000, then change the price to 4000. The Price change has to be recorded in the old_price_table along with Product_no and the date on which the price was last changed. Tables involved: 
--Product_master(product_no, sell_price)
--Old_price_table(product_no,date_change, Old_price)

drop table Product_master;
drop table old_price_table;

create table Product_master(
  product_no varchar(10),
  sell_price number
);

create table old_price_table(
  product_no varchar(10),
  date_change date,
  old_price number
);

insert into Product_master values('p00001', 800);
insert into Product_master values('p00002', 2000);
insert into Product_master values('p00003', 6000);
insert into Product_master values('p00004', 1000);

declare
  sell number;
begin
  select sell_price into sell from Product_master where product_no = 'p00001';
  if sell < 4000 then goto change;
  else 
    goto done;
  end if;
  <<change>>
    insert into old_price_table values('p00001',sysdate,sell);
    update Product_master set sell_price = 4000 where product_no = 'p00001';
  <<done>>
    dbms_output.put_line('Done!');
end;
/

--Exception
--8. Write a PL/SQL block that asks the user to input first number, second number and an arithmetic operator (+, -, *, /). If the operator is invalid, throw and handle a user-defined exception. If the second number is zero and the operator is /, handle the ZERO_DIVIDE predefined server exception.
declare
  first_num number;
  second_num number;
  operator char(1);
  invalid_operator exception;
  ans number;
begin
  first_num := '&first_number';
  operator := '&operator';
  second_num := '&second_number';
  if operator = '+' then
    ans := first_num + second_num;
  elsif operator = '-' then
    ans := first_num - second_num;
  elsif operator = '*' then
    ans := first_num * second_num;
  elsif operator = '/' then
    ans := first_num / second_num;
  else 
    raise invalid_operator;
  end if;
  dbms_output.put_line(first_num || operator || second_num || ' = ' || ans);
exception
  when invalid_operator then
    dbms_output.put_line('Invalid operator');
  when zero_divide then
    dbms_output.put_line('Divide by 0 error not allowed');
end;
/
  
--Final deletions
drop table StudentTable;
drop table Product_master;
drop table old_price_table;