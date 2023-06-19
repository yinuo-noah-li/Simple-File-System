Studio 20

1. Team member names: Chan Lee, Yu June Park, Noah Li

2. It's necessary to delete the pointer since we would want to deallocate and clean up any remaining pointer pointing to the base objects to be directed. Simply, we don't want any pointers directing to the actual password. 

4. We created a Passwordproxy object and dynamically allocated the AbstractFile of TextFile. We tested for the write function, which prompted to input a password, which is what we expected. We also tested for the functionality by typing in the wrong password, which then kept on asking for the correct password. This also shows that our read function is successful, as it prompts the corresponding result when given right/wrong passwords. 
