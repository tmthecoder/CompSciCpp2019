/****
 * Name: Tejas Mehta
 * Date: October 30th, 2019
 * Lab Name: Movie_Food_Lab
 * Extra: Used maps and iterators with the auto term, allowing me to get a key value pair and made the process of message writing and item tracking much easier, but with a learning curve
 */
#include <iostream>
#include <map>
using namespace std;
int main() {
    //Translator maps for cost and item name
    map<char, double> itemCost = {
            {'b',5.00},
            {'c',2.25},
            {'h',7.00},
            {'p',6.75},
            {'i',4.50},
    };
    map<char, string> itemNames = {
            {'b',"Beverage"},
            {'c',"Candy"},
            {'h',"Hot Dog"},
            {'p',"Popcorn"},
            {'i',"Pizza"},
    };
    //Start count at 994 so we can test the 1000th case
    int customerCount = 994;
    while (customerCount <= 1000) {
        //Set items to 0 and all bought items to 0
        map<string, int> itemsBought = {
                {"Beverage",0},
                {"Candy",0},
                {"Hot Dog",0},
                {"Popcorn",0},
                {"Pizza",0},
        };
        //Ask and get name
        cout << "Enter your first and last name:" << endl;
        string name;
        double cost = 0;
        getline(cin, name);
        //Loop in case of multiple items
        while (true) {
            //Ask and get an item
            cout << "Which item would you like to buy? Enter the letter in the parenthesis to select the item:\n"
                    "a. (B)everage: $5.00\n"
                    "b. (C)andy: $2.25\n"
                    "c. (H)ot Dog: $7.00\n"
                    "d. (P)opcorn: $6.75\n"
                    "e. P(i)zza: $4.50" << endl;
            char entry;
            cin >> entry;
            entry = char(tolower(entry));
            //Check whether it is valid
            if (entry == 'b' || entry == 'c' || entry == 'h' || entry == 'p' || entry == 'i') {
                //Add item cost to total, increment total items and the specific item's count
                cost += itemCost[entry];
                itemsBought[itemNames[entry]]++;
                //Ask if they need anything else
                cout << "Do you need to buy anything else?(y/n, defaults to n)" << endl;
                char continueBuying; cin >> continueBuying;
                if (char(tolower(continueBuying)) != 'y') {
                    //Make the presentable message by iterating through the map
                    string itemsMessage = "";
                    for(auto & item : itemsBought)
                    {
                        //Get the itemName as well as how many are being bought
                        string itemName = item.first;
                        int amount =  item.second;
                        //Check if we need to make the word plural
                        if (amount > 1) {
                            //Exempt special cases like candy and popcorn and give them their on plurals and add an s to the others
                            if (itemName == "Candy") {
                                itemsMessage += "\n" + to_string(amount) + " " + "Candies";
                            } else if (itemName == "Popcorn") {
                                itemsMessage += "\n" + to_string(amount) + " " +  "Orders of Popcorn";
                            } else {
                                itemsMessage += "\n" + to_string(amount) + " " + itemName + "s";
                            }
                        } else if (amount == 1) {
                            //Just do 1 of said item as there is no plurality
                            itemsMessage += "\n" + to_string(amount) + " " + itemName;
                        }
                    }
                    //Ask for money and show the list of items
                    cout << "Please deposit $" << cost << " and wait while I prepare your items:" << itemsMessage << endl;
                    customerCount++;
                    cin.ignore();
                    break;
                }
            } else if (entry == 'q') {
                //Special case, ask for password
                cout << "Enter the password" << endl;
                //Get password and check it, if correct, shut off, if not, just go back to normal
                string password; cin >> password;
                if (password == "ShutMeDown") {
                    cout << "Maintainable shutdown.... Powering off ...." << endl;
                    return 0;
                } else {
                    break;
                }
            } else {
                //Invalid choice, ask for another item
                cout << "That is not a proper menu choice. I'll assume that you are not hungry" << endl;
                cout << "Do you want to pick another item?" << endl;
                char answer;
                cin >> answer;
                answer = char(tolower(answer));
                //Go to next if no is said
                if (answer == 'n') {
                    cout << "I will now help the next patron." << endl;
                    customerCount++;
                    break;
                }
            }
        }
    }
    //1000th user shutdown
    cout << "Shutting down to rebuild resources..." << endl;
}