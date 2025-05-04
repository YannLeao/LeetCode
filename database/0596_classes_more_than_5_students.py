# Problem: 0596. Classes More Than 5 Students
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/classes-more-than-5-students/

import pandas as pd


def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    courses = courses.groupby('class')['student'].count().reset_index()
    return courses.loc[
        (courses['student'] >= 5),
        ['class']
    ]


# Test
data = [['A', 'Math'], ['B', 'English'], ['C', 'Math'], ['D', 'Biology'], ['E', 'Math'], ['F', 'Computer'],
        ['G', 'Math'], ['H', 'Math'], ['I', 'Math']]
dataframe = pd.DataFrame(data, columns=['student', 'class']).astype({'student': 'object', 'class': 'object'})

print(find_classes(dataframe))
