#!/usr/bin/perl -w
print 'Please type decimal number as first number : ';
$userInput_decimal=<>;
chomp($userInput_decimal);
$userInput_decimal=$userInput_decimal+0;
print 'please type octal number as second number : ';
$userInput_octal=<>;
chomp($userInput_octal);
$userInput_octal=oct($userInput_octal);
print 'please type hexadecimal number as third number : ';
$userInput_hexadecimal=<>;
chomp($userInput_hexadecimal);
$userInput_hexadecimal=hex($userInput_hexadecimal);
print "Decimal value for the first number is : $userInput_decimal\n";
print "Decimal value for the second number is : $userInput_octal\n";
print "Decimal value for the third number is : $userInput_hexadecimal\n";

