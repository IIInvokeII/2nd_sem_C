#Program to check if a given number is odd or even
#taking input
echo "Enter a number: "
read a
#dividing by 2 and checking remainder and giving output
if [ $((a%2)) -eq 0 ]
then
	echo "$a is even"
else
	echo "$a is odd"
fi
