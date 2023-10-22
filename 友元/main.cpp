#include <iostream>
#include <string>
using namespace std;

// 建筑物
class Building
{
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	};

	string m_SittingRoom; // 客厅

private:
	string m_BedRoom; // 卧室
};

// 全局函数
void guys(Building* building)
{
	cout << "全局函数guys 正在访问： " << building->m_SittingRoom << endl;
}

void test()
{
	Building building;
	guys(&building);
}

int main()
{
	test();

	return 0;
}
