#include "demo_common.h"
using namespace std;

// constexpr �����ڼ�ȷ��ֵ��ֻ����һ�� return
// constexpr ���εĺ����������в������� constexpr ʱ��һ������ constexpr

constexpr int getint() { return 10; }

int main()
{
	const int a = 12;
	const int b = 23;

	// ���벻�������غ�������Ƿ�������
	//constexpr int getint() { return 10; }

	constexpr int ret = getint();
	cout << ret << endl;

	system("pause");
	return 0;
}
