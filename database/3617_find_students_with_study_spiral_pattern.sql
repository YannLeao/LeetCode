WITH
    valids_sessions AS (
        SELECT student_id
        FROM study_sessions
        GROUP BY student_id
        HAVING COUNT(*) >= 6
    ),

    sessions_gaps AS (
        SELECT
            student_id,
            session_date - LAG(session_date) OVER (PARTITION BY student_id ORDER BY session_date) AS gap
        FROM study_sessions
    ),

    good_gaps_sessions AS (
        SELECT student_id
        FROM sessions_gaps
        GROUP BY student_id
        HAVING MAX(COALESCE(gap, 0)) <= 2
    ),

    students_stats AS (
        SELECT
            student_id,
            COUNT(DISTINCT subject) AS cycle_length,
            SUM(hours_studied)::NUMERIC AS total_study_hours
        FROM study_sessions
        WHERE
            student_id IN (SELECT student_id FROM valids_sessions)
          AND student_id IN (SELECT student_id FROM good_gaps_sessions)
        GROUP BY student_id
    )

SELECT
    st.student_id,
    st.student_name,
    st.major,
    ss.cycle_length,
    ss.total_study_hours
FROM
    students_stats AS ss
        JOIN
    students AS st ON ss.student_id = st.student_id
WHERE ss.cycle_length >= 3
ORDER BY
    cycle_length DESC,
    total_study_hours DESC