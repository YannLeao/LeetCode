WITH EmployeeRank AS (
    SELECT
        *,
        DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS ranking
    FROM
        Employee
)

SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS salary
FROM
    EmployeeRank AS e INNER JOIN
    Department AS d ON e.departmentId = d.id
WHERE
    e.ranking <= 3
;