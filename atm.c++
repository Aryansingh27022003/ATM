#include<iostream>
#include<map>
#include<fstream>
#include<string>
using namespace std;
class atm{
public:
 string acc_number;
 string debit_number;
 string pin;
 string acc_type;
 string amount;
 string amount1;
 long long withdraw_amount;
 long long total;
 string language;
 
 void balance_deposit(){
  map<string, string> details;


    cout << "Enter your debit card number: ";
    cin >> debit_number;
    cout<<"Enter the amount to deposit:";
    cin>> amount;
    details[debit_number] = amount;
  

  ofstream file;
  file.open("amount_details.txt");

  for (auto it = details.begin(); it != details.end(); it++) {
    file << it->first << "=" << it->second << endl;
  }

  file.close();
}
map<string, string> readFromFile1() {
  map<string, string> details;
  string line;
  ifstream file("amount_details.txt");

  while (getline(file, line)) {
    int pos = line.find("=");
    string key = line.substr(0, pos);
    string value = line.substr(pos + 1);
    details[key] = value;
  }

  file.close();
  return details;
}
  
void searchByKey1() {
  cout << "Enter your debit card number: ";
  string debit_number;
  cin >> debit_number;
  
  map<string, string> details = readFromFile1();
  cout<<"Amount:" <<details[debit_number]<<endl;
}
map<string, string> readFromFile2() {
  map<string, string> details1;
  string line;
  ifstream file("account_type_details.txt");

  while (getline(file, line)) {
    int pos = line.find("=");
    string key = line.substr(0, pos);
    string value = line.substr(pos + 1);
    details1[key] = value;
  }

  file.close();
  return details1;
}
  
void searchByKey2() {
  cout << "Enter your debit card number: ";
  string debit_number;
  cin >> debit_number;
  map<string, string> details1 = readFromFile2();
  cout<<"Account type:" <<details1[debit_number]<<endl;
}
void print_statement(){
 cout<<"Enter the account number"<<endl;
 cin>>acc_number;
 cout << "Enter your debit card number: ";
  string debit_number;
  cin >> debit_number;
 map<string, string> details = readFromFile1();
 cout<<"***************MINI-STATEMENT***************"<<endl;
 cout<<"Card Number- "<<debit_number<<endl;
 cout<<"Tax no-4009"<<endl;
 cout<<"Statement for account number- "<<acc_number<<endl;
 cout<<endl;
 cout<<"Amount previously in your account- "<<amount1<<endl;
 cout<<"Amount Withdrawn- "<<withdraw_amount<<endl;
 cout<<"Remaining Amount- "<<stoll(amount1)-withdraw_amount<<endl;
 cout<<"********************************************"<<endl;
}
void withdraw(){
 cout << "Enter your debit card number: ";
 string debit_number;
 cin >> debit_number;
 cout<<"Enter the amount to withdraw: ";
 cin>>withdraw_amount;
 map<string, string> details = readFromFile1();
 amount1=details[debit_number];
 if(stoll(amount1)-withdraw_amount<=0){
  cout<<"Insufficent Cash"<<endl;
 }
 else{
  cout<<"Your cash had been withdrawn successfully"<<endl;
  cout<<"RS "<<stoll(amount1)-withdraw_amount<<" remaining in your account."<<endl;
   map<string, string> details = readFromFile1();
   details[debit_number]=to_string(stoll(amount1)-withdraw_amount);
   ofstream file;
  file.open("amount_details.txt");

  for (auto it = details.begin(); it != details.end(); it++) {
    file << it->first << "=" << it->second << endl;
  }

  file.close();
  cout<<"Want to print Mini-Statement"<<endl;
    cout<<"1.YES"<<endl;
    cout<<"2.NO"<<endl;
    int option3;
    cin>>option3;
    switch(option3){
     case 1:
     print_statement();
     case 2:
     cout<<"Thank you for using ATM.";
    }
 }
 
 
}
map<string, string> readFromFile() {
  map<string, string> details;
  string line;
  ifstream file("account_details.txt");

  while (getline(file, line)) {
    int pos = line.find("=");
    string debit_number = line.substr(0, pos);
    string pin = line.substr(pos + 1);
    details[debit_number] = pin;
  }

  file.close();
  return details;
}
void change_pin(){
 cout << "Enter your debit card number: ";
 string debit_number;
 cin >> debit_number;
 cout<<"Enter your new pin: ";
 cin>>pin;
 map<string, string> details = readFromFile1();
 details[debit_number]=pin;
  ofstream file;
  file.open("account_details.txt");

  for (auto it = details.begin(); it != details.end(); it++) {
    file << it->first << "=" << it->second << endl;
  }

  file.close();
  cout<<"Your PIN has successfully been changed."<<endl;
}

 
};
class credentials: public atm{
 public:
 string debit_number;
 string pin;
 
 void registerUser(){
 map<string, string> details;
 map<string,string>details1;
 


    cout << "Enter your debit card number: ";
    cin >> debit_number;
    cout<<"Create a new pin: ";
    cin>> pin;
    details[debit_number] = pin;
    cout<<"Enter your account type: ";
    string acc_type;
    cin>>acc_type;
    details1[debit_number]=acc_type;
  

  ofstream file;
  file.open("account_details.txt");

  for (auto it = details.begin(); it != details.end(); it++) {
    file << it->first << "=" << it->second << endl;
  }

  file.close();
  
  ofstream file1;
  file1.open("account_type_details.txt");

  for (auto it = details1.begin(); it != details1.end(); it++) {
    file1 << it->first << "=" << it->second << endl;
  }

  file1.close();
}
map<string, string> readFromFile() {
  map<string, string> details;
  string line;
  ifstream file("account_details.txt");

  while (getline(file, line)) {
    int pos = line.find("=");
    string debit_number = line.substr(0, pos);
    string pin = line.substr(pos + 1);
    details[debit_number] = pin;
  }

  file.close();
  return details;
}

void searchByKey() {
 int option,option1;
  cout << "Enter your debit card number: ";
  //string username;
  cin >> debit_number;
  cout << "Enter your pin: ";
  //string password;
  cin >> pin;
  map<string, string> details = readFromFile();

  if (details.count(debit_number) == 0) {
    cout << "Details not registered" << endl;
    return;
  }
  if (details[debit_number] == pin) {
    cout << "Welcome to the ATM!" << endl;
    cout<<"Enter the correct option number to access that service:"<<endl;
    cout<<"1.Set Language"<<endl;
    cout<<"2.Check account type"<<endl;
    cout<<"3.Check your Balance"<<endl;
    cout<<"4.Deposit Amount"<<endl;
    cout<<"5.Withdraw Amount"<<endl;
    cout<<"6.Change your ATM PIN"<<endl;
    //cout<<"7.Print Mini Statement"<<endl;
    cout<<"0ption number: ";
    cin>>option;
    switch(option){
    case 1:
    cout<<"Choose your language"<<endl;
    cout<<"1.English"<<endl;
    cout<<"2.Hindi"<<endl;
    cout<<"Enter your correct option:"<<endl;
    cin>>option1;
    break;
    case 2:
    searchByKey2();
    break;
    case 3:
    searchByKey1();
    break;
    case 4:
    balance_deposit();
    break;
    case 5:
    withdraw();
    break;
    case 6:
    change_pin();
    break;
    }
    
    
  } else {
    cout << "Invalid debit card number or pin" << endl;
  }
}


};



int main(){
 int option;
  cout << "1.Already have an account?" << endl;
  cout << "2.Create a new account" << endl;
  cout << "Write the option number:-" << endl;
  cin >> option;
  for(int i=0;i<1000;i++){
  if(option!=1&&option!=2){
      cout<<"You have chosen wrong option"<<endl;
      cout << "1.Already have an account?" << endl;
      cout << "2.Create a new account" << endl;
      cout << "Write the option number:-" << endl;
      cin >> option;
      cout<<"Enter correct option"<<endl;
  }
  }
  credentials obj1;
  //credentials obj2;

  switch (option)
    {
     case 1:
      obj1.searchByKey();
      break;
     case 2:
      obj1.registerUser();
      break;
    }
    
 return 0;
 
}


