Lab 5 ReadMe

Introduction:
This is a software program that mimics common terminal commands. The program allows file system management where users can interact with each of the text files by creating them, editing/writing them, showing them and more. The code is written focused on object oriented coding principles including prototype pattern, visitor pattern and more.

Functionalities:
ls [-m] - display all the files in the current file system
rm - remove a certain file
cp - copy a certain file
touch [-p] - create a file
rn - rename a file
ds [-d] - display content of a file
cat [-a] - write on a file
catds - write and display the file
help - show all the possible commands / can show how each commands work
1. Team Members: Chan Lee, Noah Li, Yujune Park

Studio 16: Chan Lee, Yujune Park
Studio 17: Chan Lee, Yujune Park
Studio 18: Chan Lee, Yujune Park
Studio 19: Chan Lee, Yujune Park
Studio 20: Chan Lee, Yujune Park
Studio 21: Chan Lee, Yujune Park
1. Chan Lee, Yujune Park
2. Chan Lee, Yujune Park
3. Chan Lee, Yujune Park
4. Chan Lee, Yujune Park
5. Chan Lee, Yujune Park
6. Chan Lee, Yujune Park
7. Chan Lee, Yujune Park
8. Chan Lee, Yujune Park
9. Chan Lee, Yujune Park
10. Chan Lee, Yujune Park
11. Chan Lee, Yujune Park

Bugs / Errors:
1. When doing cat on image file with wrong input, it would tell the user that the command failed. However, when trying to ds on the same image file, it would say that the file did not exist. We solved this problem by realizing that we never closed the file after opening one in the CatCommand source file.

2. Vector out of subscript range error in macro command execution. Realized that we still need to pass two strings for the catds function (originally passed one because filename was the only string we needed) since we need to execute 'cat' and 'ds' which are stored in the cmd_vec.

Test Cases:

1. ls for one file
$ ls
Result: file.txt
Description: Correctly displays the name of the file, 'file.txt'

2. ls for multiple files
$ ls
Result: 
file.txt file2.txt
file3.txt file4.txt
file5.txt file6.txt

Description: Correctly displays all the names of the files with 2 files in each row

3. ls -m for multiple files
$ ls -m
Result:
file.txt text 0
file2.txt text 2
image.img image 5
Description: Correctly displays all the names of the files in meta display format

4. rm for a file
$ ls
Result: file.txt
$ rm file.txt
Result:

Description: Correctly removes the file given the filename


5. rm for non existing file
Given: file.txt
$ rm asdf
Result:
Command Failed
Description: Correctly displays that the command failed when the file given the filename is non-existent

6. cp for a file
Given: file.txt with content of "asdf"
$ cp file.txt file1
$ ls
Result:
file.txt file1.txt
$ ds file1.txt
Result: asdf

Description: Correctly copies the content of file.txt by creating another file called file1.txt and putting the content inside of file1.txt

7. cp for a file that exists
Given: file.txt, file1.txt
$ cp file.txt file1
Result: Copy failed. File already exists

Description: Correctly returns a non-success value and displays that copy failed since a file named file1.txt already exists

8. touch a new file
$ touch file.txt
$ ls
Result: file.txt

Description: Correctly creates a new txt file called file.txt as given.

8. touch an existing file
Given: file.txt
$ touch file.txt
Result: Command Failed

Description: Correctly displays that the command failed since an txt file with the name exists already in the file system.

9. touch with password
$ touch file.txt -p
Input a password:
123

Description: Correctly asks for a password when given the option of -p in the command

10. rn a file
Given: file.txt
$ rn file.txt asdf
$ ls
Result: asdf.txt

Description: file.txt gets correctly renamed to asdf.txt

11. rn a wrong file
Given: file.txt
$ rn asdf.txt asdff
Result: 
Rename can be invoked by the user with 'rn <filename> <new_name_with_no_extension>' and can rename the name of an original file.
Cat+Ds can be invoked by the user with 'catds <filename>' and can edit the content of and display the file as well.
command failed

Description: Command fails and displayInfo() gets called to show how the command should execute

12. ds a file
Given: file.img with content of 
X X
 X
X X
$ ds file.txt
Result: 
X X
 X
X X

Description: Command correctly displays the content of img in formatted way.

13. ds a wrong file
Given: file.txt
$ ds file.img
Result: Such file does not exist.

Description: Because such file does not exist, the program displays that such file does not exist.

14. ds -d (unformatted way)
Given: file.img with content of 
X X
 X
X X
$ ds file.txt -d
Result: X X X X X

Description: The option [-d] tells the program to display the file in unformatted way which it correctly returns. 

15. cat a file
Given: file.txt
$ cat file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving the file.
Asdf
:wq
$ ds file.txt
Result: Asdf

Description: The cat command allows the user to edit the content of the file where :wq saves and quits the edit mode and :q quits without saving. Thus, the command correctly displays the content of the file after it is edited through the cat command.

16. cat -a (append)
Given: file.txt with content of "asdf"
$ cat file.txt -a
asdf
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving the file.
123
:wq
$ ds file.txt
Result: asdf123

Description: The -a option displays the current content of the file and allows the user to append to the content of the specified file. Thus, the result of asdf123 is a viable result as 123 is appended to the original content of asdf.

17. cat a non-existent file
$ cat file.txt
Result: Such file does not exist

Description: Because such file does not exist (never created) in the file system, it tells the user that such file does not exist.

18. catds a file
Given: file.txt
$ catds file.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving the file.
asdfasdf
:wq
asdfasdf

Description: The catds is a macro command composed of cat and ds. Thus, the command edits the file of the command and then displays it to the user in the next step. The result makes sense as the edited input to file.txt is immediately displayed after :wq.

19. help
$ help
Result: 
cat
catds
cp
ds
ls
rm
rn
touch

Description: Displays all the possible commands which is the functionality of help. Thus, the result is ideal.

20. help a functionality
$ help touch
Result: 
The command 'touch' creates a file and can be invoked with the command : touch <filename>
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Description: By putting a specific command after help, the program executes displayInfo() of that command which explains how the command can be executed.
