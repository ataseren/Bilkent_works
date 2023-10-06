fn main() {

    println!("Question 1");
    let arr  = [1, 2, 3, 4, 5];
    println!("{:?}",arr);
    println!("arr[0] is {}",arr[0]); //Subscripts with integers are legal.
    println!("Size of arr:{}",arr.len());
    println!();

    println!("Question 2 (Rust checks range and code segment in the comments gives\n a syntax error since index is out of range.");
    /*
    Rust checks range and code segment below gives
    a syntax error since index is out of range.
    println!("arr[out of range] is {}",arr[11]);
    */
    println!();
    
    println!("Question 3 and 4");
    println!("A different type of array called \"mutable\".
    \"mut\" keyword allows user to not add or remove
    but change the elements of the array. Therefore, 
    range bindings and allocation of arrays with
    and without mutability take place before run time");
    /*
    A different type of array called "mutable".
    "mut" keyword allows user to not add or remove
    but change the elements of the array. Therefore, 
    range bindings and allocation of arrays with
    and without mutability take place before run time
    */
    let mut arr2  = [6, 7, 8, 9, 10];
    arr2[0] = 99;

    println!("{:?}",arr2);
    println!("arr2[0] is {}",arr2[0]);

    /*
    "vec!" macro, on the other hand, allows user 
    to increase or decrease the size of array.
    Therefore, range bindings and allocation of arrays
    with vec! macro takes place at run time.
    */
    
    println!("\"vec!\" macro, on the other hand, allows user
    to increase or decrease the size of array.
    Therefore, range bindings and allocation of arrays
    with vec! macro takes place at run time.");

    let mut arr3 = vec![];
    println!("Size of arr2:{}",arr3.len());
    arr3.push(11);
    arr3.push(12);
    arr3.push(13);

    println!("{:?}",arr3);
    println!("Size of arr3:{}",arr3.len());
    println!();

    println!("Question 5");
    //Rectangle multidimensional arrays are supported by Rust.
    //Ragged multidimensional arrays are NOT supported by Rust.
    //They are implemented and tested by following code segments.
    println!("Rectangle multidimensional array implementation and printing:");
    let mut arr4 = [[0u8; 4]; 6];
    arr4[0][1] = 33 ;
    arr4[0][2] = 34 ;
    arr4[0][3] = 35 ;

    println!("{:?}",arr4);
    println!();
    println!("Ragged multidimensional arrays are NOT supported by Rust.");
    println!();

    println!("Question 6 (arrays declared in first question answers this question because array is both declared and initialized at the same time)");
    println!();

    println!("Question 7");
    println!("Some slices:");
    //Slices are supported by Rust. Slice type is elaborated on the report.
    let slice = &arr[0..2];
    println!("slice is {:?}", slice);
    println!();

    println!("Question 8 (Operators for arrays are NOT provided by Rust.)");
    //Operators for arrays are NOT provided by Rust.
}
