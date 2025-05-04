# Problem: 2877. Create a DataFrame from List
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/create-a-dataframe-from-list/

import pandas as pd


def createDataframe(student_data: list[list[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data, columns=['student_id', 'age'])
