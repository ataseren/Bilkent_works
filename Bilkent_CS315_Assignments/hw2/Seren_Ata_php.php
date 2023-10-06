<?php

echo "Question 1". PHP_EOL;
echo "Boolean expressions with <, >, == and !=:". PHP_EOL;
$equalVal = (1 == 1);
$notEqualVal = (1 != 1);
$lessVal = (1 < 2);
$moreVal = (1 > 2);
var_dump($equalVal);
var_dump($notEqualVal);
var_dump($lessVal);
var_dump($moreVal);
echo "Boolean expressions with \"bool\" keyword that allows user to evaluate any value in terms of Boolean:";

var_dump((bool) "");        // bool(false)
var_dump((bool) "0");       // bool(false)
var_dump((bool) 0);         // bool(false)
var_dump((bool) 1);         // bool(true)
var_dump((bool) -2);        // bool(true)
var_dump((bool) "foo");     // bool(true)
var_dump((bool) 2.3e5);     // bool(true)
var_dump((bool) array(12)); // bool(true)
var_dump((bool) array());   // bool(false)
var_dump((bool) "false");   // bool(true)
echo PHP_EOL;

echo "Question 2 and 3". PHP_EOL;
function helper() {
    echo "No short circuit";
  }
echo "\"and\", \"or\",\"&&\" and \"||\" are short circuited.". PHP_EOL;
echo "To show the short circuit, a helper function \"helper()\" that returns a text when called has been declared." . PHP_EOL;
echo "If a short circuit happens, the function won't be called and we don't see its value." . PHP_EOL;
$a = (false && helper());
var_dump($a);
$b = (true  || helper());
var_dump($b);
$c = (false and helper());
var_dump($c);
$d = (true  or  helper());
var_dump($d);
echo PHP_EOL;

echo "Null coalescent operator \"??\" is used to check if a variable exists and it is short-circuited too". PHP_EOL;
echo "However it is in PHP 7 so it may cause some issues on Dijkstra machine.". PHP_EOL;
var_dump(false ?? "no short circuit");// false
var_dump(true ?? "no short circuit");// true
var_dump('' ?? "no short circuit");// ""
var_dump(0 ?? "no short circuit");// 0
var_dump([] ?? "no short circuit");// array()
var_dump(null ?? "no short circuit");// no short circuit in this case
echo PHP_EOL;

echo "Question 4". PHP_EOL;
echo "Short circuiting prevents calling and/or evaluating unnecessary elements in an expression and in this way, increases performance.". PHP_EOL;
echo "In addition, it prevents errors such as a loop tries to access an out-of-bounds element:". PHP_EOL;

$arr = array("a", "b", "c", "d", "e");
$index = 0;

while (($index < 5) and ($arr[$index] != "f")){
    echo "$arr[$index]" . PHP_EOL;
    $index += 1;
}
echo "If there wouldn't be a short circuit mechanism, array accessing code segment in following loop would try to access a non-existent ";
echo "index and program would give an error." . PHP_EOL;

echo PHP_EOL;
echo "Question 5". PHP_EOL;

echo "Despite the fact that short circuit prevents performance issues and errors, ";
echo "it sometimes prevent required functions from being called (side effect):". PHP_EOL;

$x = 3;
$y = 2;
function helper2(){
    echo "Program successful";
}
print_r(($x > $y) or helper2());
echo PHP_EOL;

echo "If helper2 function would be an important one for a function, loop or any code segment, ";
echo "the program depends on it would fail because short circuit";
echo "has occured and function didn't even be evaluated.";
?>