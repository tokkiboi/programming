#!/use/bin/perl -w
use strict;
use warnings;
use Data::Dumper;

my @list1 = (1, 2, 3, 4, 5, 6, 7, 8, 9);
my @list2 = (3, 5, 7, 11, 13, 15);

my %list2hash = ();

foreach my $i (@list2)
{
    $list2hash{$i} = 1;
}
print Dumper(\%list2hash);

my @newarray = ();

foreach my $i (@list1)
{
    if (!exists $list2hash{$i})
    {
        push @newarray, $i;
    }
}

#print Dumper(\@newarray);
print join ' ', @newarray;
print "\n";
