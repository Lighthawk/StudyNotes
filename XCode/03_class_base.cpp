#include "demo_common.h"
using namespace std;

// copy constructor
// move constructor
class IntNum {
public:
    IntNum(int x = 0) : xptr(new int(x)) {
        cout << "constructor" << endl;
    }
    IntNum(const IntNum& n) : xptr(new int(*n.xptr)) {
        cout << "copy constructor" << endl;
    }
    IntNum(IntNum&& n) : xptr(n.xptr) {		// && ����ֵ���ã�����������ֵ��������������ʱ��������ֵ
        n.xptr = nullptr;
        cout << "move constructor" << endl;
    }
    ~IntNum() {
        delete xptr;
        cout << "destructing" << endl;
    }
    int getInt() { return *xptr; }
private:
    int* xptr;
};

IntNum getNum() {
    IntNum a;
    return a;
}

int main() {
    cout << getNum().getInt() << endl;
    system("pause");
    return 0;
}

// ���н����
// constructor
// move constructor
// destructing
// 0
// destructing
