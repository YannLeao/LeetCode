#!/usr/bin/env bash
awk '
{
  for (i = 1; i <= NF; i++) {
    cols[i] = (cols[i] ? cols[i] " " : "") $i
  }
}
END {
  for (i = 1; i <= max; i++) print cols[i]
}
' file.txt

# First Version
#file="file.txt"
#cols=$(head -n1 "$file" | wc -w)
#for i in $(seq 1 "$cols");
#do
#    cut -d' ' -f"$i" "$file" | paste -sd' '
#done