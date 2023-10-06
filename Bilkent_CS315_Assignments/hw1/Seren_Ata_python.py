import numpy as np

# Question 1
print("Question 1")
arr = np.array([1, 2, 3, 4, 5])
print(arr)
print("Some elements from array:")
print(arr[0]) # Integers are legal in subscripts.
print(arr[1])
print(arr[-1]) # Negative integers are allowed too.
# They start from the right side of the array.

print()
# Question 2
print("Question 2 (see inline comment for details)")
"""
Python checks the ranges of an array and gives 
syntax error. Following code segment gives such 
syntax error since the index in it is out of range.
print(arr[72])
"""

# Question 3 and 4
print("Question 3 and 4")
print("Size of arr: "+ str(len(arr))) # Size of array is 5 at the beginning.
print(arr)

# We can append a new element to our array.
print("Int 6 appended")
arr = np.append(arr, 6)
print(arr)
print("Size of arr: "+ str(len(arr)))

# We can remove an element from our array too.
arr =np.delete(arr, 5)
print("Int 6 removed")
print(arr)
print("Size of arr: "+ str(len(arr)))
print()

# Question 5
print("Question 5")
print("Rectangle 2d array:")
arrRec = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]),
print(arrRec)
print()
print("Ragged 2d array:")
arrRag = np.array([[1, 2, 3, 4, 5], [6, 7, 8], [9, 10]], dtype=object )
print(arrRag)
print()

# Question 6
print("Question 6")
arr2 = np.array([10, 11, 12, 12]) #Both declaration and initializaton happen at the same time.
print(arr2)
print()

# Question 7
print("Question 7")
arrSl1 = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
print("Several slices of array: ")
print(arrSl1)
print()
print(arrSl1[2:7])
print(arrSl1[5:])
print(arrSl1[:5])
print(arrSl1[-5:-2])
print(arrSl1[2:8:2])

arrSl2 = np.array([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]])
print("Several slices of array: ")
print(arrSl2)
print()
print(arrSl2[1, 1:4])
print(arrSl2[0:2, 1:4])

# Question 8
print("Question 8")
arr2 = np.array([1, 2, 3])
arr3 = np.array([4, 5, 6])
print("arr2 and arr3:")
print(arr2)
print(arr3)
print("+ operator")
print("arr2 + arr3")
print(arr2 + arr3)
print()

print("in operator")
print("2 in arr2:")
print(2 in arr2) # true
print("53 in arr2:")
print(53 in arr2) # false
print()

print("= operator") # assigns the elements of an array to another
arr4 = arr3
print("arr4 = arr3")
print("arr4 is ")
print(arr4)
print()

print("== operator") # returns true only if the length and elements of the arrays are equal
print("arr2 == arr3:")
print(arr2 == arr3) # false
print("arr3 == arr4:")
print(arr3 == arr4) # true



