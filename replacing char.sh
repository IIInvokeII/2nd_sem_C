#Program to replace a character in a string
#taking input
echo "Enter a string: "
read a
echo "Enter character to be replaced: "
read c
echo "Enter new character: "
read n
#replacing character
a=${a//$c/$n}
echo $a
