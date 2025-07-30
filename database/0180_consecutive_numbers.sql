WITH Numbers AS (
    SELECT
        id,
        num,
        LEAD(num) OVER (ORDER BY id) AS prox_value,
        LAG(num) OVER (ORDER BY id) AS prev_value
    FROM
        Logs
)

SELECT DISTINCT
    num AS ConsecutiveNums
FROM
    Numbers
WHERE
    num = prev_value AND num = prox_value
;