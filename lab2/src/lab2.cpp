//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<iostream> 
#include<fstream> 
#include<sstream> 
#include<string> 
using namespace std; 
class student 
{ 
 public: 
     string usn,name,branch,buffer; 
   int semester; 
  void read(); 
   void pack(); 
  void write(); 
  void unpack(); 
  int search(string); 
 int del(string); 
 void modify(string); 
 }; 
int main() 
{ 
 int count,choice,len,i; 
 student s; 
  string key; 
  cout<<"\n1.add record\n2.delete record\n3.modify\n4.search\n"; 
  cin>>choice; 
  switch(choice) 
{ 
  case 1:cout<<"how many record?\n"; 
         cin>>count; 
          for(i=0;i<count;i++) 
           { 
              cout<<"data"; 
              s.read(); 
              s.pack(); 
            } 
          s.write(); 
         break; 
   case 2:cout<<"enter the key\n"; 
          cin>>key; 
          i=s.del(key); 
          break; 
   case 3:cout<<"enter the key\n"; 
          cin>>key; 
           s.modify(key); 
          break; 
   case 4:cout<<"enter the usn\n"; 
cin>>key; 
         i=s.search(key); 
          break; 
   default:cout<<"error"; 
   } 
 return 0; 
} 
void student::read() 
{ 
 cout<<"usn"; 
cin>>usn; 
cout<<"name"; 
cin>>name; 
cout<<"branch"; 
cin>>branch; 
cout<<"semester"; 
cin>>semester; 
} 
 void student::pack() 
{ 
 string sem,temp; 
 stringstream out; 
 out<<semester; 
 sem=out.str(); 
  temp.erase(); 
 temp+=usn+'|'+name+'|'+branch+'|'+sem; 
  for(;temp.size()<100;) 
   { 
 temp+='$'; 
 } 
 buffer+=temp+'\n'; 
} 

void student::write() 
{ 
 fstream file; 
 file.open("2a.txt",ios::out|ios::app); 
 file<<buffer; 
 file.close(); 
} 
 int student::search(string key) 
 { 
 fstream file; 
 int flag=0,pos=0; 
 file.open("2a.txt",ios::in); 
 while(!file.eof()) 
{ 
 buffer.erase(); 
 getline(file,buffer); 
 unpack(); 
 if(key==usn) 
{ 
 flag=1; 
 cout<<"found the record is:\n"<<buffer; 
 pos=file.tellg(); 
 cout<<"\npos="<<pos; 
 return pos; 
 } 
 } 
if(!flag) 
  cout<<"record not found"; 
 return pos; 
} 
 void student::unpack() 
{ 
 string sem; 
 int ch=1,i=0; 
 usn.erase(); 
 while(buffer[i]!='|') 
 usn+=buffer[i++]; 
 
} 
int student::del(string key) 
 { 
 fstream file; 
 char del_mark='*',t; 
 int pos=0,flag=0; 
 pos=search(key); 
 if(pos) 
{ 
 file.open("2a.txt"); 
  pos-=101; 
file.seekp(pos,ios::beg); 
file.put(del_mark); 
flag=1; 
} 
file.close(); 
if(!flag) return 0; 
 else 
 return 1; 
} 
 void student::modify(string key) 
{ 
 int choice; 
 if(del(key)) 
{ 
 cout<<"want to modify?\n1.usn 2.name 3.branch 4.semester\nenter u r choice\n"; 
 cin>>choice; 
 switch(choice) 
{ 
 case 1:cout<<"usn"; 
        cin>>usn; 
         break; 
 case 2:cout<<"name"; 
        cin>>name; 
 break; 
  case 3:cout<<"branch"; 
         cin>>branch; 
         break; 
 case 4:cout<<"semester"; 
        cin>>semester; 
 break; 
 default:cout<<"wrong choice"; 
} 
 buffer.erase(); 
 pack(); 
 write(); 
} 
} 
