fn main() {
    println!("Question 1");
    println!("Different types of boolean expressions in Rust:");
    let bool_val1 = true;
    let bool_val2 = false;
    println!("{}", bool_val1);
    println!("{}", bool_val2);

    println!("Other than literal values, Boolean values can be represented with conditionals in Rust:");
    let a = 20;
    let b = 30;
    let bool_val3 = a > b;
    let bool_val4 = a < b;
    let bool_val5 = a == b;
    let bool_val6 = a != b;
    println!("{}", bool_val3);
    println!("{}", bool_val4);
    println!("{}", bool_val5);
    println!("{}", bool_val6);
    println!();

    println!("Question 2 and 3");
    println!("\"&&\" and \"||\" are short circuited.");
    println!("To show the short circuit, helper() function has been declared.");
    println!("If a short circuit happens, function won't be called and we won't see a printed value");
    let a = false && helper();
    println!("{}", a);
    println!("--------------------");
    let b = true && helper();
    println!("{}", b);
    println!("--------------------");
    let c = false || helper();
    println!("{}", c);
    println!("--------------------");
    let d = true || helper();
    println!("{}", d);
    println!("");

    println!("Question 4");
    println!("Short circuiting prevents calling and/or evaluating unnecessary elements in an expression and in this way, increases performance.");
    println!("In addition, it prevents errors such as a loop tries to access a out-of-bounds element:");

    let arr = ["a", "b", "c", "d", "e"];
    let mut index = 0;

    while index < 5 && arr[index] != "f"{
        println!("{}", arr[index]);
        index += 1;
    }
    println!("If there wouldn't be a short circuit mechanism, arr[index] in following loop would try to access a non-existent "); 
    println!("index and program would give an error.");
    println!("");

    println!("Question 5");
    println!("Despite the fact that short circuit prevents performance issues and errors, ");
    println!("it sometimes prevent required functions from being called (side effect):");

    let x = 3;
    let y = 2;

    let result = (x > y) || helper_success();
    println!("{}", result);
    //"Program successful." haven't been printed.
    
    println!("If helper_success function would be an important one for a function, loop or any code segment, ");
    println!("the program depends on it would fail because short circuit");
    println!("has occured and function didn't even be evaluated which prints a text.");

}

fn helper() -> bool {
    println!("No short circuit");  
    true
}

fn helper_success() -> bool {
    println!("Program successful.");  
    true
}