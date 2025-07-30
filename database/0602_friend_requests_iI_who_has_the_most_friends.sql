WITH AllUsers AS (
    (
        SELECT
            accepter_id AS id,
            COUNT(*) AS count
        FROM
            RequestAccepted
        GROUP BY
            accepter_id
    )

    UNION ALL

    (
        SELECT
            requester_id AS id,
            COUNT(*) AS count
        FROM
            RequestAccepted
        GROUP BY
            requester_id
    )
)

SELECT
    id,
    SUM(count) AS num
FROM
    AllUsers
GROUP BY
    id
ORDER BY
    SUM(count) DESC
LIMIT 1
;