# Hotel_finder_data_structures

In this project, I developed a hotel finder application that helps the user search for a hotel in a specific city. The hotels are identified by the combination of hotel name and city name. The program starts by invoking the application for the terminal in the following format:

./hotelFinder -f <filename> 

The user specifies the file to implement the queries on. The file is opened, and the entries are read into the Hash Map. The Key and Values are inserted into the hash map. Then the user can choose to perform any of the following queries: find k, add s ,delete k, dump f, allinCity c, quit.

Inserting elements into a Hash Map has O(n) worst time complexity because if too many elements were hashed into the same key: looking inside this key may take O(n) time. However, in the average case, the time complexity is O(1) because it is very rare that many items are hashed to the same key (in the case of having a good hash function and we don’t have a big load balance). The hash function takes the hotel name and city name as the key. The key is a combination of the hotel name and city name separated by a comma. For every character in the key, I add them together. Then when I have the sum of the characters, I multiply it by the size of the key. This method makes every key unique because if I don’t multiply the characters with the indexes, I have alot more collisions.

Then, my program asks the user to enter a command from the mentioned queries.

1. Find k: The user is able to find an element with a specific key (hotel name and City name) and then display the entire record of the hotel. It gets the key and then goes to search in the hash map. If it finds the key, it prints the record and if it doesn’t find it, it displays a message to the user saying that the record does not exist. If there isn’t a lot of collisions, the time complexity is constant. Also, this method displays the time the program takes to find the specified hotel name and prints the comparisons as well.
  
2. add s: This method asks the user to input the whole record and add it to the hash map if it doesn’t exist. If the record exists, then it tells the user that this record already exists in the hash map. This method adds the record based on the key. It calls the function insert which separates the hotel name and city name from the record and converts them into a key and adds the whole record to the Hash Map. If there are not many collisions, then the time complexity is constant.
  
3. delete k: This method allows a user to delete a record, given the key (consisting of hotel name and city name). When the program finds the key of the specified hotel it replaces its value with the word “deleted”. If no such element exists, then it prints out an error message to the user. Again, if there aren’t many collisions, the time complexity is constant.

4. dump f: This method allows the user to read the Hash Map content into the file f. This function adds the content of the hash map into a file. Also, it sorts the content of the file f according to the hotel names. This is done through a vector. It loops through the Hash Map which has O(n) time complexity, n being the number of elements in the map and if the value is not deleted, the elements are pushed into the vector. I then use a predefined function to sort the vector.

5. allinCity c: This method allows the user to list all hotels in the city specified by the user. I loop through the Hash map and extract the value of the city from the key and print the entire value corresponding to the city. This method prints all the hotels in the specified city. If the city is not found an error message is printed. The time complexity of this operation is O(n) in which n is the number of records in the map.

6. quit: If the user enters quit in the command line, the program terminates gracefully deleting the dynamically allocated memory.
