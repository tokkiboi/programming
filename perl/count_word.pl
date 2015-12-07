# <?php
$myfile = "paragraph_perl.txt";
# $fp=fopen($myfile, "rt") or die("cannot open file");
open(F, "<$myfile") or die "Cannot open file $myfile for reading\n";
$total_count = 0;
# while(($line=fgets($fp))!=false)
while ($line = <F>)
{
    print($line);
#     $line=rtrim($line);
    chomp($line);
#     $count=preg_match_all('{\bhappy\b}im',$line, $match);
    @matches = $line =~ m{\bhappy\b}ig;
    $count = scalar @matches;
    print($count."\n");
#     print_r($match);
    $total_count = $total_count+$count;
}
print "Happy occurs in the paragraph : ".$total_count." times.\n";
# ?>
