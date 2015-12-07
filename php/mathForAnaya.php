<html>
<body>
<table border='1'>
<tr><th></th><th>total</th></tr>
<?php
$min1=0;
$min2=10;
$max1=9;
$max2=99;
for($i=0;$i<100;$i++)
{
    $num1[$i]=rand($min1, $max2);
    $num2[$i]=rand($min1, $max2);
    if($num1[$i]>10)
    {
        $num2[$i]=rand($min1, $max1);
    }
    if($num2[$i]>10)
    {
        $num1[$i]=rand($min1, $max1);
    }
    echo "<tr><td>$num1[$i]  +  $num2[$i]  =  </td><td></td></tr>";
}
//$add=$num1+$num2;
?>
</table>
</body>
</html>
