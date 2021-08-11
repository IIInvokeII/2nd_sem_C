#Program to find factorial of a given number

#taking input
echo "Enter number to find factorial for: "
read a
#storing the value for running the loop
b=$a
#initial number
s=1
#while loop to iteratively multiply each number and store it
while [ $b -gt 1 ]
do
	s=$((s*b))
	b=$((b-1))
done
#output
echo "$a! = $s"
