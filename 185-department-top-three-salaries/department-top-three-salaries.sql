with a as(
    select *,
    dense_rank() over(partition by departmentId order by salary desc) as "rnk"
    from Employee
)
-- select * from a;
select d.name Department, a.name Employee, a.salary Salary
from a
left join Department d
on a.departmentId = d.id
where a.rnk<=3;