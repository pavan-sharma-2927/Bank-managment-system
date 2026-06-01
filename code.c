#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#define active 1
#define close 0
#define inactive 2
void typeEffect(const char *text, int delay) // fuction which make terminal output beautiful
{
    while (*text)
    {
        printf("%c", *text);
        fflush(stdout);
        Sleep(delay);
        text++;
    }
}
void employee() // this function control employee login flow
{
    const char employee_id[3][15] = {"SBI-EMP-00123", "SBI-EMP-00124", "SBI-EMP-00125"};
    const char employee_pass[3][15] = {"EMP-PASS-00123", "EMP-PASS-00124", "EMP-PASS-00125]"};
    char input_id[15];
    char input_pass[15];
    bool emp_id = false;
    bool emp_pass = false;

    for (int attempt = 1; attempt <= 4; attempt++)
    {
        if (attempt > 3)
        {
            printf("\t\tEMPLOYEE ID IS BLOCKED.\n");
            printf("REASON: Multiple failed login attempts.\nPlease contact system administrator and restart the system for logging with different ID's");
            exit(1);
        }
        printf("EMPLOYEE ID :\t");
        fgets(input_id, sizeof input_id, stdin);
        input_id[strcspn(input_id, "\n")] = '\0';
        printf("PASSWORD      :\t");
        fgets(input_pass, sizeof input_pass, stdin);
        input_pass[strcspn(input_pass, "\n")] = '\0';
        for (int i = 0; i < 3; i++)
        {
            if ((strcmp(employee_id[i], input_id) == 0) && (strcmp(employee_pass[i], input_pass) == 0))
            {
                emp_id = true;
                emp_pass = true;
                printf("\n\t\t  !! SYSTEM LOGIN SUCCESSFUL !!\n");
                return;
            }
        }
        if (emp_id == false || emp_pass == false)
        {
            printf("INCORRECT EMPLOYEE ID. or INCORRECT PASSWORD\n");
        }
    }
}
void bank_details() // this fuction store costant data of bank.
{
    printf("\t\t\t\tSTATE BANK OF INDIA\n");
    printf("\t\t\tbranch    : ABCD 123\t\tcode: 115963\n");
    printf("\t\t\tEmail:sbi : 1234sbi.co.in\n");
    printf("\t\t\tPhone No. : 1234506987\n");
    printf("\t\t\tIFSC      : SBI00321524\n\n");
}
int customer_count = 0; // declare globle variable  which store customer count.
typedef struct DateTime // declare structure which store real date and time.
{
    int day, month, year;
    int hour, min, sec;
} DateTime;
typedef struct transaction // declare structure which store all transaction histry.
{
    DateTime transaction_date;
    DateTime transaction_time;
    long long transaction_id;
    float dabit_amount;
    float cradit_amount;
    float trans_balance;
} transaction;
transaction transactions[10]; // only 10 transaction can be stored.
typedef struct customer       // declare structure which store  all the personal data of customers.
{
    char name[50];
    char father_name[20];
    int dd, mm, yyyy;
    char gender[10];
    int age;
    char guardian_name[20];
    char guardian_relation[20];
    char guardian_addhar[14];
    char customer_id[14];
    char customer_PAN[11];
    char occupation[50];
    long long mobile;
    char email[50];
    char address[200];
    int pincode;
    char account_type[20];
    long long CIF_no;
    long long account;

    int security_pin;
    float balance;
    DateTime open_date;
    DateTime close_date;
    DateTime opening_time;
    DateTime closing_time;
    transaction transactions[5];
    int trasCount;
    int status;
} customer;
customer customers[1000]; // store 1000 customer data
long long CIF_number()    // Each time generate different CIF number.
{
    long long CIF = 0;
    for (int i = 0; i < 11; i++) // 11 digit number
    {
        int digit = rand() % 10;
        if (i == 0)
            digit = rand() % 9 + 1; // first digit must not be zero
        CIF = CIF * 10 + digit;
    }
    return CIF;
}
long long account_number() // Each time generate different Account number.
{
    long long account = 0;
    for (int i = 0; i < 11; i++)
    {
        int digit = rand() % 10;
        if (i == 0)
            digit = rand() % 9 + 1;
        account = account * 10 + digit;
    }
    return account;
}
long long transaction_number() // Each time generate different Transaction number and store in transaction fuction.
{
    long long number = 0;
    for (int i = 1; i <= 12; i++)
    {
        number = number * 10 + (rand() % 10);
    }
    return number;
}
void balance_inquary(int i)
{

    if (customers[i].status == active)
    {
        bank_details();
        printf("Name       : %s \t%s\n", customers[i].name, customers[i].gender);
        printf("A/c Type   : %s\n", customers[i].account_type);
        long long last_four_digit = customers[i].account % 10000;
        printf("Account Numner:\tXXXXXXX%lld\n", last_four_digit);
        if (strcmp(customers[i].account_type, "current account") == 0 && customers[i].balance < 5000)
        {
            printf("REMIANING BALANCE: %.2f\t \n", customers[i].balance);
            printf("WARNING: minimun balance should be 5000 rupees\nyour balance is lower than minimum balance,reach your minimum limit condiotion otherwise bank will cahrge 100 rupees per day. thankyou\n");
        }
        else if (strcmp(customers[i].account_type, "saving account") == 0)
        {
            printf("REMIANING BALANCE: %.2f\t \n", customers[i].balance);
        }
        else
        {
            printf("REMIANING BALANCE: %.2f\t \n", customers[i].balance);
        }
    }
    else if (customers[i].status == inactive)
        printf("This account is currently inactive. Transactions are not permitted.");
    else
    {
        printf("Account closed. No further transactions can be performed.");
    }
}
void recipt(int i)
{
    bank_details();
    int j = customers[i].trasCount - 1;
    if (j < 0)
        return;
    customers[i].transactions[j].transaction_id = transaction_number();
    printf("Transaction ID :  SBIN%lld\n", customers[i].transactions[j].transaction_id);
    time_t current_time = time(NULL);
    struct tm date = *localtime(&current_time);
    customers[i].transactions[j].transaction_date.day = date.tm_mday;
    customers[i].transactions[j].transaction_date.month = date.tm_mon + 1; // store real date and time during transaction happened.
    customers[i].transactions[j].transaction_date.year = date.tm_year + 1900;
    customers[i].transactions[j].transaction_time.hour = date.tm_hour;
    customers[i].transactions[j].transaction_time.min = date.tm_min;
    printf("DATE: \t\t  TIME \n%02d/%02d/%04d \t  %02d:%02d\n", customers[i].transactions[j].transaction_date.day, customers[i].transactions[j].transaction_date.month, customers[i].transactions[j].transaction_date.year, customers[i].transactions[j].transaction_time.hour, customers[i].transactions[j].transaction_time.min);

    long long last_four_digit = customers[i].account % 10000;
    printf("Acc No\t\t: XXXXXXX%lld\n", last_four_digit);
    // deposit and withdraw amount on the deposite and withdraw fuction with available balance
}
int creataccount(int i)
{
    int n;
    int OTP = 123456; // otp for mobile number verification.
    bool name_true = false, dob_true = false, customer_addhar_true = false, account_open = true;
    customers[i].balance = 0.0;
    customers[i].trasCount = 0;
    time_t current_time = time(NULL);
    struct tm date = *localtime(&current_time);
    printf("CUSTOMER ID:\t %d\n", i + 1000);
    customers[i].open_date.day = date.tm_mday;
    customers[i].open_date.month = date.tm_mon + 1; // store opening  date and time
    customers[i].open_date.year = date.tm_year + 1900;
    customers[i].opening_time.hour = date.tm_hour;
    customers[i].opening_time.min = date.tm_min;
    printf("opening date:  %02d/%02d/%04d\n", customers[i].open_date.day, customers[i].open_date.month, customers[i].open_date.year);
    printf("opening time:  %02d:%02d\n", customers[i].opening_time.hour, customers[i].opening_time.min);
    getchar();
    for (int j = 1; j <= 3; j++)
    {
        printf("CUSTOMER NAME:\t ");
        fgets(customers[i].name, sizeof(customers[i].name), stdin);
        customers[i].name[strcspn(customers[i].name, "\n")] = '\0';
        if (strlen(customers[i].name) > 2)
        {
            name_true = true;
            break;
        }
        else
            printf("Invalid name.\n");
    }
    for (int j = 1; j <= 3; j++)
    {
        printf("FATHER NAME  :\t ");
        fgets(customers[i].father_name, sizeof(customers[i].father_name), stdin);
        customers[i].father_name[strcspn(customers[i].father_name, "\n")] = '\0';
        if (strlen(customers[i].father_name) > 2)
        {
            break;
        }
        else
            printf("Invalid name.\n");
    }
    for (int j = 1; j <= 3; j++)
    {
        printf("For date of birth:\nEnter day  : ");
        scanf("%d", &customers[i].dd);
        printf("Enter month: ");
        scanf("%d", &customers[i].mm);
        printf("Enter year : ");
        scanf("%d", &customers[i].yyyy);
        if ((customers[i].dd > 0 && customers[i].dd < 31) && (customers[i].mm > 0 && customers[i].mm < 13) && (customers[i].yyyy > 1900))
        {
            printf("DOB\t : %02d/%02d/%04d\n", customers[i].dd, customers[i].mm, customers[i].yyyy);
            dob_true = true;
            break;
        }
        else
            printf("Invalid Date\n");
    }

    printf("GENDER       :  1:\t MALE\n\t\t2:\t FEMALE\n\t\t3:\t OTHER\t\t");
    scanf("%d", &n);
    getchar();
    if (n == 1)
        strcpy(customers[i].gender, "male");
    if (n == 2)
        strcpy(customers[i].gender, "female");
    if (n == 3)
    {
        fgets(customers[i].gender, sizeof(customers[i].gender), stdin);
        customers[i].gender[strcspn(customers[i].gender, "\n")] = '\0';
    }
    for (int j = 1; j <= 3; j++)
    {
        printf("AGE          :\t ");
        scanf(" %d", &customers[i].age);
        if (customers[i].age <= 0 || customers[i].age > 200)
        {
            printf("Invalid age\n");
        }
        else
        {
            break;
        }
    }
    getchar();
    if (customers[i].age < 18)
    {
        printf("GUARDIAN NAME:\t ");
        fgets(customers[i].guardian_name, sizeof(customers[i].guardian_name), stdin);
        customers[i].guardian_name[strcspn(customers[i].guardian_name, "\n")] = '\0';
        printf("RELATION    :\t ");
        fgets(customers[i].guardian_relation, sizeof(customers[i].guardian_relation), stdin);
        customers[i].guardian_relation[strcspn(customers[i].guardian_relation, "\n")] = '\0';
        for (int j = 0; j < 3; j++)
        {
            printf("GUARDIAN ADDHAR No.  :\t ");
            fgets(customers[i].guardian_addhar, sizeof(customers[i].guardian_addhar), stdin);
            customers[i].guardian_addhar[strcspn(customers[i].guardian_addhar, "\n")] = '\0';
            if (strlen(customers[i].guardian_addhar) != 12)
                printf("invalid addhar number, please try again\n");
            else
                break;
        }
    }
    for (int j = 1; j <= 5; j++)
    {
        printf("CUSTOMER ADDHAR No.:\t "); // kyc
        fgets(customers[i].customer_id, sizeof(customers[i].customer_id), stdin);
        customers[i].customer_id[strcspn(customers[i].customer_id, "\n")] = '\0';
        if (strlen(customers[i].customer_id) != 12)
            printf("invalid addhar number.\n");
        else
        {
            customer_addhar_true = true;
            break;
        }
    }
    for (int j = 1; j <= 3; j++)
    {
        printf("\t1: Add PAN card\t 2: next\t");
        scanf("%d", &n);
        getchar();
        if (n == 1)
        {
            for (int j = 1; j <= 3; j++)
            {
                printf("PAN NUMBER :\t ");
                fgets(customers[i].customer_PAN, sizeof(customers[i].customer_PAN), stdin);
                customers[i].customer_PAN[strcspn(customers[i].customer_PAN, "\n")] = '\0';
                if (strlen(customers[i].customer_PAN) == 10)
                    break;
                else
                    printf("invalid PAN number, please try again\n");
            }
            break;
        }
        else if (n == 2)
            break;
        else
            printf("Invalid input\n");
    }
    getchar();
    printf("customer OCCUPATION:\t ");
    fgets(customers[i].occupation, sizeof(customers[i].occupation), stdin);
    customers[i].occupation[strcspn(customers[i].occupation, "\n")] = '\0';
    for (int j = 1; j <= 4; j++)
    {
        int input_OTP;
        long long mobile;
        long long min = 999999999;
        long long max = 10000000000;
        printf("MOBILE No.     :\t ");
        scanf("%lld", &mobile);

        if (mobile > min && mobile < max)
        {
            for (int k = 1; k < 4; k++)
            {
                if (k > 3)
                {
                    printf("Too many attempt,please try after some time\n");
                    break;
                }
                printf("Enter OTP send to registered mobile number : "); // opt is 123456
                scanf("%d", &input_OTP);
                if (input_OTP == OTP)
                {
                    printf("mobile number verified successfull\n");
                    customers[i].mobile = mobile;
                    break;
                }
                else
                {
                    printf("Incorrect OTP.\n");
                }
            }
            break;
        }
        else
        {
            printf("invalid mobile number.\n");
        }
    }

    getchar();
    printf("EMAIL ID           :\t ");
    fgets(customers[i].email, sizeof(customers[i].email), stdin);
    customers[i].email[strcspn(customers[i].email, "\n")] = '\0';

    printf("CUSTOMER ADDRESS  :\t ");
    fgets(customers[i].address, sizeof(customers[i].address), stdin);
    customers[i].address[strcspn(customers[i].address, "\n")] = '\0';
    int input_pin;

    for (int j = 1; j < 3; j++)
    {
        printf("PIN CODE:\t ");
        scanf("%d", &input_pin);
        if (input_pin > 99999 && input_pin < 1000000)
        {
            customers[i].pincode = input_pin;
            break;
        }
        else
        {
            printf("Invalid pincode, please try again\n");
        }
    }
    for (int j = 1; j <= 3; j++)
    {
        printf("ACCOUNT TYPE:\t \t1- saving account\t\t2-current account\t");
        scanf("%d", &n);
        getchar();
        if (n == 1)
        {
            strcpy(customers[i].account_type, "saving account");
            printf("FIRST deposit DURING ACCOUNT OPENING : \t ");
            scanf("%f", &customers[i].balance);
            if (customers[i].balance > 0)
            {
                // Record initial deposit in transaction
                customers[i].transactions[customers[i].trasCount].cradit_amount = customers[i].balance;
                customers[i].transactions[customers[i].trasCount].dabit_amount = 0;
                customers[i].transactions[customers[i].trasCount].trans_balance = customers[i].balance;
                customers[i].transactions[customers[i].trasCount].transaction_date = customers[i].open_date;
                customers[i].transactions[customers[i].trasCount].transaction_time = customers[i].opening_time;
                customers[i].transactions[customers[i].trasCount].transaction_id = transaction_number();
                customers[i].trasCount++;
            }
            break;
        }
        else if (n == 2)
        {
            strcpy(customers[i].account_type, "current account");
            printf("FIRST deposit DURING ACCOUNT OPENING (min balance 5000): \t ");
            scanf("%f", &customers[i].balance);
            if (customers[i].balance > 0)
            {
                // Record initial deposit in transaction for current account
                customers[i].transactions[customers[i].trasCount].cradit_amount = customers[i].balance;
                customers[i].transactions[customers[i].trasCount].dabit_amount = 0;
                customers[i].transactions[customers[i].trasCount].trans_balance = customers[i].balance;
                customers[i].transactions[customers[i].trasCount].transaction_date = customers[i].open_date;
                customers[i].transactions[customers[i].trasCount].transaction_time = customers[i].opening_time;
                customers[i].transactions[customers[i].trasCount].transaction_id = transaction_number();
                customers[i].trasCount++;
            }
            break;
        }
        else if (n > 2 || n <= 0)
            printf("INVALID INPUT\n");
    }
    int input_security;
    for (int j = 1; j < 4; j++)
    {
        printf("SET 6 DIGIT SECURITY PIN:\t "); // ENTER THE SIZE
        scanf("%d", &input_security);
        if (j > 3)
        {
            printf("Too many attempt, please try after some time");
            break;
        }
        if (input_security > 99999 && input_security < 1000000)
        {
            customers[i].security_pin = input_security;
            break;
        }
        else
        {
            printf("Invalid pincode, please try again\n");
        }
    }
    if (name_true == true && dob_true == true && customer_addhar_true == true)
    {
        printf("\n\t!! ACCOUNT OPEN SUCCESSFULLY !!\n");
        customers[i].status = active;
        printf("CUSTOMERS ACCOUNT ACTIVATED SUCCESSFULLY\n");
        customers[i].account = account_number();
        customers[i].CIF_no = CIF_number();
        customer_count++;
        printf("======================================================================================================================\n");

        printf("Name       : %s\n", customers[i].name);
        printf("CIF number : %lld\n", customers[i].CIF_no);
        printf("Account No.: %lld\n\n", customers[i].account);
        printf("=========================================================================================================================\n");
        printf("would you like to print recipt\n1: yes\t 2: no\t");
        scanf("%d", &n);

        if (n == 1)
        {
            recipt(i);
            if (account_open == true)
            {
                printf("Avl Balance: %f\n", customers[i].balance);
                printf("thank for using our service !!\n");
            }
            else
            {
                printf("Amount during account open is: 0.00\n");
                printf("thank for using our service !!\n");
            }
        }
        printf("=========================================================================================================================\n");
    }
    else
    {
        printf("Account opening is failed.\n");
        if (name_true == false)
            printf("REASON: Invalid name\n");
        if (dob_true == false)
            printf("REASON: Invalid DOB\n");
        if (customer_addhar_true == false)
            printf("REASON: Invalid Addhar number");
        printf("=========================================================================================================================\n");
    }

    return 0;
}

void deposit(int i)
{
    int n, choice, input_security;
    bool deposit1 = false, deposit_true = false, deposit2 = false;
    float deposit_amount;
    char IFSCcode = "SBI00321524"; // IFSC code required during money transfer to another account.
    if (customers[i].status == active)
    {
        for (int m = 1; m <= 3; m++)
        {
            printf("1:self Deposit\t 2: Transfer Amount\t");
            scanf("%d", &choice);
            if (choice == 1)
            {

                printf("Account holder name : %s\n", customers[i].name);
                for (int k = 1; k <= 3; k++)
                {
                    int flag3 = 0;
                    printf("Enter Deposit amount      : ");
                    scanf("%f", &deposit_amount);
                    if (deposit_amount > 0)
                    {
                        for (int j = 1; j <= 3; j++)
                        {
                            printf("Enter security pin  : ");
                            scanf("%d", &input_security);
                            if (customers[i].security_pin == input_security)
                            {
                                deposit1 = true;
                                customers[i].transactions[customers[i].trasCount].cradit_amount = deposit_amount;
                                customers[i].balance += deposit_amount;
                                customers[i].transactions[customers[i].trasCount].trans_balance = customers[i].balance;
                                printf("Transaction successfull!\n");
                                deposit_true = true;
                                customers[i].trasCount++;
                                break;
                            }
                            else
                                printf("invalid security code, try again\n");
                        }
                    }
                    else if (deposit_amount <= 0)
                    {
                        printf("Insufficient amount or Invalid deposit amount\n");
                    }
                    break;
                }
            }
            else if (choice == 2)
            {
                long long input_acc;
                for (int j = 1; j <= 3; j++)
                {
                    printf("Enter Benificfiery account No.: ");
                    scanf("%lld", &input_acc);
                    getchar();
                    char bank_IFSC[1][12];
                    printf("Enter IFSC No.\t\t\t\t: ");
                    fgets(bank_IFSC[0], sizeof bank_IFSC[0], stdin);
                    bank_IFSC[0][strcspn(bank_IFSC[0], "\n")] = '\0';

                    for (int l = 0; l < customer_count; l++)
                    {
                        if ((customers[l].account == input_acc) && (strcmp(bank_IFSC[0], IFSCcode) == 0)) // if not match then what
                        {
                            printf(" Benificiary name   : %s\n", customers[l].name);
                            for (int a = 1; a <= 3; a++)
                            {
                                printf("Enter Deposit amount : ");
                                scanf("%f", &deposit_amount);
                                if (customers[i].balance < deposit_amount)
                                {
                                    printf("Insufficient amount or Invalid deposit amount \n ");
                                }
                                else
                                {
                                    for (int j = 0; j < 3; j++)
                                    {
                                        printf("Enter security pin  : ");
                                        scanf("%d", &input_security);
                                        if (customers[i].security_pin == input_security)
                                        {
                                            deposit2 = true;
                                            customers[i].transactions[customers[i].trasCount].dabit_amount = deposit_amount;
                                            customers[l].balance += deposit_amount; // reciver account amount
                                            customers[i].balance -= deposit_amount; // sender balance
                                            customers[i].transactions[customers[i].trasCount].trans_balance = customers[i].balance;
                                            printf("Transfer successful.\n");
                                            customers[i].trasCount++;
                                            deposit_true = true;
                                            break;
                                        }
                                        else
                                            printf("invalid security code, try again\n");
                                    }
                                    break;
                                }
                            }
                        }
                    }
                    if (deposit2 == false)
                        printf("Invalid IFSC code. or Benificiery Account does not found.\n");
                    else
                        break;
                }
            }
            else
                printf("Invalid Input\n");
            break;
        }
        if (deposit_true == false)
        {
            printf("Transaction failed.\n");
        }
        else
        {
            printf("would you like to print recipt\n1: yes\t 2: no\t");
            scanf("%d", &n);
            printf("=========================================================================================================================\n");

            if (n == 1)
            {
                recipt(i);
                if (choice == 1)
                {
                    printf("Cradit Amount: %f\n", customers[i].transactions[customers[i].trasCount - 1].cradit_amount);
                    printf("Avl Balance  : %f\n", customers[i].balance);
                    printf("Thank you for using our service.\n");
                }
                else if (choice == 2)
                {
                    printf("Dabited Amount: %f\n", customers[i].transactions[customers[i].trasCount - 1].dabit_amount);
                    printf("Avl Balance   : %f\n", customers[i].balance);
                    printf("Thank you for using our service.\n");
                }
            }
            else if (n == 2)
                printf("Thank you for using our service.\n");
            else
                printf("invalid Input");
        }
    }
    else if (customers[i].status == inactive)
        printf("This account is currently inactive. Transactions are not permitted.\n");
    else
    {
        printf("Account closed. No further transactions can be performed.\n");
    }
}
void withdraw(int i)
{
    int n, input_security;
    float input_amount;
    bool withdraw_amount = false;
    printf("customer name :  %s\n", customers[i].name);

    if (customers[i].status == active)
    {
        for (int l = 1; l <= 3; l++)
        {

            printf("enter the amount :  ");
            scanf("%f", &input_amount);
            if ((input_amount > 0) && (input_amount <= customers[i].balance))
            {
                for (int m = 1; m <= 4; m++)
                {
                    if (m == 4)
                    {
                        printf("Too may attemps, please try again\n");
                        break;
                    }
                    else
                    {
                        printf("enter security pin :  ");
                        scanf("%d", &input_security);
                        if (input_security == customers[i].security_pin)
                        {
                            customers[i].transactions[customers[i].trasCount].dabit_amount = input_amount;
                            customers[i].balance -= input_amount;
                            customers[i].transactions[customers[i].trasCount].trans_balance = customers[i].balance;
                            printf("transaction successfull !!\n");
                            customers[i].trasCount++;
                            withdraw_amount = true;
                            break;
                        }
                        else
                        {
                            printf("Invalid security pin\n");
                        }
                    }
                }
                break;
            }
            else
            {
                printf("Invalid amount or Insufficient balance.\n");
            }
        }
        if (withdraw_amount == false)
            printf("Transaction failed. Try again\n");
        else
        {
            printf("would you like to print recipt\n1: yes\t 2: no\t");
            scanf("%d", &n);
            printf("=========================================================================================================================\n");

            if (n == 1)
            {
                recipt(i);
                if (withdraw_amount == true)
                {
                    printf("Dabit Amount: %f\n", customers[i].transactions[customers[i].trasCount - 1].dabit_amount);
                    printf("Avl Balance : %f\n", customers[i].balance);
                    printf("thank for using our service !!\n");
                }
                else
                {
                    printf("transaction failed.\n");
                    printf("REASON: Insufficient balance or network failure\n");
                    printf("thank for using our service !!\n");
                }
            }
            else if (n == 2)
                printf("Thank you for using our service !!\n");
            else
                printf("invalid input\n");
        }
    }
    else if (customers[i].status == inactive)
        printf("This account is currently inactive. Transactions are not permitted.\n");
    else
    {
        printf("Account closed. No further transactions can be performed.\n");
    }
}

void transaction_details(int i)
{
    bank_details();
    printf("\nTransaction Details for Account: %lld\n", customers[i].account);
    printf("==============================================================================================================\n");
    printf("Date       \tTime     \tTransaction ID  \tCredit  \tDebit   \tBalance\n");
    printf("==============================================================================================================\n");
    if (customers[i].trasCount != 0)
    {
        for (int j = customers[i].trasCount - 1; j >= 0; j--)
        {
            printf("%02d/%02d/%04d  \t%02d:%02d\t\tSBIN%lld  \t%.2f\t\t%.2f\t\t%.2f\n",
                   customers[i].transactions[j].transaction_date.day,
                   customers[i].transactions[j].transaction_date.month,
                   customers[i].transactions[j].transaction_date.year,
                   customers[i].transactions[j].transaction_time.hour,
                   customers[i].transactions[j].transaction_time.min,
                   customers[i].transactions[j].transaction_id,
                   customers[i].transactions[j].cradit_amount,
                   customers[i].transactions[j].dabit_amount,
                   customers[i].transactions[j].trans_balance);
        }
    }
    else
        printf("No transaction happened.\n");
    printf("==============================================================================================================\n");
}
void customer_passbook(int i)
{
    if (customers[i].status == active)
    {
        bank_details();
        printf("Name       : %s \t%s\n", customers[i].name, customers[i].gender);
        printf("S/D/o      : %s\n", customers[i].father_name);
        printf("CIF number : %lld\n", customers[i].CIF_no);
        printf("Account No.: %lld\n", customers[i].account);
        printf("A/c Type   : %s\n", customers[i].account_type);
        printf("Address    : %s\n", customers[i].address);
        printf("Phone No.  : %lld\n", customers[i].mobile);
        printf("Email      : %s\n", customers[i].email);
        if (customers[i].age < 18)
        {
            printf("D.O.B.(minor): %d/%d/%d\n", customers[i].dd, customers[i].mm, customers[i].yyyy);
            printf("guardian name: %s\n", customers[i].guardian_name);
        }
        else
        {
            printf("D.O.B. \t:%d/%d/%d\n", customers[i].dd, customers[i].mm, customers[i].yyyy);
        }
        printf("Addhar No.  : %s   \t\tPAN: %s\n", customers[i].customer_id, customers[i].customer_PAN);
        printf("A/c opening Dt   : %02d/%02d/%04d\n", customers[i].open_date.day, customers[i].open_date.month, customers[i].open_date.year);
    }
    else if (customers[i].status == inactive)
        printf("This account is currently inactive. Transactions are not permitted.\n");
    else
    {
        printf("Account closed. No further transactions can be performed.\n");
    }
}
void close_account(int i)
{
    int n;
    long long input_mobile;
    int input_otp, share_otp = 123456;
    time_t current_time = time(NULL);
    struct tm date = *localtime(&current_time);

    customers[i].close_date.day = date.tm_mday;
    customers[i].close_date.month = date.tm_mon + 1; // store real date and time during account closing.
    customers[i].close_date.year = date.tm_year + 1900;
    customers[i].closing_time.hour = date.tm_hour;
    customers[i].closing_time.min = date.tm_min;
    printf("closing date:  %02d/%02d/%04d\n", customers[i].close_date.day, customers[i].close_date.month, customers[i].close_date.year);
    printf("closing time: %02d:%02d\n", customers[i].closing_time.hour, customers[i].closing_time.min);
    for (int j = 1; j <= 3; j++)
    {
        printf("Enter registered mobile number: ");
        scanf("%lld", &input_mobile);
        if (input_mobile == customers[i].mobile)
        {
            printf("6 digit opt is shared to your registered mobile number.\n");
            Sleep(2000);
            printf("Enter otp : "); // otp is 123456
            scanf("%d", &input_otp);
            if (input_otp == share_otp)
            {
                printf("Available balance is: %.2f\n", customers[i].balance);
                if (customers[i].balance > 0)
                {
                    printf("Account closure failed.\n");
                    printf("Reason: Remaining balance must be withdrawn before closing the account.\n");
                    break;
                }
                else if (customers[i].balance == 0)
                {
                    for (int k = 1; k <= 4; k++)
                    {
                        if (k == 4)
                        {
                            printf("Too many attaimpts, please try after some time\n");
                            break;
                        }
                        printf("WARNING: Would you like to close the account.\t1: yes\t2: no\t");
                        scanf("%d", &n);
                        if (n == 1)
                        {
                            printf("Conformation request send to registered mobile number\n"); // done by user
                            printf("1: conform\t 2: Reject\t\t");
                            scanf("%d", &n);
                            if (n == 1)
                            {
                                printf("Enter 6 digit OTP send to registered mobile number:  ");
                                scanf("%d", &input_otp);
                                if (input_otp == share_otp)
                                {
                                    printf("Account closure successful\n");
                                    customers[i].status = close;
                                    break;
                                }
                                else
                                {
                                    printf("Invalid OTP\n");
                                }
                            }
                            else if (n == 2)
                            {
                                printf("Account closure failed.\n");
                                printf("Reason: conformation request not accepted.\n");
                                break;
                            }
                            else
                            {
                                printf("Invalid input\n");
                            }
                        }
                        else if (n == 2)
                        {
                            printf("Account closure cancelled.\n");
                            break;
                        }
                        else
                        {
                            printf("Invalid Input\n");
                        }
                    }
                    break;
                }
            }
            else
            {
                printf("Invalid otp !!, try again !!\n");
            }
        }
        else
        {
            printf("Invalid mobile number,please try again\n");
        }
    }
}
void customer_detail(int i)
{
    if (customers[i].status == close)
    {
        printf("Account status: Closed.\n");
        printf("close account_date: %02d/%02d/%04d\n", customers[i].close_date.day, customers[i].close_date.month, customers[i].close_date.year);
    }
    else
    {
        printf("Account status: Active\n");
    }
    bank_details();
    printf("account open_date:\t%02d/%02d/%04d\n", customers[i].open_date.day, customers[i].open_date.month, customers[i].open_date.year);
    printf("CIF No.       :\t%lld\n", customers[i].CIF_no);
    printf("Account No.   :\t%lld\n", customers[i].account);
    printf("customer Name :\t%s\n", customers[i].name);
    printf("Father Name   :\t%s\n", customers[i].father_name);
    if (customers[i].age < 18)
    {
        printf("D.O.B.(minor) : %d/%d/%d\n", customers[i].dd, customers[i].mm, customers[i].yyyy);
        printf("guardian name : %s\n", customers[i].guardian_name);
        printf("guardian's id : %s\n", customers[i].guardian_addhar);
    }
    else
        printf("DOB       : %d/%d/%d\n", customers[i].dd, customers[i].mm, customers[i].yyyy);
    printf("mobile number   : %lld\n", customers[i].mobile);
    printf("Email id's      : %s\n", customers[i].email);
    printf("Customer Addhar : %s\n", customers[i].customer_id);
    printf("customer PAN    : %s\n", customers[i].customer_PAN);
    printf("customer Address: %s\n", customers[i].address);
    printf("pincode No.     : %d\n", customers[i].pincode);
}
void customer_list()
{
    bank_details();
    printf("S.N\tCIF No.\t\tAccount No.\t\tBalance\t\tStatus\n");
    for (int i = 0; i < customer_count; i++)
    {
        char status_str[20];
        if (customers[i].status == active)
            strcpy(status_str, "Active");
        else if (customers[i].status == close)
            strcpy(status_str, "Closed");
        else if (customers[i].status == inactive)
            strcpy(status_str, "Inactive");
        else
            strcpy(status_str, "Unknown");
        printf("%d\t%lld\t%lld\t\t%.2f\t\t%s\n", i + 1, customers[i].CIF_no, customers[i].account, customers[i].balance, status_str);
    }
}
int main()
{
    system("color 0B");
    srand(time(0)); // random number
    int choice, x, m, n;
    int insysyem = 0;
    for (int z = 1; z <= 10; z++)
    {
        if (z >= 2)
        {
            for (int k = 1; k <= 3; k++)
            {
                printf("WOULD  YOU LIKE TO\t1: LOGIN\n\t\t\t2: EXIT\t");
                scanf("%d", &m);
                if (m > 2 || m < 0)
                    printf("Invalid input\n");
                else if (m == 2)
                {
                    exit(1);
                }

                else
                {
                    typeEffect("\n\t\t\t!! THANK YOU !!\n", 100);
                    break;
                }
            }
        }
        printf("==========================================================================================================================================\n");
        typeEffect("\t\t\tSYSTEM IS LOADING.....", 50);
        Sleep(1000);
        typeEffect("\n\t\t   !! SYSTEM LOADED SUCCSSFULLY !!\n", 50);
        for (int a = 1; a <= 3; a++)
        {
            printf("\n\t\t\t1: Login\t");
            scanf("%d", &m);
            getchar();
            if (m == 1)
            {
                employee();
                typeEffect("\t\t!!WELCOME TO STATE BANK OF INDIA!!\n", 50);
                break;
            }
            else
                printf("Invalid input\n");
        }
        printf("========================================================================================================================================================\n");
        while (1) // infinite loop
        {
            bool account_found = false;
            printf("MENU\n1: CREAT ACCOUNT \t\t4: PASSBOOK\t\t\t7: CUSTOMER LIST\n2: DEPOSIT AMOUNT\t\t5: BALANCE INQUIRY\t\t8: CLOSE ACCOUNT\n3: WITHDRAW AMOUNT\t\t6: CUSTOMER_DETAILS\t\t9: SYSTEM LOGOUT\n10: TRANSACTION DETAILS\n");
            printf("======================================================================================================================================================\n");
            printf("YOUR CHOICE:\t\t");
            scanf("%d", &choice);
            if (choice < 1 || choice > 10)
            {
                printf("INVALID INPUT\n");
            }
            else if (choice == 1)
            {
                for (;;)
                {
                    creataccount(customer_count);

                    printf("\n1:\t add new customer\t\t2:\t exit\t\t");
                    scanf("%d", &m); // exit
                    if (m == 1)
                        typeEffect("Adding new customer...\n", 50);
                    else if (m == 2)
                        break;
                    else
                        printf("Invalid input\n");
                }
            }
            else if (choice == 7)
            {
                customer_list();
            }
            else if (choice == 8)
            {
                long long input_acc;
                printf("account number : ");
                scanf("%lld", &input_acc);
                for (int i = 0; i < customer_count; i++)
                {
                    if (customers[i].account == input_acc)
                    {
                        if (customers[i].status != close)
                        {
                            printf("======================================================================================================================================================\n");
                            printf("Active account\n");
                            close_account(i);
                        }
                        else
                        {
                            printf("======================================================================================================================================================\n");
                            printf("!! Account is alrady closed !!\n");
                        }
                    }
                }
            }
            else if (choice == 9)
            {
                typeEffect("\t\t\tSYSTEM LOGOUT SUCCESSFULL !!\n", 50);
                break;
            }
            else
            {

                long long input_acc;
                printf("account number: ");
                scanf("%lld", &input_acc);
                for (int i = 0; i < customer_count; i++)
                {
                    if (customers[i].account == input_acc)
                    {
                        account_found = true;
                        if (choice == 2)
                            deposit(i);
                        else if (choice == 3)
                            withdraw(i);
                        else if (choice == 4)
                        {
                            printf("======================================================================================================================================================\n");
                            customer_passbook(i);
                        }
                        else if (choice == 5)
                        {
                            printf("======================================================================================================================================================\n");
                            balance_inquary(i);
                        }
                        else if (choice == 6)
                        {
                            printf("======================================================================================================================================================\n");
                            customer_detail(i);
                        }
                        else if (choice == 10)
                        {
                            printf("======================================================================================================================================================\n");
                            transaction_details(i);
                        }
                        break;
                    }
                }
                if (account_found == false)
                    printf("Account number does not found !!\n");
            }
            printf("=================================================================================================================================================\n");
            printf("1:\t continue servise\t\t2:\t exit servise\t\t");
            scanf("%d", &x); // exit
            if (x == 2)
                break;
        }

        printf("============================================================================================================================================================\n");
    }
    return 0; // The Programe rest..!!
}