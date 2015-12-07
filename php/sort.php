<?php
$array=array(
    "0"=> "5",
    "1"=> "0",
    "2"=> "6",
    "3"=> "3",
);
print_r($array);
$count=count($array);
print_r("Total no of element in that array is :".$count."\n");
for($i=0;$i<$count-1;$i++)
{
    $smallest=$i;
    for($j=$i;$j<$count;$j++)
    {
        if($array[$j]<$array[$smallest])
        {
            $smallest=$j;
        }
    }
    $temp=$array[$i];
    $array[$i]=$array[$smallest];
    $array[$smallest]=$temp;
}
print_r($array);

?>


