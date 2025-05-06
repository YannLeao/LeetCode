# Problem: 1693. Daily Leads and Partners
# Tags: Database
# Difficulty: Easy
# Link: https://leetcode.com/problems/daily-leads-and-partners/

import pandas as pd


def daily_leads_and_partners(daily_sales: pd.DataFrame) -> pd.DataFrame:
    daily_sales = daily_sales.drop_duplicates()
    df = pd.merge(
        left=(daily_sales.groupby(['date_id', 'make_name'])['lead_id'].unique().reset_index(name='unique_leads')),
        right=(daily_sales.groupby(['date_id', 'make_name'])['partner_id'].unique()
               .reset_index(name='unique_partners')),
        on=['date_id', 'make_name'])

    df['unique_leads'] = df['unique_leads'].apply(len)
    df['unique_partners'] = df['unique_partners'].apply(len)
    return df


data = [['2020-12-8', 'toyota', 0, 1], ['2020-12-8', 'toyota', 1, 0], ['2020-12-8', 'toyota', 1, 2],
        ['2020-12-7', 'toyota', 0, 2], ['2020-12-7', 'toyota', 0, 1], ['2020-12-8', 'honda', 1, 2],
        ['2020-12-8', 'honda', 2, 1], ['2020-12-7', 'honda', 0, 1], ['2020-12-7', 'honda', 1, 2],
        ['2020-12-7', 'honda', 2, 1]]
data_frame = pd.DataFrame(data, columns=['date_id', 'make_name', 'lead_id', 'partner_id']).astype(
    {'date_id': 'datetime64[ns]', 'make_name': 'object', 'lead_id': 'Int64', 'partner_id': 'Int64'})

print(daily_leads_and_partners(data_frame))
