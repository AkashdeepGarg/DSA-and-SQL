# Write your MySQL query statement below
select contest_id, round(((count(r.user_id) / (SELECT 
        COUNT(user_id)
      FROM 
        Users))*100),2) as percentage from register r group by r.contest_id order by percentage DESC, r.contest_id ASC;