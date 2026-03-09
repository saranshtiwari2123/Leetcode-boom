select distinct p1.email as Email 
from Person as p1
join person as p2
on p1.email = p2.email
AND p1.id<>p2.id;