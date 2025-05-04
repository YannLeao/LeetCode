# Problem: 1905. Count Salary Categories
# Tags: Database
# Difficulty: Medium
# Link: https://leetcode.com/problems/count-salary-categories/

import pandas as pd


def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    accounts['category'] = accounts.apply(
        lambda x: 'Low Salary' if x['income'] < 20000 else (
            'Average Salary' if x['income'] <= 50000 else 'High Salary'),
        axis=1
    )

    # accounts['category'] = pd.cut(
    #     accounts['income'],
    #     bins=[-float('inf'), 20000, 50000, float('inf')],
    #     labels=['Low Salary', 'Average Salary', 'High Salary'],
    # )

    return (accounts.groupby(by='category', observed=False)
            .size()
            .to_frame('accounts_count')
            .reindex(['Low Salary', 'Average Salary','High Salary'], fill_value=0)
            .reset_index())


# Test
data = [[3, 108939], [2, 12747], [8, 87709], [6, 91796]]
dataframe = pd.DataFrame(data, columns=['account_id', 'income']).astype({'account_id': 'Int64', 'income': 'Int64'})

print(count_salary_categories(dataframe))
