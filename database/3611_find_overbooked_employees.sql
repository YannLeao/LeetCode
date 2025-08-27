WITH
    meetings_week AS (
        SELECT
            employee_id,
            SUM(duration_hours) AS hours_week
        FROM meetings
        GROUP BY
            employee_id,
            DATE_PART('week', meeting_date),
            DATE_PART('year', meeting_date)
    )

SELECT
    e.employee_id,
    e.employee_name,
    e.department,
    COUNT(*) AS meeting_heavy_weeks
FROM
    employees AS e
        JOIN
    meetings_week AS m ON e.employee_id = m.employee_id
WHERE m.hours_week > 20
GROUP BY
    e.employee_id,
    e.employee_name,
    e.department
HAVING COUNT(*) >= 2
ORDER BY
    meeting_heavy_weeks DESC,
    employee_name ASC
;