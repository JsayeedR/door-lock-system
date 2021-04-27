//demonstration how a home security could work with very simple functions !!
//USE masterpassword to set the entry password & also delete it.


#include<iostream>

using namespace std;
string masterpassword="1234";
string password[100];

int main()
{
    int x,y,z;
    string datain;
    string deldata;
    cout<<"A demonstration of HOME security system with pasworrd ONLY!"<<endl;
    cout<<"Master Password is 1234"<<endl;
L1:
    cout<<"Enter Password :"<<endl;
    cin>>datain;
    z = 0;

    for(int i=0; i<100; i++)
    {
        if(datain==password[i])
        {
            cout<<"DOOR OPEN"<<endl;
            goto L1;
        }
    }

    if(datain==masterpassword)
    {
        cout<<"1.Add New\n2.Delete"<<endl;
        cin>>x;
        switch(x)
        {
        case 1:
        {
            cout<<"Enter New ID for User from 0 to 99"<<endl;
            cin>>y;
            if(y<100)
            {
                cout<<"Enter New Password"<<endl;
                cin>>datain;
                if(datain!=masterpassword)
                {
                    password[y]=datain;
                }
                else
                {
                    cout<<"Can not use this password!! Try Other!"<<endl;
                }
            }
            else
            {
                cout<<"Wrong ID!  Enter New ID for User from 0 to 99"<<endl;
            }
            break;

        }
        case 2:
        {
            cout<<"Enter Password To Delete User"<<endl;
            cin>>deldata;

            for(int i=0; i<100; i++)
            {
                if(deldata==password[i])
                {
                    password[i]='\0';
                    cout<<"USER ID NO:"<< i<<" is Deleted"<<endl;
                    z=100;
                }
            }

            if(z!=100)
            {
                cout<<"No user found with the password"<<endl;
            }
            break;
        }

        default:
        {

            cout<<"TRY Latter"<<endl;
        }

        }
        goto L1;
    }

    else
    {
        cout<<"Alert!! Wrong Password, Door Closed !! "<<endl;
        goto L1;
    }
}
