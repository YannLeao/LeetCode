# Problem: 2887. Fill Missing Data
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/fill-missing-data/

import pandas as pd


def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products['quantity'] = products['quantity'].fillna(value=0)
    return products
