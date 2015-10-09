##PROBLEM A10:
print "input numerical value as a decimal:\t";
$num1 = <stdin>,;
chomp ($num1);
print "input numerical value as a octal number (without leading 0):\t";
$num2 = <stdin>;
chomp ($num2);
print "input numerical value as a hexadecimal number (without leading 0x):\t";
$num3 = <stdin>;
chomp ($num3);
$num2 = oct($num2) if $num2 =~ /^0/; # catches 077 0b10 0x20
$num3 = hex($num3) if $num3 =~ /^0x/; # catches 077 0b10 0x20
print "\n\nThe input values are\n $num1\t $num2\t $num3\n";
print "\nDecimal value:\t Octal Value\t Hex Value";
printf "\n%#d", ($num1);
printf "\n%#d\t\t %#o\t\t",($num2)x2;
printf "\n%#d\t\t\t\t %#x\n",($num3)x2;

## Output
#input numerical value as a decimal:     1234
#input numerical value as a octal number (without leading 0):    123
#input numerical value as a hexadecimal number (without leading 0x):     12


#The input values are
# 1234    123     12

#Decimal value:   Octal Value     Hex Value
#1234
#123              0173
#12                               0xc
#Press any key to continue . . .
##