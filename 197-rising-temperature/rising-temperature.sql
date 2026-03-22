with a as (select *,
 lag(temperature, 1, 999999999) over (order by recordDate) preTemp,
 lag(RecordDate, 1) over (order by recordDate) preDate
from Weather)

select id
from a
where temperature >preTemp and DATEDIFF(recordDate,preDate) = 1;