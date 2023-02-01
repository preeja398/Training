#include<iostream>
#include<cstring>
using namespace std;

class Account {
    private :
        char name[50];
        long int  accountNumber;
        float balance;	
    public :	
        void createAccount(char name[], long int accountNumber,float balance) {
           strcpy(this->name, name);
            this->accountNumber = accountNumber;
            this->balance = balance;
	}

	void deposit(int amount) {
	    balance += amount;
            printf("***Amount deposit successfully***\n") ;
	}

        void withdraw(int amount) {
	    if(balance  >= amount) {
	        balance -= amount;
		printf("***Amount Withdraw successfully***\n");
	    } else {
	          printf("***Insufficient amount to withdraw***\n");
	    }	
	}

        void closeAccount() {
	    balance = 0;
	}	    

        void listAccount () {
            printf("Name:%s\n", name);
	    printf("Account Number:%ld\n", accountNumber);
	    printf("Account balance:%f\n", balance);

	}

	long int getAccountNumber() {
	    return accountNumber;
	}

	float getBalance() { 
	    return balance;
	}	    
};	


int main () {
    Account *account= new Account[10];
    int choice;
    int index;
    int number = 0;
    char name[50];
    long int accountNumber;
    float balance;
    int amount;	    

    while(1) {
        printf("1.Create account\n2.Check balance\n3.Deposit\n4.Withdraw\n5.close Account\n6.List all Accounts\n7.Exit\n");
        printf("Enter the choice:\n");
	scanf("%d", &choice);

	if((getchar()) != '\n') {
	    printf("***Enter the valid choice***\n");
            while((getchar()) != '\n');
	} else {	    

            switch(choice) {	
                case 1:
                    if(number  < 10) { 
                        printf("Enter the name:\n");
                        scanf("%s", name);
                        printf("Enter the account number:\n");
                        scanf("%ld", &accountNumber);
                        printf("Enter the initial Amount:\n");
                        scanf("%f", &balance);
		        account[number].createAccount(name, accountNumber,balance);
		        number++;
		        printf("***Account created successfully***\n");
                    } else {
		          printf("***Created maximum no.of account***\n");
                      } 
	            break;

	        case 2:
                    printf("Enter the Account number to check balance:\n");
                    scanf("%ld", &accountNumber);

	            for(index = 0; index < number; index ++) {
                        if(account[index].getAccountNumber() == accountNumber) {
                             printf("Account balance:%f\n", account[index].getBalance());		         
			     break;
                        }
		    }

		    if (index == number) {
                        printf("***Enter correct Account Number***\n");
                    }
	            break;

                case 3:
	            printf("Enter the Account number to deposit:\n");
                    scanf("%ld", &accountNumber);

                    for(index = 0; index < number; index ++) {
                        if(account[index].getAccountNumber() == accountNumber) {
                            printf("Enter deposit amount:\n");
	                    scanf("%d", &amount);
                            account[index].deposit(amount);
		            break;
                        }
		    }

	            if(index == number) {
		        printf("***Enter correct Account Number***\n");
		    }
                    break;

	        case 4:
	            printf("Enter the Account number to withdraw:\n");
                    scanf("%ld", &accountNumber);

                    for(index = 0; index < number; index ++) {
  	                if(account[index].getAccountNumber() == accountNumber) {
                            printf("Enter withdraw amount:\n");
                            scanf("%d", &amount);
                            account[index].withdraw(amount);
	       	            break;
		        }
		    } 

		    if(index == number) {
                        printf("***Enter correct Account Number***\n");
                    }
                    break;

	        case 5:
	            printf("Enter the Account number to close:\n");
                    scanf("%ld", &accountNumber);

                    for(index = 0; index < number; index ++) {
                        if(account[index].getAccountNumber() == accountNumber) {
                            account[index].closeAccount();
	                    break;
		        }
		    }

		    if(index == number) {
                        printf("***Enter correct Account Number***\n");
		    }
		    break;

	        case 6:
                    for(index = 0; index < number; index ++) {
                        account[index].listAccount();
		    }
	            break;

	        case 7:
                    delete [] account;
                    account = nullptr;
	            exit(0);
	    
	        default :
		    printf("***Enter correct choice***\n");
          }
       } 
    }
}
