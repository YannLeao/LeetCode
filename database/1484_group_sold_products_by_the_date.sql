WITH
    ActivitiesClean AS (
        SELECT DISTINCT * FROM Activities
    )

SELECT
    sell_date,
    COUNT(product) AS num_sold,
    STRING_AGG(product, ',' ORDER BY product) AS products
FROM
    ActivitiesClean
GROUP BY
    sell_date
ORDER BY
    sell_date
;