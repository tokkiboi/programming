<?php
$myfile="num.txt";
$fp=fopen($myfile, "rt") or die ("error opening file". mysql_error());
while(($line=fgets($fp))!=false)
{
    $line=rtrim($line);
    preg_match('{(.{6})$}', "000000$line", $match);
    $sixdigit=$match[1];
    print($sixdigit."\n");
}
?>
