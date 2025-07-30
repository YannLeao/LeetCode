WITH
    Categories AS (
        SELECT
            CASE
                WHEN income < 20000 THEN 'Low Salary'
                WHEN income <= 50000 THEN 'Average Salary'
                ELSE 'High Salary'
            END AS category
        FROM
            Accounts
    ),

    AllCategories AS (
        SELECT 'Low Salary' AS category
        UNION ALL
        SELECT 'Average Salary'
        UNION ALL
        SELECT 'High Salary'
    )

SELECT
    a.category,
    COALESCE(COUNT(c.category), 0) AS accounts_count
FROM
    AllCategories AS a
        LEFT JOIN
    Categories AS C ON a.category = c.category
GROUP BY
    a.category
;