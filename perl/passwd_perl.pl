#<?php
#
#/*
#Look in /etc/passwd file. It looks like this.
#
#root:x:0:0:root:/root:/bin/bash
#bin:x:1:1:bin:/bin:/sbin/nologin
#daemon:x:2:2:daemon:/sbin:/sbin/nologin
#adm:x:3:4:adm:/var/adm:/sbin/nologin
#lp:x:4:7:lp:/var/spool/lpd:/sbin/nologin
#sync:x:5:0:sync:/sbin:/bin/sync
#shutdown:x:6:0:shutdown:/sbin:/sbin/shutdown
#halt:x:7:0:halt:/sbin:/sbin/halt
#mail:x:8:12:mail:/var/spool/mail:/sbin/nologin
#news:x:9:13:news:/etc/news:
#
#I want you to print out the content in this format
#
#User     |Home directory  |Login shell
#---------+----------------+--------------------
#root     |/root           |/bin/bash
#bin      |/bin            |/sbin/nologin
#daemon   |/sbin           |/sbin/nologin
#adm      |/var/adm        |/sbin/nologin
#lp       |/var/spool/lpd  |/sbin/nologin
#sync     |/sbin           |/bin/sync
#shutdown |/sbin           |/sbin/shutdown
#halt     |/sbin           |/sbin/halt
#mail     |/var/spool/mail |/sbin/nologin
#news     |/etc/news       |
#---------+----------------+--------------------
#*/
#
$myfile="/etc/passwd";
#$fp=fopen($myfile, 'rt') or die ("cannot open file for read: $myfile\n");
open(F, "<$myfile") or die "Cannot open file\n";
#$user = array();
#$home_directory = array();
#$login_shell = array();
#$user_length =           strlen('User');
 $user_length = length('User')   ;
#$home_directory_length = strlen('Home Directory');
 $home_directory_length = length('Home Directory');
#$login_shell_length =    strlen('Login Shell');
 $login_shell_length = length('Login Shell');
#while($line = fgets($fp))
while($line=<F>)
{
#    $line = rtrim($line);
     chomp($line);
#    # root:x:0:0:root:/root:/bin/bash
#    $split_line = preg_split('{:}', $line);
     @split_line = split(m{:}, $line);     
#    # [0] => root
#    # [1] => x
#    # [2] => 0
#    # [3] => 0
#    # [4] => root
#    # [5] => /root
#    # [6] => /bin/bash
#    array_push($user, $split_line[0]);
     push(@user, @split_line[0]);
#    array_push($home_directory, $split_line[5]);
     push(@home_directory, @split_line[5]);
#    array_push($login_shell, $split_line[6]);
     push(@login_shell, @split_line[6]);
#
#    $len = strlen($split_line[0]);
#    if($len > $user_length) {
#        $user_length = $len;
#    }
#    $len = strlen($split_line[5]);
#    if($len > $home_directory_length) {
#        $home_directory_length = $len;
#    }
#    $len = strlen($split_line[6]);
#    if($len > $login_shell_length) {
#        $login_shell_length = $len;
#    }
#}
     $len = length(@split_line[0]);
     if($len > $user_length) {
         $user_length = $len;
     }
    $len = length(@split_line[5]);
    if($len > $home_directory_length) {
        $home_directory_length = $len;
    }
    $len = length(@split_line[6]);
    if($len > $login_shell_length) {
        $login_shell_length = $len;
    }
 }   
#$user_length++;
#$home_directory_length++;
#$login_shell_length++;
    $user_length++;
    $home_directory_length++;
    $login_shell_length++;
    
#
#echo str_pad('User', $user_length, ' ')
#   . '|'
#   . str_pad('Home Directory', $home_directory_length, ' ')
#   . '|'
#   . str_pad('Login Shell', $login_shell_length, ' ')
#   . "\n"
#   ;
#
#$dashline = str_pad('', $user_length, '-').'+'.str_pad('', $home_directory_length, '-' ).'+'.str_pad('', $login_shell_length, '-')."\n";
#
#echo $dashline;
 print 'User'. ' ' x ($user_length-length('user')).'|'.'Home Directory'. ' ' x ($home_directory_length-length('Home Directory')).'|'.'Login Shell'.' ' x ($login_shell_length-length('Login Shell'))."\n";
 $dashline = '-' x $user_length.'+'.'-' x $home_directory_length.'+'.'-' x $login_shell_length."\n";
 print $dashline;
 
#for($x=0;$x<count($user);$x++)
#{
#    echo str_pad($user[$x], $user_length, " ") . '|'
#       . str_pad($home_directory[$x], $home_directory_length, " ") . '|'
#       . str_pad($login_shell[$x], $login_shell_length, " ") . "\n";
#}
 for($x=0;$x< scalar(@user);$x++ )
 {
     print $user[$x].' 'x($user_length-length(@user[$x])).'|'.@home_directory[$x].' 'x($home_directory_length-length(@home_directory[$x])).'|'.@login_shell[$x].' 'x($login_shell_length-length(@login_shell[$x]))."\n";

 }

#echo $dashline;
 print $dashline;
#
#?>
#
#
#
