# Write your MySQL query statement below
Select distinct author_id as id
from Views
Where author_id = viewer_id
order by id;