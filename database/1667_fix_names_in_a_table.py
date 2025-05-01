# Problem: 1667. Fix Names in a Table
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/fix-names-in-a-table/

import pandas as pd


def fix_names(users: pd.DataFrame) -> pd.DataFrame:
    users['name'] = users['name'].str.capitalize()
    return users.sort_values(by='user_id')
