void main() {  
    print("Question 1");
    print("Different types of boolean expressions with operators in Dart:");
    var a = 5; 
    var b = 10; 
    print(a == b);
    print(a != b);
    print(a < b); 
    print(a > b);
    print("Unlike many other languages, Boolean data type in Dart recognizes "); 
    print("only the literal true as true. Any other value is considered as false.\n");
    /*
    if(str) { 
        print('String is not empty'); 
    } 
    else { 
        print('Empty String'); 
    }
    */
    //In some compilers, this codes segment works and "str" is considered as false in if statement.
    print("Question 2 and 3");
    print("\"&&\" and \"||\" are short circuited.");
    print("To show the short circuit, helperTrue() and helperFalse() functions have been declared.");
    print("They return true and false values, respectively.");
    print("If a short circuit happens, functions won't be called and we won't see a printed value");
    print(false && helperTrue());
    print("--------------------");
    print(true && helperTrue());
    print("--------------------");
    print(false || helperFalse());
    print("--------------------");
    print(true || helperFalse());
    print("");
    // Functions that return Boolean values have been declared since Dart compiler in Dijkstra 
    // doesn't allow other values to be considered as Boolean value.
    print("Question 4");
    print("Short circuiting prevents calling and/or evaluating unnecessary elements in an expression and in this way, increases performance.");
    print("In addition, it prevents errors such as a loop tries to access a out-of-bounds element:");

    var list = ["a", "b", "c", "d", "e"];
    var index = 0;

    while ((index < 5) && (list[index] != "f")){
        print(list[index]);
        index += 1;
    }
    print("If there wouldn't be a short circuit mechanism, list[index] in following loop would try to access a non-existent "); 
    print("index and program would give an error.");
    print("");

    print("Question 5");
    print("Despite the fact that short circuit prevents performance issues and errors, ");
    print("it sometimes prevent required functions from being called (side effect):");

    var x = 3;
    var y = 2;

    print((x > y) || helperError());
    //"Program successful." haven't been printed.
    
    print("If helperError function would be an important one for a function, loop or any code segment, ");
    print("the program depends on it would fail because short circuit");
    print("has occured and function didn't even be evaluated.");
}   

bool helperTrue() {
    print("No short circuit");
    return true;
}

bool helperFalse() {
    print("No short circuit");
    return false;
}

bool helperError(){
    print("Program successful.");
    return false;
}