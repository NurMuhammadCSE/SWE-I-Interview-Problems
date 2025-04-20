-- Write a SQL Query to fetch the details of employees having id as 1
SELECT * FROM employees WHERE id = 1;

-- Write a SQL Query to fetch the details of employees having id as 1 and city as DHAKA
SELECT * FROM EMPLOYEES WHERE ID = 1 AND CITY = 'DHAKA';

-- Write a SQL Query to fetch the details of employees having salary greater than 1200 and city as DHAKA.
SELECT * FROM EMPLOYEES WHERE SALARY > 1200 AND CITY = 'DHAKA';

-- Write a SQL Query to fetch the details of employees who are not from DHAKA.
SELECT *
FROM EMPLOYEES
    -- WHERE CITY IS NOT 'DHAKA';
WHERE
    CITY NOT IN ('DHAKA');

-- Write a SQL Query to fetch the details of employees having the maximum salary.
SELECT * FROM employees ORDER BY salary DESC;

-- Write a SQL Query to fetch the details of 2 employees having the maximum salary.
SELECT * FROM employees ORDER BY salary DESC LIMIT 2;

-- ************** Aggregate Functions ******************   --
-- Write a query to find the total number of employees in each city
SELECT city, COUNT(name) FROM employees GROUP BY city;

-- Write a query to find the maximum salary of employees in each city in descending order
SELECT city, COUNT(name)
FROM employees
GROUP BY
    city
ORDER BY city DESC;

-- Write a query to display the department names alongside the total count of employees in each department, sorting the results by the total number of employees in descending order.
SELECT department, COUNT(name)
FROM employees
GROUP BY
    department
ORDER BY name DESC;

-- Write a query to list the departments where the average salary is greater than 1200, also display the department name and the average salary.
SELECT departments, AVG(salary)
FROM employees
GROUP BY
    departments
HAVING
    AVG(salary) > 1200;

-- *************** Top SQL Questions asked in interviews ****************** ---
-- Write a query to find the total number of employees working in the ‘IT’ department’
SELECT COUNT(*) FROM employees WHERE department = 'IT';

-- Write a query to find all the employees that have their name starting from ‘R’
SELECT * FROM EMPLOYEES WHERE name LIKE 'R%';

-- Write a query to find unique salaries in employee table
SELECT DISTINCT salary FROM employees;

-- Write a query to find the rows where a department has NULL values
SELECT * FROM employees WHERE department is NULL;

-- Write a query to find the duplicate rows in employee for column department.
SELECT department, COUNT(*)
FROM employees
GROUP BY
    department
HAVING
    COUNT(*) > 0;

-- 