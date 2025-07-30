SELECT
    today.id
FROM
    Weather AS today
         JOIN
    Weather AS yesterday ON today.recordDate = yesterday.recordDate + INTERVAL '1 day'
WHERE
    today.temperature > yesterday.temperature
;