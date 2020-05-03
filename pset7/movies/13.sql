select people.name
from movies join stars on movies.id = stars.movie_id join people on people.id = stars.person_id
where movies.id in
(select movies.id
from movies join stars on movies.id = stars.movie_id join people on people.id = stars.person_id
where name = 'Kevin Bacon' and birth = 1958) and people.name != 'Kevin Bacon'
