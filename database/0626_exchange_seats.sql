WITH NewSeat AS (
    SELECT
        id, student,
        CASE
            WHEN id % 2 = 1 AND id + 1 IN (SELECT id FROM Seat) THEN id + 1
            WHEN id % 2 = 0 THEN id - 1
            ELSE id
        END AS new_id
    FROM
        Seat
)

SELECT
    new_id AS id,
    student
FROM
    NewSeat
ORDER BY
    new_id
;