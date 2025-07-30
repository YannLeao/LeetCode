WITH
    SalesCleaned AS (
        SELECT DISTINCT * FROM Sales
    ),

    CountSales AS (
        SELECT
            product_id,
            COUNT(*) as count
FROM
    SalesCleaned
GROUP BY
    product_id
    )

SELECT
    product_id, product_name
FROM
    Product
WHERE

    product_id IN
    (
        SELECT product_id FROM Sales
        WHERE sale_date BETWEEN '2019-01-01' AND '2019-03-31'
    )

  AND product_id NOT IN
      (
          SELECT product_id FROM Sales
          WHERE sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31'
      )
;