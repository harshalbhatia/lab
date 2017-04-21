#!/bin/bash
if [ $# -gt 0 ]
then
	echo "Backed-up files are:"
	tar -pczvf a1_backup.tar $1
else
	echo "Please enter an argument."
fi

# Say 'a1.txt' is the file to be backed up.
# Execution:
# 	$ sh a1.sh a1.txt
# Output:
# 	Backed-up files are:
# 	a1.txt