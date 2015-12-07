<html>
<body>
<table border='1'>
<?php

/*
Look in /etc/passwd file. It looks like this.

root:x:0:0:root:/root:/bin/bash
bin:x:1:1:bin:/bin:/sbin/nologin
daemon:x:2:2:daemon:/sbin:/sbin/nologin
adm:x:3:4:adm:/var/adm:/sbin/nologin
lp:x:4:7:lp:/var/spool/lpd:/sbin/nologin
sync:x:5:0:sync:/sbin:/bin/sync
shutdown:x:6:0:shutdown:/sbin:/sbin/shutdown
halt:x:7:0:halt:/sbin:/sbin/halt
mail:x:8:12:mail:/var/spool/mail:/sbin/nologin
news:x:9:13:news:/etc/news:

I want you to print out the content in this format

User     |Home directory  |Login shell
---------+----------------+--------------------
root     |/root           |/bin/bash
bin      |/bin            |/sbin/nologin
daemon   |/sbin           |/sbin/nologin
adm      |/var/adm        |/sbin/nologin
lp       |/var/spool/lpd  |/sbin/nologin
sync     |/sbin           |/bin/sync
shutdown |/sbin           |/sbin/shutdown
halt     |/sbin           |/sbin/halt
mail     |/var/spool/mail |/sbin/nologin
news     |/etc/news       |
---------+----------------+--------------------
*/

$myfile="/etc/passwd";
$fp=fopen($myfile, 'rt') or die ("cannot open file for read: $myfile\n");
echo "<tr><th>User</th><th>Home Directory</th><th>Login Shell</th></tr>";
while(($line=rtrim(fgets($fp)))!=false)
{
    # root:x:0:0:root:/root:/bin/bash
    $split_line = preg_split('{:}', $line);
    # [0] => root
    # [1] => x
    # [2] => 0
    # [3] => 0
    # [4] => root
    # [5] => /root
    # [6] => /bin/bash
    $user=$split_line[0];
    $home_directory=$split_line[5];
    $login_shell=$split_line[6];
    echo "<tr><td>$user</td><td>$home_directory</td><td>$login_shell</td></tr>";
}
?>
</table>
</body>
</table>
