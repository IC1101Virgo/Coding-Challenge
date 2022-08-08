# Write your MySQL query statement below
SELECT p.firstname, p.lastname, a.city, a.state
FROM PERSON p 
left join address a
using (personid)