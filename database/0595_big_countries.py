# Problem: 0595. Big Countries
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/big-countries/

import pandas as pd


def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    return world.loc[(world['area'] >= 3000000) | (world['population'] >= 25000000),
    ['name', 'population', 'area']]
