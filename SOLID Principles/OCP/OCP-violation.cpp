#include<iostream>

using namespace std;

class Product {
    public :
    string name;
    double price;
    
    public : 
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

    double calculatePrice(){
        double totalPrice = 0;
        for(auto p : products){
            totalPrice += p -> price;
        }
        return totalPrice;
    }
};

class Invoice {
    private : 
    ShoppingCart* cart;

    public : 
    Invoice(ShoppingCart* cart){
        this-> cart = cart;
    }

    void printInvoice(){
        cout << "Invoice: " << endl;
        for(auto p : cart -> getProducts()){
            cout << p->name << " : " << p->price << endl;
        }
        cout << "total Price : " << cart -> calculatePrice() << endl;
    }
};

class Storage {
    private : 
    ShoppingCart* cart;

    public : 
    Storage(ShoppingCart* cart){
        this->cart = cart;
    }
    
    void saveToSQLDB(){
      cout << "Saving to SQL DB: " << endl;
    }
    void saveToMongoDB(){
        cout << "Saving to MongoDB: " << endl;
    }
    void saveToFile(){
        cout << "Saving to File: " << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    cart -> addProduct(new Product("Laptop2", 1000));
    cart -> addProduct(new Product("Phone2", 500));
    
    Invoice* invoice = new Invoice(cart);
    invoice -> printInvoice();

    Storage* storage = new Storage(cart);
    storage -> saveToSQLDB();
    return 0;
}