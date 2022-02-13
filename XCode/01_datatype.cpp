#include "demo_common.h"
using namespace std;


// 类型转换，浮点数位数，格式化输出
// static_cast, same as c
// dynamic_cast, base -> derived
// const_cast, remove const
// reinterpret_cast, func pointer -> return value changed

const int outer_param = 0x3f3f3f3f;

int main()
{
	int a = 12;
	float b = 0.1;
	double c = 0.1;

	cout << a << " " << static_cast<float>(1.1 * a) << endl;
	cout << b << " " << (int)b << endl;
	cout << c << endl;

	system("pause");
	return 0;
}
