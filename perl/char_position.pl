#!/use/bin/perl -w
use strict;
use warnings;

print 'Please type a string : ';
my $string = <>;
chomp($string);
my $char = 'E';
my $offset = 0;
my $result = index($string, $char, $offset);

while($result != -1)
{
    print "Found $char at $result\n";
    $offset = $result+1;
    $result = index($string, $char, $offset);
    
}

