# Write your MySQL query statement below
select s.user_id, round(SUM(IF(c.action = 'confirmed', 1, 0)) / COUNT(1),2) AS confirmation_rate  
FROM 
    signups s 
LEFT JOIN 
    confirmations c ON s.user_id = c.user_id
GROUP BY 
    s.user_id;
