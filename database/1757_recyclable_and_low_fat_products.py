# Problem: 1757. Recyclable and Low Fat Products
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/recyclable-and-low-fat-products/

import pandas as pd


def find_products(products: pd.DataFrame) -> pd.DataFrame:
    return products.loc[(products['low_fats'] == 'Y') & (products['recyclable'] == 'Y'),
    ['product_id']]
