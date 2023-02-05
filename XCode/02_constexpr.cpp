#include "demo_common.h"
using namespace std;

// constexpr 编译期间确定值，只允许一个 return
// constexpr 修饰的函数，其所有参数都是 constexpr 时，一定返回 constexpr

constexpr int getint() { return 10; }

int main()
{
	const int a = 12;
	const int b = 23;

	// 编译不过，本地函数定义非法。。。
	//constexpr int getint() { return 10; }

	constexpr int ret = getint();
	cout << ret << endl;

	system("pause");
	return 0;
}
