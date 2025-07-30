SELECT
    patient_id,
    patient_name,
    conditions
FROM
    Patients
WHERE
    conditions ~* '\yDIAB1[0-9]*\y'
    AND conditions !~* '\+DIAB1[0-9]*'
;