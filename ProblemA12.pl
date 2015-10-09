#Problem A12
#Write a program that has a long string given which contains at least three 'e'
#The program finds the positions of the first, second, and third "e" in the string and prints the results.
#Test the program with the data:

$string = 'elephants eat a large quantity of food';
$char = 'e';
$offset = 0;
$position = index($string, $char,$offset);
$second = $position + 1;
$third = $second + 1;
print "$string\n";
while ($position != -1 && $position <= 10) {
print "Found the character \u$char at $position\n";
$offset = $position + 1;
$position = index($string, $char, $offset);
};

## Output of the file
#elephants eat a large quantity of food
#Found the character E at 0
#Found the character E at 2
#Found the character E at 10
#Press any key to continue . . .
##