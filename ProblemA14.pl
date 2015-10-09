#Problem A14
#Write a program that, given three strings, uses string comparisons to select and print the smallest in ASCII
#sort order. Do not use the sort function.
$string1=<stdin>;
$string2=<stdin>;
$string3=<stdin>;
$string1=~s/(.)/ord($1)/eg;
$string2=~s/(.)/ord($1)/eg;
$string3=~s/(.)/ord($1)/eg;
print "Ascii 1: $string1\n";
print "Ascii 2: $string2\n";
print "Ascii 3: $string3\n";

if ($string1 >= $string2 && $string1 >= $string3){$string1==$highest}
elsif ($string1 <= $string2 && $string1 <= $string3){$string1 == $lowest}
elsif (($string1 >= $string2 && $string1 <= $string3) || ($string1 >= $string3 && $string1 <= $string2)){$string1 == $middle};
$lowest=~s/(.)/chr($1)/eg;
$middle=~s/(.)/chr($1)/eg;
$highest=~s/(.)/chr($1)/eg;
print "$lowest\t$middle\t$highest\n";


