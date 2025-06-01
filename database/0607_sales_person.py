# 607. Sales Person
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/sales-person/

import pandas as pd


def sales_person(sales_persons: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    orders = pd.merge(left=company, right=orders, on='com_id', how='inner')
    sale_to_red = orders.drop(orders.query('name != "RED"').index)['sales_id'].unique().tolist()
    return sales_persons.loc[~sales_persons['sales_id'].isin(sale_to_red), ['name']]


#Tests
data = [[1, 'John', 100000, 6, '4/1/2006'], [2, 'Amy', 12000, 5, '5/1/2010'], [3, 'Mark', 65000, 12, '12/25/2008'],
        [4, 'Pam', 25000, 25, '1/1/2005'], [5, 'Alex', 5000, 10, '2/3/2007']]
sales_person_df = pd.DataFrame(data, columns=['sales_id', 'name', 'salary', 'commission_rate', 'hire_date']).astype(
    {'sales_id': 'Int64', 'name': 'object', 'salary': 'Int64', 'commission_rate': 'Int64',
     'hire_date': 'datetime64[ns]'})

data = [[1, 'RED', 'Boston'], [2, 'ORANGE', 'New York'], [3, 'YELLOW', 'Boston'], [4, 'GREEN', 'Austin']]
company_df = pd.DataFrame(data, columns=['com_id', 'name', 'city']).astype(
    {'com_id': 'Int64', 'name': 'object', 'city': 'object'})

data = [[1, '1/1/2014', 3, 4, 10000], [2, '2/1/2014', 4, 5, 5000], [3, '3/1/2014', 1, 1, 50000],
        [4, '4/1/2014', 1, 4, 25000]]
orders_df = pd.DataFrame(data, columns=['order_id', 'order_date', 'com_id', 'sales_id', 'amount']).astype(
    {'order_id': 'Int64', 'order_date': 'datetime64[ns]', 'com_id': 'Int64', 'sales_id': 'Int64', 'amount': 'Int64'})

print(sales_person(sales_person_df, company_df, orders_df))
