#!/bin/bash
echo "Enter the string to be searched:"
read str
echo "Enter the name of the file in which the string is to be searched:"
read fname
if [ -f $fname ]
then
	echo "The line containing $str in $fname:"
	grep -n $str $fname
else
	echo "File does not exist."
fi

# Execution and Output:
# 	$ sh a4.sh
# 	Enter the string to be searched:
# 	boss
# 	Enter the name of the file in which the string is to be searched:
# 	a4.txt
# 	The line containing boss in a4.txt:
# 	3:My boss recklessly peed on my assignment, so I couldn't do well on my poster!
