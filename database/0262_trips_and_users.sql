WITH
    unbanned_userS AS (
        SELECT users_id FROM Users
        WHERE banned = 'No'
    )

SELECT
    request_at AS "Day",
    ROUND(
            AVG(CASE
                    WHEN status IN ('cancelled_by_driver', 'cancelled_by_client') THEN 1.0
                    ELSE 0.0
                END),
            2
    ) AS "Cancellation Rate"
FROM
    Trips t
        JOIN unbanned_users u_client ON t.client_id = u_client.users_id
        JOIN unbanned_users u_driver ON t.driver_id = u_driver.users_id
WHERE request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY request_at
;