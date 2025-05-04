# Problem: 2890. Reshape Data: Melt
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/reshape-data-melt/

import pandas as pd


def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    return report.melt(id_vars='product', var_name='quarter', value_name='sales')

# id_vars: o que você quer manter fixo.
# var_name: nome da nova coluna onde os nomes das colunas viram valores.
# value_name: nome da nova coluna onde os valores dessas colunas são armazenados.
