WITH Total AS (
    SELECT COUNT(*) AS total FROM Users
)

SELECT
    r.contest_id,
    ROUND(
            COUNT(DISTINCT r.user_id) * 100.0 / t.total,
            2
    ) AS percentage
FROM
    Register AS r,
    Total AS t
GROUP BY
    r.contest_id,
    t.total
ORDER BY
    percentage DESC,
    r.contest_id ASC
;