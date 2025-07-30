WITH AllEmployees AS (
    SELECT DISTINCT employee_id FROM Employees
    UNION
    SELECT DISTINCT employee_id FROM Salaries
)

SELECT
    employee_id
FROM
    AllEmployees
WHERE
    employee_id NOT IN (SELECT DISTINCT employee_id FROM Employees)
   OR employee_id NOT IN (SELECT DISTINCT employee_id FROM Salaries)
ORDER BY
    employee_id
;