#include<iostream>
using namespace std;

class Burger {
    public : 
    virtual void prapare() = 0;
    virtual ~Burger() {}
};

class StandardBurger : public Burger {
    public : 
    void prapare() override{
        cout << "Preparing Standard Burger" << endl;
    }
};

class BasicBurger : public Burger {
    public : 
    void prapare() override {
        cout << "Preparing Basic Burger" << endl;
    }

};

class PremiumBurger : public Burger {
    public : 
    void prapare() override{
        cout << "Preparing Premium Burger" << endl;
    }
};

class StandardWheatBurger : public Burger {
    public : 
    void prapare() override {
        cout << "Preparing Standard Wheat Burger" << endl;
    }
};

class BasicWheatBurger : public Burger {
    public : 
    void prapare() override {
        cout << "Preparing Basic Wheat Burger" << endl;
    }
};

class PremiumWheatBurger : public Burger {
    public : 
    void prapare() override {
        cout << "Preparing Premium Wheat Burger" << endl;
    }
};

class GarlicBread{
    public : 
    virtual void prepare() = 0;
};

class BasicGarlicBread : public GarlicBread {
    public : 
    void prepare() override {
        cout << "Preparing Basic Garlic Bread" << endl;
    }
};

class StandardGarlicBread : public GarlicBread {
    public : 
    void prepare() override {
        cout << "Preparing Standard Garlic Bread" << endl;
    }
};

class PremiumGarlicBread : public GarlicBread {
    public : 
    void prepare() override {
        cout << "Preparing Premium Garlic Bread" << endl;
    }
};

class MealFactory{
    public : 
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
};

class KingBurger : public MealFactory {
    public : 
    Burger* createBurger(string& type) override {
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

    GarlicBread* createGarlicBread(string& type) override {
        if(type == "Basic"){
            return new BasicGarlicBread();
        }else if(type == "Standard"){
            return new StandardGarlicBread();
        }else if(type == "Premium"){
            return new PremiumGarlicBread();
        }else{
            cout << "Invalid Garlic Bread Type" << endl;
            return nullptr;
        }
    }
};

class SinghBurger : public MealFactory {
    public : 
    Burger* createBurger(string& type) override {
        if(type == "Basic"){
            return new BasicWheatBurger();
        }else if(type == "Standard"){
            return new StandardWheatBurger();
        }else if(type == "Premium"){
            return new PremiumWheatBurger();
        }else{
            cout << "Invalid Burger Type" << endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string& type) override {
        if(type == "Basic"){
            return new BasicGarlicBread();
        }else if(type == "Standard"){
            return new StandardGarlicBread();
        }else if(type == "Premium"){
            return new PremiumGarlicBread();
        }else{
            cout << "Invalid Garlic Bread Type" << endl;
            return nullptr;
        }
    }
};

int main(){
    string type = "Standard";
    MealFactory* myMealFactory = new KingBurger();
    Burger* burger = myMealFactory->createBurger(type);
    GarlicBread* garlicBread = myMealFactory->createGarlicBread(type);
    burger->prapare();
    garlicBread->prepare();
    return 0;
}