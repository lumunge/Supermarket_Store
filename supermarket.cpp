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
    int choice;
    string item;
    int amount, price;
    while(true){
        cout << "---------------Welcome to the Supermarket-----------------" << endl;
        cout << " 1: View Items \n 2: Add To Cart \n 3: Check Out \n 4: Search Items \n 5: Edit Items \n 6: Exit Market " << endl;
        cout << "Make a choice ", cin >> choice;
        if(choice == 1){
            //display items
            if(stock.size() == 0){
                cout << "Empty Supermarket!!" << endl;
            }else{
                printMap(stock);
            }
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
            int total = 1;
            //check out items
            if(stock.size() == 0){
                cout << "Empty Market!!" << endl;
            }else{
                cout << "Enter item name ", cin >> item;
                cout << "Enter amount(kgs) ";
                it = stock.find(item);
                if(it == stock.end()){
                    cout << "Item out of stock!!" << endl;
                }else{
                    while(true){
                        cin >> amount;
                        if(amount < it->second.first){
                            cout << "Item was added to cart!" << endl;
                            cart.insert({it->first, {amount, it->second.second}});
                            it->second.first -= amount;
                            cout << "----------------YOUR CART-------------------" << endl;
                            printMap(cart);
                            for(auto ct = cart.begin(); ct != cart.end(); ++ct){
                                total += ct->second.first * ct->second.second;
                            }
                            cout << "Total Payable: $" << total-1 << endl;
                            break;
                        }else{
                            cout << item << " running low, Please lower quantity ";
                        }
                    }
                }
            }
        }else if(choice == 4){
            //search items
        }else if(choice == 5){
            //Edit items
        }else if(choice == 6){
            cout << "----------------------Leaving Supermarket---------------------" << endl;
            break;
            //quit()
        }
    }
        return 0;
}
