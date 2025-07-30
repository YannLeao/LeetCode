WITH
    DailyTotal AS (
        SELECT
            visited_on,
            SUM(amount) AS amount
        FROM Customer
        GROUP BY visited_on
    ),

    RollingWindow AS (
        SELECT
            visited_on,

            SUM(amount) OVER (
                ORDER BY visited_on
                ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
            ) AS amount,

            ROUND(
                AVG(amount) OVER (
                    ORDER BY visited_on
                    ROWS BETWEEN 6 PRECEDING AND CURRENT ROW),
                2
            ) AS average_amount
        FROM
            DailyTotal
        ORDER BY
            visited_on ASC
    )

SELECT
    visited_on, amount, average_amount
FROM
    RollingWindow
WHERE
    visited_on >= (SELECT MIN(visited_on) + 6 FROM Customer)
;