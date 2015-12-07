#!/use/bin/perl -w
use strict;
use warnings;

print "Please type the string (1 12 a 2 5 P Q) : ";
my $input = <>;
chomp($input);
my @split_input = split(/\s+/, $input);
my $sum = 0;
foreach my $val (@split_input)
{
    if ($val =~ /^q$/i)
    {
        last;
    }

    if ( $val =~ m/^\d+$/ && 1 <= $val && $val <=20 )
    {
        if ($sum == 0)  # First time printing
        {
            print "$val";
        }
        else {
            print "+$val";
        }
        $sum += $val;
    }
}
if ($sum == 0)
{
    print "No valid number was entered\n";
}
else
{
    print "=$sum\n";
}

