#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <list>
#include <chrono>
#include<vector>


#include "hashclass.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv)//our main function
{
	int cnt=0;
	string line;//declaring the each line of the text file as a string - needed when we read the file
	HashMap myHashMap(130003);//the capacity of the HashMap //100,000*1.33 then take the largest prime number 

	string file=argv[2];//this corresponds to the file name in the command line argument
	//opening the csv file
	ifstream fin;
	fin.open(file);
	if(!fin){
		cout<< "The file cannot be opened!"<<endl;
		exit(-1);
	}
	getline(fin,line); //reading each line from the file
	//cout << line << endl;
	//int cntt = 0;
	while(getline(fin, line))//this loop keeps on reading each line in the file
	{
		
		
		//cout << line << endl;
		int pos = line.find(','); //finding the position of the first comma
		pos = line.find(',', pos+1);// finding the position of the second comma
		string key = line.substr(0, pos);//key consisting of the beginning to the second comma
		string value = line.substr(pos+1, string::npos);//the value consisting of everything after the second comma till the end
		//cout << key << ":" << value << endl;
		//getline(fin,key,',');
		myHashMap.insert(key,value);//inserting the key and the value in the HashMap
		//getline(fin,cityName);
		//cout<<key<<","<<value<<endl;
		//myHashMap.insert(key,cityName,value);
	}
	fin.close();//closing the file

	cout<<"Hash Map Size = "<<myHashMap.getSize()<<endl;//printing the size for the HashMap

	string choice;//choice is the the user's provided string
	while(true)
	{
		cout<< ">>";//asking a user for a query
		getline(cin,choice);//getting the entered command from the user

		if (choice.find("quit") != string::npos)//if the user chooses quit, the porgram quits
			break;
		else if(choice.find("find") != string::npos&& (choice.size() > 2))//else if the user chooses "find" 
		{
			//extracting the query by finding whatever is after "find"
			string query = choice.substr(choice.find(" ")+1, string::npos);
			auto start = high_resolution_clock::now();//starting to count the time
			string result = myHashMap.search(query);//calling the search function
			auto end = high_resolution_clock::now();//ending the couting of the time
			auto time = duration_cast<microseconds>(end-start);//the time needed is "end - start" measured in microseconds
			cout<<"Time needed: "<<time.count()<<" ms"<<endl;
			if(myHashMap.search(query)!="Deleted")//if the query is not deleted
			{
				//cout<<myHashMap.search(query)<<endl;
				cout<<"The record for " << choice <<" is: " << query+","+result <<endl;//print the record
				cout << "Number of comparisons:" << myHashMap.cnt << endl;//print the number of comparisons
			}

			else 
			{
				cout<<"The record has been deleted."<<endl;//else if the record has been deleted
			}
			
		}
		else if (choice.find("add") != string::npos)//if the user chooses to add a record
		{
			string key,value;
			int pos = choice.find(',');//finding the first comma
			pos = choice.find(',', pos+1);//finding the second comma
			string query=choice.substr(4,pos-4);//specifying the query from after "add "(the first letter from user is at a position 4)
			string valuee=choice.substr(pos+1);
			//cout << query << endl;//prints the query the user entered
			//cout<<valuee<<endl;
			//cout<<"hash: "<<myHashMap.search(query)<<endl;
			//cout<<"key:" <<key<<endl;
			//cout<<"query: "<<query<<endl;
			//cout<<"value: "<<value<<endl;


			if (myHashMap.search(query)== "Deleted"){ //if the query is deleted then insert in into the HashMap 
				myHashMap.insert(query,valuee);
				cout<<"The Record has been Added"<<endl;

			}

			else if (myHashMap.search(query)!= "Not Found!")
			{//if the query is found
				cout<<"This record already exists"<<endl;
			}
				//then it already exists
			//else
			//{
			//	myHashMap.insert(key,value);//if it doesn't exist we add the user's query
			//cout<<"The Record has been Added"<<endl;//printing that we added the record
			//}
		}

		else if (choice.find("delete")!=string::npos && (choice.size()>2))//if the user wants to delete the a record
		{

			string query = choice.substr(choice.find(" ")+1, string::npos);//after the word delete till the end
			if (myHashMap.search(query)!="Not Found!")//if the query is found
				{
					myHashMap.erase(query);//call the erase function
					cout<<"The record for "+query+" has been deleted."<<endl;//if the record is found, we delete it
				}
			else
				cout<<"Sorry! The record was not found."<<endl;//if it is not found
		}


		else if(choice.find("allinCity")!=string::npos && (choice.size()>1))//if the user chooses to print all hotels in a specific city
		{

			string query=choice.substr(choice.find(" ")+1, string::npos);//again extract the query from whatever is after "allinCity "
			myHashMap.allinCity(query);//calling the function allin City
		}


		else if(choice.find("dump")!=string::npos&& (choice.size()>1))//if the user chooses dump 
		{
			string dFile=choice.substr(choice.find(" ")+1, string::npos);//whatever is after "dump "
			myHashMap.CreateVector(dFile);//calling the function of creating the vector to dump the entire structure in a file
			cout<< "The Content of the Hash Map has been dumpted into the file"<<endl;
		}

		else
			cout<<"Incorrect Input"<<endl;//if the user types in any incorrect input, he gets an error message
	}
	exit(0);
}