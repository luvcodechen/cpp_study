#include <iostream>
#include <string>
using namespace std;

// ������
class Building
{
public:
	Building()
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	};

	string m_SittingRoom; // ����

private:
	string m_BedRoom; // ����
};

// ȫ�ֺ���
void guys(Building* building)
{
	cout << "ȫ�ֺ���guys ���ڷ��ʣ� " << building->m_SittingRoom << endl;
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
