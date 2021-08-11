#program for greatest of 3 numbers

#getting the input for all the numbers
echo "Enter the 3 numbers: "
read a
read b
read c

#the following are all the possible cases to consider with the 3 numbers and are self explanatory
if [ $a -gt $b ] && [ $a -gt $c ]
then
	echo "$a is the largest"
elif [ $b -gt $a ] && [ $b -gt $c ]
then
	echo "$b is the largest"
elif [ $c -gt $a ] && [ $c -gt $b ]
then
	echo "$c is the largest"
elif [ $a -eq $b ] && [ $a -gt $c ]
then
	echo "$a is the largest"
elif [ $a -eq $c ] && [ $a -gt $b ]
then
	echo "$a is the largest"
elif [ $b -eq $c ] && [ $b -gt $a ]
then
	echo "$b is the largest"
elif [ $a -eq $b ] && [ $b -eq $c ]
then
	echo "All numbers are equal"
fi
