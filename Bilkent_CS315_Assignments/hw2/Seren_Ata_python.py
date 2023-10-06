#Question 1
#Different types of boolean expressions in Python
print("Question 1")
print("Different types of boolean expressions in Python:")
print("Boolean expressions with <, >, == and !=:")
print(0 < 1)
print(0 > 1)
print(0 == 1)
print(0 != 1)
print("\n")
print("Boolean expressions with bool() function that allows user to evaluate any value in terms of Boolean:")
print(bool("string"))
print(bool(123))
print(bool(["Ata", "Ahmet", "Alp"]))
print("\n")
print("There are not many values that evaluate to False in a Boolean evaluation")
print("except empty values such as (), [], {}, "", 0, the value None and the value False itself.")
print(bool(()))
print(bool([]))
print(bool({}))
print(bool(""))
print(bool(0))
print(bool(None))
print(bool(False))
print("\n")

#Question 2 and 3
print("Question 2 and 3")
print("\"and\", \"or\" and conditional operators such as \"<, >, <=, >=\" are short circuited.")
print("To show the short circuit, a helper function \"helper1()\" that returns a text when called has been declared.")
print("If a short circuit happens, the function won't be called and we don't see its value.")
def helper1():
    return "Further value has been checked."
def helper2(i):
    print("Further value in comparison has been checked.")
    return i

#prints 0 without calling helper function (short circuit)
print("-"*10)
print(0 and helper1())
print("-"*10)

#prints helper function value (no short circuit)
print(1 and helper1())
print("-"*10)

#prints 1 without calling helper function (short circuit)
print(1 or helper1())
print("-"*10)

#prints helper function value (no short circuit) 
print(0 or helper1())
print("-"*10)

#calls helper function and doesn't print 1 (short circuit)
print(0 or helper1() or 1)
print("-"*10)

#directly prints 1 (short circuit)
print(0 or helper1() and 1)
print("-"*10)
print("-"*10)
print("-"*10)

#prints false without calling helper function (short circuit)
print( 5 > 10 > helper2(1) )
print("-"*10)

#prints true with calling helper function (no short circuit)
print( 5 < 10 > helper2(1) )
print("-"*10)

#prints false with calling helper function (no short circuit)
print( 5 < 10 > helper2(15) )
print("\n")

print("Question 4")
print("Short circuiting prevents calling and/or evaluating unnecessary elements in an expression and in this way, increases performance.")
print("In addition, it prevents errors such as a loop tries to access an out-of-bounds element:")

list = ["a", "b", "c", "d", "e"]
index = 0
while ((index < 5) and (list[index] != "f")):
    print(list[index])
    index += 1
print("If there wouldn't be a short circuit mechanism, list[index] in following loop would try to access a non-existent index and program would give an error.")
print("\n")

print("Question 5")
print("Despite the fact that short circuit prevents performance issues and errors, it sometimes prevents required functions from being called (side effect):")

a = 3
b = 2
def helper3():
    return "Program successful"
print((a > b) or helper3())
#"Program successful" hasn't been printed.

print("If helper3 function would be an important one for a function, loop or any code segment, the program depends on it would fail because short circuit")
print("has occurred and function didn't even be evaluated.")





