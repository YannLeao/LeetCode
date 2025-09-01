#!/usr/bin/env bash
awk 'NR==10 {print; exit}' file.txt