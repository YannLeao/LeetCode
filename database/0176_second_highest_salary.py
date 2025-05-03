# Problem: 0176. Second Highest Salary
# Tags: Database
# Difficulty: Medium
# Link: https://leetcode.com/problems/second-highest-salary/

import pandas as pd


def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    list_ = list(set(employee['salary']))
    list_.sort(reverse=True)

    try:
        dictionary = {'SecondHighestSalary': [list_[1]]}
        return pd.DataFrame(dictionary)
    except IndexError:
        return pd.DataFrame({'SecondHighestSalary': [None]})
