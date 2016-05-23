#include <iostream>

using namespace std;

class Bakery {
    public:
        void yammy() { cout << "No" << endl;};
};

class Bread:public Bakery {
    public:
        void yammy() {
            cout << "Bread is yammy." << endl;
        }
};

class Cookie:public Bakery {
    public:
        void yammy() {
            cout << "Cookie is yammy." << endl;
        }
};

class AbstractBakeryFactory {
public:
    Bakery* genBakery();
};

class BreadFactory:public AbstractBakeryFactory{
    public:
        Bread* genBakery() { return new Bread();}
};



int main() {
    BreadFactory bf;
    auto bakery = bf.genBakery();
    bakery->yammy();
};
