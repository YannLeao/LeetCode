# Problem: 183. Customers Who Never Order
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/customers-who-never-order/


import pandas as pd


def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    return customers.loc[(~customers['id'].isin(orders['customerId'])), ['name']] \
        .rename(columns={'name': 'Customers'})
