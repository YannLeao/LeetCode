# Problem: 1683. Invalid Tweets
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/invalid-tweets/

import pandas as pd


def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    return tweets.loc[(tweets['content'].str.len() > 15), ['tweet_id']]
