# Problem: 1050. Actors and Directors Who Cooperated At Least Three Times
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/

import pandas as pd


def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    actor_director = (actor_director.groupby(['actor_id', 'director_id'])['timestamp']
                      .count()
                      .reset_index()
                      .query('timestamp >= 3'))
    return actor_director[['actor_id', 'director_id']]


# Test
data = [[1, 1, 0], [1, 1, 1], [1, 1, 2], [1, 2, 3], [1, 2, 4], [2, 1, 5], [2, 1, 6]]
dataframe = pd.DataFrame(data, columns=['actor_id', 'director_id', 'timestamp']).astype(
    {'actor_id': 'int64', 'director_id': 'int64', 'timestamp': 'int64'})

print(actors_and_directors(dataframe))
