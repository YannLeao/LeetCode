# Problem: 0184. Departament Highest Salary
# Tags: Database
# Difficulty: Medium
# Link: https://leetcode.com/problems/department-highest-salary/

import pandas as pd


def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    employee = employee.rename(columns={'name': 'Employee', 'salary': 'Salary'})
    department = department.rename(columns={'name': 'Department'})

    result = pd.merge(employee, department, left_on='departmentId', right_on='id', how='inner')

    max_salaries = result.groupby('Department')['Salary'].transform('max')

    return result.loc[
        (result['Salary'] == max_salaries),
        ['Departament', 'Employee', 'Salary']
    ]
