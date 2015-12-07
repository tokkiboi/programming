#!/usr/bin/perl -w
#use strict;
#use warnings;

print 'Please type a string : ';
my $string = <>;
chomp($string);
my $string_length = length($string);
$string_length = ($string_length - 5);
my $first_five = substr($string, 0, 5);
my $last_five = substr($string, ($string_length), 5);
print "First five characters are : $first_five\n";
print "Last five characyers are : $last_five\n";
