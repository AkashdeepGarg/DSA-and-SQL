# Write your MySQL query statement below
select t.name from (select a.name as name, count(a.id) as count_of_employee from employee a, employee b where a.id = b.managerId group by b.managerId) t where t.count_of_employee>=5;