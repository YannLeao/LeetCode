# Problem: 586. Customer Placing the Largest Number of Orders
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/

import pandas as pd


def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    if 'customer_number' not in orders.columns or orders['customer_number'].empty:
        return pd.DataFrame({'customer_number': []})

    max_customer = orders['customer_number'].value_counts().idxmax()
    return pd.DataFrame({'customer_number': [max_customer]})


# Test
data = []
dataframe = pd.DataFrame(data, columns=['order_number', 'customer_number']).astype(
    {'order_number': 'Int64', 'customer_number': 'Int64'})

print(largest_orders(dataframe))
