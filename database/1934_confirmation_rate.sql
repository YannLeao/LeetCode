WITH Requests AS (
    SELECT
        s.user_id,
        SUM((c.action = 'confirmed')::int) AS confirmations,
        COUNT(c.action) AS requests
    FROM
        Signups AS s
            LEFT JOIN
        Confirmations AS c
        ON s.user_id = c.user_id
    GROUP BY
        s.user_id
)

SELECT
    user_id,
    CASE
        WHEN requests = 0 THEN 0.00
        ELSE ROUND(confirmations::numeric / requests, 2)
        END AS confirmation_rate
FROM
    Requests
;