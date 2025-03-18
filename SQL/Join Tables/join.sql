CREATE TABLE student(
    id INT PRIMARY KEY,
    name VARCHAR(50)
);

DROP TABLE student;

INSERT INTO student(id, name)
VALUES
(101, 'English'),
(102, 'Bangla'),
(103, 'Arabic'),
(104, 'Math');


SELECT * FROM student;

CREATE Table courses(
    id INT PRIMARY KEY,
    name VARCHAR(50)
);

DROP TABLE courses;

INSERT INTO courses(id, name)
VALUES
(101, 'CSE'),
(102, 'EEE'),
(103, 'ECE');

SELECT * FROM courses;

SELECT * FROM student
INNER JOIN courses
ON student.id = courses.id;


SELECT * FROM student
LEFT JOIN courses
ON student.id = courses.id;