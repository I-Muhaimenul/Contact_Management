#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define cn 100
#define fn 5

using namespace std;

class contact
{
public:
    char name[30];
    string number;
};


class account_profile
{
private:
    const float fnf_rate;
    const float nfnf_rate;
    static float balance;
    static int total_t;
public:
    account_profile():fnf_rate(0.025),nfnf_rate(0.075) {}

    void add(float b)
    {
        balance=balance+b;
        cout<<"\n\nRecharged Successful!\nYour current balance is "<<balance<<" Taka\n\n\n";
    }
    int get_t()
    {
        return total_t;
    }
    void get_acp(float &f,float &n,float &b)
    {
        b=balance;
        f=fnf_rate;
        n=nfnf_rate;
    }
    void set_acp(float b,float t)
    {
        balance=b;
        total_t=t;
    }

};
float account_profile::balance=100;
int account_profile::total_t=0;


class phone_book
{
private:
    contact people[cn];
    contact fnf[fn];
    static int i;
    static int j;
    account_profile A;
public:
    void set_info()
    {
        if(i<cn)
        {
            int m;

            cout<<"\n\nEnter the number: ";
            cin>>people[i].number;
            cout<<"Enter contact name: ";
            cin>>people[i].name;
            system("cls");
            cout<<"\n\nContact is added!\n\n";
            cout<<"\n\nDo you want to add this number in fnf list?\n1 to Yes\n2 to No\n\nEnter your choice : ";
            cin>>m;
            system("cls");
            if(m==1)
            {
                if(j<fn)
                {
                    fnf[j]=people[i];
                    j++;
                    cout<<"\n\nfnf is added!\n\n";
                }
                else cout<<"\n\nfnf list is full!!!\n\n";
            }
            i++;
        }
        else cout<<"\n\nContact list is full!!!\n\n";
    }

    void search(char* s);
    void show();

};
int phone_book::i=0;
int phone_book::j=0;


class battery
{
private:
    static float charge;
    int start_h,start_m,start_s;
    int end_h,end_m,end_s;
public:
    battery()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        start_h=1 + ltm->tm_hour ;
        start_m= 1 + ltm->tm_min ;
        start_s= 1 + ltm->tm_sec;
    }
    void after_()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        end_h=1 + ltm->tm_hour ;
        end_m= 1 + ltm->tm_min ;
        end_s= 1 + ltm->tm_sec;

    }
    void charge_count(int t)
    {
        int start=(start_h*3600)+(start_m*60)+start_s;
        int after=(end_h*3600)+(end_m*60)+end_s;
        int d=after-start-t;

        charge=100-((d*.001)+(t*.01));
        system("cls");
        if(charge<15) cout<<"\n\nBattery Low!!\nBattery Percentage "<<charge<<"%\n"<<endl;
        else if(charge<0.1) cout<<"\n\nCharge Finished!!!\nTurning of!!\n"<<endl;
        else cout<<"\n\nBattery Percentage "<<charge<<"%\n"<<endl;
    }

};
float battery::charge=100;


class phone
{
private:
    static int hi;
    contact his[10];
public:
    phone_book pb;
    account_profile ap;
    battery bt;

    void call(contact C,int n);
    void get_history(contact C1)
    {
        his[hi]=C1;
        hi++;
    }
    void show_history()
    {
        int m;
        cout<<"\n\nCall history:\t\n";
        for(m=0; m<hi; m++)
        {
            cout<<"\n\t\t"<<his[m].name<<"\n\t\t"<<his[m].number<<"\n";
        }
    }
};
int phone::hi=0;

int main()
{
    int choice;
    char smile=('z'+135);
    phone ph;

    cout <<"\n\n\n\t\tWelcome!! "<<smile<<"\n\n\n"<< "\nMenu:\n\t1 to Enter Phonebook\n\t2 to Call\n\t3 to See battery usage\n\t4 to Add balance\n\t5 to exit\n\nEnter your choice: ";
    cin>>choice;
    while(1)
    {
        if(choice==1)
        {
            int ch;
            system("cls");
            cout << "\nPhonebook:\n\t1 to Add contact\n\t2 to Show contacts\n\t3 to Search contacts\n\t4 to Cancel\n\nEnter your choice: ";
            cin>>ch;
            if(ch==1)
            {
                ph.pb.set_info();
            }
            else if(ch==2)
            {
                ph.pb.show();
            }
            else if(ch==3)
            {
                char s[20];
                system("cls");
                cout<<"\nEnter the keyword you want to Search: ";
                cin>>s;
                ph.pb.search(s);
            }
            else if(ch==4)
            {
                system("cls");
            }
        }
        else if(choice==2)
        {
            char s[20];
            system("cls");
            cout<<"\nEnter the name you want to Call: ";
            cin>>s;
            ph.pb.search(s);
        }
        else if(choice==3)
        {
            int q;
            q=ph.ap.get_t();
            ph.bt.after_();
            ph.bt.charge_count(q);
        }
        else if(choice==4)
        {
            int d;
            system("cls");
            cout<<"\n\nEnter the amount you want to recharge: ";
            cin>>d;
            ph.ap.add(d);
        }
        else if(choice==5)
        {
            system("cls");
            ph.show_history();
            cout<<"\n\n\n\t\tGood Bye!! "<<smile<<"\n\n\n";
            break;
        }
        cout << "\nMenu:\n\t1 to Enter Phonebook\n\t2 to Call\n\t3 to See battery usage\n\t4 to Add balance\n\t5 to exit\n\nEnter your choice: ";
        cin>>choice;
    }
    return 0;
}


void phone_book::show()
{
    int m,n,q=0,r;
    if(i>0)
    {
        cout<<"\n\n1 to show all contacts\n2 to show fnf contacts\n(0 to cancel)\n\nEnter your choice: ";
        cin>>r;
        system("cls");
        if(r==1)
        {
            for(m=0; m<i; m++)
            {
                for(n=0; n<j; n++)
                {
                    if((fnf[n].number)==(people[m].number))
                    {
                        q=1;
                        break;
                    }
                    else
                    {
                        q=0;
                    }
                }

                if(q==1) cout<<"\nfnf:\t\t"<<people[m].name<<"\n\t\t"<<people[n].number<<endl;
                else cout<<"\nNon fnf:\t"<<people[m].name<<"\n\t\t"<<people[n].number<<endl;
            }
        }
        else if(r==2)
        {
            for(n=0; n<j; n++)
            {
                cout<<"\nfnf:\t\t"<<fnf[n].name<<"\n\t\t"<<fnf[n].number<<endl;
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        cout<<"\nList is empty!!\n";
        return;
    }
}


void phone_book::search(char* s)
{
    int m,x=0,y=0,p,q=0;
    contact temp[cn];
    phone ph;
    if(i>0)
    {
        for(m=0; m<i; m++)
        {
            char *c1=new(char[strlen(people[m].name)+1]);
            strcpy(c1,people[m].name);
            char *z=strstr((strupr(c1)),(strupr(s)));
            if(z!=NULL)
            {
                temp[y]=people[m];
                y++;
                cout<<y<<". \t"<<people[m].name<<"\n \t"<<people[m].number<<"\n\n";
                x=1;
            }
        }
        if(x==1)
        {
            int n;
            cout<<"Whom you want to call? (Press 0 to cancel) : ";
            cin>>n;
            if(n!=0)
            {
                for(p=0; p<j; p++)
                {
                    if((fnf[p].number)==(temp[n-1].number))
                        q=1;
                }
                if(q==1) ph.call(temp[n-1],1);
                else ph.call(temp[n-1],2);
            }
            else
            {
                system("cls");
                return;
            }
        }
        else cout<<"No match Found\n";
    }
    else
    {
        cout<<"\nList is empty!!\n";
        return;
    }
}


void phone::call(contact C,int n)
{
    int w,pulse1,l,s=0,m=0,h=0,t;
    float b=0;
    float bl,f,nf,tot;

    get_history(C);
    account_profile ac;
    tot=ac.get_t();
    ac.get_acp(f,nf,bl);

    system("cls");
    cout<<"\n\n\t"<<C.name<<"\n\n\n\t"<<C.number<<"\n\n\nCalling";
    w=rand()%13;
    for(l=0; l<w; l++)
    {
        Sleep(1000);
        cout<<". ";
    }
    for(t=0;; t++)
    {
        system("cls");
        b=bl;
        cout<<"\n\n\t"<<C.name<<"\n\n\n\t"<<C.number<<"\n\n\n";
        cout<<"\t"<<h<<":"<<m<<":"<<s;
        Sleep(1000);
        s++;
        if(s==60)
        {
            m++;
            s=0;
        }
        if(m==60)
        {
            h++;
            m=0;
        }
        if(kbhit()) break;
    }
    tot=tot+t;

    if(n==1)
    {
        if(t%5==0)
        {
            pulse1=t;
            bl = bl - (f*pulse1);
        }
        else
        {
            pulse1=((t/5)+1)*5;
            bl = bl - (f*pulse1);
        }
    }
    else
    {
        if(t%5==0)
        {
            pulse1=t;
            bl = bl - (nf*pulse1);
        }
        else
        {
            pulse1=((t/5)+1)*5;
            bl = bl - (nf*pulse1);
        }
    }
    b=b-bl;
    system("cls");
    ac.set_acp(bl,tot);

    cout<<"\n\n\tDuration: "<<h<<":"<<m<<":"<<s;
    cout<<"\n\n\tCharged "<<b<<" Taka\n"<<"\tAccount balance is "<<bl<<" Taka\n\n";
}
