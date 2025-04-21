-- Write a solution to find the ids of products that are both low fat and recyclable.
SELECT product_id FROM products
WHERE low_fats = 'y' AND  recyclable = 'y';

-- Find the names of the customer that are not referred by the customer with id = 2.
SELECT name FROM customer
where referee_id != 2 or referee_id is null;

-- Write a solution to find the name, population, and area of the big countries.
select name, population, area from world
where area >= 3000000 or population >= 25000000;

-- Write a solution to find all the authors that viewed at least one of their own articles.
select distinct author_id as id from views
where author_id = viewer_id order by id;

-- Write a solution to find the IDs of the invalid tweets. The tweet is invalid if the number of characters used in the content of the tweet is strictly greater than 15.
select tweet_id from tweets
where length(content) > 15;

