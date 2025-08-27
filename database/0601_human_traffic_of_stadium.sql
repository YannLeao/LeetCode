WITH

    consecutive_groups AS (
        SELECT
            id,
            visit_date,
            people,
            id - ROW_NUMBER() OVER (ORDER BY id) as group_id
        FROM stadium
        WHERE people >= 100

    ),

     valid_groups AS (
         SELECT group_id FROM consecutive_groups
         GROUP BY group_id HAVING COUNT(*) >= 3
     )

SELECT
    id,
    visit_date,
    people
FROM consecutive_groups
WHERE group_id IN (SELECT group_id FROM valid_groups)
;