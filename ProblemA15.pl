#Problem A15
#Write a program that, given an integer between 1 and 12, prints the corresponding month of the year
#(January, February, ...).

print "Please enter numeric value of a month of the year:\t";
$monthInt = <stdin>;
if ( $monthInt == 1){print "January\n"}
elsif ( $monthInt == 2){print "February\n"}
elsif ( $monthInt == 3){print "March\n"}
elsif ( $monthInt == 4){print "April\n"}
elsif ( $monthInt == 5){print "May\n"}
elsif ( $monthInt == 6){print "June\n"}
elsif ( $monthInt == 7){print "July\n"}
elsif ( $monthInt == 8){print "August\n"}
elsif ( $monthInt == 9){print "September\n"}
elsif ( $monthInt == 10){print "October\n"}
elsif ( $monthInt == 11){print "November\n"}
elsif ( $monthInt == 12){print "December\n"}
## Output $monthInt = 1
#Please enter numeric value of a month of the year:      1
#January
#Press any key to continue . . .

## Output $monthInt = 6
#Please enter numeric value of a month of the year:      6
#June
#Press any key to continue . . .

## Output $monthInt = 12
#Please enter numeric value of a month of the year:      12
#December
#Press any key to continue . . .