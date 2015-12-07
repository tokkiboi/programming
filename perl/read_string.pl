#!/usr/bin/perl -w
print 'Please type a string : ';
$string=<>;
$str_length=length($string);
print $string x $str_length."\n" ;
