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


HashNode::HashNode(string key, string value)//returns the key and value
{
	this->key=key;
	this->value=value;			
}

string HashNode::getKey()//gets the key
{
	return this-> key; 
}

string HashNode::getValue()//gets the value
{
	return this->value;
}

string HashNode::getHotelName()//gets the hotel name and returns it
{
	int pos = this->key.find(',');
	string HotelName = key.substr(0, pos);
	return HotelName;
}

string HashNode::getcityName()//gets the city name and returns it
{
	//whatever is after the first comma
	int pos1 = this->key.find(',');
	string cityName = key.substr(pos1+1, string::npos);
	return cityName;
}

void HashNode::ChangeValue(string newValue)//changing the value to deleted
{
	this->value=newValue;

} 

HashMap::HashMap(int capacity)//allocates the capacity of the HashMap
{
	nodeArray= new HashNode*[capacity];
	this->capacity=capacity;
	this-> size=0; 
}
		
int HashMap::hashCode(const string key)//creating the HashCode
{
	//creating hash code for the key 
	long KeySum=0;
	for(int i=0; i<key.length();i++)
	{
		KeySum+=(int)key[i]*i;//summing all the keys 
	}
	KeySum=KeySum*key.size();
	//cout<<KeySum<<endl;
	return KeySum%(this->capacity);
}

string HashMap::search(const string key)
//searching for a key and returning its value 
{ 
	this->cnt=0; 
	int index= hashCode(key);//the index is the HashCode of the key
	while(nodeArray[index]!=NULL && this->cnt<=this->capacity)//while the index of the HashCode is not NULL and less the capacity
	{
		//cout << cnt << " " << index << " " << nodeArray[index]->getKey() << " " << key << endl;
		this->cnt++;//increasing the counter
		if (nodeArray[index]->getKey()==key)//if the index of the HashCode is equal to the key, we get it
		{
			return string(nodeArray[index]->getValue());//here we return the value of the key
		}
		else {
			index=(index+1)%this->capacity;//we keep on searching the HashTable
		}
	}
			return "Not Found!";//if not found just return not found
}

void HashMap::insert(const string key, const string value)//insert function which inserts the key and the value
{
	int index=hashCode(key);
	HashNode* temp= new HashNode(key,value); //creates a new temp variable which is a pointer to the HashNode 
	while(nodeArray[index]!=NULL && nodeArray[index]->getValue()!="Deleted") //while the index of the hash code is not null and the value has not been deleted 
	{
		//if (nodeArray[index]->getValue()=="Deleted"){

				index=(index+1)%this->capacity;
			//}

	}
	nodeArray[index]=temp; 
	this->size++;


}

void HashMap::erase(const string key) //function which earases the key 
{
	int cnt=0;
	int index=hashCode(key);
	while(nodeArray[index]!=NULL && cnt<= this->capacity) // if it doesnt point to null 
	{
		if (nodeArray[index]->getKey()==key) // if it matches the key get it 
		{
			nodeArray[index]->ChangeValue("Deleted");// nodeArray[index]->NULL; //change it to deleted 
			this->size--; //decrease the size of the hash map by one 
			break;
		}
		else
		{
			index=(index+1)%this->capacity; 
		cnt++;
		}
	}
}	

void HashMap::allinCity(const string cityName) //function that returns all the hotels in a city 
{
	int cnt=0;
	for (int i=0; i<this->capacity; i++)
	{
		if (nodeArray[i]!=NULL && nodeArray[i]->getcityName()==cityName) //if it doesnt point to null and the city name matches the city name provided by the user 
		{
			cout<<nodeArray[i]->getHotelName()<<endl;// get hotel name
			cnt++;
		}
	}
		if (cnt==0)
		{
				cout<<"The City is not found"<<endl;
		}
}
void HashMap::CreateVector(string& fileName) //function that creates the vector 
{
	ofstream dumpFile; //create the output file 
	vector<string> dumpVector; //creating a vector of strings called dumpVector 
	dumpFile.open(fileName); //open the file name 
	for(int i=0; i<this->capacity;i++)
	{
		if (nodeArray[i]!= NULL && nodeArray[i]->getValue()!="Deleted") //if the node array is not equal to null and the value has been changed to deleted 
		{
			dumpVector.push_back(nodeArray[i]->getKey()); //then we push it into the vecotr 
		}
	}
	sort(dumpVector.begin(), dumpVector.end()); //sorting the vector in increasing alphabatical order 
	for (int i = 0; i < dumpVector.size(); i ++)
	{
		string key = dumpVector[i];
		string value = this->search(key);
		dumpFile << key << "," << value << endl; //printing the key and value into the dump File 
	}
			dumpFile.close(); //closing the file 
}
int HashMap::getSize() //returns the size of the hash map 
{
	return this->size;
}

HashMap::~HashMap() //dellocates the allocated memory 
{
	delete[] this->nodeArray;
}