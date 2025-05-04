# Problem: 2878. Get the Size of a DataFrame
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/get-the-size-of-a-dataframe/

import pandas as pd


def getDataframeSize(players: pd.DataFrame) -> list[int]:
    return list(players.shape)
