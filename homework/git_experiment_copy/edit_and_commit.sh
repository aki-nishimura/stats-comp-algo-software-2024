#!/usr/bin/env bash

cd "${HOME}/stats-comp-algo-software-2024/homework/git_experiment_copy"

for commit_count in {2..10000}
do
  let linenum="10+$commit_count"
  sentence_to_add="This is Sentence $commit_count."
  # Fill in
  sed -i "$linenum i $sentence_to_add" foo.tex
  git add -u
  git commit -m "Add sentence $commit_count"
  du -s -k . | awk '{print $1}' >> git_repo_size_history.txt
done
