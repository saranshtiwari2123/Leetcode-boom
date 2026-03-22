with a as(select *, 
 count(managerId) over (partition by managerId) x
 from Employee)

 select name
 from(
    select distinct b.name, b.id
    from a 
    join a as b
    on a.managerId = b.id
    where a.x>=5
) temp
