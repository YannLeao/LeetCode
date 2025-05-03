# Problem: 0177. Nth Highest Salary
# Tags: Database
# Difficulty: Medium
# Link: https://leetcode.com/problems/nth-highest-salary/

import pandas as pd


def nth_highest_salary(employee: pd.DataFrame, N: int):
    if N <= 0:
        return pd.DataFrame({f'getNthHighestSalary({N})': [None]})

    list_ = list(set(employee['salary']))
    list_.sort(reverse=True)

    try:
        dictionary = {f'getNthHighestSalary({N})': [list_[N-1]]}
        return pd.DataFrame(dictionary)
    except IndexError:
        return pd.DataFrame({f'getNthHighestSalary({N})': [None]})


# Tests
dataframe = dict(id=[1, 2, 3], salary=[100, 200, 300])
print(nth_highest_salary(employee=dataframe, N=0))
