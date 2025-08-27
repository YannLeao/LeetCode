WITH Capital AS (
    SELECT
        stock_name,
        SUM(price) FILTER (WHERE operation = 'Sell') AS sales,
        SUM(price) FILTER (WHERE operation = 'Buy') AS buys
    FROM Stocks
    GROUP BY stock_name
)

SELECT
    stock_name,
    (sales - buys) AS capital_gain_loss
FROM Capital