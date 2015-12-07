<html>
<body>
<pre>
<?php

$good_or_bad = $_GET['good_or_bad'];
$hash = $_GET['hash'];
preg_match('{(..)$}', $hash, $matches);
$dir = $matches[1];

umask(0);
$rootdir = './db_goodfiles';
if ($good_or_bad == 'good') {
    if (!file_exists("$rootdir/$dir")) {
        mkdir("$rootdir/$dir", 0777, true);
    }
    touch("$rootdir/$dir/$hash");
}
else {
    if (file_exists("$rootdir/$dir/$hash")) {
        unlink("$rootdir/$dir/$hash");
        $dir_entries = glob("$rootdir/$dir/*");
        if (count($dir_entries) == 0) {
            rmdir("$rootdir/$dir");
        }
    }
}
?>
</pre>
</body>
</html>
