CREATE TABLE employee (
    employee_id INT PRIMARY KEY,
    name VARCHAR(50),
    dept VARCHAR(50),
    dept_id INT
);

DROP TABLE employee;

INSERT INTO employee VALUES (101, 'Nur', 'IT', 1);

INSERT INTO
    employee (
        employee_id,
        name,
        dept,
        dept_id
    )
VALUES (102, 'Rahman', 'IT', 2),
    (103, 'Sakib', 'CSE', 2),
    (104, 'Rahim', 'EEE', 1);

SELECT * FROM employee;

CREATE TABLE department (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50)
);

INSERT INTO
    department (dept_id, dept_name)
VALUES (1, 'IT'),
    (2, 'CSE'),
    (3, 'EEE');

SELECT * FROM department;

SELECT * FROM employee, department;

SELECT *
FROM employee, department
WHERE
    employee.dept_id = department.dept_id;

SELECT employee.name, department.dept_name
FROM employee, department
WHERE
    employee.dept_id = department.dept_id;

-- (1) INNER JOIN
SELECT e.dept_id, e.name, d.dept_name
from employee as e
    INNER JOIN department as d ON e.dept_id = d.dept_id;

-- (2) LEFT JOIN (LEFT OUTER JOIN)
select e.dept_id, e.name, d.dept_name
from Employee e
    LEFT JOIN department d ON e.dept_id = d.dept_id;

-- (3) RIGHT JOIN (RIGHT OUTER JOIN)
SELECT e.dept_id, e.name, d.dept_name
from Employee e
    RIGHT JOIN department d ON e.dept_id = d.dept_id;

-- (4) FULL JOIN (FULL OUTER JOIN)
SELECT e.dept_id, e.name, d.dept_name
from Employee e
    FULL JOIN department d ON e.dept_id = d.dept_id;

-- (5) CROSS JOIN
SELECT e.dept_id, e.name, d.dept_name
FROM Employee e
    CROSS JOIN department d;