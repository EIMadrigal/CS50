select title, rating
from movies, ratings
where id = movie_id and year = 2010
order by rating desc, title