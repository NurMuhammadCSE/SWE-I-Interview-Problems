CREATE TABLE students(
    id INT PRIMARY KEY,
    name VARCHAR(50)
);

CREATE TABLE courses(
    id INT PRIMARY KEY,
    name VARCHAR(50)
);

DROP TABLE students;
DROP TABLE courses;

INSERT INTO students(id, name)
VALUES
-- (101, 'English'),
-- (102, 'Bangla'),
(103, 'Arabic'),
(104, 'Math'),
(105, 'Maths'),
(106, 'Physics'),
(107, 'Chemistry'),
(108, 'Biology'),
(109, 'History'),
(110, 'Geography');

TRUNCATE TABLE students;

SELECT * FROM students;

INSERT INTO courses(id, name)
VALUES
(101, 'CSE'),
(102, 'EEE'),
(103, 'ECE'),
(104, 'MBBS');

TRUNCATE TABLE courses;

SELECT * FROM courses;


--  INNER JOIN
SELECT * FROM students
INNER JOIN courses
ON students.id = courses.id;


-- LEFT JOIN
SELECT * FROM students -- LEFT TABLE
LEFT JOIN courses -- RIGHT TABLE
ON students.id = courses.id;

-- RIGHT JOIN
SELECT * FROM students
RIGHT JOIN courses
ON students.id = courses.id;


-- FULL JOIN
SELECT * FROM students
FULL JOIN courses
ON students.id = courses.id;

-- SELF JOIN
SELECT * FROM students
JOIN courses
ON students.id = courses.id;


-- UNION
SELECT * FROM students
LEFT JOIN courses
ON students.id = courses.id
UNION
SELECT * FROM students
RIGHT JOIN courses
ON students.id = courses.id;


-- LEFT EXCLUSIVE JOIN
SELECT * FROM students
LEFT JOIN courses
ON students.id = courses.id
WHERE courses.id is NULL;


-- RIGHT EXCLUSIVE JOIN
SELECT * FROM students
RIGHT JOIN courses
ON students.id = courses.id
WHERE students.id IS NULL;


-- Employee Table
CREATE TABLE employee(
    id INT PRIMARY KEY,
    name VARCHAR(50),
    manager_id INT
);

DROP TABLE employee;

INSERT INTO employee(id, name, manager_id)
VALUES
(101, 'Nur', NULL),
(102, 'Khadija', 102),
(103, 'Mishu', 101),
(104, 'Didar', 101),
(105, 'Didar', 103);

TRUNCATE TABLE employee;
SELECT * FROM EMPLOYEE;

SELECT a.name as Manager, b.name as Employee FROM employee as a
JOIN employee as b 
ON a.id = b.manager_id;

-- SELF JOIN
SELECT * FROM EMPLOYEE AS A 
JOIN EMPLOYEE AS B
ON A.id = B.manager_id;


-- UNION ALL
SELECT name FROM employee
UNION ALL
SELECT name FROM employee;

-- UNION
SELECT * FROM EMPLOYEE
UNION
SELECT * FROM EMPLOYEE;

SELECT name FROM employee
UNION
SELECT name FROM employee;


-- SQL -> Sub-Queries
CREATE TABLE school(
    id INT PRIMARY KEY,
    name VARCHAR(50),
    total_students INT,
    total_teacher INT
);

INSERT INTO school(id, name, total_students, total_teacher) VALUES
(101, 'DMA', 2000, 40),
(102, 'TMKM', 15000, 130),
(103, 'DSKM', 8000, 120),
(104, 'MDUM', 600, 25),
(105, 'LTQNM', 700, 15);

SELECT * FROM SCHOOL;

SELECT AVG(total_students) FROM school;
SELECT SUM(total_students) FROM school;


SELECT name, total_students FROM school
WHERE total_students > 5000;


SELECT * FROM school
WHERE total_students > (
    SELECT AVG(total_students) FROM school
);

