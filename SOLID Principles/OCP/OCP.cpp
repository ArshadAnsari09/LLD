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

class Persistence {
    private : 
    ShoppingCart* cart;

    public : 
    virtual void save(ShoppingCart* cart) = 0;
};

class SQLPersistence : public Persistence {
    public : 
    void save(ShoppingCart* cart) override {
       cout << "Saving to SQL Database..." << endl;
    }
};

class MonogDBPersistence : public Persistence {
    public : 
    void save(ShoppingCart* cart) override {
       cout << "Saving to MongoDB Database..." << endl;
    }
};

class FilePersistence : public Persistence {
    public : 
    void save(ShoppingCart* cart) override {
       cout << "Saving to file..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    cart -> addProduct(new Product("Laptop2", 1000));
    cart -> addProduct(new Product("Phone2", 500));
    
    Invoice* invoice = new Invoice(cart);
    invoice -> printInvoice();

    Persistence* sqldb = new SQLPersistence();
    Persistence* mongodb = new MonogDBPersistence();
    Persistence* filedb = new FilePersistence();
    sqldb -> save(cart);
    mongodb -> save(cart);
    filedb -> save(cart);
    return 0;
}