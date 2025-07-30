WITH customer_no_transaction AS (
    SELECT
        v.customer_id,
        t.visit_id
    FROM
        Visits AS v
            LEFT JOIN
        Transactions AS t ON v.visit_id = t.visit_id
    WHERE
        t.visit_id IS NULL
)

SELECT
    customer_id,
    COUNT(*) AS count_no_trans
FROM
    customer_no_transaction
GROUP BY
    customer_id
;