<?php

/*
Both integer and string types are allowed in subscripts 
since arrays are types of maps in PHP.
*/
echo "Question 1". PHP_EOL;

$keyedArray = array(
    "Ahmet" => "first",
    "Ata" => "second",
    "Can" => "third",
    "Alp" => "fourth",
    "Ayda" => "fifth",
);
echo "keyedArray: ". PHP_EOL;
print_r($keyedArray);
echo PHP_EOL;
$noKeyedArray = array("zero","one", "two", "three", "four");
echo "noKeyedArray: ". PHP_EOL;
print_r($noKeyedArray);

echo "Some elements of the noKeyedArray:". PHP_EOL;
echo $noKeyedArray[0]. PHP_EOL;
echo $noKeyedArray[1]. PHP_EOL;
echo $noKeyedArray[2]. PHP_EOL;
echo PHP_EOL;

echo "Some elements of the keyedArray: ". PHP_EOL;
echo $keyedArray["Ahmet"]. PHP_EOL;
echo $keyedArray["Ata"]. PHP_EOL;
echo PHP_EOL;
echo "For keyed arrays, string (and integer if assigned as key) subscripts are legal but only integer subscripts are legal at no-keyed arrays.". PHP_EOL;
echo PHP_EOL;

echo "Question 2". PHP_EOL;
echo "Code segment in the comments gives a syntax error since PHP checks ranges of arrays." .PHP_EOL;
echo PHP_EOL;
/*
Following code segment gives a syntax error since PHP checks ranges of arrays.
echo $noKeyedArray[8]. PHP_EOL;
*/

echo "Question 3 and 4". PHP_EOL;
/*
Ranges of arrays and allocation in PHP are bound at 
run time because ranges can be changed and new data can be
allocated at run time.
*/
echo "Manipulation in keyedArray and noKeyedArray:";
$keyedArray[5] = "sixth";
$noKeyedArray[5] = "six";
echo "New element added to keyedArray: ";
echo $keyedArray[5] . PHP_EOL;
echo "New element added to noKeyedArray: ";
echo $noKeyedArray[5] . PHP_EOL;
echo PHP_EOL;

echo "Dynamic array implementation:". PHP_EOL;
$dynamicArray = array();
echo "Size can be increased with every append:". PHP_EOL;
for($i = 0; $i < 5; $i++)
{
    $dynamicArray[$i] = $i;
    echo "Size: ", count($dynamicArray). PHP_EOL;
    echo $dynamicArray[$i]. PHP_EOL;
}
echo PHP_EOL;

echo "Question 5". PHP_EOL;
//Rectangle multidimensional arrays are supported by PHP.
//They are implemented and tested by following code segments.
$multiRecArray = array (
    array("Ahmet",16,1),
    array("Ata",19,6),
    array("Derin",21,5),
    array("Seren",20,20)
);
echo "Rectangle 2d array:". PHP_EOL;
print_r($multiRecArray);

//Ragged multidimensional arrays are supported by PHP.
//They are implemented and tested by following code segments.

$multiJagArray = array (
    array("Ahmet",16,1,2,3,4,5),
    array("Ata",19,6,3),
    array("Derin"),
    array("Seren",20)
);

/*
It is a ragged array because arrays in the $multiJagArray
have different sizes. Because of this, code segment below doesn't work
and commented.
echo $multiJagArray[1][9];
*/
echo "Ragged 2d array:". PHP_EOL;
print_r($multiJagArray);
echo PHP_EOL;

echo "Question 6 (arrays declared in first question answers this question because array is both declared and initialized at the same time)".PHP_EOL;
echo PHP_EOL;

echo "Question 7". PHP_EOL;
echo "Some slices of the array: ";
print_r($noKeyedArray);
echo PHP_EOL;
//Slices are supported by PHP. Slice types are elaborated on the report.
print_r(array_slice($noKeyedArray,2));
print_r(array_slice($noKeyedArray,-3));
print_r(array_slice($noKeyedArray,1,2));
print_r(array_slice($noKeyedArray,-2,2));
print_r(array_slice($noKeyedArray,2,2,true));
print_r(array_slice($noKeyedArray,2,2,false));
echo PHP_EOL;

echo "Question 8". PHP_EOL;
echo "Operators for arrays are tested by some code segments.". PHP_EOL;
//Operators for arrays are tested by following code segments.
print_r( $keyedArray+$noKeyedArray);
echo PHP_EOL;
print_r( $keyedArray==$noKeyedArray);
echo PHP_EOL;
print_r( $keyedArray===$noKeyedArray);
echo PHP_EOL;
print_r( $keyedArray!=$noKeyedArray);
echo PHP_EOL;
print_r( $keyedArray<>$noKeyedArray);
echo PHP_EOL;
?>
