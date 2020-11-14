-- list the names of all people who have directed a movie that received a rating of at least 9.0

SELECT p.name from people as p
JOIN directors as d ON d.person_id = p.id
JOIN movies as m ON m.id = d.movie_id
JOIN ratings as r ON m.id = r.movie_id
WHERE r.rating >= 9.0;