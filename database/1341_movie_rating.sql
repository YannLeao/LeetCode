(
    SELECT
        u.name AS results
    FROM
        Users AS u
            INNER JOIN
        MovieRating AS m ON u.user_id = m.user_id
    GROUP BY
        u.user_id, u.name
    ORDER BY
        COUNT(m.rating) DESC,
        u.name ASC
    LIMIT 1
)

UNION ALL

(
    SELECT
        mo.title AS results
    FROM
        Movies AS mo
            INNER JOIN
        MovieRating AS mr ON mo.movie_id = mr.movie_id
    WHERE
        EXTRACT(YEAR FROM created_at) = 2020
      AND EXTRACT(MONTH FROM created_at) = 2
    GROUP BY
        mo.movie_id, mo.title
    ORDER BY
        AVG(mr.rating) DESC,
        mo.title ASC
    LIMIT 1
);