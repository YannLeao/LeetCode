WITH books_no_returned AS (
    SELECT
        book_id,
        COUNT(*) FILTER (WHERE return_date IS NULL) AS count
FROM
    borrowing_records
GROUP BY
    book_id
)

SELECT
    l.book_id,
    l.title,
    l.author,
    l.genre,
    l.publication_year,
    b.count AS current_borrowers
FROM
    library_books AS l
        INNER JOIN
    books_no_returned AS b ON l.book_id = b.book_id
WHERE
    b.count - l.total_copies = 0
ORDER BY
    current_borrowers DESC,
    title ASC
;