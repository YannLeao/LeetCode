WITH
    covid_tests_positive AS (
        SELECT
            patient_id,
            test_date AS test_date_positive,
            ROW_NUMBER() OVER (PARTITION BY patient_id ORDER BY test_date ASC) AS rn_positive
        FROM covid_tests
        WHERE result = 'Positive'
    ),

    covid_tests_negative AS (
        SELECT
            c.patient_id,
            cp.test_date_positive,
            c.test_date AS test_date_negative,
            ROW_NUMBER() OVER (PARTITION BY c.patient_id ORDER BY c.test_date ASC) AS rn_negative
        FROM
            covid_tests AS c
                JOIN
            covid_tests_positive AS cp ON c.patient_id = cp.patient_id
        WHERE
            result = 'Negative'
          AND c.test_date > cp.test_date_positive
          AND cp.rn_positive = 1
    )

SELECT
    p.patient_id,
    p.patient_name,
    p.age,
    c.test_date_negative - c.test_date_positive AS recovery_time
FROM
    patients AS p
        JOIN
    covid_tests_negative AS c ON p.patient_id = c.patient_id
WHERE c.rn_negative = 1
ORDER BY recovery_time, patient_name
;