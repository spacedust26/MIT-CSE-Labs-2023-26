--Tiggers
--Lab exercises

--Row Triggers
--1. Based on the University database Schema in Lab 2, write a row trigger that records along with the time any change made in the Takes (ID, course-id, sec-id, semester, year, grade) table in log_change_Takes (Time_Of_Change, ID, courseid,sec-id, semester, year, grade).
create table log_change_Takes(
  Time_Of_Change date,
  id varchar(5),
  courseid varchar(8),
  sec_id varchar(8),
  semester varchar(6),
  year numeric(4,0),
  grade varchar(2)
);

create or replace trigger takes_change before insert or update or delete on takes for each row 
begin 
  case
    when inserting then 
      insert into log_change_Takes values(sysdate, :new.id, :new.course_id, :new.sec_id, :new.semester, :new.year, :new.grade);
    when updating or deleting then
      insert into log_change_Takes values(sysdate, :old.id, :old.course_id, :old.sec_id, :old.semester, :old.year, :old.grade);
    end case;
end;
/

--2. Based on the University database schema in Lab: 2, write a row trigger to insert the existing values of the Instructor (ID, name, dept-name, salary) table into a new table Old_ Data_Instructor (ID, name, dept-name, salary) when the salary table is updated.	
create table Old_Data_Instructor(
  id varchar(5),
  name varchar(20),
  dept_name varchar(20), 
  salary numeric(8,2)
);

create or replace trigger instructor_changes before update of salary on instructor for each row
begin
    insert into Old_Data_Instructor values(:old.id, :old.name, :old.dept_name, :old.salary);
end;
/

--Database Triggers
--3. Based on the University Schema, write a database trigger on Instructor that checks the following:
-- The name of the instructor is a valid name containing only alphabets.
-- The salary of an instructor is not zero and is positive
-- The salary does not exceed the budget of the department to which the instructor belongs.
create or replace trigger instructor_valid before insert or update on instructor for each row
declare
  dep_budget number;
begin
  if not regexp_like(:new.name, '^[[:alpha:]]+$') then
    raise_application_error(-20001,'Invalid name format. Must contain only alphabets.');
  end if;
  if :new.salary <= 0 then
    raise_application_error(-2002,'Salary must be positive non zero value');
  end if;
  select budget into dep_budget from department where dept_name = :new.dept_name;
  if :new.salary > dep_budget then
    raise_application_error(-2003,'Salary exceeds the budget of the department.');
  end if;
end;
/

--4. Create a transparent audit system for a table Client_master (client_no, name, address, Bal_due). The system must keep track of the records that are being deleted or updated. The functionality being when a record is deleted or modified the original record details and the date of operation are stored in the auditclient (client_no, name, bal_due, operation, userid, opdate) table, then the delete or update is allowed to go through.
create table Client_master(
  client_no int,
  name varchar(25),
  address varchar(50),
  bal_due number
);

create table auditclient(
  client_no int,
  name varchar(25),
  bal_due number,
  operation varchar(20),
  userid int,
  opdate date
);

create or replace trigger audit_changes before delete or update on Client_master for each row 
declare
begin
  case 
    when updating then
      insert into auditclient values(:old.client_no, :old.name, :old.bal_due, 'Update',1000,sysdate);
    when deleting then
      insert into auditclient values(:old.client_no, :old.name, :old.bal_due, 'Delete',1000,sysdate);
  end case;
end;
/

--Instead of Triggers
--5. Based on the University database Schema in Lab 2, create a view Advisor_Student which is a natural join on Advisor, Student and Instructor tables. Create an INSTEAD OF trigger on Advisor_Student to enable the user to delete the corresponding entries in Advisor table.
create view Advisor_Student as
select advisor.s_id, advisor.i_id from advisor, student, instructor where advisor.s_id = student.id and advisor.i_id = instructor.id;

create or replace trigger advisor_change instead of delete on Advisor_Student for each row
begin
  delete from advisor where s_id = :old.s_id and i_id = :old.i_id;
end;
/