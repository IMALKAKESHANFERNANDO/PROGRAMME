-- Active: 1793443593863@@127.0.0.1@3306@my_database
CREATE DATABASE IF NOT EXISTS my_database;

USE my_database;

CREATE TABLE IF NOT EXISTS Suppliers (
    sid INT PRIMARY KEY,
    sname VARCHAR(50),
    address VARCHAR(100)
);\

SHOW DATABASES;
USE my_database;
SHOW TABLES;

INSERT INTO Suppliers (sid, sname, address) VALUES
(1, 'Supplier A', '123 Main St'),
(2, 'Supplier B', '456 Oak Ave'),
(3, 'Supplier C', '789 Pine Rd');

SELECT * FROM Suppliers;
USE my_database;
UPDATE SUPPLIERS 
SET ADDRESS = "COLOMBO"
WHERE SID = 1;
SELECT * FROM SUPPLIERS;

INSERT INTO suppliers (SID,SNAME,ADDRESS) VALUES (4, " supplier D ", "KANDY");
SELECT * FROM suppliers;

update suppliers 
set sname = "supun prabath"
where sid = 3;
SELECT * FROM suppliers;

DELETE FROM suppliers
WHERE sid = 2;
SELECT * FROM suppliers;

DESCRIBE suppliers;
 
 UPDATE suppliers
 SET Phone = CASE sid
    when 1 then '0702345678'
    when 3 then '0702345678'
    when 4 then '0703452123'
END
WHERE SID IN (1,3,4);

SELECT *FROM suppliers;

INSERT INTO suppliers (SID,SNAME,ADDRESS,PHONE)
VALUES(2, "supplier B","GALLE", "0701234567");
SELECT *FROM suppliers;
