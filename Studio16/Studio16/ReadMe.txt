Studio 16

1. Team member names: Chan Lee, Yu June Park, Noah Li

2. The process of declaring an interface in C++:
First make a class with pure virtual methods. A pure virtual method is the class method that can be assigned to be 0 and is virtual. The interface can be declared by creating a new class that overrides the aforementioned virtual methods. The new classes will contain the interface. 

3a. Is this an example of “interface inheritance” or “implementation inheritance”?
    Because we don't use any implementation from the base class, this is an example of the interface inheritance. 

3b. They cannot be public; however, it does not matter if they are private or protected because we're not extending and inheriting from the TextFile. 

4. TextFile classes behaved as expected for the test cases.
    They included: writing to/reading from a TextFile, appending and re-writing over it.
    
5. We oriented the pointer to an AbstractFile object to point to a TextFile object.
main:
    AbstractFile* file = new TextFile("file.txt");
	vector<char> vc = { 'r', 'a', 'n', 'd', 'o', 'm' };
	vector<char> vc2 = {'s', 't', 'r'};
	file->write(vc);
	file->read();
	file->append(vc2);
	file->read();
	return 0;
