--  list the names of all people who starred in a movie in which Kevin Bacon also starred

SELECT distinct(p.name) from people as p
JOIN stars as s ON s.person_id = p.id
JOIN movies as m ON m.id = s.movie_id
WHERE m.title in
(SELECT distinct(m.title) from movies m
JOIN stars as s ON s.movie_id = m.id
JOIN people as p ON s.person_id = p.id
WHERE p.name = 'Kevin Bacon' AND p.birth='1958') AND p.name != 'Kevin Bacon';