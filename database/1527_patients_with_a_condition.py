# Problem: 1527. Patients With a Condition
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/patients-with-a-condition/

import pandas as pd


def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    return patients.loc[
        patients['conditions'].str.contains(r'(?<!\+)\bDIAB1\d*\b', regex=True),
        ['patient_id', 'patient_name', 'conditions']
    ]
