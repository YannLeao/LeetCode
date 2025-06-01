# 1378. Replace Employee ID With The Unique Identifier
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/

import pandas as pd


def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    return pd.merge(left=employee_uni, right=employees, on='id', how='right')[['unique_id', 'name']]


# Test
data = [[1, 'Alice'], [7, 'Bob'], [11, 'Meir'], [90, 'Winston'], [3, 'Jonathan']]
dataframe = pd.DataFrame(data, columns=['id', 'name']).astype({'id': 'int64', 'name': 'object'})
data = [[3, 1], [11, 2], [90, 3]]
dataframe_uni = pd.DataFrame(data, columns=['id', 'unique_id']).astype({'id': 'int64', 'unique_id': 'int64'})

print(replace_employee_id(dataframe, dataframe_uni))
