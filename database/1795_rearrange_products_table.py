# Problem: 1795. Rearrange Products Table
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/rearrange-products-table/

import pandas as pd


def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    products = products.melt(id_vars='product_id', var_name='store', value_name='price')
    return products.loc[
        (~products['price'].isna()),
        ['product_id', 'store', 'price']
    ]


# Test
data = [[0, 95, 100, 105], [1, 70, None, 80]]
dataframe = (pd.DataFrame(data, columns=['product_id', 'store1', 'store2', 'store3'])
             .astype({'product_id': 'Int64', 'store1': 'Int64', 'store2': 'Int64', 'store3': 'Int64'}))
print(rearrange_products_table(dataframe))
