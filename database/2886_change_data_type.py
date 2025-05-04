# Problem: 2886. Change Data Type
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/change-data-type/

import pandas as pd


def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students['grade'] = students['grade'].astype('int')
    return students
