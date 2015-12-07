<?php
/*
Look in data.txt file. It's a list of files and directories that look like this:

R  +    esp-shared/usr.sbin/chassism/fx-xre/Makefile.depend.i386
R  +    pan-release/shared/jnx/acc_cntl_gencfg_blob_tags.h
R  +    pan-release/shared/jnx/jdhcp_gencfg_tags.h
R  +    pan-release/shared/jnx/acc_cntl_shared_pan.h
R  +    pan-release/shared/jnx/ipc_acc_cntl_pan.h
R  +    vendor/bcm-sdk-code/bmacsec/
R  +    vendor/bcm-sdk-code/bmacsec/phy
R  +    vendor/bcm-sdk-code/bmacsec/phy/bcm84756
R  +    vendor/bcm-sdk-code/bmacsec/phy/bcm84756/bcm84756_ucode.c
R  +    vendor/bcm-sdk-code/bmacsec/phy/bcm84756/bcm84756.c
R  +    vendor/bcm-sdk-code/bmacsec/phy/mac/Makefile
R  +    esp-shared/usr.sbin/exdiag/common/dim/Makefile.depend.i386
R  +    esp-shared/usr.sbin/exdiag/common/driver/device/Makefile.depend.i386
R  +    esp-shared/usr.sbin/exdiag/common/driver/device/gp_ucd90xx.c
R  +    vendor/bcm-sdk-code/bmacsec/phy/bcm84756/phy84756.h


First 8 characters of the lines you don't want. Filenames start after the first 8
characters. If you look closely, some lines are directories and some lines are files.
The goal is to find the minimum set of 'svn add' commands that can add everything
in this list.

As you know, if you do 'svn add some-directory' then everything under some directory
gets added to subversion repository. So you don't need to do
'svn add some-directory/a.txt' to add a.txt separately.

Likewise, it will be enough if you did 'svn add vendor/bcm-sdk-code/bmacsec'. Then you
won't have to do 'svn add vendor/bcm-sdk-code/bmacsec/phy/bcm84756/bcm84756_ucode.c'.

So, I want you to scan the files and print out the minimal set of things needed
to add the entire list to subversion repository.

For this example case, the list will be this:

esp-shared/usr.sbin/chassism/fx-xre/Makefile.depend.i386
esp-shared/usr.sbin/exdiag/common/dim/Makefile.depend.i386
esp-shared/usr.sbin/exdiag/common/driver/device/Makefile.depend.i386
esp-shared/usr.sbin/exdiag/common/driver/device/gp_ucd90xx.c
pan-release/shared/jnx/acc_cntl_gencfg_blob_tags.h
pan-release/shared/jnx/acc_cntl_shared_pan.h
pan-release/shared/jnx/ipc_acc_cntl_pan.h
pan-release/shared/jnx/jdhcp_gencfg_tags.h
vendor/bcm-sdk-code/bmacsec

Write a program to print this minimal list on the screen.

*/
$myfile = "data.txt";
$fp=fopen($myfile, 'rt') or die ("Cannot open file to read : $myfile\n");
$lines = array();
while(!feof($fp))
{
    $line = fgets($fp);
    $line = preg_replace('{^........}', '', $line);
    $line = preg_replace('{\n$}s', '', $line);
    $line = preg_replace('{/$}', '', $line);
    $line = preg_replace('{/+}', '/', $line);
    if ($line == '')
    {
        continue;
    }
    $lines[$line] = 1;
}

foreach(array_keys($lines) as $line)
{
    $explode = explode("/", $line);
    array_pop($explode);
    $parents = array();
    $filename = "";
    foreach($explode as $value)
    {
        $filename = $filename.$value;
        array_push($parents, $filename);
        $filename .= '/';
    }
    # esp-shared/usr.sbin/chassism/fx-xre/Makefile.depend.i386
    # =>
    # esp-shared/usr.sbin/chassism/fx-xre
    # esp-shared/usr.sbin/chassism
    # esp-shared/usr.sbin
    # esp-shared

    $parent_is_not_there = 1;
    foreach($parents as $parent)
    {
        if(array_key_exists($parent, $lines))
        {
            $parent_is_not_there = 0;
            break;
        }
    }

    if ($parent_is_not_there == 1)
    {
        echo "$line\n";
    }
}
?>
