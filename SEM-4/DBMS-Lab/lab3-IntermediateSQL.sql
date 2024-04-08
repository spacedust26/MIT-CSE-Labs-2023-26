--LAB 3 - Intermediate SQL
--lab Exercises

--Set Operations
-- UNION (Use union all to retain duplicates):
-- 1. Find courses that ran in Fall 2009 or in Spring 2010
(select course_id from section where semester = 'Fall' and year = 2009) union all (select course_id from section where semester = 'Spring' and year = 2010);

--INTERSECT (Use intersect all to retain duplicates):
-- 2. Find courses that ran in Fall 2009 and in spring 2010
(select course_id from section where semester = 'Fall' and year = 2009) intersect all (select course_id from section where semester = 'Spring' and year = 2010);

-- MINUS:
-- 3. Find courses that ran in Fall 2009 but not in Spring 2010
(select course_id from section where semester = 'Fall' and year = 2009) minus (select course_id from section where semester = 'Spring' and year = 2010);

-- Null values
-- 4. Find the name of the course for which none of the students registered.
select title from course where course_id not in(select course_id from takes);

-- Nested Subqueries
-- Set Membership (in / not in):
-- 5. Find courses offered in Fall 2009 and in Spring 2010.
select course_id from section where semester = 'Fall' and year = 2009 and course_id in(select course_id from section where semester = 'Spring' and year = 2010);

--6. Find the total number of students who have taken course taught by the instructor with ID 10101.
select count(distinct takes.id) from takes join teaches on takes.course_id = teaches.course_id and teaches.id in(select id from teaches where id = 10101);

--7. Find courses offered in Fall 2009 but not in Spring 2010.
select course_id from section where semester = 'Fall' and year = 2009 and course_id not in(select course_id from section where semester = 'Spring' and year = 2010);

--8. Find the names of all students whose name is same as the instructor’s name.
select name from student where name in (select name from instructor);

--Set Comparison (>=some/all)
-- 9. Find names of instructors with salary greater than that of some (at least one) instructor in the Biology department.
select name from instructor where salary > some(select salary from instructor where dept_name = 'Biology');

-- 10. Find the names of all instructors whose salary is greater than the salary of all instructors in the Biology department.
select name from instructor where salary > all(select salary from instructor where dept_name = 'Biology');

--11. Find the departments that have the highest average salary.
select dept_name , avg(salary) from instructor
group by dept_name having avg(salary) >= all(select avg(salary) from instructor group by dept_name);

--12. Find the names of those departments whose budget is lesser than the average salary of all instructors.
select dept_name from department where budget < all(select avg(salary) from instructor);

--Test for Empty Relations (exists/ not exists)
-- 13. Find all courses taught in both the Fall 2009 semester and in the Spring 2010 semester
select course_id from section s where semester = 'Fall' and year = 2009 and exists(select * from section t where semester = 'Spring' and year = 2010 and s.course_id = t.course_id);

-- 14. Find all students who have taken all courses offered in the Biology department.
select s.name from student s where not exists((select course_id from course where dept_name = 'Biology') except (select t.course_id from takes t where s.id = t.id));

-- Test for Absence of Duplicate Tuples
-- 15. Find all courses that were offered at most once in 2009.
select course_id from course where course_id in (select course_id from section where year = 2009 group by course_id having count(course_id) < 2);

-- 16. Find all the students who have opted at least two courses offered by CSE department.
select s.name from student s join takes t on s.id = t.id join course c on t.course_id = c.course_id where c.dept_name = 'Comp. Sci.' group by s.name having count(distinct t.course_id) >= 2;

--Subqueries in the From Clause
-- 17. Find the average instructors salary of those departments where the average salary is greater than 42000
select dept_name, avg_salary from (select dept_name, avg(salary) avg_salary from instructor group by dept_name) where avg_salary > 42000;

--Views
-- 18. Create a view all_courses consisting of course sections offered by Physics department in the Fall 2009, with the building and room number of each section.
create view all_courses as select course_id, sec_id, building , room_number from section where semester = 'Fall' and year = 2009 and course_id in (select course_id from course where dept_name = 'Physics');

-- 19. Select all the courses from all_courses view.
select course_id from all_courses;

--20. Create a view department_total_salary consisting of department name and total salary of that department.
create view department_total_salary as select dept_name, sum(salary) total_sal from instructor group by dept_name;
