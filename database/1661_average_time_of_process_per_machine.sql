WITH
Starts AS (
    SELECT
        machine_id, process_id, activity_type, timestamp,
        ROW_NUMBER() OVER (PARTITION BY machine_id, process_id ORDER BY timestamp) AS rn
    FROM
        Activity
    WHERE
        activity_type = 'start'
),

Ends AS (
    SELECT
        machine_id, process_id, activity_type, timestamp,
        ROW_NUMBER() OVER (PARTITION BY machine_id, process_id ORDER BY timestamp) AS rn
    FROM
        Activity
    WHERE
        activity_type = 'end'
)

SELECT
    e.machine_id,
    ROUND(
        SUM(e.timestamp - s.timestamp)::numeric / COUNT(DISTINCT e.process_id),
        3
    ) AS processing_time
FROM
    Starts AS s
        JOIN
    Ends AS e
        ON s.machine_id = e. machine_id
        AND s.process_id = e.process_id
        AND s.rn = e.rn
GROUP BY
    e.machine_id
;