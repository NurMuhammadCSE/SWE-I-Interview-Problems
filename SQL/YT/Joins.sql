-- Write a solution to show the unique ID of each user, If a user does not have a unique ID replace just show null.
select unique_id, name from Employees as e
left join EmployeeUNI as eu
on e.id = eu.id;


-- Write a solution to report the product_name, year, and price for each sale_id in the Sales table.
select product_name, year, price from sales 
left join product 
on sales.product_id = product.product_id;

-- Write a solution to find the IDs of the users who visited without making any transactions and the number of times they made these types of visits.
SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans 
from Visits v 
LEFT JOIN Transactions t 
ON v.visit_id = t.visit_id  
WHERE t.transaction_id IS NULL 
GROUP BY v.customer_id; 

-- Write a solution to find all dates' id with higher temperatures compared to its previous dates (yesterday).
SELECT w1.id FROM weather as w1
JOIN weather AS w2
ON w1.recordDate = DATE_ADD(W2.recordDate, INTERVAL 1 DAY)
WHERE W1.temperature > W2.temperature;


