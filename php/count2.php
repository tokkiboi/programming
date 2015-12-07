<html>
<body> 
<form action="count2.php" method="post">
<input type="submit"> 
</form>
<?php
$click_count=0;
$myFile="clickCounter.txt";
$fp=fopen($myFile, 'r') or die ("unable to open $myFile for reading\n");
$click_count=fgets($fp);
$click_count=rtrim($click_count);
fclose($fp);
$fp=fopen($myFile, 'w')or die ("unable to open in write mode");
$click_count++;
fwrite($fp, $click_count);
fclose($fp);
$fp=fopen($myFile, 'r') or die ("unable to open in read mode");
$click_count=fgets($fp);
?> 
You clicked <?php echo $click_count; ?> times
</body>
</html>
