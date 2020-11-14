-- list the names of all people who starred in Toy Story
SELECT p.name from people as p
JOIN stars as s ON s.person_id = p.id
JOIN movies as m ON m.id = s.movie_id
WHERE m.title='Toy Story';