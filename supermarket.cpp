#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<bits/stdc++.h>
#include<limits>
using namespace std;

void printMap(map<string, pair<int, int>> stock){
    cout << "NAME \t" << "QTY(kg) \t" << "PRICE(kg)" << endl;
    for(auto itr = stock.begin(); itr != stock.end(); ++itr){
        cout << itr->first << "\t" << itr->second.first << "\t\t" << itr->second.second << "\n";
    }
}

int main(){
    map<string, pair<int, int>> stock;
    map<string, pair<int, int>> cart;
    map<string, pair<int, int>>::iterator it;
    int total = 0;
    int choice;
    string item;
    int amount, price;
    while(true){
        cout << "---------------Welcome to the Supermarket-----------------" << endl;
        cout << " 1: View Stock \n 2: View Cart \n 3: Add To Stock \n 4: Add to Cart \n 5: Check Out \n 6: Search Items \n 7: Edit Items \n 8: Exit Market " << endl;
        cout << "Make a choice ", cin >> choice;
        if(choice == 1){
            //display items
            if(stock.size() == 0){
                cout << "Empty Supermarket!!" << endl;
            }else{
                printMap(stock);
            }
        }else if(choice == 2){
            if(cart.size() == 0){
                cout << "Empty Cart!! " << endl;
            }else{
                printMap(cart);
            }
        }else if(choice == 3){
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
        }else if(choice == 4){
            //check out items
            if(stock.size() == 0){
                cout << "Empty Supermarket!!" << endl;
            }else{
                cout << "Enter item name ", cin >> item;
                it = stock.find(item);
                if(it == stock.end()){
                    cout << "Item out of stock!!" << endl;
                }else{
                    cout << "Enter amount(kgs) ";
                    while(true){
                        cin >> amount;
                        if(amount < it->second.first){
                            cout << "Item was added to cart!" << endl;
                            cart.insert({it->first, {amount, it->second.second}});
                            it->second.first -= amount;
                            cout << "----------------YOUR CART-------------------" << endl;
                            printMap(cart);
                            /*
                            for(auto ct = cart.begin(); ct != cart.end(); ++ct){
                                total += ct->second.first * ct->second.second;
                            }
                            cout << "Total Payable: $" << total << endl;
                            break;
                            */
                            break;
                        }else{
                            cout << item << " running low, Please lower quantity ";
                        }
                    }
                }
            }
        }else if(choice == 5){
            for(auto ct = cart.begin(); ct != cart.end(); ++ct){
                total += ct->second.first * ct->second.second;
            }
            cout << "Total Payable: $" << total << endl;
        }else if(choice == 6){
            //search items
            cout << "Enter item name to search ", cin >> item;
            it = stock.find(item);
            if(it == stock.end()){
                cout << "Item is not avaliable " << endl;
            }else{
                cout << it->first << " " << it->second.first << " " << it->second.second << endl;
            }
        }else if(choice == 7){
            //Edit items
            cout << "Enter name of item ", cin >> item;
            it = cart.find(item);
            if(it == cart.end()){
                cout << "No such item your cart! " << endl;
            }else{
                cout << it->first << " " << it->second.first << " " << it->second.second << endl;
                cout << "Change name ", cin >> item;
                cout << "Change amount ", cin >> amount;
                cout << "Change price ", cin >> price;
                /*
                it->first = item;
                it->second.first = amount;
                it->second.second = price;
                */
                cout << "Items changed Successfully! " << endl;
                cout << it->first << " " << it->second.first << " " << it->second.second << endl;
            }
        }else if(choice == 8){
            cout << "----------------------Leaving Supermarket---------------------" << endl;
            break;
            //quit()
        }
    }
        return 0;
}
