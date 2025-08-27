WITH
    sessions_stats AS (
        SELECT
            book_id,
            COUNT(*) AS total_sessions,
            COUNT(*) FILTER (WHERE session_rating >= 4) AS cnt_max_ratings,
            COUNT(*) FILTER (WHERE session_rating <= 2) AS cnt_min_ratings,
            MAX(session_rating) AS highest_rating,
            MIN(session_rating) AS lowest_rating
        FROM reading_sessions
        GROUP BY book_id
        HAVING COUNT(*) >= 5
    )

SELECT
    s.book_id,
    b.title,
    b.author,
    b.genre,
    b.pages,
    highest_rating - s.lowest_rating AS rating_spread,
    ROUND(
            (s.cnt_max_ratings + s.cnt_min_ratings)::NUMERIC / NULLIF(s.total_sessions, 0),
            2
    ) AS polarization_score
FROM
    sessions_stats AS s
        JOIN
    books AS b ON s.book_id = b.book_id
WHERE
    s.cnt_max_ratings > 0
  AND s.cnt_min_ratings > 0
  AND (s.cnt_max_ratings + s.cnt_min_ratings)::NUMERIC / NULLIF(s.total_sessions, 0) >= 0.6
ORDER BY
    polarization_score DESC,
    title DESC
;