# 570. Managers with at Least 5 Direct Reports
# Tags: Database
# Difficulty: Medium
# Link: https://leetcode.com/problems/managers-with-at-least-5-direct-reports/

import pandas as pd


def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    employee = employee.drop(employee.query('id == managerId').index)
    counts = employee['managerId'].value_counts().reset_index()

    employee = pd.merge(left=employee, right=counts, left_on='id', right_on='managerId', how='left')
    return employee.query('count >= 5')['name'].to_frame()


# Tests
data = [[101, 'John', 'A', None], [102, 'Dan', 'A', 101], [103, 'James', 'A', 101], [104, 'Amy', 'A', 101],
        [105, 'Anne', 'A', 101], [106, 'Ron', 'B', 101]]
employee_df = pd.DataFrame(data, columns=['id', 'name', 'department', 'managerId']).astype(
    {'id': 'Int64', 'name': 'object', 'department': 'object', 'managerId': 'Int64'})

print(find_managers(employee_df))
