#!/bin/bash

#SBATCH -p shared
#SBATCH --nodes=1
#SBATCH --mem=2G
#SBATCH -c 4
#SBATCH --job-name=hw
#SBATCH --mail-user=sparthi1@jhu.edu
#SBATCH --mail-type=ALL
#SBATCH -o logs/disk_space.txt
#SBATCH -e logs/disk_space.txt

### trying using a different reference fasta file 
echo "**** Job starts ****"
date +"%Y-%m-%d %T"
echo "**** JHPCE info ****"
echo "User: ${USER}"
echo "Job id: ${SLURM_JOB_ID}"
echo "Job name: ${SLURM_JOB_NAME}"
echo "Node name: ${SLURMD_NODENAME}"


cd "${HOME}/stats-comp-algo-software-2024/homework/git_experiment_copy"

for commit_count in {1..10000}
do
	let linenum="10+$commit_count"
	sentence_to_add="This is Sentence $commit_count."
	sed -i "$linenum i This is the sentence $commit_count." foo.tex
	git add -u
	git commit -m "Add sentence $commit_count to tex file"
	du -h -s . | awk '{print $1}'>> git_repo_size_history.txt
done


echo "**** Job ends ****"
date +"%Y-%m-%d %T"
