#!/usr/bin/env bash
tr -s '[:space:]' '\n' < words.txt | sort | uniq -c | sort -nr | awk '{print $2, $1}'