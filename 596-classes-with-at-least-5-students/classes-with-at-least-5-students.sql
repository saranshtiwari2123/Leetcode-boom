with a as(
    select class, count(class) over(partition by class) no
    from Courses
)

select distinct class
from a
where no>=5;