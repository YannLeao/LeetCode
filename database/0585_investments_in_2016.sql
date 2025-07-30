WITH
    SameTiv2015 AS (
        SELECT DISTINCT i1.pid
        FROM Insurance AS i1
                 JOIN
            Insurance AS i2 ON i1.pid != i2.pid AND i1.tiv_2015 = i2.tiv_2015
    ),

    SameLocal AS (
        SELECT DISTINCT i1.pid
        FROM Insurance AS i1
                JOIN
            Insurance AS i2 ON i1.lon = i2.lon AND i1.lat = i2.lat AND i1.pid != i2.pid
    )

SELECT
    ROUND(SUM(tiv_2016)::NUMERIC, 2) AS tiv_2016
FROM
    Insurance
WHERE
    pid IN (SELECT pid FROM SameTiv2015) AND pid NOT IN (SELECT pid FROM SameLocal)
;