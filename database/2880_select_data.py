# Problem: 2880. Select Data
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/select-data/

import pandas as pd


def selectData(students: pd.DataFrame) -> pd.DataFrame:
    return students.loc[
        (students['student_id'] == 101),
        ['name', 'age']
    ]