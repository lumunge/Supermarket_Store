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
    map<string, pair<int, int>>::iterator st;
    int total = 0;
    int difference;
    int choice;
    string item;
    int amount, price;
    while(true){
        cout << "---------------Welcome to the Supermarket-----------------" << endl;
        cout << " 1: View Stock \n 2: View Cart \n 3: Add To Stock \n 4: Add to Cart \n 5: Check Out \n 6: Search Items \n 7: Edit Items \n 8: Clear Cart \n 9: Exit Market " << endl;
        cout << "Make a choice ", cin >> choice;
        if(choice == 1){
            //display items
            if(stock.size() == 0){
                cout << "Empty Supermarket!!" << endl;
            }else{
                cout << "\t\t ITEMS IN STOCK " << endl;
                printMap(stock);
            }
        }else if(choice == 2){
            if(cart.size() == 0){
                cout << "Empty Cart!! " << endl;
            }else{
                cout << "\t\t CART ITEMS " << endl;
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
                            break;
                        }else{
                            cout << item << " running low, Please lower quantity ";
                        }
                    }
                }
            }
        }else if(choice == 5){
            //check out
            if(cart.size() == 0){
                cout << "Please purchase some items " << endl;
            }else{
                for(auto ct = cart.begin(); ct != cart.end(); ++ct){
                    total += ct->second.first * ct->second.second;
                }
                cout << "Total Payable: $" << total << endl;
            }
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
            if(cart.size() == 0){
                cout << "Empty Cart " << endl;
            }else{
                cout << "Enter cart item ", cin >> item;
                it = cart.find(item);
                st = stock.find(item);
                if(it == cart.end()){
                    cout << "No such item your cart! " << endl;
                }else{
                    cout << it->first << " " << it->second.first << " " << it->second.second << endl;
                    cout << "Change amount ", cin >> amount;
                    if(amount > st->second.first){
                        cout << "Running out of item, Please reduce amount " << endl;
                    }else if(amount > it->second.first){
                        difference = amount - it->second.first;
                        st->second.first -= difference;
                        it->second.first += difference;
                        cout << "Change was Successfull! " << endl;
                        cout << it->first << " " << it->second.first << " " << it->second.second << endl;
                    }else{
                        difference = it->second.first - amount;
                        st->second.first += difference;
                        it->second.first -= difference;
                        cout << "Change was Successfull! " << endl;
                        cout << it->first << " " << it->second.first << " " << it->second.second << endl;
                    }
                }
            }
        }else if(choice == 8){
            //empty cart
            if(cart.size() == 0){
                cout << "Cart is empty!!" << endl;
            }else{
                cart.clear();
                cout << "Cart was cleared Successfully!" << endl;
            }
        }else if(choice == 9){
            //quit
            cout << "----------------------Leaving Supermarket---------------------" << endl;
            break;
        }
    }
        return 0;
}
