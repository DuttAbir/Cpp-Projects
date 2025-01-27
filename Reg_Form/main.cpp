#include<iostream> 
#include<fstream>
#include<windows.h>
#include<sstream>

using namespace std; 

class Login
{
private:
  string LoginID, Password;
public:
  Login():LoginID(""),Password(""){};
  
  void setID (string ID){
    LoginID = ID;
  }

  void setPas(string pw){
    Password = pw;
  }

  string getID (){
    return(LoginID);
  }

  string getPass(){
    return(Password);
  }
};

void registration(Login Log){
  system("cls");
  string id, pw;
  cout<<"\tEnter Login ID: ";
  cin>>id;
  Log.setID(id);
  start:
  cout<<"\tEnter a Strong Password: ";
  cin>>pw;
  if (pw.length()>=8)
  {
    Log.setPas(pw);
  }
  else
  {
    cout<<"\tEnter Minimum 8 characters!"<<endl;
    goto start;
  }
  ofstream outFile("Login.txt", ios::app);
  if (!outFile)
  {
    cout<<"\tERROR : File can not open"<<endl;
  }
  else
  {
    outFile<<"\t"<<Log.getID()<<" : "<<Log.getPass()<<endl<<endl;
    cout<<"\tUser Registered Successfully!"<<endl;
  }
  outFile.close();
  Sleep(3000);
}

void log_in(){
  system("cls");
  string id, pw;
  cout<<"\tEnter Login ID: ";
  cin>>id;
  cout<<"\tEnter Password: ";
  cin>>pw;

  ifstream inFile("Login.txt");

  if (!inFile)
  {
    cout<<"\tERROR: File Can not ne open!"<<endl;
  }
  else
  {
    string line;
    bool found = false;
    while (getline(inFile,line))
    {
      stringstream ss;
      ss<<line;
      string userID, userPw;
      char delimiter;
      ss>>userID>>delimiter>>userPw;

      if (id==userID && pw == userPw)
      {
        found=true;
        cout<<"\tPlease Wait";
        for (int i = 0; i < 3; i++)
        {
          cout<<".";
          Sleep(800);
        }
        system("cls");
        cout<<"\tWelcome to this page"<<endl;
      }
    }
    if (!found)
    {
      cout<<"\tERROR: Incorrect Login ID or Password"<<endl;
    }
  }
  inFile.close();
  Sleep(5000);
}


int main()
 { 
      Login log;
      bool exit = false;
      while (!exit)
      {
        system("cls");
        int val;

        cout<<"\tWelcome to Registration Form"<<endl;
        cout<<"\t****************************"<<endl;
        cout<<"\t1.Register."<<endl;
        cout<<"\t2.Login."<<endl;
        cout<<"\t3.Exit."<<endl;
        cout<<"\tEnter Choice : ";

        cin>>val;

        if (val == 1)
        {
          registration(log);
        }
        else if(val == 2)
        {
          log_in();
        }
        else if (val == 3)
        {
          system("cls");
          exit = true;
          cout<<"\tGOOD BYE!"<<endl;
          Sleep(3000);
        }
        
        
        Sleep(1000);

      }
      return 0;
      
 } 