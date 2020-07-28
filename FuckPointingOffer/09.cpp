#include <stack>
using namespace std;

class CQueue {
public:
    std::stack<int> a, b;
    CQueue() {}
    
    void appendTail(int value) {
        a.push(value);
    }
    
    int deleteHead() {
        if (a.empty() && b.empty()) return -1;
        else if (b.empty() && !a.empty()) {
            while(!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
        int t = b.top();
        b.pop();
        return t;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */