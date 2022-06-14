# Write your MySQL query statement below
SELECT w1.id FROM Weather w1, Weather w2 where w2.recordDate = SUBDATE(w1.recordDate,1) AND w1.Temperature>w2.Temperature;