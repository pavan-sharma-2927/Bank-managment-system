# Bank-managment-system
this project is made after compeleting C language to use all the concept in this project

.Project Introduction: 
A console-based Bank Management system. which covering core operations and focusing heavily on

>input validation
>transaction control
>real date and time update
>user Input handling.

Employee login:

For system security , I implemented login security in my system with controlled access handling. After 3 failed login attempts, the Employee ID is automatically blocked to prevent unauthorized access. Because authentication isn’t just about logging it’s about stopping the wrong people from getting in.

User Input handling:

If a user enters invalid input more than three times during any operation, the system automatically cancels the transaction. This prevents misuse, reduces unnecessary system load, and ensures that repeated errors do not affect data integrity.

2. Why does i Develop it?

The main purpose of this project is to understand how banking systems work behind the scenes. It focuses on handling user data, maintaining transaction records with real date and time update, and preventing invalid or unauthorized actions action by user.

3.Core Operations

The system allows employees to perform the following operations according to Account status( Active , Inactive, close ):
> Employee Login          
> Create Account           
> Deposit Money          
> Withdraw Money          
> Transaction History 
> Customer Passbook    
> Balance Inquiry         
> Customer Details       
> Customer List            
> Close Account          
> System Logout     

deposit and withdraw contain recipt which contains real date and time, account number, and other details which need in recipt.

4. How does it work?

The system starts with an employee login. If the login details are correct, access is granted to the main menu. If the user enters wrong credentials three times, the system blocks the employee ID to prevent misuse.
After login, the employee can choose different operations from the menu. The system checks all inputs carefully, such as DOB, Addhar number, Mobile number, OTP of registered Mobile No. , Security pin, account number, balance, and personal details. If something is wrong, it shows an error instead of crashing.
Each transaction is handled properly to make sure the data stays correct and consistent.
After completing all the operation user must be logout form the system which shows system stability and data prevention. 



