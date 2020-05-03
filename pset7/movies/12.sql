select title
from movies join stars on movies.id = stars.movie_id join people on people.id = stars.person_id
where name = 'Johnny Depp' and movies.title in
(select title
from movies join stars on movies.id = stars.movie_id join people on people.id = stars.person_id
where name = 'Helena Bonham Carter')
