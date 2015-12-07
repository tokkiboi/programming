<html>
<body>
<form action="clickCountFromDataBase.php" method="post">
<input type="submit"> You clicked
<?php
$count=0;
//php connect to mysql
$con=mysql_connect("localhost", "root", "mangoo");
if(!$con)
{
    die('could not connect :'.mysql_error());
}
$result=mysql_select_db("click", $con);
if(!$result)
{
    die(mysql_error());
}
$result=mysql_query("SELECT count FROM clickCounter");
if(!$result)
{
    die(mysql_error());
}
$row=mysql_fetch_array($result);
$c=$row['count'];
$c++;
$result=mysql_query("UPDATE clickCounter SET count=$c WHERE 1");
if(!$result)
{
    die(mysql_error());
}
print($c);




mysql_close($con);

?> times
</form>
</body>
</html>
