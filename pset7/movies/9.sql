select name
from people, movies, stars
where movie_id = movies.id and person_id = people.id and year = 2004
order by birth