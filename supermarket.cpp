#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<bits/stdc++.h>
#include<sstream>
#include<limits>
using namespace std;

void printMap(map<string, pair<int, int>> stock){
    for(auto itr = stock.begin(); itr != stock.end(); ++itr){
        cout << itr->first << " " << itr->second.first << " " << itr->second.second << "\n";
    }
}

int main(){
    map<string, pair<int, int>> stock;
    int choice;
    string item;
    int amount, price;
    cout << "---------------Welcome to the Supermarket-----------------" << endl;
    cout << " 1: View Items \n 2: Add To Cart \n 3: Check Out \n 4: Search Items \n 5: Edit Items \n 6: Exit Market " << endl;
    cout << "Make a choice ", cin >> choice;
    //stock.insert({item, {amt, price}});
    //printMap(stock);
    if(choice == 1){
        //display items
    }else if(choice == 2){
        //add items to cart
        cout << "Enter product name: ", cin >> item;
        while(true){
            cout << "Enter product amount(kgs): ";
            if(cin >> amount){
                break;
            }else{
                cout << "Invalid amount!! \n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        while(true){
            cout << "Enter product price: ";
            if(cin >> price){
                break;
            }else{
                cout << "Invalid Price!! \n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        stock.insert({item, {amount, price}});
        cout << "Success!" << endl;
        printMap(stock);
    }else if(choice == 3){
        //check out items
    }else if(choice == 4){
        //search items
    }else if(choice == 5){
        //Edit items
    }else if(choice == 6){
        //quit()
    }
    return 0;
}