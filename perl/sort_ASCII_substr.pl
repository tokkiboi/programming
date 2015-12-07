#!/usr/bin/perl -w
use strict;
use warnings;

print "Please type first string : ";
my $string1 = <>;
chomp($string1);
print "Please type second string : ";
my $string2 = <>;
chomp($string2);
print "Please type third string : ";
my $string3 = <>;
chomp($string3);
my $i;
my $ascii_value_string1 = 0;
for($i=0;$i<length($string1);$i++)
{
    $ascii_value_string1=$ascii_value_string1 + ord(substr $string1, $i);
}
print "Ascii value for 1st string is : ".$ascii_value_string1."\n";
my $ascii_value_string2 = 0;
for($i=0;$i<length($string2);$i++)
{
    $ascii_value_string2=$ascii_value_string2 + ord(substr $string2, $i);
}
print "Ascii value for 2nd string is : ".$ascii_value_string2."\n";
my $ascii_value_string3 = 0;
for($i=0;$i<length($string3);$i++)
{
    $ascii_value_string3=$ascii_value_string3 + ord(substr $string3, $i);
}
print "Ascii value for 3rd string is : ".$ascii_value_string3."\n";
my @string = ($string1, $string2, $string3);
my @sorted_string = sort @string;
print "\nsorted strings are\n";
print join "\n",@sorted_string;
print "\n";
