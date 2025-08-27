WITH
    ranked_reviews AS (
        SELECT
            employee_id,
            review_date,
            rating,
            ROW_NUMBER() OVER (
                PARTITION BY employee_id
                ORDER BY review_date DESC
            ) AS rn
        FROM performance_reviews
    ),

    last_three_ratings AS (
        SELECT
            employee_id,
            ARRAY_AGG (rating ORDER BY review_date) AS rating_array
        FROM ranked_reviews
        WHERE rn <= 3
        GROUP BY employee_id
        HAVING COUNT(*) = 3
    )

SELECT
    l.employee_id,
    e.name,
    l.rating_array[3] - l.rating_array[1] AS improvement_score
FROM
    last_three_ratings AS l
        JOIN
    employees AS e ON l.employee_id = e.employee_id
WHERE
    l.rating_array[1] < l.rating_array[2] AND l.rating_array[2] < l.rating_array[3]
ORDER BY
    improvement_score DESC,
    name ASC
;