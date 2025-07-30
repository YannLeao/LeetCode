WITH Total AS (
    SELECT
        p.product_id,
        SUM(u.units) AS total_units,
        SUM(u.units * p.price) AS total_price
    FROM
        Prices AS p
            LEFT JOIN
        UnitsSold AS u
            ON u.product_id = p.product_id
            AND u.purchase_date BETWEEN p.start_date AND p.end_date
    GROUP BY
        p.product_id
)

SELECT
    product_id,
    COALESCE(
            ROUND(total_price::numeric / NULLIF(total_units, 0), 2),
            0
    ) AS average_price
FROM
    Total
;