# Problem: 1484. Group Sold Products By The Date
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/group-sold-products-by-the-date/

import pandas as pd


def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    activities = activities.drop_duplicates()
    return pd.merge(
        left=(activities.groupby('sell_date')['product'].count().reset_index(name='num_sold')),
        right=(activities.groupby('sell_date')['product'].apply(lambda x: ','.join(sorted(x))).reset_index(name='products')),
        on='sell_date')


# Test
data = [['2020-05-30', 'Headphone'], ['2020-06-01', 'Pencil'], ['2020-06-02', 'Mask'], ['2020-05-30', 'Basketball'],
        ['2020-06-01', 'Bible'], ['2020-06-02', 'Mask'], ['2020-05-30', 'T-Shirt']]
dataframe = pd.DataFrame(data, columns=['sell_date', 'product']).astype(
    {'sell_date': 'datetime64[ns]', 'product': 'object'})

print(categorize_products(dataframe))
