/*
In DBMS, ACID stands for Atomicity, Consistency, Isolation, and Durability. These are the four key properties that guarantee reliable and consistent processing of database transactions.
1. Atomicity: Ensures that a transaction is treated as a single unit, which either completes in full or not at all.
Atomicity ensures that a transaction comprising multiple operations is executes as a single unit. It either completes all operations successfully or rolls back.

2. Consistency: Ensures that a transaction brings the database from one valid state to another, maintaining database invariants.

3. Isolation: Ensures that transactions are executed in isolation from one another, preventing concurrent transactions from interfering with each other.
Isolation ensures that transactions do not affect each other, even when they are executed concurrently.

Isolation ensures that concurrently running transactions do not interfere with each other intermediate state, maintaining the integrity of the database.

4. Durability: Ensures that once a transaction has been committed, it will remain in the system even in the event of a system failure.
Durability ensures that once a transaction is committed, its changes are permanent and will survive system failures.


CAP Theorem: In a distributed database system, it is impossible to simultaneously guarantee all three of the following properties:
1. Consistency: All nodes see the same data at the same time.
2. Availability: Every request receives a response, either success or failure.
3. Partition Tolerance: The system continues to operate despite network partitions.

In practice, a distributed system can only guarantee two of these three properties at any given time.
For example, a system can be consistent and available but not partition-tolerant, or
it can be partition-tolerant and available but not consistent.
This is known as the CAP theorem, which states that in a distributed system, you can only achieve two out of the three properties at any given time.


This file is part of the DBMS project, which implements a database management system with ACID properties.

DNS: DNS (Domain Name System) is a hierarchical and decentralized naming system for computers, services, or any resource connected to the Internet or a private network. It translates human-readable domain names (like www.example.com) into IP addresses (like 
dns is a internet which maps human-readable domain names to their associate IP addresses. Without DNS, users would have to remember IP addresses to access websites, which is impractical. 

Indexing: Indexing is a way to optimize the performance of a db. it's a data structure technique  which is used to quickly locate and access the data in a database. 

Normalization: Normalization is a process of organizing data in a database to reduce redundancy and improve data consistency or integrity. The main goals of normalization are to eliminate data redundancy, ensure data integrity, and make the database more efficient.

Redundant data wastes a lot of disk space and creates maintenance issues Update, Insert, Delete anomaly.
There are several normal forms, each with specific rules and requirements. The most common normal forms are:
1. First Normal Form (1NF): Ensures that each column contains atomic values and that
each row is unique. It eliminates repeating groups and ensures that each column contains only one value.
2. Second Normal Form (2NF): Builds on 1NF by ensuring that all non-key attributes are fully functionally dependent on the primary key. It eliminates partial dependencies.
3. Third Normal Form (3NF): Builds on 2NF by ensuring that all non-key attributes are not only fully functionally dependent on the primary key but also independent of each other. It eliminates transitive dependencies.
4. Boyce-Codd Normal Form (BCNF): A stricter version of 3 NF that addresses certain anomalies not handled by 3NF. It requires that every determinant is a candidate key.


Denormalization: Denormalization is db optimization technique in which we add redundant data to one or more tables to improve read performance. 


E-R Model: The Entity-Relationship (ER) model is a high-level data model used to describe the structure of a database. It represents the relationships between entities in a database and is often used as a blueprint for designing a database schema. The ER model consists of entities, attributes, and relationships.

It develops a conceptual design for the db. It also develop a very simple and easy to design view of data.


HTTP: HTTP (Hypertext Transfer Protocol) is an application layer protocol used for transmitting hypertext (web pages) over the Internet. It defines the set of rules on how the information can be transmitted on the www. It helps the web browser and web server to communicate with each other. HTTP is a request-response protocol, where a client (usually a web browser) sends a request to a server, and the server responds with the requested resource (such as a web page or an image).
HTTP is a stateless protocol, meaning that each request from a client to a server is an independent transaction.

HTTPS: HTTPS (Hypertext Transfer Protocol Secure) is an extension of HTTP that adds a layer of security by using SSL/TLS encryption. It ensures that the data transmitted between the client and server is secure and cannot be intercepted or tampered with by malicious actors. HTTPS is commonly used for secure communication on the web, especially for sensitive transactions like online banking and e-commerce.


Scalability: Scalability is the ability of a system to handle increased load or demand by adding resources, such as hardware or software, without sacrificing performance. 

There are two main types of scalability: 
vertical scalability (scaling up) and horizontal scalability (scaling out). 
Vertical scalability involves adding more resources (CPU, memory, storage) to a single server, while horizontal scalability involves adding more servers/machine to distribute the load.

Load Balancing: Load balancing is a technique used to distribute incoming network traffic across multiple servers or resources to ensure that no single server becomes overwhelmed. It helps improve performance, reliability, and availability of applications by evenly distributing the workload.


Caching: Caching is a technique used to store frequently accessed data in a memory temporary storage area (cache) to improve performance and reduce latency / load on the  server or db. 

CDN: A Content Delivery Network (CDN) is a distributed network of servers that delivers web content, such as images, videos, and scripts, to users based on their geographic location. 


Sharding: Sharding is a method of spliting and storing a single logical dataset in multiple databases or servers.

BD Sharding is horizontal scaling technique used to split a large db into smaller. Independent pieces called shards. Each shard contains a subset of the data, and they can be distributed across multiple servers or databases. Sharding helps improve performance, scalability, and availability by allowing the system to handle larger datasets and higher traffic loads.




*/