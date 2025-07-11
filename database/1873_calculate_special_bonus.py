# Problem: 1873. Calculate Special Bonus
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/calculate-special-bonus/

import pandas as pd


def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees.apply(
        lambda x: x['salary'] if (x['name'][0] != 'M' and x['employee_id'] % 2 != 0) else 0,
        axis=1
    )
    return employees[['employee_id', 'bonus']].sort_values(by='employee_id')
