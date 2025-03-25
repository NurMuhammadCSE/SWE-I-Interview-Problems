CREATE TABLE account (
    id INT PRIMARY KEY,
    name VARCHAR(50),
    balance INT NOT NULL DEFAULT 111,
    CONSTRAINT acc_balance CHECK (balance >= 100)
);

DROP TABLE account;

INSERT INTO
    account (id, name, balance)
VALUES (101, 'Nur', 100),
    (102, 'Rahman', 200),
    (103, 'Sakib', 300),
    (104, 'Rahim', 400);

INSERT INTO account (id, name) VALUES (105, 'Darda');

SELECT * FROM account;

-- Add new Column
ALTER TABLE account ADD interest FLOAT NOT NULL DEFAULT 1110.222;

-- Modify Column
-- ALTER TABLE account MODIFY interest FLOAT NOT NULL DEFAULT 1110.222;
-- DESC account;

-- Change Column Name
-- ALTER TABLE account CHANGE COLUMN interest interest_rate FLOAT NOT NULL DEFAULT 1110.222;

-- Update Column
UPDATE account SET interest = 1000.22 WHERE id = 101;

-- Delete Column
ALTER TABLE account DROP COLUMN interest;

CREATE TABLE customer (
    id INT PRIMARY KEY,
    name VARCHAR(50),
    address VARCHAR(50),
    gender CHAR(2),
    balance INT NOT NULL DEFAULT 111
);

DROP TABLE customer;

-- Insert
INSERT INTO
    customer (
        id,
        name,
        address,
        gender,
        balance
    )
VALUES (101, 'Nur', 'Dhaka', 'M', 100),
    (
        102,
        'Rahman',
        'Dhaka',
        'M',
        200
    ),
    (
        103,
        'Sakib',
        'Dhaka',
        'M',
        300
    ),
    (
        104,
        'Rahim',
        'Dhaka',
        'M',
        400
    );

SELECT * FROM customer;

INSERT INTO customer VALUES ( 105, 'Darda', 'Dhaka', 'M', 500 );

INSERT INTO
    customer (
        id,
        name,
        address,
        gender,
        balance
    )
VALUES (
        106,
        'Didar',
        'Dhaka',
        'M',
        600
    );

INSERT INTO customer (id, name) VALUES (107, 'Dipu'), (108, 'Dip');

SELECT * FROM customer;

-- Update
UPDATE customer SET address = 'Gaibandha', gender = 'M' WHERE id = 101;

-- Update Multiple Rows
UPDATE customer SET address = 'Gaibandha' WHERE id IN (102, 103);