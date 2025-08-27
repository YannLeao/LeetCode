WITH
    AvgTrial AS (
        SELECT
            user_id,
            ROUND(
                    AVG(activity_duration),
                    2
            ) AS trial_avg_duration
        FROM UserActivity
        WHERE activity_type = 'free_trial'
        GROUP BY user_id
        ORDER BY user_id
    ),

    AvgPaid AS (
        SELECT
            user_id,
            ROUND(
                    AVG(activity_duration),
                    2
            ) AS paid_avg_duration
        FROM UserActivity
        WHERE activity_type = 'paid'
        GROUP BY user_id
        ORDER BY user_id
    )

SELECT
    t.user_id,
    t.trial_avg_duration,
    p.paid_avg_duration
FROM
    AvgTrial AS t
        INNER JOIN
    AvgPaid AS p ON t.user_id = p.user_id
;