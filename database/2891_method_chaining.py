# Problem: 2891. Method Chaining
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/method-chaining/

import pandas as pd


def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    return animals.sort_values(by='weight', ascending=False).loc[(animals['weight'] > 100), ['name']]
