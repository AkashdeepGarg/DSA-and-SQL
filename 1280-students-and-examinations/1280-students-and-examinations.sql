# Write your MySQL query statement below

# The below query is correct but won't add results that are not threre in the table i.e. rows with count 0
# select s.student_id, s.student_name, e.subject_name, count(e.subject_name) from Students s, Examinations e where s.student_id = e.student_id group by e.subject_name, s.student_name order by s.student_id, e.subject_name;

SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.subject_name) as attended_exams
FROM Students s
CROSS JOIN Subjects sub
LEFT JOIN Examinations e ON s.student_id = e.student_id AND e.subject_name = sub.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id, sub.subject_name;
