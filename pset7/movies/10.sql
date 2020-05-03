select name
from people, ratings, directors
where id = person_id and ratings.movie_id = directors.movie_id and rating >= 9.0