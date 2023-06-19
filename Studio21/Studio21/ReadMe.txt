Studio 21

2. It is important to delcare a virtual destructor in the base class since every call to delete the pointers to the base class objects will also call delete on the derived class. The base resource will be deleted by doing so. 

3. CommandPrompt becomes flexible when adaptin to the changes in the real implementations of the file factor and system by using interfaces such as AbstractFileFactory and AbstractFileSystem. This is because the CommandPrompt doesn't depend on the implementation. The interfection allows the clients to code so that the code is extensible and adaptable. 

4. After dynamically allocating SimpleFileSystem, SimpleFileFactory, and TouchCommand Object, we configured a CommandPrompt variable to those objects. Then by executing run function on that variable, we tested the command "touch example_file.txt". In our main, we tested to see if example_file.txt was created by opening the file, which returned 0, so our test case succeeded.
