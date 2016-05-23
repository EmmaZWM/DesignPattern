#include <iostream>

using namespace std;

class Duck {
public:
    Duck() { }
    void swim() {
        cout << "I can swim." << endl;
    }
};

class Chicken {
public:
    void boat() {
        cout <<  "I am on a boat to swim." << endl;
    }
};

// Class Adapter
class DuckAdapter:public Duck, private Chicken {
public:
    void swim() { this->boat();} 
private:
    Chicken* _chicken;
};

// Object Adapter
class DuckAdapter2:public Duck {
public:
    DuckAdapter2(Chicken* chicken) { _chicken = chicken;}
    void swim() { _chicken->boat();};
private:
    Chicken* _chicken;
};

int main() {
    DuckAdapter da;
    da.swim();

    Chicken* c = new Chicken();
    DuckAdapter2 da2(c);
    da2.swim();
}
