WITH students_subjects AS (
    SELECT
        st.student_id,
        st.student_name,
        su.subject_name
    FROM
        Students AS st
            CROSS JOIN
        Subjects AS su
)

SELECT
    st.student_id,
    st.student_name,
    st.subject_name,
    COUNT(e.subject_name) AS attended_exams
FROM
    students_subjects AS st
        LEFT JOIN
    Examinations AS e
    ON e.student_id = st.student_id AND e.subject_name = st.subject_name
GROUP BY
    st.student_id, st.student_name, st.subject_name
ORDER BY
    student_id, subject_name
;