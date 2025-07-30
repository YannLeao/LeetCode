WITH FirstOrders AS (
    SELECT DISTINCT ON (customer_id)
    customer_id,
    order_date,
    customer_pref_delivery_date
FROM
    Delivery
ORDER BY
    customer_id, order_date ASC
    )

SELECT
    ROUND(
            COUNT(order_date) FILTER (WHERE order_date = customer_pref_delivery_date) * 100.0/ COUNT(*),
            2
    ) AS immediate_percentage
FROM
    FirstOrders
;
