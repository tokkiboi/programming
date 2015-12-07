<html>
<body>

You Clicked
<?php 
$clickCounter=0;
$myFile="clickCounterFile.txt";
$fp=fopen($myFile, 'r') or die ("Cant open file");
$clickCounter=fgets($fp);
$clickCounter = rtrim($clickCounter);
$clickCounter=str_replace("\n", "", $clickCounter);
fclose($fp);
$fp=fopen($myFile, 'w') or die ("Cant open file");
$clickCounter++;
fwrite($fp, $clickCounter);
fclose($fp);
$fp=fopen($myFile, 'r') or die ("Cant open file");
$totalClick=fgets($fp);
fclose($fp);
echo $totalClick;
?> times.
</body>
</html>
