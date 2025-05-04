# Problem: 0178. Rank Scores
# Tags: Database
# Difficulty: Medium
# Link: https://leetcode.com/problems/rank-scores/

import pandas as pd


def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores['rank'] = scores['score'].rank(method='dense', ascending=False)
    return scores[['score', 'rank']].sort_values(by='score', ascending=False)


# Test
data = [[1, 3.5], [2, 3.65], [3, 4.0], [4, 3.85], [5, 4.0], [6, 3.65]]
scores = pd.DataFrame(data, columns=['id', 'score']).astype({'id': 'Int64', 'score': 'Float64'})

print(order_scores(scores))
