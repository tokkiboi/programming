#!/usr/bin/perl -w
use warnings;
use strict; 

print 'Print first string : ';
my $string1 = <>;
chomp($string1);
print 'Print second string : ';
my $string2 = <>;
chomp($string2);
print 'Print third string : ';
my $string3 = <>;
chomp($string3);
my @ascii_char_num1 = unpack("C*", $string1);
my @ascii_char_num2 = unpack("C*", $string2);
my @ascii_char_num3 = unpack("C*", $string3);
my $sum1=0;
my $sum2=0;
my $sum3=0;
my $i;
for($i=0;$i<scalar @ascii_char_num1;$i++)
{
 $sum1 = $sum1+ $ascii_char_num1[$i];
}
print "sum of ascii character for string 1 is : ".$sum1."\n";
for($i=0;$i<scalar @ascii_char_num2;$i++)
{
 $sum2 = $sum2+ $ascii_char_num2[$i];
}
print "sum of ascii character for string 2 is : ".$sum2."\n";
for($i=0;$i<scalar @ascii_char_num3;$i++)
{
 $sum3 = $sum3+ $ascii_char_num3[$i];
}
print "sum of ascii character for string 3 is : ".$sum3."\n";
my @string = ($string1, $string2, $string3);
my @sorted_strings = sort @string;
print "\n Strings correctly sorted\n";
print join "\n", @sorted_strings;
print "\n";
my $shortest_string = $sorted_strings[0];
print "Shortest string is : ".$shortest_string;
print "\n";

