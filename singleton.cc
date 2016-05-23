#include <iostream>

using namespace std;

class Context {
public:
    static Context* getInstance() {
        if ( instance == NULL ) {
            cout << "create new" << endl;
            instance = new Context();
        }
        return instance;
    }

private:
    static Context*  instance;
    Context() {}
};
Context* Context::instance = NULL;

int main() {
    auto c1 = Context::getInstance();
    auto c2 = Context::getInstance();
}
