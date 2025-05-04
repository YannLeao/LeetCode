# Problem: 2889. Reshape Data: Pivot
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/reshape-data-pivot/

import pandas as pd


def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    return weather.pivot(index='month', columns='city', values='temperature')

# index: o que você quer manter como linha.
# columns: o que vira coluna.
# values: os dados que preencherão a tabela.
