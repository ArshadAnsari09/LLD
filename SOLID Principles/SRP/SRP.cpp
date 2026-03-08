#include<iostream>
#include<vector>

using namespace std;

class Product {
    public: 
    string name;
    double price;

    Product(string name,double price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart {
    private :
    vector<Product*> products;

    public : 
    void addProduct(Product* p){
        products.push_back(p);
    }
    vector<Product*>& getProducts(){
        return products;
    }

    double calculateTotalPrice(){
        double totalPrice = 0;
        for(auto p: products){
            totalPrice += p->price;
        }
        return totalPrice;
    }
};

class ShoppingCartInvoice{
    ShoppingCart* cart;
    
    public : 
    ShoppingCartInvoice(ShoppingCart* cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout << "Invoice: " << endl;
        for(auto p : cart -> getProducts()){
            cout << p->name << " : " << p->price << endl;
        }
        cout << "Total Price: " << cart -> calculateTotalPrice() << endl;
    }
};

class ShoppingCartStorage{
    private : 
    ShoppingCart* cart;

    public : 
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart = cart;
    }

    void saveToDB(){
        cout << "Saving invoice to database..." << endl;
    }

};

int main () {
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop1", 1000));
    cart->addProduct(new Product("Mouse1", 50));

    ShoppingCartInvoice* cartInvoice = new ShoppingCartInvoice(cart);
    cartInvoice->printInvoice();
    return 0;
}