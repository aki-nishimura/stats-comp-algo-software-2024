#!/usr/bin/env bash

module load tex

cd "${HOME}/stats-comp-algo-software-2024/homework/git_experiment_copy"

# Add repo size for the first commit
du -s -k . | awk '{print $1}' >> git_repo_size_history.txt

# Add repo size for the 2...10000 commits
for commit_count in {2..10}
do
  let linenum="10+$commit_count"
  sentence_to_add="This is Sentence $commit_count."
  sed -i "$linenum i $sentence_to_add" foo.tex
  pdflatex foo.tex > /dev/null
  git add foo.tex
  git commit -m "Insert sentence $commit_count in the TeX file"
  du -s -k . | awk '{print $1}' >> git_repo_size_history.txt
done
