# Problem: 1741. Find Total Time Spent by Each Employee
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/find-total-time-spent-by-each-employee/

import pandas as pd


def total_time(employees: pd.DataFrame) -> pd.DataFrame:
    employees['total_time'] = employees['out_time'] - employees['in_time']
    employees = employees.rename(columns={'event_day': 'day'})
    return employees.groupby(['day', 'emp_id'])['total_time'].sum().reset_index()


# Test
data = [['1', '2020-11-28', '4', '32'], ['1', '2020-11-28', '55', '200'], ['1', '2020-12-3', '1', '42'],
        ['2', '2020-11-28', '3', '33'], ['2', '2020-12-9', '47', '74']]
dataframe = pd.DataFrame(data, columns=['emp_id', 'event_day', 'in_time', 'out_time']).astype(
    {'emp_id': 'Int64', 'event_day': 'datetime64[ns]', 'in_time': 'Int64', 'out_time': 'Int64'})

print(total_time(dataframe))
