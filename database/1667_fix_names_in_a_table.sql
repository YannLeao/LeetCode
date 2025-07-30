SELECT
    u.user_id,
    UPPER(SUBSTRING(name FROM 1 FOR 1)) || LOWER(SUBSTRING(name FROM 2)) AS name
FROM
    Users AS u
ORDER BY
    u.user_id
;