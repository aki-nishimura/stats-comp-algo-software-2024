#!/usr/bin/env bash
#
# Requires installation of `coreutils` via Homebrew. The seed for `gshuf` 
# needs to have >= 42 bytes and only the first 42 bytes of info are used.
#
# Example usage: bash extra/make_pairs.sh $seed

seed=$1
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
    # https://stackoverflow.com/questions/59895/how-do-i-get-the-directory-where-a-bash-script-is-located-from-within-the-script
input_file="${SCRIPT_DIR}/github_usernames.txt"

# Check if the input file exists and is readable
if [[ ! -r "$input_file" ]]; then
    echo "Error: Input file not found or not readable."
    exit 1
fi

# Read the names from the input file into an array
names=($(<"$input_file"))

# Shuffle according to the given seed if provided
if [ -n ${seed+x} ]; then
    echo "Using seed: $seed"
    shuf_names=($(gshuf --random-source=<(echo "$seed") -e "${names[@]}"))
else
    shuf_names=($(gshuf -e "${names[@]}"))
fi

# Print names in pairs
echo ""
for ((i=0; i<${#shuf_names[@]}; i+=2)); do
    echo ${shuf_names[i]}
    echo ${shuf_names[i+1]}
    echo ""
done
