<?php
//open file
$myfile="lab1.txt";
$fp=fopen($myfile, 'rt') or die("cannot open file");
//count total line in file
$line_count=count(file($myfile));
print("total line in the file is :".$line_count."\n");
//reading first line and delete new line character
$total_questions=fgets($fp);
$total_questions=rtrim($total_questions);
print($total_questions."\n");
//reading second line and delete new line character and split string in new array
$right_answers=fgets($fp);
$right_answers=rtrim($right_answers);
print($right_answers."\n");
$right_answers_each=str_split($right_answers);
print("Print array after spilt\n");
print_r($right_answers_each);
//reading rest of the file as a string
for($i=0;$i<$line_count-2;$i++)
{
      $student_pin_answer[$i]=fgets($fp);
      //$student_pin_answer[$i]=rtrim($student_pin_answer);
    
}
print_r($student_pin_answer);
//exploding string in 2 arrays - pin and answer
for($i=0;$i<$line_count-2;$i++)
{
        $result=$student_pin_answer[$i];
        $student_pinAndAnswer=explode(" ",$result);
        print_r($student_pinAndAnswer);
        $student_pin[$i]=$student_pinAndAnswer[0];
        $student_answer[$i]=$student_pinAndAnswer[1];
}
print("Print after explode\n");
for($i=0;$i<$line_count-2;$i++)
{
    print("student pin is : ". $student_pin[$i]." student answer is: ".$student_answer[$i]."\n");
}    
//split answer for each student(string) in array 
for($i=0;$i<$line_count-2;$i++)
{
     $result=$student_answer[$i];
     $result=rtrim($result);
     $student_each_answers=str_split($result);
     print_r($student_each_answers);
     for($j=0;$j<$total_questions;$j++)
     {
      $studentAnswer[$i][$j]=$student_each_answers[$j];
     }

}
//calculating right answer for each student by comparing two arrays
for($j=0;$j<$line_count-2;$j++)
{
    $right_answer_count=0;
    for($i=0;$i<$total_questions;$i++)
    {
        if($studentAnswer[$j][$i]==$right_answers_each[$i])
        {
            $right_answer_count=$right_answer_count+1;
        }
    }
    $total_right_answer[$j]=$right_answer_count;
}    
for($j=0;$j<$line_count-2;$j++)
{
        print("Total right answer for ".$student_pin[$j]." is ".$total_right_answer[$j]."\n");
}    

?>
