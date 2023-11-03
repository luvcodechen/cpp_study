// 创建时间： 2023/11/1 22:03:32

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

using namespace std;
typedef map<int, int> MAPINT;
//STL从广义上分为：容器，算法，迭代器
// 容器和算法之间通过迭代器进行无缝衔接
// STL六大组件： 容器，算法，迭代器，仿函数，适配器，空间配置器
//  容器： 各种数据结构，如vector,list,deque,set,map等
// 算法：如sort,find,copy,for_each
// 迭代器：扮演了容器与算法之间的胶合剂
// 仿函数：行为类似函数，可作为算法的某种策略
// 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
// 空间配置器： 负责空间的配置与管理


void myprint(int val)
{
	std::cout << val << " ";
}

// vector 存放内置数据类型
void test1()
{
	std::vector<int> v;

	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::vector<int>::iterator itBegin = v.begin();
	std::vector<int>::iterator itEnd = v.end();

	// while (itBegin != itEnd)
	// {
	// 	std::cout << *itBegin << std::endl;
	// 	itBegin++;
	// }

	// for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	// {
	// 	std::cout << *i << std::endl;
	// }

	std::for_each(v.begin(), v.end(), myprint);
}

// vector 存放自定义类型 
void test2()
{
	class my_class1
	{
	public:
		my_class1(const std::string& name, const int& age)
			: name(name),
			  age(age)
		{
		}

		std::string name;
		int age;
	};

	my_class1 m1("ss", 12);
	my_class1 m2("sssdf", 12);
	my_class1 m3("sf s", 12);
	my_class1 m4("fas ss", 12);
	my_class1 m5("d ss", 12);

	std::vector<my_class1> v(1, m1);
	v.push_back(m2);
	v.push_back(m3);
	v.push_back(m4);
	v.push_back(m5);

	for (auto m : v)
	{
		std::cout << m.name << " " << m.age << std::endl;
	}


	// std::cout << v.size() << std::endl;
	// std::cout << v.capacity() << std::endl;
}

// vector 嵌套
void test3()
{
	vector<vector<int>> v(10, vector<int>(5));

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			v[i][j] = i * j;
		}
	}

	for (auto item : v)
	{
		for (auto value : item)
		{
			cout << value << "\t";
		}
		cout << endl;
	}
}

//string 基本概念
void test4()
{
	string s1; // 默认构造

	const char* str = "hello world";

	string s2(str);

	cout << s2 << endl;

	string s3(s2);
	cout << s3 << endl;

	string s4(10, 's');
	cout << s4 << endl;
}

// string 赋值方法
void test5()
{
	const char* str = "hello world";
	string s1;
	s1.assign("hello cpp");
	cout << s1 << endl;

	string s2;
	s2.assign(str, 5);
	cout << s2 << endl;

	string s3;
	s3.assign(str);
	cout << s3 << endl;

	string s4;
	s4.assign(10, 'd');
}

// string 拼接
void test6()
{
	const char* str = "hello world";

	string s1(" sss");
	s1 += str;
	cout << s1 << endl;

	string s2("s");
	s2 += 'q';
	cout << s2 << endl;

	s2 += s1;
	cout << s2 << endl;

	string s3;
	s3.append(str);
	cout << s3 << endl;

	s3.append(str, 5);
	cout << s3 << endl;

	s3.append(s2, 0, 2);
	cout << s3 << endl;
}

//string 查找替换
void test7()
{
	const char* str = "hello world_rl";

	string s1(str);

	int pos = s1.find("x");
	cout << pos << endl;

	pos = s1.rfind("rl"); //rfind是从右往左查找
	cout << pos << endl;

	string s2 = "abcdefg";

	//从第一个位置起，三个字符替换为。。
	s2.replace(1, 3, "11hvb");
	cout << s2 << endl;
}

// string 比较
void test8()
{
	string s1 = "z ello";
	string s2 = "zz";
	int ea = s1.compare(s2);
	if (ea == 0)
	{
		cout << "相等";
	}
	else if (ea > 0)
	{
		cout << "第一个大";
	}
	else
	{
		cout << "第二大";
	}
}

//string 字符存取
void test9()
{
	const char* str = "hello world";

	string s1(str);

	//通过[]访问

	for (int i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < s1.size(); ++i)
	{
		cout << s1.at(i) << " ";
	}
	cout << endl;
}

// string 插入和删除
void test10()
{
	const char* str = "hello world";
	string s1(str);

	s1.insert(1, "ok");
	cout << s1 << endl;

	s1.erase(1, 2);
	cout << s1 << endl;
}

// string 子串
void test11()
{
	const char* str = "hello world";
	string s1(str);
	string substr = s1.substr(1, 3);
	cout << substr << endl;
}

void printVector(const vector<int>& V)
{
	for (auto element : V)
	{
		cout << element << " ";
	}
	cout << endl;
}

// vector 插入和删除
void test12()
{
	vector<int> v(10, 1);
	printVector(v);

	v.insert(v.begin(), 20);
	printVector(v);
	v.insert(v.begin() + 5, 2, 20);
	printVector(v);

	v.erase(v.begin());
	printVector(v);
}

//deque 构造函数 类似于vector
void test13()
{
	deque<int> d1;

	for (int i = 0; i < 5; ++i)
	{
		d1.push_back(i + 1);
	}

	for (auto value : d1)
	{
		cout << value << " ";
	}
	cout << endl;
}

// stack
void test14()
{
	stack<int> s;
	s.push(1);
	s.push(10);
	s.push(19);

	cout << s.top() << endl;
	s.pop();
	cout << s.top();
}

// queue
void test15()
{
	queue<int> q;
	q.push(1);
	q.push(3);
	q.push(5);
	cout << q.front() << endl;
	cout << q.back() << endl;
	q.pop();
	q.pop();
	q.pop();
	cout << q.size();
}

void printList(const list<int>& L)
{
	for (auto element : L)
	{
		cout << element << " ";
	}
	cout << endl;
}

// list
void test16()
{
	list<int> L;
	L.assign(5, 99);
	for (auto l : L)
	{
		cout << l << " ";
	}
	cout << endl;
	cout << L.size() << endl;
	cout << L.max_size() << endl;
	L.unique();
	cout << L.size() << endl;
	L.push_back(10);
	L.push_back(15);
	L.push_back(19);
	L.push_back(1);
	for (auto val : L)
	{
		cout << val << " ";
	}
	cout << endl;
	L.reverse();
	printList(L);
	L.sort();
	printList(L);
}


void printSet(const set<int>& S)
{
	for (set<int>::const_iterator it = S.begin(); it != S.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// set
void test17()
{
	set<int> s1;
	s1.insert(22);
	s1.insert(255);
	s1.insert(65);
	s1.insert(89);

	printSet(s1);

	set<int> s2(s1);
	printSet(s2);

	set<int> s3 = s2;
	printSet(s3);

	set<int> s4;
	if (s4.empty())
	{
		cout << "空" << endl;
	}

	s4.insert(4);
	s4.insert(1);
	s4.insert(78);
	s4.insert(96);
	printSet(s4);
	s4.erase(++s4.begin());
	printSet(s4);
	s4.erase(96);
	printSet(s4);
	s4.clear();
	printSet(s4);
	cout << s4.count(100) << endl;
	set<int>::iterator pos = s4.find(96);
	if (pos != s4.end())
	{
		cout << "find it" << endl;
	}
	else
		cout << "not find" << endl;
}

// pair
void test18()
{
	pair<string, int> p1("tom", 29);
	pair<string, int> p2 = make_pair("shjs", 32);

	cout << p1.first << " " << p1.second << endl;
}

void printMap(const map<int, int>& map)
{
	for (auto element : map)
	{
		cout << element.first << " " << element.second << " ";
	}
	cout << endl;
}

// map
void test19()
{
	map<int, int> m;
	m.insert(pair<int, int>(4, 410));
	m.insert(pair<int, int>(3, 310));
	m.insert(pair<int, int>(2, 210));
	m.insert(pair<int, int>(1, 110));
	cout << m[1] << endl;
	printMap(m);

	map<int, int> m2(m);
	printMap(m2);

	MAPINT m3;
	m3 = m2;
	printMap(m3);
}

// 谓词
// 返回bool类型的仿函数称为谓词
// 如果operator()接受一个参数，那么叫做一元谓词
// 如果operator()接受两个参数，那么叫做二元谓词

class my_class
{
public:
	bool operator()(int val)
	{
		return val < 5;
	}
};

class my_class1
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

// 一元谓词
void test20()
{
	vector<int> v(5, 6);
	v.push_back(4);
	v.push_back(3);

	auto it = find_if(v.begin(), v.end(), my_class());
	if (it == v.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find" << endl;
		cout << *it << endl;
	}
}

// 二元谓词
void test21()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(44);
	v.push_back(243);
	v.push_back(12);
	v.push_back(211);
	printVector(v);

	sort(v.begin(), v.end());
	printVector(v);

	sort(v.begin(), v.end(), my_class1());
	printVector(v);
}

// 内建函数对象 
void test22()
{
	negate<int> n;
	cout << n(50) << endl;

	plus<int> p;
	cout << p(10, 20) << endl;

	vector<int> v(5, 1);
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] *= v[i] + i * 2;
	}
	printVector(v);

	sort(v.begin(), v.end(), greater<int>());
	printVector(v);

	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(false);
	for (auto vb_reference : v1)
	{
		cout << vb_reference << " ";
	}
	cout << endl;

	vector<bool> v2;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());

	for (auto vb_reference : v2)
	{
		cout << vb_reference << " ";
	}
	cout << endl;
}

// 常用算法
void test23()
{
	vector<int> v(8);
	for (int i = 0; i < v.size(); ++++i)
	{
		v.push_back(i);
	}
	auto it = find_if(v.begin(), v.end(), my_class());
	if (it != v.end())
	{
		cout << "find" << endl;
	}
	else
	{
		cout << "not find" << endl;
	}

	auto it1 = adjacent_find(v.begin(), v.end());
	if (it1 != v.end())
	{
		cout << "find" << endl;
	}
	else
	{
		cout << " not find" << endl;
	}

	printVector(v);

	auto is = binary_search(v.begin(), v.end(), 8);
}

int main()

{
	// test1();
	// test2();
	// test3();
	// te]st4();
	// test5();
	// test6();
	// test7();
	// test8();
	// test9();
	// test10();
	// test11();
	// test12();
	// test13();
	// test14();
	// test15();
	// test16();
	// test17();
	// test18();
	// test19();
	// test20();
	// test21();
	// test22();
	test23();
	return 0;
}
