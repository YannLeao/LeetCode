# Problem: 2882. Drop Duplicate Rows
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/drop-duplicate-rows/

import pandas as pd


def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    customers = customers.drop_duplicates(subset='email')
    return customers[['customer_id', 'name', 'email']]
