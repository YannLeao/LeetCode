WITH RECURSIVE Hierarchy AS (

    SELECT
        employee_id,
        employee_name,
        manager_id,
        salary,
        1 AS level,
        ARRAY[employee_id] AS path
    FROM Employees
    WHERE manager_id IS NULL

    UNION ALL

    SELECT
        e.employee_id,
        e.employee_name,
        e.manager_id,
        e.salary,
        h.level + 1 AS level,
        h.path || e.employee_id AS path
    FROM
        Employees AS e
            JOIN
        Hierarchy AS h ON e.manager_id = h.employee_id
)

SELECT
    h1.employee_id,
    h1.employee_name,
    h1.level,

    (SELECT COUNT(*) FROM Hierarchy AS h2
     WHERE h1.employee_id = ANY(h2.path)
       AND h2.employee_id != h1.employee_id) AS team_size,

    (SELECT COALESCE(SUM(salary), 0) FROM Hierarchy AS h2
     WHERE h1.employee_id = ANY(h2.path)
        AND h2.employee_id != h1.employee_id) + h1.salary AS budget
FROM
    Hierarchy AS h1
ORDER BY
    h1.level ASC,
    budget DESC,
    h1.employee_name ASC
;