# Bank-managment-system
this project is made after compeleting C language to use all the concept in this project

<h1>1.Project Introduction: </h1>
A console-based Bank Management system. which covering core operations and focusing heavily on

<h3>
  >input validation <br>
>transaction control<br>
>real date and time update<br>
>user Input handling.
<br>
</h3>

<h1>Employee login:</h1>

For system security , I implemented login security in my system with controlled access handling. After 3 failed login attempts, the Employee ID is automatically blocked to prevent unauthorized access. Because authentication isn’t just about logging it’s about stopping the wrong people from getting in.

<h2>User Input handling:</h2>

If a user enters invalid input more than three times during any operation, the system automatically cancels the transaction. This prevents misuse, reduces unnecessary system load, and ensures that repeated errors do not affect data integrity.

<h1>2. Why does i Develop it?</h1>

The main purpose of this project is to understand how banking systems work behind the scenes. It focuses on handling user data, maintaining transaction records with real date and time update, and preventing invalid or unauthorized actions action by user.

<h1>3.Core Operations</h1>

The system allows employees to perform the following operations according to Account status( Active , Inactive, close ):
<h3>
> Employee Login <br>         
> Create Account <br>          
> Deposit Money   <br>       
> Withdraw Money  <br>        
> Transaction History <br>
> Customer Passbook   <br> 
> Balance Inquiry     <br>    
> Customer Details   <br>    
> Customer List     <br>       
> Close Account     <br>     
> System Logout<br>

</h3>
deposit and withdraw contain recipt which contains real date and time, account number, and other details which need in recipt.

<h1>4. How does it work?</h1>

The system starts with an employee login. If the login details are correct, access is granted to the main menu. If the user enters wrong credentials three times, the system blocks the employee ID to prevent misuse.
After login, the employee can choose different operations from the menu. The system checks all inputs carefully, such as DOB, Addhar number, Mobile number, OTP of registered Mobile No. , Security pin, account number, balance, and personal details. If something is wrong, it shows an error instead of crashing.
Each transaction is handled properly to make sure the data stays correct and consistent.
After completing all the operation user must be logout form the system which shows system stability and data prevention. 

<h1>Future improvement.</h1>
<h3>
  > adding GUI<br>
> add multiple uses simultaneously<br>
> improvement encription of data transfer<br>
> add internet connectivity.<br>
</h3>



