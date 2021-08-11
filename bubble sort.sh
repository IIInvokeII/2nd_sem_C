#program to sort an array of elements
#taking input
echo "Enter No. Of Elements: "
read n
echo "Enter Array Elements: "
for ((i=0; i<n; i++))
do
    read a[$i]
done

#alternative method to declare an array
#a=(3 2 1)
#n=3

#bubble sort
for ((i=0; i<n; i++))
do
	for ((j=0; j<n-1; j++))
    	do
		x=${a[j]}
		y=${a[j+1]}
        	if [ $x -gt $y ]
        	then
            		temp=${a[j]}
	    		a[$j]=${a[j+1]}
			a[$((j+1))]=$temp
        	fi
	done
done

#output
echo "Array after sorting: "
for ((i=0; i<n; i++))
do
    echo ${a[i]}
done
