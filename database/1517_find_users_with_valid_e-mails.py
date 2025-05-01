# Problem: 1517. Find Users With Valid E-Mails
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/find-users-with-valid-e-mails/

import pandas as pd


def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    return users.loc[
        (users['mail'].str.contains('^[A-Za-z][A-Za-z0-9_.-]*@leetcode\.com$', regex=True)),
        ['user_id', 'name', 'mail']
    ]
