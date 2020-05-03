select name
from people, stars, movies
where movie_id = movies.id and person_id = people.id and title = 'Toy Story'