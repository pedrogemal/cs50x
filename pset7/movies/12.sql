-- titles of all movies in which both Johnny Depp and Helena Bonham Carter starred

SELECT m.title from movies as m
JOIN stars as s ON s.movie_id = m.id
JOIN people as p ON p.id = s.person_id
WHERE p.name='Johnny Depp' and m.title in
(SELECT m.title from movies as m
JOIN stars as s ON s.movie_id = m.id
JOIN people as p ON p.id = s.person_id
WHERE p.name='Helena Bonham Carter');

