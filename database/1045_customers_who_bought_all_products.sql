WITH
    CustomerClean AS (
        SELECT DISTINCT * FROM Customer
    ),

    TotalProducts AS (
        SELECT COUNT(*) AS total FROM Product
    )


SELECT
    c.customer_id
FROM
    TotalProducts AS t,
    Product AS p
        RIGHT JOIN
    CustomerClean AS c ON p.product_key = c.product_key
GROUP BY
    c.customer_id,
    t.total
HAVING
    COUNT(c.customer_id) = t.total
;