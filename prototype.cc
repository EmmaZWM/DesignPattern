#include <iostream>
#include <map>

using namespace std;

class Bread {
public:
    virtual Bread* clone() = 0;
    virtual void yammy() = 0;
};

class FrenchBread:public Bread {
    Bread* clone() { return (Bread*)new FrenchBread();};
    void yammy() {
        cout << "French bread is yammy." << endl;
    }
};

class BritishBread:public Bread {
    Bread* clone() { return (Bread*)new BritishBread();}
    void yammy() {
        cout << "British bread is awful." << endl;
    }
};

class Bakery {
public:
    void addBread(string type, Bread* bread) {
        breadList[type] = bread;
    }

    Bread* getBread(string type) {
        return breadList[type];
    }
private:
    map<string, Bread*> breadList;
};

int main() {
    Bakery b;
    b.addBread("french", ((Bread*)new FrenchBread())->clone());
    auto c = b.getBread("french");
    c->yammy();
}
