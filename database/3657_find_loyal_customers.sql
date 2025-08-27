WITH
    customer_stats AS (
        SELECT
            customer_id,
            COUNT(*) FILTER (WHERE transaction_type = 'purchase') as purchase_count,
            COUNT(*) FILTER (WHERE transaction_type = 'refund') as refund_count,
            COUNT(*) as total_transactions,
            MIN(transaction_date) as first_transaction_date,
            MAX(transaction_date) as last_transaction_date
        FROM customer_transactions
        GROUP BY customer_id
    )

SELECT customer_id
FROM customer_stats
WHERE
    purchase_count >= 3
  AND last_transaction_date - first_transaction_date >= 29
  AND (refund_count::NUMERIC / NULLIF(total_transactions, 0)) < 0.2
ORDER BY customer_id
;