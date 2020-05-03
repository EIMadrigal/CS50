select title
from movies, ratings, stars, people
where movies.id = ratings.movie_id and movies.id = stars.movie_id and
    people.id = stars.person_id and name = 'Chadwick Boseman'
order by rating desc limit 5