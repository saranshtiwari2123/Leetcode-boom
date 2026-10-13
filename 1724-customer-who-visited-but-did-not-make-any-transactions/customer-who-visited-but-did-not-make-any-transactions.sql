
select V.customer_id, count(V.customer_id) as count_no_trans
from Visits V
left join Transactions T
on v.visit_id = T.visit_id
where transaction_id is NULL
group by V.customer_id;