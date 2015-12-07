<?php
$myfile="all.txt";
$fp=fopen("$myfile", 'rt') or die ("error opening file : ".mysql_error());
$allfiles=array();
while(($line=fgets($fp))!=false)
{
    $line=rtrim($line);

    if (!preg_match('{\.([^/\.]+)$}', $line, $matches))
    {
        continue;
    }
    if ($matches[1] == 'svn' || $matches[1] == 'svn-base')
    {
        continue;
    }
    $filetype = $matches[1];


    if(!array_key_exists($filetype, $allfiles))
    {
        $allfiles[$filetype]=array();
    }
    array_push($allfiles[$filetype],$line );

}
print_r($allfiles);
?>
