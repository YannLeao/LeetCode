WITH
    word_content AS (
        SELECT
            content_id,
            content_text,
            UNNEST(
                    STRING_TO_ARRAY(
                            REPLACE(content_text, '-', ' - '),
                            ' '
                    )
            ) AS word
        FROM user_content
    )

SELECT
    content_id,
    content_text AS original_text,
    REPLACE(
            STRING_AGG(
                    UPPER(SUBSTRING(word FROM 1 FOR 1)) || LOWER(SUBSTRING(word FROM 2)),
                    ' '
            ),
            ' - ',
            '-'
    ) AS converted_text
FROM word_content
GROUP BY
    content_id,
    content_text
ORDER BY content_id
;
