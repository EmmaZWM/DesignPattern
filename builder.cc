#include<iostream>
#include <map>

using namespace std;

class Bread {
public:
    void powder(string powder) {bread["powder"] = powder;}
    void water(string water) { bread["water"] = water; }
    void bake(string bake) { bread["bake"] = bake;}
    void juice(string juice) { bread["juice"] = juice; }

    void getBread() {
        for(auto it=bread.begin(); it != bread.end(); it++ ) {
            cout << it->first << ":" << it->second << endl;
        }
    }

protected:
    map<string, string> bread;
};

class FrechBread:public Bread {
public:
    void powder(string powder) { bread["powder"] = "french " + powder;}
    void water(string water) { bread["water"] = "french" + water;}
    void bake(string bake) { bread["bake"] = "french " + bake;}
    void juice(string juice) { bread["juice"] = "french " + juice;}
};

class Bakery {
public:
    void setBread(Bread* b) {_b = b;}
    void cook(string powder, string water, string bake, string juice) {
        _b->powder(powder);
        _b->water(water);
        _b->bake(bake);
        _b->juice(juice);
    }

private:
    Bread* _b;
};


int main() {
    Bakery b;
    Bread* fb = new FrechBread();
    b.setBread(fb);
    b.cook("high tense powder", "clean water", "low tempreture", "apple juice");
    fb->getBread();

}
