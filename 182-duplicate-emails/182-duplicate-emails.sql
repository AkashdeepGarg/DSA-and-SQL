# Write your MySQL query statement below
select distinct A.email as Email from Person A, Person B where A.email = B.email and A.id <> B.id;