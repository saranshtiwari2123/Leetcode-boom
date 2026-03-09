select e.name as Employee
from employee as e
join employee as m
on e.managerId=m.Id
where e.salary>m.salary;
