$myfile="paragraph_perl.txt";
open(F, "<$myfile") or die "cannot open file";
$total_count = 0;
while($line=<F>)
{
    print ($line);
    chomp($line);
    @matches = $line =~ m{\bhappy\b}ig;
    $count = scalar @matches;
    print $count."\n";
    $total_count = $total_count+$count;
}
 print "happy repeates: ". $total_count." times.\n";
