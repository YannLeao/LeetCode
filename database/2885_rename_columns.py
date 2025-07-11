# Problem: 2885. Rename Columns
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/rename-columns/

import pandas as pd


def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    return students.rename(columns={
        'id': 'student_id',
        'first': 'first_name',
        'last': 'last_name',
        'age': 'age_in_years'
    })
