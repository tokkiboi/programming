#Problem A13
#Write a program that has a long string given.
#Assignment A
#http://voyager.deanza.edu/~oldham/cis33a-Perl/assignments/assignmentA.html[10/8/2015 7:11:55 PM]
#The program extracts the first five characters and the last five characters. and prints the results.
#Test the program with the data: 

$string = 'elephants eat a large quantity of food';
$first_five = $string;
$first_five =~ s/(^.{5}).*$/$1/;
$last_five = substr($string,-5);

print "\USTRING\E:\t$string\n\n";
print "\ufirst 5 charaters in the string are \n\U$first_five\E\n";
print "\ulast 5 characters in the string are \n\U$last_five\E\n";


## Output of the file
#STRING: elephants eat a large quantity of food
#
#First 5 charaters in the string are
#ELEPH
#Last 5 characters in the string are
# FOOD
#Press any key to continue . . .
##