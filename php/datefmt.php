<?php
/*
Run the date command from php
(you will need system or exec or similar php function)

The output will look like this
Thu Dec 27 13:27:37 PST 2012


reformat that and print it out in this format
2012-12-27 13:27:37

*/
$date=exec('date');
#Thu Dec 27 15:53:17 PST 2012
print("\n");
preg_match("{^([^\s]+)\s+([^\s]+)\s+([^\s]+)\s+([^\s]+)\s+([^\s]+)\s+([^\s]+)$}", $date, $matches);
#    [0] => Thu Dec 27 16:15:26 PST 2012
#    [1] => Thu
#    [2] => Dec
#    [3] => 27
#    [4] => 16:15:26
#    [5] => PST
#    [6] => 2012

$month=$matches[2];
switch($month)
            {
            case "Jan" : $m= "01"; break;
            case "Feb" : $m= "02"; break;
            case "Mar" : $m= "03"; break;
            case "Apr" : $m= "04"; break;
            case "May" : $m= "05"; break;
            case "Jun" : $m= "06"; break;
            case "Jul" : $m= "07"; break;
            case "Aug" : $m= "08"; break;
            case "Sep" : $m= "09"; break;
            case "Oct" : $m= "10"; break;
            case "Nov" : $m= "11"; break;
            case "Dec" : $m= "12"; break;
           }

$formated_date=$matches[6]."-".$m."-".$matches[3]." ".$matches[4];
print($formated_date."\n");
?>
