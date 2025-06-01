# 1280. Students and Examinations
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/students-and-examinations/

import pandas as pd


def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame,
                              examinations: pd.DataFrame) -> pd.DataFrame:
    students = students.sort_values(by='student_id')
    subjects = subjects.sort_values(by='subject_name')

    students_names = students['student_name'].unique().tolist()
    subjects_names = subjects['subject_name'].unique().tolist()

    subjects = (
        pd.MultiIndex.from_product(iterables=[students_names, subjects_names], names=['student_name', 'subject_name'])
        .to_frame(index=False))

    students = pd.merge(left=students, right=subjects, on='student_name', how='inner')
    examinations = (examinations.groupby(['student_id', 'subject_name'])['subject_name']
                    .size().reset_index(name='attended_exams'))

    students = pd.merge(left=students, right=examinations, on=['student_id', 'subject_name'], how='left')

    students['attended_exams'] = students['attended_exams'].fillna(0)
    return students


# Test
data = [[1, 'Alice'], [2, 'Bob'], [13, 'John'], [6, 'Alex']]
students_df = pd.DataFrame(data, columns=['student_id', 'student_name']).astype(
    {'student_id': 'Int64', 'student_name': 'object'})

data = [['Math'], ['Physics'], ['Programming']]
subjects_df = pd.DataFrame(data, columns=['subject_name']).astype({'subject_name': 'object'})

data = [[1, 'Math'], [1, 'Physics'], [1, 'Programming'], [2, 'Programming'], [1, 'Physics'], [1, 'Math'], [13, 'Math'],
        [13, 'Programming'], [13, 'Physics'], [2, 'Math'], [1, 'Math']]
examinations_df = pd.DataFrame(data, columns=['student_id', 'subject_name']).astype(
    {'student_id': 'Int64', 'subject_name': 'object'})

print(students_and_examinations(students_df, subjects_df, examinations_df))
