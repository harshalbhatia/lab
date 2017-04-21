#!/bin/bash
if [ -f $1 ]
then
	echo "Soft links are:"
	find -L . -xtype l -samefile $1
else
	echo "File does not exist."
fi

# Say 'a2.txt' is the file whose soft links are to be found.
# Execution:
# 	$ sh a2.sh a2.txt
# Output:
# 	Soft links are:
# 	./a2link

# Another, more 'hacky' and 'unreliable' solution might be to use 'ls -l' along with 'grep'
# Replace the 'find' line with:
# ls -l | grep "^l.*$1" | cut -d " " -f 11
# You might have to adjust the last number.