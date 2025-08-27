WITH

    scores_extrems AS (
        SELECT
            student_id,
            subject,
            FIRST_VALUE(score) OVER w_asc AS first_score,
            FIRST_VALUE(score) OVER w_desc AS latest_score
        FROM Scores
        WINDOW
            w_asc AS (PARTITION BY student_id, subject ORDER BY exam_date ASC),
            w_desc AS (PARTITION BY student_id, subject ORDER BY exam_date DESC)
    )

SELECT DISTINCT
    student_id,
    subject,
    first_score,
    latest_score
FROM scores_extrems
WHERE latest_score > first_score
ORDER BY student_id, subject
;