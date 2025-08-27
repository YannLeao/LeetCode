WITH
    valid_drivers AS (
        SELECT
            t.driver_id,
            t.trip_date,
            d.driver_name,
            t.distance_km::NUMERIC / NULLIF(t.fuel_consumed, 0) AS fuel_efficiency
        FROM
            trips AS t
                JOIN
            drivers AS d ON t.driver_id = d.driver_id
    ),

    trips_half_year AS (
        SELECT
            driver_id,
            driver_name,
            AVG(fuel_efficiency) FILTER (WHERE EXTRACT(MONTH FROM trip_date) BETWEEN 1 AND 6) AS first_half_avg,
            AVG(fuel_efficiency) FILTER (WHERE EXTRACT(MONTH FROM trip_date) BETWEEN 7 AND 12) AS second_half_avg
        FROM valid_drivers
        GROUP BY driver_id, driver_name
        HAVING
            AVG(fuel_efficiency) FILTER (WHERE EXTRACT(MONTH FROM trip_date) BETWEEN 1 AND 6) IS NOT NULL
            AND AVG(fuel_efficiency) FILTER (WHERE EXTRACT(MONTH FROM trip_date) BETWEEN 7 AND 12) IS NOT NULL
    )

SELECT
    driver_id,
    driver_name,
    ROUND(first_half_avg, 2) AS first_half_avg,
    ROUND(second_half_avg, 2) AS second_half_avg,
    ROUND(second_half_avg - first_half_avg, 2) AS efficiency_improvement
FROM trips_half_year
WHERE second_half_avg - first_half_avg >= 0
ORDER BY
    efficiency_improvement DESC,
    driver_name ASC
;