Studio 18

1. Team member names: Chan Lee, Yu June Park, Noah Li

2. Assuming that the concrete file classes are already defined, it would not be difficult to create a new file system that creates different types rather than the SimpleFileSystem. We would have to modify the createFile() method to know which file types it will create. 

3. A disadvantage is that the objects will become more difficult to understand as they will be more complex. An advantage is that the code will be compatible between different file systems and the code will be more flexible. Also, it allows for encapsulation of the code. We would want to create a new concrete file factory class when we want to interact uniquely with the file type. The file factory must be modified if a new file type is introduced. If the file system implementations manage the same type of tiles, the factory can be used for both. If not, it cannot be used for both. 


4. 
Image File: { ‘X’, ‘ ‘, ‘X’, ‘ ‘, ‘X’, ‘ ‘, ‘X’,’ ‘, ‘X’, ‘3’ }
X X
 X
X X                                            


5. It depends on the Abstract Interface.
