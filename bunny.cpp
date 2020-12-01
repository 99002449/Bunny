#include<bits/stdc++.h>
#include"bunny.h"
using namespace std;


//Base class functions
string bunnyParent::getName(){return name;}
string bunnyParent::getGender(){return gender;}
string bunnyParent::getColor(){return color;}
int bunnyParent::getAge(){return age;}
bool bunnyParent::getRadioactive(){return radioactive;}

void bunnyParent::setName(string name)
{
   this->name=name;
}
void bunnyParent::setGender(string gender)
{
   this->gender=gender;
}
void bunnyParent::setColor(string color)
{
   this->color=color;
}
void bunnyParent::setAge(int age)
{
   this->age=age;
}
void bunnyParent::setRadioactive(bool radioactive)
{
   this->radioactive=radioactive;
}


//Inherited class fuctions
void bunny::GetRandomName()
{
    vector<string> thenames;
    readthat(thenames);

    setName(thenames[rand()%100]);
}

void bunny::GetRandomGender()
{
    int flag=rand()%2;
    if(flag==0)
        setGender("male");
    else if(flag==1)
        setGender("female");

}

void bunny::GetRandomColour()
{
    int flag=rand()%4;

    if(flag==0)
        setColor("white");
    else if(flag==1)
        setColor("black");
    else if(flag==2)
        setColor("brown");
    else if(flag==3)
        setColor("spotted");

}

void bunny::GetRadioactiveOrNot()
{
    int flag=rand()%1000;

    if(flag>0 && flag<20)
    {
        setRadioactive(true);
        cout<<"\t\t\t\t\tRADIO-ACTIVE is born\n";}
    else
        setRadioactive(false);

}
void bunny::readthat(vector<string>&bunnynames)
{
    string S;
    fstream fin;
    fin.open("Names.csv",ios::in);
    while(getline(fin,S))
    {
        bunnynames.push_back(S);

    }
    fin.close();

}

