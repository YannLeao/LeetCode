WITH Manager AS (
    SELECT
        e1.name,
        COUNT(e2.managerId) AS n_employees
    FROM
        Employee AS e1
            JOIN
        Employee AS e2 ON e1.id = e2.managerId
    GROUP BY
        e1.name
)
SELECT
    name
FROM
    Manager
WHERE
    n_employees >= 5
;