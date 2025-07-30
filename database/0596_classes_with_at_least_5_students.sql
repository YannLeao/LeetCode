WITH Quantity AS (
    SELECT
        class,
        COUNT(student) AS count
FROM
    Courses
GROUP BY
    class
    )

SELECT
    class
FROM
    Quantity
WHERE
    count >= 5
;