CREATE DATABASE org;
-- SHOW DATABASES;

USE org;

CREATE TABLE Worker (
    worker_id INT NOT NULL PRIMARY KEY,
    first_name CHAR(50),
    last_name CHAR(50),
    salary INT,
    joining_date DATE,
    department CHAR(50)
);

INSERT INTO
    Worker (
        worker_id,
        first_name,
        last_name,
        salary,
        joining_date,
        department
    )
VALUES (
        101,
        'John',
        'Doe',
        1000,
        '2019-01-01',
        'HR'
    ),
    (
        102,
        'Jane',
        'Doe',
        2000,
        '2019-01-01',
        'IT'
    ),
    (
        103,
        'Alice',
        'Doe',
        3000,
        '2019-01-01',
        'Finance'
    ),
    (
        104,
        'Bob',
        'Doe',
        4000,
        '2019-01-01',
        'HR'
    ),
    (
        105,
        'Charlie',
        'Doe',
        5000,
        '2019-01-01',
        'IT'
    ),
    (
        106,
        'David',
        'Doe',
        6000,
        '2019-01-01',
        'Finance'
    ),
    (
        107,
        'Eve',
        'Doe',
        7000,
        '2019-01-01',
        'HR'
    ),
    (
        108,
        'Frank',
        'Doe',
        8000,
        '2019-01-01',
        'IT'
    ),
    (
        109,
        'Grace',
        'Doe',
        9000,
        '2019-01-01',
        'Finance'
    ),
    (
        110,
        'Helen',
        'Doe',
        10000,
        '2019-01-01',
        'HR'
    );
;
INSERT INTO Worker VALUES (
        111,
        'Helen',
        'Doe',
        10000,
        '2019-01-01',
        NULL
    );

SELECT * FROM Worker;

SELECT first_name, last_name from Worker;

SELECT 44 + 44;

SELECT now();

SELECT lcase ('Nur Muhammad');

SELECT ucase ('Nur Muhammad');

SELECT concat('Nur', ' ', 'Muhammad');

SELECT length('Nur Muhammad');

SELECT trim(' Nur Muhammad ');

SELECT substring('Nur Muhammad', 1, 3);

SELECT replace( 'Nur Muhammad', 'Nur', 'Nur Muhammad' );

SELECT round(4.4);

SELECT floor(4.9);

SELECT ceil(4.1);

SELECT max(salary) FROM Worker;

SELECT min(salary) FROM Worker;

SELECT sum(salary) FROM Worker;

SELECT avg(salary) FROM Worker;

SELECT count(salary) FROM Worker;

SELECT distinct department FROM Worker;

SELECT * FROM Worker WHERE salary > 5000;

SELECT * FROM Worker WHERE salary BETWEEN 3000 AND 6000;

SELECT * FROM Worker WHERE department = 'HR';

SELECT * FROM Worker WHERE department IN ('HR', 'IT');

SELECT * FROM Worker WHERE salary BETWEEN 5555 AND 9999;

SELECT * FROM Worker WHERE department = 'HR' AND salary > 5000;

SELECT *
FROM Worker
WHERE
    department = 'HR'
    OR salary > 5000
    OR department = 'IT'
    OR department = 'Finance';

SELECT *
FROM Worker
WHERE
    department = 'HR'
    AND salary > 5000
    OR department = 'IT'
    OR department = 'Finance';

SELECT * FROM Worker WHERE department NOT IN ('HR', 'IT');

SELECT * FROM Worker WHERE department IS NULL;

-- Pattern Matching
SELECT * FROM Worker WHERE first_name LIKE 'J%';

-- Searching
SELECT * FROM Worker WHERE first_name LIKE '%a%';

-- Wildcard
SELECT * FROM Worker WHERE first_name LIKE '_a%';

-- Sorting
SELECT * FROM Worker ORDER BY salary;

-- Distinct
SELECT DISTINCT department FROM Worker;

-- Group By
SELECT department from Worker GROUP BY department;

-- Distinct and Group By
SELECT department, COUNT(department) FROM Worker GROUP BY department;

SELECT department, COUNT(department) FROM Worker GROUP BY department;

-- Having
SELECT department, COUNT(department) FROM Worker GROUP BY department HAVING COUNT(department) > 1;

-- Limit
SELECT * FROM Worker LIMIT 5;

-- Limit and Offset
SELECT * FROM Worker LIMIT 5 OFFSET 2;

-- AVG salary per department
SELECT department, AVG(salary) from Worker GROUP BY department;

SELECT department, MIN(salary) FROM Worker GROUP BY department;

SELECT department, MAX(salary) FROM Worker GROUP BY department;

SELECT department, SUM(salary) FROM Worker GROUP BY department;

SELECT department, COUNT(salary) FROM Worker GROUP BY department;

-- Group By Having
SELECT department, COUNT(department) from Worker GROUP BY department HAVING COUNT(department) > 1;

