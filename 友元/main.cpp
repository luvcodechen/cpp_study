// #include <iostream>
// #include <string>
// using namespace std;
//
// // 建筑物类
// class Building
// {
// 	//guys 是类Building的朋友，可以访问私有成员
// 	friend void guys(Building* building);
//
// public:
// 	Building()
// 	{
// 		m_SittingRoom = "客厅";
// 		m_BedRoom = "卧室";
// 	};
//
// 	string m_SittingRoom; // 客厅
//
// private:
// 	string m_BedRoom; // 卧室
// };
//
// // 全局函数做友元
// void guys(Building* building)
// {
// 	cout << "全局函数guys 正在访问： " << building->m_SittingRoom << endl;
// 	cout << "全局函数guys 正在访问： " << building->m_BedRoom << endl;
// }
//
// void test()
// {
// 	Building building;
// 	guys(&building);
// }
//
// // int main()
// // {
// // 	test();
// //
// // 	return 0;
// // }
