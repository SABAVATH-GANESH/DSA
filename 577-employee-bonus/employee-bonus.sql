# Write your MySQL query statement below
select name,bonus from Employee Left join Bonus on Employee.empId=Bonus.empId
where(bonus<1000 OR bonus is NULL);