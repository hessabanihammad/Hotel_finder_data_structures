#ifndef HASHCLASS_H
#define HASHCLASS_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <list>
#include <chrono>
#include<vector>


using namespace std;
using namespace std::chrono;

class HashNode //this is the HashNode class
{
	private: //private members of the class
		string key; //the key has the hotel name and city name
		string value; //the value are the other details other than the hotel name and city name 
	
	public:
		HashNode(string key, string value);

		string getKey(); //a function that gets the key

		string getValue();//a function that gets the value

		string getHotelName();//a function that gets the hotel name

		string getcityName();//a function that gets the city name

		void ChangeValue(string newValue);//a function that changes the value to "Deleted"
}; 

class HashMap
{
	private:
		HashNode **nodeArray; //Array of pointers to Hash nodes 
		int size; //Size of the Hashmap 
		int capacity; //Total Capacity of Hashmap 
	public: //public members of the class 
		int cnt; //counter that keeps track of the number of comparisons 
		
		HashMap(int capacity);//the capacity of the HashMap

		int hashCode(const string key); //creating the hashcode

		string search(const string key); //searching for the key function
	
		void insert(const string key, const string value); //inserting a hotel value function 

		void erase(const string key); //erasing the key from the hash map

		void allinCity(const string cityName); //function that return all the hotels in the entered city

		void CreateVector(string& fileName);//creating a vector for the dump function
		
		int getSize();//getting the size of the Hashmap

		~HashMap(); //dellocates the memory of the Hashmap
};	

#endif