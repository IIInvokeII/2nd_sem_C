#Program to check if a given number is an armstrong number
#taking input
echo "Enter a number: "
read a
#storing it to check value after calculation
b=$a
c=0	#count variable
#while loop to count the number of digits
while [ $b -ge 1 ]
do
	c=$((c+1))
	b=$((b/10))
done
echo "No. of digits: $c"
b=$a
d=0
s=0
#calcuting the armstrong number
while [ $d -lt $c ]
do
	r=$((a%10))
	s=$((s+(r**c)))
	a=$((a/10))
	echo "Value of r: $r, s: $s, a: $a"
	d=$((d+1))
done
if [ $b -eq $s ]
then
	echo "$b is an Armstrong Number."
else
	echo "$b is not an Armstrong Number."
fi
