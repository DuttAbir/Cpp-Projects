#include<iostream> 
#include<fstream>
#include<sstream>
#include<windows.h>

using namespace std; 

class Bill{
      string Item;
      int Rate, Quantity;
   public:
      Bill() : Item(""), Rate(0) , Quantity(0){}

      void setItem(string item){
         Item = item;
      }
      void setRate(int rate){
         Rate=rate;
      }
      void setQuant(int qnt){
         Quantity = qnt;
      }

      string getItem(){
         return Item;
      }

      int getRate(){
         return Rate;
      }

      int getQnt(){
         return Quantity;
      }

};

void addItem(Bill b){
   bool close = false;
   while (!close)
   {
      int choice;
      cout<<"\t1.Add"<<endl;
      cout<<"\t2.Close"<<endl;
      cout<<"\tEnter Choice : ";

      cin>>choice;

      if (choice == 1)
      {
         string item;
         int rate, qnt;
         cout<<"\tEnter Item Name : ";
         cin>>item;
         b.setItem(item);

         cout<<"\tEnter Quantity : ";
         cin>>qnt;
         b.setQuant(qnt);

         cout<<"\tEnter Rate : ";
         cin>>rate;
         b.setRate(rate);

         ofstream out("C:/Users/dutta/Documents/C C++/C++ projects/Market_Billing/Bill.txt", ios::app);
         if (!out)
         {
            cout<<"\tERROR : File can not be opened"<<endl;
         }
         else{
            out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQnt()<<endl<<endl;
         }
         out.close();
         cout<<"\tItem added successfully"<<endl;
         Sleep(3000);
      }
      else if(choice == 2){
         system("cls");
         close = true;
         cout<<"\tBack to Main Menu"<<endl;
         Sleep(3000);
      }
      
   }
   
}

void printBill(){
   system("cls");
   int count = 0;
   bool close = false;
   while (!close)
   {
      system("cls");
      int choice;
      cout<<"\t1.Add Bill"<<endl;
      cout<<"\t2.Close Session"<<endl;
      cout<<"\tEnter Choice : ";
      cin>>choice;

      if (choice == 1)
      {
         string item;
         int qnt;
         cout<<"\tEnter Item : ";
         cin>>item;
         cout<<"\tEnter Quantity : ";
         cin>>qnt;
         ifstream in("C:/Users/dutta/Documents/C C++/C++ projects/Market_Billing/Bill.txt");
         ofstream out("C:/Users/dutta/Documents/C C++/C++ projects/Market_Billing/Bill_temp.txt");

         string line;
         bool found = false;
         while (getline(in, line))
         {
            stringstream ss;
            ss<<line;
            string itemName;
            int itemRate, itemQnt;
            char delimeter;
            ss>>itemName>>delimeter>>itemRate>>delimeter>>itemQnt;
            if(item == itemName){
               found = true;
               if (qnt <= itemQnt)
               {
                  int amount = itemRate * qnt;
                  cout<<"\t Item | Rate | Quantity| Amount"<<endl;
                  cout<<"\t"<<itemName<<"\t "<<itemRate<<"\t "<<qnt<<"\t "<<amount<<endl;
                  int newQnt = itemQnt - qnt;
                  itemQnt = newQnt;
                  count+=amount;
                  
                  out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQnt<<endl<<endl;
               }
               else
               {
                  cout<<"\tSorry! "<<item<<" not Available"<<endl;
               }
            }
            else
            {
               out<<line<<endl;
            }
         }
         if (!found)
         {
            cout<<"\tItem Not Found!"<<endl;
         }
         out.close();
         in.close();
         remove("C:/Users/dutta/Documents/C C++/C++ projects/Market_Billing/Bill.txt");
         rename("C:/Users/dutta/Documents/C C++/C++ projects/Market_Billing/Bill_temp.txt", "C:/Users/dutta/Documents/C C++/C++ projects/Market_Billing/Bill.txt");
      }
      else if (choice == 2)
      {
         close = true;
         cout<<"\tCounting Total Bill"<<endl;
      }
      Sleep(3000);
   }
   system("cls");
   cout<<endl<<endl;
   cout<<"\t Total Bull ------------- : "<<count<<endl<<endl;
   cout<<"\tThanks for Shoping"<<endl;
   Sleep(5000);
}

int main()
 { 
   Bill b;
   bool exit = false;
   while(!exit){
      system("cls");
      int val;
      cout<<"\tWelcome to Supermarket Billing System"<<endl;
      cout<<"\t*************************************"<<endl;
      cout<<"\t\t1.Add Item"<<endl;
      cout<<"\t\t2.Bill Print"<<endl;
      cout<<"\t\t3.Exit"<<endl;
      cout<<"\t\tEnter Choice : ";

      cin>>val;

      if (val==1)
      {
         system("cls");
         addItem(b);
         Sleep(3000);
      }

      else if(val == 2){
         printBill();
      }
      else if (val == 3)
      {
         system("cls");
         exit = true;
         cout<<"\t Good BYE !"<<endl;
         Sleep(3000);
      }
   }
    return 0; 
 } 