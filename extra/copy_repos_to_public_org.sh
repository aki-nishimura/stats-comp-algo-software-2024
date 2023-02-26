#!/usr/bin/env bash

gh_orgname="stats-comp-algo-software-2023"
reponame="hiperglm"

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
	# https://stackoverflow.com/questions/59895/how-do-i-get-the-directory-where-a-bash-script-is-located-from-within-the-script
input_file="${SCRIPT_DIR}/github_usernames.txt"

while read line
do
	gh_usrname="$line"

	git clone --mirror "https://github.com/${gh_usrname}/${reponame}" ${gh_usrname}/.git
	cd $gh_usrname
	git config --bool core.bare false

	gh repo create --public "https://github.com/${gh_orgname}/${gh_usrname}"
	git push --all "https://github.com/${gh_orgname}/${gh_usrname}"
	cd ..
	
done < "$input_file"