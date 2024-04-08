--LAB 4 - Complex Queries on SQL
--Lab Exercises

-- Group By:
-- 1. Find the number of students in each course.
select course_id, count(id) from takes group by course_id;

-- 2. Find those departments where the average number of students are greater than 10.
select dept_name, count(distinct id) from student group by dept_name having count(distinct id) > 10; 

-- 3. Find the total number of courses in each department.
select dept_name, count(course_id) from course group by dept_name;

-- 4. Find the names and average salaries of all departments whose average salary is greater than 42000.
select dept_name, avg(salary) from instructor group by dept_name having avg(salary) > 42000;

-- 5. Find the enrolment of each section that was offered in Spring 2009.
select sec_id, count(distinct id) from takes where semester = 'Spring' and year = 2009 group by sec_id;

-- Ordering the display of Tuples (Use ORDER BY ASC/DESC):
-- 6. List all the courses with prerequisite courses, then display course id in increasing order.
select course_id , prereq_id from prereq order by course_id asc;

-- 7. Display the details of instructors sorting the salary in decreasing order. 
select * from instructor order by salary desc;

-- Derived Relations:
-- 8. Find the maximum total salary across the departments.
select max(total_sal) from (select sum(salary) as total_sal from instructor group by dept_name);

-- 9. Find the average instructors’ salaries of those departments where the average salary is greater than 42000.
select avg(inst_sal) from (select avg(salary) inst_sal from instructor group by dept_name having avg(salary) > 42000);

-- 10. Find the sections that had the maximum enrolment in Spring 2010
with total_enrol(sec_id, val) as (select sec_id, count(id) from section natural join takes where semester='Spring' and year=2010 group by sec_id)
select sec_id, max(val) from total_enrol group by sec_id;

-- 11. Find the names of all instructors who teach all students that belong to ‘CSE’ department.
select distinct name from instructor i join teaches t on i.id = t.id where course_id in (select course_id from takes natural join student where dept_name = 'Comp. Sci.');

-- 12. Find the average salary of those department where the average salary is greater than 50000 and total number of instructors in the department are more than 5.
select dept_name, avg(salary) from instructor group by dept_name having avg(salary) > 50000 and count(id) > 5;

-- With Clause:
-- 13. Find all departments with the maximum budget.
with temp as(select max(budget) as mb
from department)
select dept_name, budget
from department, temp
where department.budget = mb;

-- 14. Find all departments where the total salary is greater than the average of the total salary at all departments.
with temp as (select avg(sum(salary)) asum from instructor group by dept_name)
select dept_name, sum(salary)
from instructor,temp
group by dept_name, asum
having sum(salary) > asum;

-- (Use ROLLBACK (and SAVEPOINT) to undo the effect of any modification on database before COMMIT)
-- 15. Transfer all the students from CSE department to IT department.
savepoint sp1;
update student set dept_name = 'IT' where dept_name = 'Comp. Sci.';
rollback to sp1;

-- 16. Increase salaries of instructors whose salary is over $100,000 by 3%, and all others receive a 5% raise
savepoint sp2;
update instructor set salary = case 
when salary <= 10000 then salary * 1.05
else salary * 1.03
end;
rollback to sp2;