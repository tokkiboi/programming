#Problem A16
#Write a program that, given a floating-point number, prints the number rounded to two digits.
#For example. 14.334 will be rounded to 14.33 but 14.336 will be rounded to 14.34.

print "Input a floating-point value:\t";
$x = <stdin>;
$rnd = sprintf("%.2f", $x);
print "$rnd\n";

## Output #1
#Input a floating-point value:   14.334
#14.33
#Press any key to continue . . .
## END

## Output #2
#Input a floating-point value:   14.336
#14.34
#Press any key to continue . . .
## END #2