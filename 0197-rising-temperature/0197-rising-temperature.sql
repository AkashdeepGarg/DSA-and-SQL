# Write your MySQL query statement below
select a.id from Weather a, Weather b where (a.id <> b.id and DATEDIFF(a.recordDate, b.recordDate) = 1 and a.temperature >b.temperature);