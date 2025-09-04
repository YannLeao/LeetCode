import json
from pathlib import Path

with open('metadata.json') as f:
    metadata = json.load(f)

# Mapas de badges
difficulty_badges = {
    "Easy": "![Easy](https://img.shields.io/badge/-Easy-8BC34A?style=flat-square&logo=leetcode&logoColor=white)",
    "Medium": "![Medium](https://img.shields.io/badge/-Med.-FFA000?style=flat-square&logo=leetcode&logoColor=white)",
    "Hard": "![Hard](https://img.shields.io/badge/-Hard-F44336?style=flat-square&logo=leetcode&logoColor=white)"
}

language_badges = {
    "py": "![Python](https://img.shields.io/badge/-Python-3776AB?style=flat-square&logo=python&logoColor=white)",
    "cpp": "![C++](https://img.shields.io/badge/-C++-f34b7d?style=flat-square&logo=c%2B%2B&logoColor=white)",
    "sql": "![SQL](https://img.shields.io/badge/-SQL-4169E1?style=flat-square&logo=postgresql&logoColor=white)",
    "sh": "![Shell](https://img.shields.io/badge/-Shell-4EAA25?style=flat-square&logo=gnu-bash&logoColor=white)"
}

supported_extensions = {
    ".py": "py",
    ".cpp": "cpp",
    ".sql": "sql",
    ".sh" : "sh"
}


def smart_title(text):
    return ' '.join(word if word.isupper() else word.capitalize() for word in text.replace('_', ' ').split())


def get_badge(mapping, key, default_color="grey"):
    return mapping.get(key, f"![{key}](https://img.shields.io/badge/-{key}-{default_color}?style=flat-square)")


root = Path(__file__).parent
folders = [f for f in root.iterdir() if f.is_dir() and f.name != ".git"]

header = """# LeetCode Solutions

> This repository contains my solutions to [LeetCode](https://leetcode.com/u/YannLeao/) problems, as part of my 
studies in algorithms, data structures and data analysis.

## Progress
<div align="center" justify="center">
<img src="https://leetcard.jacoblin.cool/YannLeao?ext=heatmap&theme=transparent&border=0">
</div>

## Badges

### Annual Badges
<div align="left">
<img src="_assets/Badge_50_Days.gif" width="10%">
</div>

### Study Plan Badges
<div align="left">
<img src="_assets/Badge_Introduction_to_Pandas.gif" width="10%">
<img src="_assets/Badge_SQL_50.gif" width="10%">
</div>

## Solved Problems

| Nº   | Problem | Tags | Difficulty | Language |
|------|---------|------|------------|----------|
"""

rows = []

for folder in sorted(folders):
    for file in sorted(folder.iterdir()):
        if not file.is_file() or file.suffix not in supported_extensions:
            continue

        lang_key = supported_extensions[file.suffix]
        parts = file.stem.split('_', 1)
        if len(parts) != 2 or not parts[0].isdigit():
            continue

        number, raw_name = parts
        title = smart_title(raw_name)
        path = f"{folder.name}/{file.name}"

        metadata_entry = metadata.get(number, {})
        tags = metadata_entry.get("tags", [folder.name.replace("_", " ").title()])
        tag = ", ".join(tags)

        difficulty = metadata_entry.get("difficulty")
        difficulty_badge = get_badge(difficulty_badges, difficulty)
        language_badge = get_badge(language_badges, lang_key)

        row = f"| {number} | [{title}]({path}) | {tag} | {difficulty_badge} | {language_badge} |"
        rows.append((int(number), row))

rows.sort(key=lambda x: x[0])


output_file = "README.md"
with open(output_file, "w", encoding="utf-8") as f:
    f.write(header)
    f.write("\n".join(row for _, row in rows))
    f.write("\n")
