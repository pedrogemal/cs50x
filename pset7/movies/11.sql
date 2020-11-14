-- list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated

SELECT m.title from movies as m
JOIN stars as s ON s.movie_id = m.id
JOIN people as p ON p.id = s.person_id
JOIN ratings as r ON m.id = r.movie_id
WHERE p.name = 'Chadwick Boseman'
ORDER BY r.rating DESC
LIMIT 5;