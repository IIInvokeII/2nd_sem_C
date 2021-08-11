#Progrom to display fibonacci series
#taking input
echo "Enter how many fibonacci numbers to print: "
read n
#storing inital values
f1=0
f2=1
f=0
#counting variable
c=3
#displaying
echo ""
echo "1. $f"
echo "2. $f2"
#while loop to calculate and display the values iteratively
while [ $n -gt 2 ]
do
	f=$((f1+f2))
	temp=$f1
	f1=$f2
	f2=$((temp+f2))
	echo "$c. $f "
	n=$((n-1))
	c=$((c+1))
done
