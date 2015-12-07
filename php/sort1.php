<?php
$array=array(
    "0"=> "5",
    "1"=> "0",
    "2"=> "6",
    "3"=> "3",
);
print_r($array);
mysort($array);
print("Printing array after function call\n");
print_r($array);

//============================================================
function mysort(&$array)
{
    $count = count($array);
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
}
//=========================================================================

?>


