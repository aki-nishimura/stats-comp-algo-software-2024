#!/usr/bin/env bash

cd "${HOME}/stats-comp-algo-software-2024/homework/git_experiment_copy"

for commit_count in {1..10000}
do
  let linenum="10+$commit_count"
  sentence_to_add="This is Sentence $commit_count."
  sed -i "$linenum i This is Sentence $commit_count." foo.tex
  git add foo.tex
  git commit -m "Add sentence $commit_count to TeX file"
  du -h -s .|awk '{print $1}' >> git_repo_size_history.txt
done
