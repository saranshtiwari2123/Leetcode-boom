with a as (select *,
lag(num, 1)
    over(order by id) p_val,
lead(num, 1)
    over(order by id) n_val
from Logs)

select distinct num as ConsecutiveNums from a where
num=p_val and num=n_val;