WITH QueriesClean AS (
    SELECT DISTINCT * FROM Queries
)

SELECT
    DISTINCT query_name,
    ROUND(
            AVG(rating::numeric / position),
            2
    ) AS quality,
    ROUND(
             COUNT(rating) FILTER (WHERE rating < 3) * 100.0 / COUNT(*),
             2
     ) AS poor_query_percentage
FROM
    QueriesClean
GROUP BY
    query_name
;