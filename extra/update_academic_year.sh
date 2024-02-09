#!/usr/bin/env bash

curr_year=$(date +%Y)
prev_year=$(($curr_year - 1))
find . -type f \( -name "*.Rmd" -o -name "*.sh" \) -exec \
	gsed -i "s/stats-comp-algo-software-${prev_year}/stats-comp-algo-software-${curr_year}/g" {} \;