#!/bin/bash

# Set initial line number
linenum=10

# Loop for 10000 times
for ((i=1; i<=10000; i++))
do
    # Add a new sentence to foo.tex using sed
    sed -i "$linenum i This is sentence number $i." foo.tex

    # Compile foo.tex 
    module load tex
    pdflatex foo.tex > foo.pdf

    # Commit changes to the repository excluding foo.pdf
    git add foo.tex
    git commit -m "Add sentence $i to TeX file"

    # Increment line number for the next iteration
    linenum=$((linenum + 1))
    
    # Record the size of the repository in git_repo_size_history.txt
    du -s -k . | awk '{print $1}' >> git_repo_size_history.txt
done