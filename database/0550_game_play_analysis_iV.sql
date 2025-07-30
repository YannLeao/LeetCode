WITH

    TotalPlayers AS (
        SELECT
            COUNT(DISTINCT player_id) AS total
        FROM
            Activity
    ),

    FirstLoggin AS (
        SELECT
            player_id,
            MIN(event_date) AS first_date
        FROM
            Activity
        GROUP BY
            player_id
    )

SELECT
    COALESCE(
            (
                SELECT
                    ROUND(
                            COUNT(today.player_id)::numeric / t.total,
                            2
                    ) AS fraction
                FROM
                    TotalPlayers AS t,
                    Activity AS today
                        INNER JOIN
                    FirstLoggin AS f
                    ON today.player_id = f.player_id
                        AND today.event_date = f.first_date
                        INNER JOIN
                    Activity AS tomorrow
                    ON today.player_id = tomorrow.player_id
                        AND today.event_date = tomorrow.event_date - INTERVAL '1 day'
            GROUP BY
            t.total
        ),
        0
    ) AS fraction
;