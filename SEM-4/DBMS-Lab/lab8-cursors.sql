--Cursors
--Lab exercises

--CursorName %ISOPEN / FOUND / NOT FOUND:
--1. The HRD manager has decided to raise the salary of all the Instructors in a given department number by 5%. Whenever, any such raise is given to the instructor, a record for the same is maintained in the salary_raise table. It includes the Instuctor Id, the date when the raise was given and the actual raise amount. Write a PL/SQL block to update the salary of each Instructor and insert a record in the salary_raise table.
--salary_raise(Instructor_Id, Raise_date, Raise_amt)
drop table salary_raise;
create table salary_raise(
  instructor_id varchar(5),
  raise_date date,
  raise_amt numeric(8,2)
);

declare
  cursor c is select * from instructor;
  temp instructor%rowtype;
begin
  open c;
  loop fetch c into temp;
    insert into salary_raise values(temp.id,sysdate,temp.salary * 0.05);
    exit when c % notfound;
  end loop;
  close c;
  update instructor set salary = 1.5 * salary;
end;
/

--CursorName%ROWCOUNT:
--2. Write a PL/SQL block that will display the ID, name, dept_name and tot_cred of the first 10 students with lowest total credit.
declare
  cursor c is select * from student order by tot_cred asc;
  stud student%rowtype;
begin
  open c;
  loop fetch c into stud;
  dbms_output.put_line(stud.id || ' ' ||stud.name ||' ' || stud.dept_name ||' ' || stud.tot_cred);
  exit when c%rowcount >= 10;
  end loop;
  close c;
end;
/

--Cursor For Loops:
--3.Print the Course details and the total number of students registered for each course along with the course details - (Course-id, title, dept-name, credits, instructor_name, building, room-number, time-slot-id, tot_student_no )
declare
  cursor c1 is select course_id, count(distinct id) as num from takes group by course_id;
  cursor c2 is select c.course_id, c.title, c.dept_name, c.credits, i.name, s.building, s.room_number, s.time_slot_id from course c, instructor i, section s where c.dept_name = i.dept_name and c.course_id = s.course_id;
begin
  for rec in c1 loop
    dbms_output.put_line(rec.course_id || ' ' || rec.num);
  end loop;
  for det in c2 loop
    dbms_output.put_line(det.course_id || ' ' || det.title || ' ' || det.dept_name ||' ' || det.credits||' ' || det.name||' ' || det.building||' ' || det.room_number||' ' || det.time_slot_id );
  end loop;
end;
/

--4. Find all students who take the course with Course-id: CS101 and if he/ she has less than 30 total credit (tot-cred), deregister the student from that course. (Delete the entry in Takes table)
declare
  cursor c1 is select * from takes where course_id = 'CS101';
  tc student.tot_cred%type;
begin
  for temp in c1 loop
    select tot_cred into tc from student where id = temp.id;
    if tc < 30 then
      delete from takes where id = temp.id and course_id = temp.course_id;
    end if;
  end loop;
end;
/

--Where Current of:
--5. Alter StudentTable(refer Lab No. 8 Exercise) by resetting column LetterGrade to F. Then write a PL/SQL block to update the table by mapping GPA to the corresponding letter grade for each student.
update StudentTable set LetterGrade = 'F';
declare
  cursor c1 is select * from StudentTable for update;
  gpa StudentTable.GPA%type;
  grade char(2);
begin
  for temp in c1 loop
      select GPA into gpa from StudentTable where RollNo = temp.RollNo;
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
    update StudentTable set LetterGrade = grade where current of c1;
  end loop;
end;
/

--Parameterized Cursors:
--6. Write a PL/SQL block to print the list of Instructors teaching a specified course.
declare
  cursor c1(ci teaches.course_id%type) is select * from teaches where course_id = ci;
  cid teaches.course_id%type;
begin
  cid := '&course_id';
  for temp in c1(cid) loop
    dbms_output.put_line(temp.id);
  end loop;
end;
/

--7. Write a PL/SQL block to list the students who have registered for a course taught by his/her advisor.
declare
  advisor_id_var instructor.id%type := 10101;
  cursor c (aid instructor.iD%type) is select distinct s.id, s.name from student s join Takes t on s.id = t.id join teaches te on t.course_id = te.course_id join instructor i on te.id = i.id where i.id = aid;
  student_id student.id%type;
  student_name student.name%type;
begin
  for temp in c(advisor_id_var) loop
      dbms_output.put_line('Student ID: ' || temp.id || ', Student Name: ' || temp.name);
  end loop;
end;
/


