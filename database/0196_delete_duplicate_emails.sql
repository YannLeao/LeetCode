DELETE FROM
    Person as P1
    USING
    Person AS p2
WHERE
    p1.email = p2.email AND p1.id > p2.id
;