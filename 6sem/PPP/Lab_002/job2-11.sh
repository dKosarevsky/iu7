#!/bin/bash
#SBATCH --job-name="DeadLock"
#SBATCH --partition=debug
#SBATCH --nodes=10
#SBATCH --time=0-00:00:30
#SBATCH --ntasks-per-node=1
#SBATCH --mem=1992

mpirun -np 10 p11d


