import "dart:io";
void main() { 
   print("Question 1");
   var arr = [1,2,3,4,5];
   print(arr);
   print("Some elements from the array:");
   print(arr[0]);
   print(arr[1]);
   print(arr[2]); //Subscripts with integers are legal.
   print("Subscripts with integers are legal.");
   print("");

   print("Question 2");
   print("Dart checks range and code segment below gives syntax error since subscript is out of range: print(arr[10]);" );
   /*
   Dart checks range and code segment below
   gives syntax error since subscript is out of range.
   print(arr[10]); 
   */
   print("");

   print("Question 3 and 4");
   print("New element can be added to array: ");
   print(arr);
   print("with length: ");
   print(arr.length);
   arr.add(15);
   print("Final array: ");
   print(arr);
   print("with length: ");
   print(arr.length);


   /*Allocation and range bound before run time 
   in this type of array because its size is fixed at the allocation
   and can't be changed during run time.
   */
   print("A fixed-size array: ");
   var fixedBoundArr = new List(3);
   fixedBoundArr[0] = 0;
   fixedBoundArr[1] = 1;
   fixedBoundArr[2] = 2;
   print(fixedBoundArr); 
   
   /*
   add() func works for arr because its range is bound in run time 
   and can be changed. However, range of fixed-length arrays can't be changed. 
   Because of this, following code segment will give an error.
   add.fixedBoundArr(5);
   */ 
   
   /*
   Different than the "fixed-size" arrays, Dart provides us the
   "growable" arrays that are similar to dynamic arrays. Their ranges can be changed
   at any time and new data can be allocated for new elements.
   */

   print("A dynamic array: ");
   var dynArr = new List();
   //print(dynArr[0]); won't print because allocation or range didn't happen.
   print(dynArr.length);
   dynArr.add(3);
   print(dynArr.length);
   dynArr.add(4);
   print(dynArr.length);
   dynArr.add(5);
   print(dynArr.length);
   print(dynArr);
   print("");
   print("I made detailed explanations at my report and in the comments of the code for these questions.");
   print("");

   print("Question 5");
   //Rectangle multidimensional arrays are supported by Dart.
   //They are implemented and tested by following code segments.
   List rec1 = [1,2,3,4];
   List rec2 = [5,6,7,8];
   List rec3 = [9,10,11,12];
   List rectangle = [rec1, rec2, rec3];
   print("Rectangle 2d array:");
   print(rectangle);

   //Ragged multidimensional arrays are supported by Dart.
   //They are implemented and tested by following code segments.
   List rag1 = [1,2,3];
   List rag2 = [5,6,7,8];
   List rag3 = [9,10];
   List ragged = [rag1, rag2, rag3];
   print("Ragged 2d array:");
   print(ragged);
   print("");

   print("Question 6 (arrays declared in first question answers this question because array is both declared and initialized at the same time)");
   print("");

   print("Question 7");
   //Slices are supported by Dart. Slice types are elaborated on the report.
   print("Some type of slices:");
   print(arr.sublist(1, 3));
   print(arr.sublist(2));
   print("");

   print("Question 8");
   List arr1 = [1,2,3,4,5];
   List arr2 = [6,7,8,9,10];
   
   print("Operators for arrays are tested by some code segments.");
   //Operators for arrays are tested by following code segments.
   print(arr1 + arr2);
   print(arr2 == arr1);
   print(arr2 != arr1);
   List arr3 = [...arr1,0,...arr2];
   print(arr3);
}