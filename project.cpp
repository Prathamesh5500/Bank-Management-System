#include<iostream>
#include<fstream>
#include<unistd.h>
using namespace std;

class bank_holder
{
    private:
        char name[40];
        char address[50];
        long long int phn_no;
        char d_o_b[12];
        char today_date[12];
        char addhar_no[20];
        long int acc_no;
        long int bank_bal;
        long int pass;
        long int loan;
        long int FD;
        long int RL;
    public:
        bank_holder()
        {
            bank_bal=0;
            loan=0;
            FD=0;
            RL=0;
        }
        void create_acc();
        void acc_holder_details();
        void deposit();
        void withdrawal();
        void balance_enq();
        void prt_passbook();
        void easy_loan();
        void update_acc();
        void delete_acc();
        void fixed_deposit();
        void return_loan();
        
};

void bank_holder::create_acc()
{   
    int p,t;
    fflush(stdin);
    cout<<"\n\t\tENTER TODAY'S DATE  (*DD/MM/YYYY)           : ";
    cin.getline(today_date,12);
    cout<<"\n\t\tENTER COUSTMER NAME (*only capital letters) : ";
    cin.getline(name,40);
    cout<<"\n\t\tENTER YOUR PERMENANT ADDRESS                : ";
    cin.getline(address,50);
    fflush(stdin);
    cout<<"\n\t\tENTER YOUR PHONE NUMBER                     : ";
    cin>>phn_no;
    fflush(stdin);
    cout<<"\n\t\tENTER YOUR DATE OF BIRTH  (*DD/MM/YYYY)     : ";
    cin.getline(d_o_b,12);
    fflush(stdin);
    cout<<"\n\t\tENTER YOUR ADDHAR NUMBER (*xxxx xxxx xxxx)  : ";
    cin.getline(addhar_no,20);
    fflush(stdin);  
    do
    {
    	cout<<"\n\t\tSET YOUR PASSWORD  (*4 digit number)        : ";
        cin>>p;
    	cout<<"\n\t\tCONFIRM YOUR PASSWORD                       : ";
        cin>>t;
        if(p==t)
        {
            pass=p;
            break;
        }
        cout<<"\n\t\tSOMETHING WENT WRONG !!!";
    }
    while(p!=t);
    acc_no=phn_no/19;
}

void bank_holder::acc_holder_details()
{
    int key;
    cout<<"\n\t\t>ENTER YOUR SIGNATURE (*password) : ";
    cin>>key;
    if(key==pass)
    {
        cout<<"\n\n\t\t___________BANK HOLDER DETAILS___________\n";
        cout<<"\n\t\t>CUSTOMER NAME             : "<<name;
        cout<<"\n\t\t>ACCOUNT NUMBER            : "<<acc_no;
        cout<<"\n\t\t>ISSUED DATE               : "<<today_date;
        cout<<"\n\t\t>CONTACT NUMBER            : "<<phn_no;
        cout<<"\n\t\t>ADDRESS                   : "<<address;
        cout<<"\n\t\t>DATE OF BIRTH             : "<<d_o_b;
        cout<<"\n\t\t>ID PROOF(*addhar number)  : "<<addhar_no;
        cout<<"\n\t\t>loan                      : "<<loan;
        cout<<"\n\t\t>FIXED DEPOSIT             : "<<FD;
    }
    else
    {
        cout<<"\n\n\t\tXXX ENTERED WRONG SIGNATURE XXX";
        cout<<"\n\t\t          TRY AGAIN!!!";
    }
}

void bank_holder::deposit()
{
    int chs;
    long int t;
    cout<<"\n\n\t___________CHOOSE ACCOUNT TYPE___________\n";
    cout<<"\n\t>1.SAVINGS\n\t>2.CURRENT\n\t>";
    cin>>chs;
    cout<<"\n\t>ENTER AMOUNT TO BE DEPOSITED     : ";
    cin>>t;
    bank_bal=bank_bal+t;
    cout<<"\n\n\tDEPOSIT SUCCESSFULL!!!";
    cout<<"\n\tTHANK YOU!!!(*you will get 5% interest/year.)";
    
    ofstream fout;
    fout.open("BANK_HOLDER_DETAILS.txt",ios::app);
    fout<<"\n\n\t\t"<<"*DEPOSIT = "<<t<<"\t"<<"*WITHDRAW = "<<"-"<<"\t*BALANCE = "<<bank_bal<<endl;
    fout.close();
}

void bank_holder::withdrawal()
{
    float w;
    int key;
    cout<<"\n\n\t\t___________WITHDRAWAL___________\n";
    cout<<"\n\t\t>ENTER AMOUNT TO BE WITHDRAW : ";
    cin>>w;
    cout<<"\n\t\t>ENTER YOUR SIGNATURE (*password) : ";
    cin>>key;
    if(key==pass)
    {
        if(w<=bank_bal)
        {
            bank_bal=bank_bal-w;
            cout<<"\n\t\t>WITHDRAWL SUCCESSFULL!!!";
            
            ofstream fout;
            fout.open("BANK_HOLDER_DETAILS.txt",ios::app);
            fout<<"\n\t\t"<<"*DEPOSIT = "<<"-\t"<<"*WITHDRAW = "<<w<<"\t*BALANCE = "<<bank_bal<<endl;
            fout.close();
        }
        else
        {
            cout<<"\n\t\t>XXX WITHDRAWL UNSUCCESSFULL!!! XXX";
            cout<<"\n\t\t     ......OUT OF CASH.........";
            cout<<"\n\t\t            TRY AGAIN!!!";
        }
    }
    else
    {
        cout<<"\n\n\t\tXXX ENTERED WRONG SIGNATURE XXX";
        cout<<"\n\t\t          TRY AGAIN!!!";
    }
}

void bank_holder::balance_enq()
{
    int key;
    cout<<"\n\n\t\t___________BANK BALANCE DETAIL___________\n";
    cout<<"\n\t\t>ENTER YOUR SIGNATURE (*password) : ";
    cin>>key;
    if(key==pass)
    {
        cout<<"\n\t\t>BANK BALANCE   : "<<bank_bal;
        cout<<"\n\t\t>INTEREST(*5%)   : "<<(float)bank_bal*.05;
    }
    else
    {
        cout<<"\n\n\t\tXXX ENTERED WRONG SIGNATURE XXX";
        cout<<"\n\t\t          TRY AGAIN!!!";
    }
}

void bank_holder::prt_passbook()
{
    char ch;
    ifstream fin;
    fin.open("BANK_HOLDER_DETAILS.txt",ios::in);
    cout<<"\n\n\t\t________________TRANSACTIONS_________________\n";
    while(!fin.eof())
    {
        ch=fin.get();
        cout<<ch;
    }
    fin.close();
}

void bank_holder::easy_loan()
{
    if(loan==0)
    {
    	cout<<"\n\t\t>[1].Car loan\n\t\t>[2].Home loan :";
    	int e;
    	cin>>e;
    	if(e==1)
		{
        	cout<<"\n\n\t\t___________CAR LOAN___________\n\n";
       		cout<<"\t\tYOU HAVE TO GIVE 10% INTEREST ON CAR LOAN\n";
        	int c;
        	cout<<"\t\t >[1].YES\n\t\t >[2].NO  :";
        	cin>>c;
        	if(c==1)
        	{
           		cout<<"\n\t\t>HOW MUCH LOAN DO YOU WANT (in Rs.) : ";
            	cin>>loan;
            	cout<<"\n\t\tYour loan is approved \n";
            	cout<<"\t\tYou have taken loan of Rs. "<<loan;
            	cout<<"\n\t\tYOU HAVE TO RETURN "<<loan + loan*0.10<<" Rs.\n";
        	}
        	else
        	{
            	cout<<"\n\t\tSORRY\n";
        	}
        }
    	else if(e==2)
		{
       		cout<<"\n\n\t\t___________HOME LOAN___________\n\n";
       		cout<<"\t\tYOU HAVE TO GIVE 7% INTEREST ON HOME LOAN\n";
       		int c;
       		cout<<"\t\t >[1].YES\n\t\t >[2].NO  :";
       		cin>>c;
       		if(c==1)
            {
          		cout<<"\n\t\t>HOW MUCH LOAN DO YOU WANT (in Rs.) : ";
           		cin>>loan;
           		cout<<"\n\t\tYour loan is approved \n";
           		cout<<"\t\tYou have taken loan of Rs. "<<loan;
           		cout<<"\n\t\tYOU HAVE TO RETURN "<<loan + loan*0.07<<" Rs.\n";
       		}
       		else
       		{
        	   	cout<<"\n\t\tSORRY\n";
       		}
    	}
    	else
    	{
        	cout<<"\n\n\t\tPLEASE,ENTER CORRECT CHOICE !!!";
    	} 
	}
	else
    {
		cout<<"\n\n\t\t     SORRY !!!";
		cout<<"\n\n\t\t YOU HAVE ALREADY TAKEN LOAN !!!";
	}   
}

void bank_holder::return_loan()
{
    if(loan!=0)
    {
        cout<<"\n\n\t\t___________RETURN LOAN___________\n\n";
        cout<<"\t\tHOW MUCH LOAN DO YOU WANT RETURN : ";
        cin>>RL;
        if(RL==loan)
        {
            cout<<"\n\t\tYOU HAVE RETURN ALL LOAN OF Rs. "<<RL;
            cout<<"\n\n\t\t     THANK YOU !!!";
            loan=0;
        }
        else if(RL<loan)
        {
            cout<<"\n\t\tYOU HAVE RETURN LOAN OF Rs. "<<RL;
            cout<<"\n\t\tNOW YOU HAVE TO RETURN LOAN OF Rs. "<<loan-RL;
            loan=loan-RL;
            cout<<"\n\n\t\t     THANK YOU !!!";
        }
    }
}

void bank_holder::fixed_deposit()
{
    int f;
    cout<<"\n\n\t\t___________FIXED DEPOSIT___________\n\n";
	cout<<"\t\tFOR HOW MUCH YEAR YOU WANT TO DO FIXED DEPOSIT \n";
    cout<<"\t\t>[5]\n\t\t>[10]  :";
    cin>>f;
    if(f==5)
    {
        cout<<"\n\t\tHOW MUCH MONEY YOU WANT TO SAVE IN FIXED DEPOSIT :";
        cin>>FD;
        cout<<"\n\t\tYOUR FIXED DEPOSIT IS APPROVED";
        cout<<"\n\t\t"<<FD ;
        cout<<"Rs. SAVED ON YOUR FIXED DEPOSIT\n";
        cout<<"\t\tYOU WILL GET "<<FD+FD*0.07<<" Rs. AFTER 5 YEARS\n";
    }
    else if(f==10)
    {
        cout<<"\n\t\tHOW MUCH MONEY YOU WANT TO SAVE IN FIXED DEPOSIT :";
        cin>>FD;
        cout<<"\n\t\tYOUR FIXED DEPOSIT IS APPROVED";
        cout<<"\n\t\t"<<FD ;
        cout<<"Rs. SAVED ON YOUR FIXED DEPOSIT\n";
        cout<<"\t\tYOU WILL GET "<<FD+FD*0.08<<" Rs. AFTER 10 YEARS\n";
    }
    else
    {
        cout<<"\n\t\tCHOOSE A CORRECT OPTION\n";
    }
}


void bank_holder::update_acc()
{
    int ch,key;
    acc_holder_details();
    cout<<"\n\n\t\t==== ENTER WHAT YOU WANT TO CHANGE ====";
    cout<<"\n\t\t[1].NAME\n\t\t[2].PHONE NUMBER\n\t\t[3].ADDRESS\n\t\t[4].DATE OF BRTH\n\t\t";
    cin>>ch;
    cout<<"\n\t\t>ENTER YOUR SIGNATURE (*password) : ";
    cin>>key;
    if(key==pass)
    {
        switch (ch)
        {
            case 1:
                fflush(stdin);
                cout<<"\n\t\tENTER COUSTMER NAME(*only capital letters) : ";
                cin.getline(name,40);
                break;
            case 2:
                fflush(stdin);
                cout<<"\n\t\tENTER YOUR PHONE NUMBER                    : ";
                cin>>phn_no;
                break;
            case 3:
                fflush(stdin);
                cout<<"\n\t\tENTER YOUR PERMENANT ADDRESS               : ";
                cin.getline(address,50);
                break;
            case 4:
                fflush(stdin);
                cout<<"\n\t\tENTER YOUR DATE OF BIRTH                   : ";
                cin.getline(d_o_b,12);
                break;
            default:
                fflush(stdin);
                cout<<"\n\t\tXXX ENTER WRONG CHOISE XXX";
                cout<<"\n\t\t    TRY AGAIN !!!";         
        }
    }
    else
    {
        cout<<"\n\n\t\tXXX ENTERED WRONG SIGNATURE XXX";
        cout<<"\n\t\t          TRY AGAIN !!!";
    }
}

void bank_holder::delete_acc()
{
    int key;
    cout<<"\n\n\t\t==== ACCOUNT DELETION ====";
    cout<<"\n\t\t>ENTER YOUR SIGNATURE (*password) : ";
    cin>>key;
    if(key==pass)
    {
        cout<<"\n\n\t\t YOUR ACCOUNT IS DELETED !!!";
        cout<<"\n\n\t\t     THANK YOU !!!";
        exit(1);
    }
    else
    {
        cout<<"\n\n\t\tXXX ENTERED WRONG SIGNATURE XXX";
        cout<<"\n\t\t          TRY AGAIN !!!";
    }
}

int main()
{
    bank_holder b;
    int ch;
    cout<<"\n\n\n\n\n\t\t---------                       ---------\n";
    cout<<"\t\t=========== WELCOME TO SBI !!! ==========\n";
    cout<<"\t\t---------                       ---------\n\n\n";
    sleep(2);
    do
    {
        cout<<"\n\n\n\t\tHOW CAN WE HELP YOU ?\n\n\t\t>[1].CREATE ACCOUNT\n\t\t>[2].ACCOUNT HOLDER DETAILS\n\t\t>[3].DEPOSIT MONEY\n\t\t>[4].BALANCE ENQUIRY\n\t\t>[5].WITHDRAWAL\n\t\t>[6].TRANSACTIONS";
        cout<<"\n\t\t>[7].QUICK LOAN\n\t\t>[8].RETURN LOAN\n\t\t>[9].FIXED DEPOSIT\n\t\t>[10].UPDATE ACCOUNT DETAILS\n\t\t>[11].DELETE ACCOUNT\n\t\t>[12].EXIT.\n\n\t\tENTER YOUR CHOICE :";
        cin>>ch;
        switch(ch)
        {
            case 1:
                system("CLS");
                b.create_acc(); 
                break;
            case 2:
                system("CLS");
                b.acc_holder_details();
                break;
            case 3:
                system("CLS");
                b.deposit();
                break;
            case 4:
                system("CLS");
                b.balance_enq();
                break;
            case 5:
                system("CLS");
                b.withdrawal(); 
                break;
            case 6:
                system("CLS");
                b.prt_passbook();
                break;
            case 7:
                system("CLS");
                b.easy_loan();
                break;
            case 8:
                system("CLS");
                b.return_loan();
                break;
            case 9:
                system("CLS");
                b.fixed_deposit();
                break;
            case 10:
                system("CLS");
                b.update_acc(); 
                break;
            case 11:
                system("CLS");
                b.delete_acc(); 
                break;
            case 12:
                system("CLS");
                cout<<"\t\t---------                   ---------\n";
                cout<<"\t\t===========  THANK YOU !!! ===========\n";
                cout<<"\t\t---------                   ---------\n\n\n";
                exit(1);
            default:
                cout<<"\n\n\t\tPLEASE,ENTER CORRECT CHOISE !!!";    
        }
    }
    while(ch!=12);
}
