<?php
$basename="all.txt";
$fp=fopen($basename, 'rt') or die ("error opening file:". mysql_error());
$allfiles=array();
while(($line=fgets($fp))!=false)
{
    $line=rtrim($line);
    if(!(strstr($line, ".svn")|| strstr($line, "svn-base")))
    {
        if(!preg_match('{^(.*)/([^/]+)$}', $line, $matches))
        {
            continue;
        }
        $dirname=$matches[1];
        $basename=$matches[2];
        if(!array_key_exists($dirname, $allfiles))
        {
            $allfiles[$dirname]=array();
        }
        array_push($allfiles[$dirname], $basename);
    }
}
print_r($allfiles);
?>
