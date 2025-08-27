WITH
    sales_seasons AS (
        SELECT
            p.category,
            s.quantity,
            s.price * s.quantity AS revenue,
            CASE
                WHEN EXTRACT(MONTH FROM s.sale_date) IN (12, 1, 2) THEN 'Winter'
                WHEN EXTRACT(MONTH FROM s.sale_date) IN (3, 4, 5) THEN 'Spring'
                WHEN EXTRACT(MONTH FROM s.sale_date) IN (6, 7, 8) THEN 'Summer'
                WHEN EXTRACT(MONTH FROM s.sale_date) IN (9, 10, 11) THEN 'Fall'
                END AS season
        FROM
            sales AS s
                JOIN
            products AS p ON s.product_id = p.product_id
    ),

    ranked_seasons AS (
        SELECT
            season,
            category,
            SUM(quantity) AS total_quantity,
            SUM(revenue) AS total_revenue,
            RANK() OVER(
            PARTITION BY season
            ORDER BY SUM(quantity) DESC, SUM(revenue) DESC
        ) AS rank
        FROM sales_seasons
        GROUP BY
            season, category
    )

SELECT season, category, total_quantity, total_revenue
FROM ranked_seasons
WHERE rank = 1
ORDER BY season
;