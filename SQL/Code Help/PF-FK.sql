CREATE TABLE student (
    student_id INT PRIMARY KEY,
    name VARCHAR(50),
    dept_id INT
);

INSERT INTO student VALUES (101, 'Nur', 1);

INSERT INTO student VALUES (102, 'Rahman', 2);

INSERT INTO student VALUES (103, 'Sakib', 2);

INSERT INTO student VALUES (104, 'Rahim', 1);

SELECT * FROM student;

CREATE TABLE courses (
    course_id INT PRIMARY KEY,
    subject_name VARCHAR(50),
    student_id INT,
    FOREIGN KEY (student_id) REFERENCES student (student_id)
);

INSERT INTO courses VALUES (1, 'CSE101', 101);

insert INTO courses VALUES (2, 'CSE102', 102);

insert INTO courses VALUES (3, 'CSE103', 103);

DROP TABLE courses;

SELECT * FROM courses;

SELECT s.student_id, s.name, c.subject_name as Subject_Name
FROM student s
    INNER JOIN courses c ON s.student_id = c.student_id;