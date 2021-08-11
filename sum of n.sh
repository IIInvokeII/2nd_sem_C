#Program to find the sum of the first N natural numbers

#taking input
echo "Enter N to find the sum of N Natural numbers: "
read n

#using the mathematical formula to calculate it 
s=$(((n*(n+1))/2))
echo "The sum of the first $n natural numbers is: $s"
