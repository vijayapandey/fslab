//============================================================================
// Name        : lab3.cpp
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
 int count,choice,sem,i; 
student s; 
 string key; 
cout<<"\n1.add record\n2.delete record\n3.modify\n4.search\nenter ur choice:"; 
cin>>choice; 
 switch(choice) 
{ 
 case 1:cout<<"how many record?\n"; 
        cin>>count; 
        for(i=0;i<count;i++) 
            { 
        cout<<"data;"; 
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
 case 4:cout<<"enter the usn"; 
        cin>>key; 
        i=s.search(key); 
        break; 
 default:cout<<"\nerror"; 
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
 string sem; 
 stringstream out; 
 out<<semester; 
 sem=out.str(); 
 buffer+=usn+'|'+name+'|'+branch+'|'+sem+'$'+'\n'; 
 } 

int student::del(string key) 
{ 
 fstream file; 
char del_mark='*',t; 
int pos,flag=0; 
pos=search(key); 
if(pos) 
{ 
 file.open("3b.txt"); 
pos=pos-(buffer.size()+1); 
 file.seekp(pos,ios::beg); 
 file.put('*'); 
 flag=1; 
file.close(); 
return 1; 
} 
if(!flag) 
{ 
cout<<"\nunsucessful deletion"; 
   return 0; 
} 
} 
int student::search(string key) 
{ 
fstream file; 
 int flag=0,pos=0; 
 file.open("3b.txt",ios::in); 
 while(!file.eof()) 
{ 
buffer.erase(); 
getline(file,buffer); 
unpack(); 
if(key==usn) 
{ 
 cout<<"\nfound key,the record is\n"<<buffer; 
flag=1; 
pos=file.tellg(); 
file.close(); 
return pos; 
} 
} 
if(!flag) 
{ 
cout<<("\nrecord not found\n"); 
file.close(); 
return 0; 
} 
} 
 void student::unpack() 
{ 
 string sem; 
int ch=1,i=0; 
 usn.erase(); 
 while(buffer[i]!='|') 
 usn+=buffer[i++]; 
 
} 
void student::modify(string key) 
{ 
 int choice; 
if(del(key)==1) 
{ 
cout<<"\nwhat to modify?\n1.usn 2.name 3.branch 4.sem\n"; 
cout<<"enter ur choice:"; 
cin>>choice; 
switch(choice) 
{ 
 case 1:cout<<"usn\n"; 
        cin>>usn; 
        break; 
case 2:cout<<"name\n"; 
        cin>>name; 
        break; 
case 3:cout<<"branch\n"; 
 cin>>branch; 
       break; 
case 4:cout<<"semester\n"; 
       cin>>semester; 
       break; 
default:cout<<"wrong choice"; 
} 
 buffer.erase(); 
pack(); 
write(); 
cout<<"\nmodification sucess\n"; 
} 
else 
   cout<<"\nmodification unsucessful\n"; 
} 
 void student::write() 
{ 
 fstream file; 
 file.open("3b.txt",ios::out|ios::app); 
file<<buffer; 
file.close(); 
} 







