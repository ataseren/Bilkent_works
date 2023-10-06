package main

import "fmt"

/*
Design Issue 1
Go supports nested subprogram but not in a way similar to Python. 
Outer subprogram "nested()" is declared normally. However, I needed to declare inner subprogram anonymously, 
initialized as a variable "inner" and called the subprogram via this variable which are features that Go allows. 
*/
func nested() {
	fmt.Println("This is the outer part of nested subprogram.")
    
    inner := func() {
        fmt.Println("This is the inner part of nested subprogram.")
    }
	inner()
}

/*
Design Issue 2
In Go, variables declared out of a subprogram are global and variables declared 
in a subprogram are local. To show this, I declared a global variable "gVal". 
Value of this variable, 1975, has been printed by a subprogram in the main() subprogram.
Also, it has been printed in main() subprogram separately. To show the local variable effect, 
I declared gVal with value 2010 locally this time, in the main() subprogram. As I expected, print
statement has printed this new local value.
*/

var gVal = 1975

func scope(){
	fmt.Println("Value of global variable gVal in scope() subprogram = ", gVal)
}

/*
Design Issue 3
Go supports pass-by-value and pass-by-reference (they are named as call-by-value and call-by reference in Go). 
For pass-by-value, I used passByValue1(a int) and passByValue2(a int) int subprograms. By using them and a variable, 
I tested that subprograms with pass-by-value take the value inside and can change its data locally but when they terminate, 
changes on the variables don't last. 

For pass-by-reference, I used passByReference(b *int ) and a pointer initialized in terms of Go language 
rules and pointed to an int value. Like the languages that use pointers such as C++, changes on the referenced 
pointer happened in the subprogram has changed the value of the variable at the outside of the function. 
*/
func passByValue1(a int) {
    a = 10
}

func passByValue2(a int) int {
    return a
}

func passByReference(b *int) {
    *b = 13
}

/*
Design Issue 4
In Go, keyword and default parameters are not supported. However, they can be imitated by using structs and "variadic functions". 
To imitate keyword parameters, I declared a struct that works in a similar way to structs in other 
languages and used it as a parameter in useKeywordParameters subprogram. In this way, I can access to the variables in struct 
in any order while using it in the subprogram call in the main(). 

To imitate default parameters, I declared a variadic function which is a function with a "..." parameter that allows fucntion
to be invoked with zero or more arguments for that parameter. The parameter can be accessed by using array notation. In defaultParameters,
I wrote a code that initializes a default value to the first element if no parameters have been entered.
*/
type keywordParameters struct {
  p1, p2, p3 int
}

func useKeywordParameters(ps keywordParameters) int {
  return ps.p1 + ps.p2 + ps.p3 
}


func defaultParameters(arr ...int){
	var def int = 8
	if len(arr) > 0 {
		def = arr[0]
	}
	
	fmt.Println("Result of defaultParameters = ", def)
}

/*
Design Issue 5
Go language support anonymous functions that can be initialized with a parameter. Such function allows us to form a closure. 
I declared a multiplier function that returns an anonymous function. I used this return value to initialize the anonymous function 
with a variable in main() subprogram.
*/
func multiplier(m1 int) func(m2 int) int{
	return func(m2 int) int{
		return m1*m2
	}
}

func main() {
	fmt.Println("Design Issue 1")
	nested() //This function is supposed to print 2 different statement in the subprogram and in the inner subprogram.
	fmt.Println()

	fmt.Println("Design Issue 2")
	fmt.Println("Value of global variable gVal in main() = ", gVal)
	scope()
	var gVal = 2021 //Local declaration of global variable gVal
	fmt.Println("Value of global variable gVal after declared and be local in main() = ", gVal)
	fmt.Println()

	fmt.Println("Design Issue 3")
	var x int = 5
	fmt.Println("Before passByValue1(x) x = ", x)
	passByValue1(x)
	fmt.Println("After passByValue1(x) x = ", x) //No change after passByValue1(x)
	fmt.Println("Result of passByValue2(x) = ", passByValue2(x)) //Directly returns the given value
	fmt.Println()
	
	var y1 int = 98
	var y *int = &y1
	fmt.Println("Before passByReference(y) y = ", *y)
	passByReference(y)
	fmt.Println("After passByReference(y) y = ", *y) //Changes the value via pointer
	fmt.Println()

	fmt.Println("Design Issue 4")
	fmt.Printf("Result of subprogram with keyword parameters: ")
	fmt.Println(useKeywordParameters(keywordParameters{p3: 6, p1: 12})) //No order is needed
	fmt.Println("Result of subprogram with default parameters: ")
	defaultParameters() // Prints 8 as default
	defaultParameters(3) // Prints given value
	fmt.Println()

	fmt.Println("Design Issue 5")
	var multiply = multiplier(9) 
	fmt.Println(multiply(2))
	fmt.Println(multiply(3)) //Closure has been created and used


}
