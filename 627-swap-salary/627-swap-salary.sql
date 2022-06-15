# Write your MySQL query statement below
#update Salary set sex='f' where sex='m';
# update Salary set sex='m' where sex='f';
UPDATE Salary SET sex = IF(sex = 'f', 'm', 'f');