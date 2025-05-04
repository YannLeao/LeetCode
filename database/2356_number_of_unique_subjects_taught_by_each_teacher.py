# Problem: 2356. Number of Unique Subjects Taught by Each Teacher
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/

import pandas as pd


def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    teacher = teacher[['teacher_id', 'subject_id']].drop_duplicates()
    teacher = teacher.rename(columns={'subject_id': 'cnt'})
    return teacher.groupby('teacher_id')['cnt'].count().reset_index()


# Test
data = [[1, 2, 3], [1, 2, 4], [1, 3, 3], [2, 1, 1], [2, 2, 1], [2, 3, 1], [2, 4, 1]]
dataframe = pd.DataFrame(data, columns=['teacher_id', 'subject_id', 'dept_id']).astype(
    {'teacher_id': 'Int64', 'subject_id': 'Int64', 'dept_id': 'Int64'})

print(count_unique_subjects(dataframe))
