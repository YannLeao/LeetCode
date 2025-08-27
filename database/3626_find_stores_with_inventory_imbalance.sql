WITH
    valid_stores AS (
        SELECT store_id FROM inventory
        GROUP BY store_id HAVING COUNT(*) >= 3
    ),

    product_ranks AS (
        SELECT
            i.store_id,
            s.store_name,
            s.location,
            i.product_name,
            i.quantity,
            i.price,
            FIRST_VALUE(i.product_name) OVER w_expensive as most_exp_product,
            FIRST_VALUE(i.quantity) OVER w_expensive as expensive_quantity,
            FIRST_VALUE(i.product_name) OVER w_cheap as cheapest_product,
            FIRST_VALUE(i.quantity) OVER w_cheap as cheapest_quantity
        FROM inventory i
                 JOIN stores s ON i.store_id = s.store_id
        WHERE i.store_id IN (SELECT store_id FROM valid_stores)
        WINDOW
            w_expensive AS (PARTITION BY i.store_id ORDER BY i.price DESC, i.inventory_id),
            w_cheap AS (PARTITION BY i.store_id ORDER BY i.price ASC, i.inventory_id)
    )

SELECT DISTINCT
    store_id,
    store_name,
    location,
    most_exp_product,
    cheapest_product,
    ROUND(
            cheapest_quantity::NUMERIC / NULLIF(expensive_quantity, 0),
            2
    ) AS imbalance_ratio
FROM product_ranks
WHERE cheapest_quantity > expensive_quantity
ORDER BY
    imbalance_ratio DESC,
    store_name ASC
;