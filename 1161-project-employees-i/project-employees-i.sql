select p.project_id,
        round(sum(e.experience_years)/count(*), 2) AS average_years

from Project p
left join Employee e
on p.employee_id = e.employee_id
group by project_id;