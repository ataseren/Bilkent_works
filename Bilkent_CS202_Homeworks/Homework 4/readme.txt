-I created a HashNode class to put data from files into hash table with their indices.
This class is also friend with WordNetwork class.

-My adjacent matrix and hash table are dynamically allocated. Also I used several dynamically allocated arrays in my functions.
There are 5757 words in given .txt file, so we need 5757x5757 2D adjacency matrix. However, I took size from these files and used it instead of
using 5757 just in case if you use different files.

-I have a concern about output. listConnectedComponents() method prints a very large output and it even doesn't fit terminal.
When I run this method, I can't reach other function's outputs.
Because of this, sometimes I couldn't check other methods if they are working properly.
To solve this problem, I sometimes commented that function in my main file.

-My another concern is about listConnectedComponents() method too. In this method, I considered at least 2 connected vertices as component.
For example, word "roger" has several neigbors. However, word "nexus" doesn't have any neighbors.
Therefore, there is a component with connections of "roger" but "nexus" is not considered as component.
I only printed these valid components but easily, I can print other type of components by not using one of my helper methods.

-My destructor in WordNetwork deletes adjacency matrix and hash table at the end of the program.
I also deleted other dynamic arrays when I'm done with them.