WITH OnlyDepartament AS (
    SELECT
        e.employee_id
    FROM
        Employee AS e
    GROUP BY
        e.employee_id
    HAVING
        COUNT(*) = 1
)

SELECT
    e.employee_id,
    e.department_id
FROM
    Employee AS e
        LEFT JOIN
    OnlyDepartament AS o ON o.employee_id = E.employee_id
WHERE
    e.primary_flag = 'Y' OR  o.employee_id IS NOT NULL
;
