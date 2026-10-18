select p.product_id,
    round(
        ifnull((sum(p.price*u.units) / sum(u.units)),0),
        2
        ) as average_price
from Prices p
left join UnitsSold u
on p.product_id = u.product_id 
AND
u.purchase_date between p.start_date AND p.end_date
group by p.product_id;