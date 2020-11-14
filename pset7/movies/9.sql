-- list the names of all people who starred in a movie released in 2004, ordered by birth year

SELECT p.name from people as p
JOIN stars as s ON s.person_id = p.id
JOIN movies as m ON m.id = s.movie_id
WHERE m.year='2004'
GROUP BY p.name
ORDER BY p.birth;