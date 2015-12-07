#!/usr/bin/perl -w
use strict;
use warnings;

print "Please type a floating point number : ";
my $float_num = <>;
chomp ($float_num);
print "rounded floating point number is : ";
printf("%.2f\n", $float_num);
