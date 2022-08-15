#include<iostream>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<stdlib.h>
#include <iomanip>
using namespace std;
void function();
void adminView();
int compare(string s1,string s2);

class date{
		
	public:
		int day,month,year;
		datex()
		{
		cout<<"\n\t\t\tENTER DATE(dd/mm/yy):";
		day:
		cout<<"\n\t\t\tDay:";
		cin>>day;
		if(day>31)
		{
			cout<<"\n\t\t\tRe-enter day";
			goto day;
		}
		month:
		cout<<"\n\t\t\tMonth:";
		cin>>month;
		if(month>12)
		{
			cout<<"\n\t\t\tRe-enter month";
			goto month;
		}
		cout<<"\n\t\t\tYear:";
		cin>>year;
		cout<<"\n\t\t\t___________________";
		cout<<"\n\t\t\tDate:"<<day<<"/"<<month<<"/"<<year<<"\n";
		cout<<"\t\t\t___________________\n";
		}
			
				
};

class cow: public date{

	public:
		int yield1,yield2;
		int id;
		static int c;
		cow()
		{
		c++;
	//	cout<<"Hello. We are inside the constructor for cow number  "<< c;
		do{	cout<<"\n\t\t\t______________________________\n";
			cout<<"\n\t\t\tINPUT ID FOR COW :	"<<c<<endl;
			cout<<"\n\t\t\t";
			cin>>id;
		
			}while(id<0);
			
			do{
			cout<<"\n\t\t\tINPUT FIRST YIELD OF ID:   "<<id<<"\t";
			cout<<"\n\t\t\t";
			cin>>yield1;
			}while(yield1<0);
			
			do{
			cout<<"\n\t\t\tINPUT SECOND YIELD OF ID:   "<<id <<"\n";
			//cout<<"\n\t\t\t______________________________\n";
			cout<<"\n\t\t\t";
			cin>>yield2;
			}while(yield2<0);
			
			}
				
				friend float percentage(cow *ptr,int n);
				friend float total(cow *ptr,int n);
				friend int total(cow*ptr,float min_yield);
};
int cow::c=0;

class Verifyid{
		protected:
			char v_id[4]={'2','0','K','-'};
			char id_no[8];
		public:
			string verifyId(){
				q:
				cout<<"\n\t\t\tENTER YOUR ID\n\t\t\t";
				cin>>id_no;
				if('2'==id_no[0] && '0'==id_no[1] && 'K'==id_no[2] && '-'==id_no[3])
				{
					cout<<"\n\t\t\tID VERIFIED!"<<endl;
				}
				else{
					cout<<"\n\t\t\tID UNNVERIFIED!"<<endl;
					goto q;
				}
				return id_no;
			}
	};
		
class Wage{
	//	float salary;
		
	public:
		float salary;
		float calculateWage(int dh,int dm){
			salary=dh*1000+dm*15;
			
			return salary;
		}
};	

	
	
class Employee:public date,public Verifyid,public Wage{
	int salary;	
	public:
	//	int salary;	
		void employeeview()
		{	string x;
			char id_no[8];
		struct entry_time{
			int hours;
			int mins;
		};
		struct exit_time{
			int hours;
			int mins;
		};
		struct difference{
			int hours;
			int mins;
		};
			;//used to store verified id# from above class function// 
			entry_time t1;
			exit_time t2;
			difference dif;
			date d;
			fflush(stdin);
			valid:
			int choice;getch();
			system("CLS");
			cout<<"\n\t\t***********************************"<<endl;
			cout<<"\t           YOU ARE IN EMPLOYEE VIEW MODE"<<endl;
			cout<<"\t\t***********************************";
			cout<<"\n\n\t\tPRESS 1 TO SAVE ENTRY AND EXIT TIME\n\t\tPRESS 2 TO CALCULATE YOUR WAGE\n\t\t";
			cin>>choice;
			if(choice==1)
			{
			x=verifyId();
		//	cout<<"\n\t\t\tENTER DAY OF MONTH :\n\t\t\t"<<endl;
			d.datex();
		//	cout<<"\t\tEnter time in format(hours:min)in 24 hour mode"<<endl<<endl<<endl;	
			cout<<"\n\t\t\tENTER ENTRY TIME IN HOURS: \n\t\t\t\t";
			cin>>t1.hours;
			cout<<"\n\t\t\t\tENTER ENTRY TIME MINUTES: "<<endl<<"\t\t";
			cin>>t1.mins;
			cout<<"\n\t\t\t\tENTER EXIT TIME IN HOURS: "<<endl<<"\t\t";
			cin>>t2.hours;
			cout<<"\n\t\t\t\tENTER EXIT TIME MINUTES: "<<endl<<"\t\t";
			cin>>t2.mins;
			
			fstream file;
			file.open("employeetime.txt",ios::out|ios::app);
			file<<"\t\t\tEmployee ID# : "<<x;
			file<<"\n\t\t\tEntry time:"<<t1.hours<<":"<<t1.mins;
			file<<"\n\t\t\tExit time:"<<t2.hours<<":"<<t2.mins;
			file<<"\n\t\t\tDate:"<<d.day<<"/"<<d.month<<"/"<<d.year<<endl<<endl;
			cout<<"DATA SAVED SUCCESSFULLY\n";
		    }
			if(choice==2)
		    {
		    int s;
			x=verifyId();	
			d.datex();
			cout<<"\n\t\t\tENTER ENTRY TIME IN HOURS: "<<endl;
			cin>>t1.hours;
			cout<<"\n\t\t\tENTER ENTRY TIME MINUTES: "<<endl<<"\t\t";
			cin>>t1.mins;
			cout<<"\n\t\t\tENTER EXIT TIME IN HOURS: "<<endl<<"\t\t";
			cin>>t2.hours;
			cout<<"\n\t\t\tENTER EXIT TIME MINUTES: "<<endl<<"\t\t";
			cin>>t2.mins;
			
		    if(t1.mins > t2.mins)
           {
            --t2.hours;
            t2.mins += 60;
           }
           dif.mins=t2.mins-t1.mins;
           dif.hours=t2.hours-t1.hours;
            cout << endl << "\n\t\t\tTIME DIFFERENCE: " << t2.hours << ":" << t2.mins;
            cout << " - " << t1.hours << ":" << t1.mins;
            cout << " = " << dif.hours << ":" << dif.mins;
            
			s=calculateWage(dif.hours,dif.mins);//please improve salary function//
			cout<<"\n\t\t\tSALARY COMPUTED IS : PKR "<<s<<endl;
			salary=s;
			fflush(stdin);
			
			fstream file;
			file.open("employeesalary.txt",ios::out|ios::app);
			file<<" VERIFIED ID#:"<<x<<"\tSALARY: PKR "<<s<<endl;
			file.close();
			cout<<"\n\t\tSALARY SUCCESSFULLY STORED;"<<endl;
		//	file.write((char))
			
			}
			else if(choice==3)
			{
				cout<<"\n\t\tYYOU CHOSE TO EXIT FROM EMPLOYEE-VIEW";
			}
			else
			{
			cout<<"\n\t\t\tSELECT A VALID OPTION PLEASE "<<endl;	
			goto valid;
			}
			}
		};

float percentage(cow *ptr,int n)
{	
  	int co=0;
    float totalm;
	float total(cow *ptr,int n);
	int fid;
	float p,perc;
	totalm=total(ptr,n);  //variable used to store total milk yield of all cows in farm//
	cout<<"\n\t\tENTER COW ID TO FIND PERCENTAGE OF \n"<<endl;
	cout<<"\t\tCOW ID :  ";
	cin>>fid;
	int flag=0;
	do{
		if(fid==ptr->id)
		{
	
			p=ptr->yield1+ptr->yield2;  //used to calculate total milk yeild of specific cow//
			perc=(p/totalm)*100;
			flag=1;

		}
else
{	//cout<<"first id of "<<ptr->id<<"did not match entered id of"<<fid;
	ptr++;
};
co++;
if(co>5)
{

	break;
}

}while(flag==0);
	//else {ptr++;cout<<"next id\n";}};

	if(co>5)
	{
		cout<<"\n\t\tCOW ID :"<<fid<<" NOT FOUND IN INPUT\n";
	}

	else
    {
	cout<<"\n\t\t\ID# "<<ptr->id<<" PRODUCED " << perc <<"% OF TOTAL MILK TODAY;"<<endl;
	}
	char c;
	if(co<5){
	cout<<"\n\t\tPRESS Y TO SAVE IN FILE OR N TO NOT SAVE\n";
	cin>>c;
				if(c=='y'||c=='Y')
				{
					fstream file;
					file.open("percentage.txt",ios::out|ios::app);
					if(!file)
					{
						cout<<"File not found!"<<endl;
					}
					else
					{
						file<<"\nCOW ID #  "<<fid <<":: "<<perc<<" litres\t"<<endl;
						date a;
						a.datex();
					//	"date was "<<a.day<"/"<<a.month<<"/"<<a.year<<"\n"//
						file<<"date was "<<a.day<<"/"<<a.month<<"/"<<a.year<<"\n";
						file.close();
					}
				}
				else if(c=='n'||c=='N')
				{	
				cout<<"\nYou chose not to store record\n";
				}
				return perc;
}
}


int total(cow*ptr,float min_yield)//tell that fx overiding
{
		float y;
		y=ptr->yield1+ptr->yield2;
		//	check used in error detections cout<<y <<"inside fx is y"<<endl;cout<<min_yield<<"inside fx is minyiled"<<endl; //var storing milk yeild of specific cow//
		if(y<min_yield)
		{
			return ptr->id;
		}
		else
		{return 0;}
		
}

void whcompute(char a)
{	
    int w;
	float h;
	float bmi;
	int aa;
	string name;
	if(a=='r')name="RED SINDHI";
	if(a=='c')name="CHOLISTANI";
	if(a=='s')name="SAHIWALI";
	cout<<"\n\tTHE "<<name <<" COW HAS AN AVERAGE WEIGHT RANGE OF 130-160 KILOGRAMS,\n\tENTER WEIGHT OF YOUR "<<name<<"  COW\n\t\t";
	cin>>w;
	cout<<" \n\tTHE "<<name<<" COW HAS AN AVERAGE HEIGHT OF 2.2-3.2 METERS\n\tENTER HEIGHT OF YOUR "<<name<<"COW \n\t\t";
	cin>>h;
	bmi=w/(h*h);
	cout<<"\n\tENTER SIGNIFICANT FIGURES\n";
	cin>>aa;
	cout<<" \tBMI OF COW :   "<<setprecision(aa)<<bmi;
	if(bmi<10)
	{	cout<<"\t_______________________________________________";
		cout<<"\n\tBMI STATUS : LOW \n\tVACCINATE THE COW.\n";
		cout<<"\t_______________________________________________";
	}
	if(bmi>=10)
	{	cout<<"\t_______________________________________________";
		cout<<"\n\tBMI STATUS :  VERY GOOD \n\tCOW IS OF OLD AGE SO MILK PRODUCTION HAS DECREASED.\n\t W.R.T BMI,YOU CAN SELL IT FOR "<< w*800<< "PKR\n";
		cout<<"\t_______________________________________________";
	}
	
	
}

float total(cow *ptr,int n)//tell that fx overiding
{
	float totals=0;
    cow *tptr=ptr;
	for(int i=0;i<n;i++)
	{
		totals=totals+tptr->yield2+tptr->yield1;//variable storing milk yields of each cow//
		tptr++;
	}
	return totals;
}

void bill(int a,int n)
{	int price,exp,wage;fstream file;int sum;int mw;	getch();	system("cls");
		cout<<"\t\t\t___________________________________\n";
		cout<<"\t\t\tENTER MILK PRICE FOR TODAY:  ";cin>>price;
		mw=price*a;
		cout<<"\t\t\t___________________________________\n";
		cout<<"\n\t\t\t MILK WORTH: "<<mw<<" PKR.\n ";
		sum=mw;
		cout<<"\t\t\t___________________________________\n";
		cout<<"\t\t\tENTER EXPENSE OF COW FEED.\n";cin>>exp;n=3;cout<<"\n\t\t\t___________________________________\n";
		sum=sum-exp;
	file.open("employeesalary.dat",ios::in | ios::binary );Employee *ee=new Employee[n];
					//ow *cowobj1= new cow[n];Employee *ee=new ee[n];
				if(file.read((char*)&ee,sizeof(ee)));
						do{	cout<<"\t\t\t";
							//wage=1000*ee->salary;
						//	cout<<ee->salary*1000 <<"PKR WAS SALARY GIVEN TO EMPLOYEE TODAY\n";
							//sum=sum-(ee->salary*1000);
							ee++;
							
							
						}while(!EOF);
					//	file<<"date was "<<a.day<<"/"<<a.month<<"/"<<a.year<<"\n";
						file.close();
						Sleep(500);
						cout<<"\n\t\t\t____________________________\n";
						cout<<"\t\t\tNET PROFIT OF TODAY : "<<sum << " PKR\n";
						cout<<"\n\t\t\tPRESS ANY KEY TO CONTINUE\n";
						getch();
}
void adminView()
{
	
	enter:
	string pass="";
	string password;
	int check;
	int choice;
	cout<<"\nEnter password: \n";char ch;
	ch=getch();
        
        while(ch != 13)
		{
			pass.push_back(ch);
			cout << '*';
			ch = getch();
		}	
//	cout<<"Enter password: \n";
	//fflush(stdin);
	//cin>>password;
	//check=compare(password,pass);
	if(pass=="bhainscolony")
	{
	cout<<"\n\t\t\tAccess granted\n";
	system("CLS");
	do{
	function();
	cout<<"\nIf you want to re-use the code press anything but 5";
	cin>>choice;
	}while(choice!=5);
	}
	else 
	{	cout<<"\nre-enter the password\n";
	goto enter;	
	
}
}
void function(void){
	int n;
	int ids;
	cout<<"\t\t**************************************************\n";
	cout<<"\t\t          WELCOME TO THE DAIRY FARM SOFTWARE              \n";
	cout<<"\t\t*************************************************\n";
	cout<<"\n\t\tYOU ARE IN AUTHORISED ADMINVIEW\n";
	cout<<"\n\nEnter the amount of cows in the farm.\n";
	cin>>n;
	int choice;
	float yieldl;
	cow *cowobj= new cow[n];
	char c;
	system("CLS");
	cout<<"\t\t\t*********Menu*********\n";
	
		cout<<"\nPress 1 to calculate the total milk yield of the cows in the farm.\n";
		cout<<"\nPress 2 to check which cows produce less milk than specified.\n";
		cout<<"\nPress 3 to check which cow produced what percentage of milk.\n";
		cout<<"\nPress 4 to check health of cow.\n";
		cout<<"\nPress 0 to exit\n";
		cout<<"\nSelect option:";
		cin>>choice;
		switch(choice)
		{
			case 1:
		{		cout<<"\nYou chose option1.\n"; 
		        cout<<"Let us calculate the total milk yield of all the cows in the farm.";
		        float tot=total(cowobj,n);
				cout<<"\n\nTOTAL MILK YEILD="<<tot<<" litres.\n\nDo you want to store the result?Press Y for yes and N for no.\n";
				cin>>c;
				if(c=='y'||c=='Y')
				{
					fstream file;
					file.open("total.txt",ios::out|ios::app);
					if(!file){
						cout<<"File not found!"<<endl;
					}
					else{
						file<<"\nTotal milk yield of all cows was "<<tot<<" litres"<<endl;
						date a;
						a.datex();
						file<<"Date:"<<a.day<<"/"<<a.month<<"/"<<a.year<<"\n";
						
						file.close();
					}
				}
				else if(c=='n'||c=='N')
				{	
				cout<<"\nYou chose not to store record\n";
				}
				bill(tot,n);
				break;
		}
		
			case 2:
		{		
				cout<<"\nYou chose option 2.\n";
				cout<<"Let us compare the milk yield with your desired limit.\n";
				cout<<"\nDesired yield limit:";
				cin>>yieldl; //providing our milk yield limit//
				float val;	date a;
				for(int i=0;i<n;i++)
				{
					val=total(cowobj,yieldl); //storing id of cow returned from function//
					//cout<<val<<"is retuened value in fx";	check used in error detections
					if(val!=0)
					{
						cout<<"\nCow of id"<<val<<" produced less milk than the limit of "<<yieldl<<" litres\n";
						fstream file;
						file.open("yield.txt",ios::out|ios::app);
						if(!file){cout<<"File not found!"<<endl;}
						else
						{
						file<<"\nID of cow which produced less milk than "<<yieldl<<" litres was "<<val<<endl;
						
						a.datex();
						file<<"Date:"<<a.day<<"/"<<a.month<<"/"<<a.year<<"\n";
						file.close();
						}
						file.open("yield.dat",ios::out | ios::binary );
						
						file.write((char*)&cowobj, sizeof(cowobj));
						file.write((char*)&a,sizeof(a));
					//	file<<"date was "<<a.day<<"/"<<a.month<<"/"<<a.year<<"\n";
						file.close();
						
					}
					else
					{	
						cout<<"\nThe cow with id "<<cowobj->id<<" produced milk above than your specified limit\n";
					}
					cowobj++;
				}
				break;	
		}
			case 3:
				{cout<<"\nYou chose option 3.";
				 cout<<"\nLet us check which id produced what percentage of the milk.\n";
				float perc=percentage(cowobj,n);
				//cout<<"Do you want to store record? (Press Y to store record/N to not store)"<<endl;
				
				break;
				}
			case 4:
				{fstream file;int weight;char type;float height;
				cout<<"\nYou chose option 4. Let us check for the sick cow.\n ";
				file.open("yield.dat",ios::in | ios::binary);
				cow *cowobj1= new cow[n];date v;
				if(file.read((char*)&cowobj1,sizeof(cowobj1))&&(file.read((char*)&v,sizeof(v))))
				{
				cout<<"this is data";
				cout<<"COW ID :		"<< cowobj1->id<<"\n";
				cout<<" MILK PRODUCED:	"<<cowobj1->yield1+cowobj1->yield2<<"\n";
				cout<<"Date:	"<< v.day<<"/"<<v.month<<"/"<<v.year<<"\n";
				cout<<"enter cow type. Is it Sahiwal(S), Red Sindhi(R), Cholistan(C)\n";
				cin>>type;
				if(type=='s')
				{
				whcompute(type);
				}
				else if(type=='r')
				{
					whcompute(type);
				}
				else if(type=='c')
				{
						whcompute(type);
				}
				else
				{
					cout<<"invalid type entered\n";
				}
				}
				else 
				{
					cout<<"file does not exist";
				}
				break;
}
}
}

int compare(string s1,string s2)
{
 
    if (s1 != s2)
    {	cout<<"\nCorrect match\n";
        return 1;
    }
    else
        {
        	cout<<"Incorrect match\n"<<endl;
        	return 0;
		}
}
int main()
{
	int ch;
	int no;
	Employee e;	
do{	system("color 0D");
	cout<<"\n\t\t\t\t\t\tMAIN MENU\n";
	cout<<"\t\t\t\t\t____________________________\n";
	cout<<"\n\t\t\t\t\tENTER 1 FOR ADMIN-VIEW    \n";
		cout<<"\t\t\t\t\t_________________________\n";
	cout<<"\n\t\t\t\t\tENTER 2 FOR EMPLOYEE-VIEW  \n";
		cout<<"\t\t\t\t\t_________________________\n";
	cout<<"\n\t\t\t\t\tENTER 0 TO EXIT            \n";
		cout<<"\t\t\t\t\t_________________________\n";
	cout<<"\n\t\t\t\t\tSELECT OPTION:	";
	cin>>ch;
	if(ch==1)
	{system("Color 0A");
		cout<<"\n\t\t\t\t\tYOU SELECTED ADMIN-VIEW";Sleep(400);system("cls");
		adminView();
	}
	else if(ch==2)
	{	system("Color 0E");
		e.employeeview();fstream file;
		file.open("employeesalary.dat",ios::out| ios::binary);
		file.write((char*)&e,sizeof(e));
		file.close();
	}
	else
	{	system("Color 0C");
	//	;cout<<"\n\t\t\tWRONG INPUT\n";
		getch();
		system("cls");
	}
	}while(ch=0);
}
