WITH AccumulatedSum AS (
    SELECT
        person_name,
        SUM(weight) OVER (ORDER BY turn) AS accumulated_sum
    FROM
        Queue
)

SELECT
    person_name
FROM
    AccumulatedSum
WHERE
    accumulated_sum <= 1000
ORDER BY
    accumulated_sum DESC
    LIMIT
    1
;