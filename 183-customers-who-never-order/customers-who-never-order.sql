select c.name as Customers
from orders as o
right join Customers as c
on o.customerId = c.id
where o.id is null;