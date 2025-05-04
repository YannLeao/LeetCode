# Problem: 0196. Delete Duplicate Emails
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/delete-duplicate-emails/

import pandas as pd


def delete_duplicate_emails(dataframe: pd.DataFrame) -> None:
    dataframe.sort_values(by='id', inplace=True)
    dataframe.drop_duplicates(inplace=True, subset=['email'])


# Test
data = [[3, 'john@example.com'], [1, 'bob@example.com'], [2, 'john@example.com']]
person = pd.DataFrame(data, columns=['id', 'email']).astype({'id': 'int64', 'email': 'object'})
delete_duplicate_emails(person)
print(person)
