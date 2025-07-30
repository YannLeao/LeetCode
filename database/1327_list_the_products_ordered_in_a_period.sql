WITH SalesFebruary2020 AS (
    SELECT
        p.product_name,
        COALESCE(SUM(o.unit), 0) AS count
FROM
    Products AS p
    LEFT JOIN
    Orders AS o ON p.product_id = o.product_id
WHERE
    o.order_date >= '2020-02-01' AND o.order_date <= '2020-02-29'
GROUP BY
    p.product_name
)

SELECT
    product_name,
    count AS unit
FROM
    SalesFebruary2020
WHERE
    count >= 100
;