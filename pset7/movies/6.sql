select AVG(rating)
from movies, ratings
where id = movie_id and year = 2012