<html>
<body>
<form action="count_click.php" method="post">
<input type="Submit"> You Clicked
<?php
$count=0;
//connect database
$con=mysql_connect("localhost", "root", "mangoo");
if(!$con)
{   
    die("not able to connect: ".mysql_error());
}
//select database 
$result=mysql_select_db("click", $con);
if(!$result)
{   
    die("Cannot select database click: ".mysql_error());
}
$result=mysql_query("SELECT count FROM clickCounter");
if(!$result)
{   
    die("Cannot select count from clickCounter: ".mysql_error());
}
$row=mysql_fetch_array($result);
if(!$row)
{   
    die("Cannot fetch array:".mysql_error());
}
$c=$row['count'];
$c++;
$result=mysql_query("UPDATE clickCounter SET count=$c WHERE 1");
if(!$result)
{   
    die("Cannot update query:".mysql_error());
}
print $c;
mysql_close($con);

?> times
</form>
</body>
</html>
