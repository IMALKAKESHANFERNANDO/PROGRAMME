-- Active: 1793443593863@@127.0.0.1@3306@mysql
CREATE DATABASE IF NOT EXISTS company_db;
use company_db;

create table Emp (
    ID int primary key,
    name VARCHAR(50),
    district VARCHAR(100)
);

create table dept (
    id int primary key,
    division VARCHAR(50)

);
select * from emp;

insert into emp (id, name , district)
values
(1001,"Kasun","ampara"),
(1002,"Nimal","galle"),
(1003,"Sunil","kandy");

insert into dept (id, division)
values
(1001,"Sales"),
(1002,"Marketing"),
(1003,"IT");

SELECT * from dept;

SELECT *
from emp
where district = "galle";

update emp
set name ="vimal"
where id = 2;
select * from emp;

select emp.id, emp.name, emp.district
from emp
inner join dept
on emp.id=dept.id
where dept.division = "Sales";

select dept.id, dept.division, emp.name
from dept
left join emp
on dept.id = emp.id
where emp.district = "kandy";


select emp.id,emp.name,emp.district
from emp
right join dept
on emp.id=dept.id
where dept.division = "IT";

DELETE from emp
where id=1003;

select * from emp;