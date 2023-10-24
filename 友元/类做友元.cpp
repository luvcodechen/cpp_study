#include  <iostream>
#include <string>

using namespace std;

class Building
{
	// 类做友元
	friend class guys;

public:
	Building();

public:
	string m_SittingRoom; // 客厅

private:
	string m_BedRoom; //  卧室
};

// 类外写成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

class guys
{
public:
	Building* building;

	guys()
	{
		// 创建建筑物对象
		building = new Building;
	}

	// 参观函数 访问Building中的属性
	void visit()
	{
		cout << "guys 正在访问 " << building->m_SittingRoom << endl;
		cout << "guys 正在访问 " << building->m_BedRoom << endl;
	};
};

// void test()
// {
// 	guys g;
// 	g.visit();
// }

// int main()
// {
// 	test();
// 	return 0;
// }
