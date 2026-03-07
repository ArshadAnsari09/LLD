#include<iostream>

using namespace std;

class Product {
    public :
    string name;
    double price;

    Product(string name,double price){
        this->price = price;
        this->name = name;
    }
};

class ShoppingCart {
    private : 
    vector<Product*> products;

    public : 
    void addProduct(Product* p){
        products.push_back(p);
    }

    vector<Product*>& getProduct(){
        return products;
    }

    double calculatePrice(){
        double totalPrice = 0;
        for(auto p : products){
            totalPrice += p->price;
        }
        return totalPrice;
    }

    void printInvoice(){
        cout << "Invoice: " << endl;
        for(auto p : products){
            cout << p->name << " : " << p->price << endl;
        }
        cout << "Total Price: " << calculatePrice() << endl;
    }

    void saveToDB(){
        cout << "Saving invoice to database..." << endl;
    }
};

int main() {
    ShoppingCart* sc = new ShoppingCart();
    sc->addProduct(new Product("Laptop", 1000));
    sc->addProduct(new Product("Mouse", 50));
    sc->printInvoice();
    sc->saveToDB();
    return 0;
}