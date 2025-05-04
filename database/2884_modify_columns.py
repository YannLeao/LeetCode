# Problem: 2884. Modify Columns
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/modify-columns/

import pandas as pd


def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['salary'] = employees['salary'] * 2
    return employees
