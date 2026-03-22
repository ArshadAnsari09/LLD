
#include<iostream>
using namespace std;

class Burger {
    public : 
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger : public Burger {
    public:
    void prepare() override{
        cout << "Preparing Basic Burger" << endl;
    }
};

class PremiumBurger : public Burger {
    public : 
    void prepare() override {
        cout << "Preparing Premium Burger" << endl;
    }
};

class StandardBurger : public Burger {
    public : 
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};

class BurgerFactory{
    public :
    Burger* createBurger(string& type){
        if(type == "Basic"){
            return new BasicBurger();
        }else if(type == "Standard"){
            return new StandardBurger();
        }else if(type == "Premium"){
            return new PremiumBurger();
        }else{
            cout << "Invalid Burger Type" << endl;
            return nullptr;
        }
    }
};

int main(){
    string type = "Standard";
    BurgerFactory* myBurgerFactory = new BurgerFactory();
    Burger* burger = myBurgerFactory->createBurger(type);
    burger->prepare();
    return 0;
}