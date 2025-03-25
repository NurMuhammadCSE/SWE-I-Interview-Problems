CREATE DATABASE codeHelp;

USE codeHelp;

CREATE TABLE student(
    id INT PRIMARY KEY,
    name VARCHAR(50)
);

DROP TABLE student;

INSERT INTO student VALUES(101, 'Nur');
INSERT INTO student VALUES(102, 'Rahman');
INSERT INTO student VALUES(103, 'Sakib');
INSERT INTO student VALUES(104, 'Rahim');

SELECT * FROM student;

