#!/usr/bin/perl -w
use strict;
use warnings;

open FILE, "<input.txt" or die; #open the file for reading
my $record_separator = $/;
undef $/;              # This is Perl's record separator variable
                       # $scalar = <FILEPOINTTER> operation reads only
                       # till it finds $/. Usually value of $/ is \n.
                       # Now, if we throw away $/, perl won't know where
                       # to stop reading from FILEPOINTER. So it will read
                       # as much as it can, which is till end of file.
my $text = <FILE>;
$/ = $record_separator; # We don't need to mess with record separator
                        # any more. So, restoring it's value.

$text =~ tr/a-z/A-Z/;
my @characters = split(//, $text);
#print join "\n", @characters;

my %counts = ();

foreach my $c (@characters)
{
    $counts{$c} += 1;
}

foreach my $c ('A'..'Z')
{
    print "$c : ".$counts{$c}."\n";
}

