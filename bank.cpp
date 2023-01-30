#include<iostream>
#include<string.h>
#include<limits>
using namespace std;

class Account {
    private :
        string name;
        long int  accountNumber;
        float balance;	
    public :	
        void createAccount(string name, long int accountNumber,float balance) {
            this ->name = name;
            this->accountNumber = accountNumber;
            this->balance = balance;
	}
        
	void deposit(int amount) {
	    balance += amount;
            cout <<"***Amount deposit successfully***" << endl;
	}
  
        void withdraw(int amount) {
	    if(balance  >= amount) {
	        balance -= amount;
		cout <<"***Amount Withdraw successfully***" << endl;
	    } else {
	          cout << "***Insufficient amount to withdraw***" << endl;
	    }	
	}
        
        void closeAccount() {
	    balance = 0;
	}	    
	
		    
        void listAccount () {
            cout << "Name:" << name << endl;
	    cout << "Account Number:" << accountNumber << endl;
	    cout << "Account balance:" << balance << endl;
	    
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
    string name;
    long int accountNumber;
    float balance;
    int amount;	    

    while(1) {
        cout << "1.Create account\n2.Check balance\n3.Deposit\n4.Withdraw\n5.close Account\n6.List all Accounts\n7.Exit\n";
        cout << "Enter the choice:";
        cin >> choice;

	switch(choice) {	
            case 1:
                if(number  < 10) { 
                    cout << "Enter the name:";
                    cin >> name;
                    cout << "Enter the account number:";
                    cin >> accountNumber;
                    cout << "Enter the initial Amount:";
                    cin >> balance;
		    account[number].createAccount(name, accountNumber,balance);
		    number++;
		    cout <<"***Account created successfully***" << endl;
		} else {
		      cout << "***Created maximum no.of account***\n";
		} 
	        break;
		  
	    case 2:
                cout << "Enter the Account number to check balance:";
                cin >>accountNumber;
           
	        for(index = 0; index < number; index ++) {
                    if(account[index].getAccountNumber() == accountNumber) {
                        cout <<"Account balance:" << account[index].getBalance() <<endl;		         
			break;
		    }
		}
	            
		if (index == number) {
                    cout << "***Enter correct Account Number***" <<endl;
		}
	        break;

            case 3:
	        cout << "Enter the Account number to deposit:";
                cin >>accountNumber;

                for(index = 0; index < number; index ++) {
                    if(account[index].getAccountNumber() == accountNumber) { 	                       cout << "Enter deposit amount:";
	                cin >> amount;
                        account[index].deposit(amount);
		        break;	  
		    }
		}

	        if(index == number) {
		    cout << "***Enter correct Account Number***" <<endl;
		}
                break;

	    case 4:
	        cout << "Enter the Account number to withdraw:";
                cin >>accountNumber;

                for(index = 0; index < number; index ++) {
  	            if(account[index].getAccountNumber() == accountNumber) {
                        cout << "Enter withdraw amount:";
                        cin >> amount;
                        account[index].withdraw(amount);
	       	        break;
		    }
		}

		if(index == number) {
                    cout << "***Enter correct Account Number***" <<endl;
		}
                break;
	      
	    case 5:
	        cout << "Enter the Account number to close:";
                cin >>accountNumber;

                for(index = 0; index < number; index ++) {
                    if(account[index].getAccountNumber() == accountNumber) {
                        account[index].closeAccount();
	                break;
		    }
		}

		if(index == number) {
                    cout << "***Enter correct Account Number***" <<endl;
		}
		break;
                
	    case 6:
                for(index = 0; index < number; index ++) {
                    account[index].listAccount();
		}
	        break;
	    
	    case 7:
	        exit(0);
            
	    default :
		cout << "***Enter correct choice***" << endl;
	} 
    }
}
