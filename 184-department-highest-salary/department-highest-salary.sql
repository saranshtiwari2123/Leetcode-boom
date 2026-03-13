with a as (select *,
dense_rank() over(partition by departmentId order by salary desc) as rk
from Employee
)

select d.name Department, a.name Employee, a.salary Salary
from a
left join Department d
on a.departmentId = d.id
where rk=1;