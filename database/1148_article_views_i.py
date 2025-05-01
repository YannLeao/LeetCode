# Problem: 1148. Article Views I
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/article-views-i/

import pandas as pd


def article_views(views: pd.DataFrame) -> pd.DataFrame:
    return (views.loc[(views['author_id'] == views['viewer_id']), ['author_id']]
            .rename(columns={'author_id': 'id'})
            .drop_duplicates()
            .sort_values(by='id'))
