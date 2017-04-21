#!/bin/bash
if [ $# -lt 3 ]
then
	echo "Enter atleast 3 columns."
# Check that all three columns are less than 9	
elif [ $1 -le 9 -a $2 -le 9 -a $3 -le 9 ]
then
	echo "The contents of columns $1, $2, and $3 are:"
	ls -l | cut -d " " -f $1,$2,$3
else
	echo "Please enter column numbers from 1 to 9 only."
fi

# Execution:
# 	$ sh a3.sh
# Output:
# 	The contents of columns 1, 5, and 9 are:
# 	total
# 	-rw-rw-r-- 255 a1.sh
# 	-rw-rw-r--  22:57
# 	lrwxrwxrwx  22
# 	-rw-rw-r-- 472 a2.sh
# 	-rw-rw-r--  22
# 	-rw-rw-r-- 375 a3.sh