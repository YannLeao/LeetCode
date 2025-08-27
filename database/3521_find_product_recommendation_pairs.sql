WITH
    ProductByUsers AS (
        SELECT DISTINCT
            p.user_id,
            p.product_id,
            i.category
        FROM
            ProductPurchases AS p
                JOIN
            ProductInfo AS i ON p.product_id = i.product_id
    ),

    ProductPairs AS (
        SELECT
            p1.user_id,
            p1.product_id AS product1_id,
            p2.product_id AS product2_id,
            p1.category AS product1_category,
            p2.category AS product2_category
        FROM
            ProductByUsers AS p1
                JOIN
            ProductByUsers AS p2
            ON p1.user_id = p2.user_id
                AND p1.product_id < p2.product_id
    )

SELECT
    product1_id,
    product2_id,
    product1_category,
    product2_category,
    COUNT(*) AS customer_count
FROM ProductPairs
GROUP BY
    product1_id,
    product2_id,
    product1_category,
    product2_category
HAVING COUNT(*) >= 3
ORDER BY
    customer_count DESC,
    product1_id ASC,
    product2_id ASC
;