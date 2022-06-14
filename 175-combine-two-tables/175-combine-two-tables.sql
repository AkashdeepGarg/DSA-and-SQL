# Write your MySQL query statement below
/*select firstName, lastName, city, state from table Person,Address where Person.personId=Address.personId;*/

select firstName,lastName,city,state from Person LEFT JOIN Address ON Person.personId=Address.personId;