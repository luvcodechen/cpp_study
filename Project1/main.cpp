#include <iostream>
using namespace std;
#include <string>
#include "teacher.h"
// #define __STDC_CONSTANT_MACROS

//
// extern "C" {
// #include "libavcodec/avcodec.h"
// #include <libavformat/avformat.h>
// }

class Student
{
public:
	string get_name() const
	{
		return name;
	}

	int get_num() const
	{
		return num;
	}

	void set_name(const string& name)
	{
		this->name = name;
	}

	void set_num(int num)
	{
		this->num = num;
	}

	void to_string() const
	{
		cout << name << " " << num;
	}

private:
	string name;
	int num;
	int age = 10;
};

int main()
{
	// int* p = nullptr;
	// // cout << sizeof(p);
	// int a = 10, b = 30;
	// // const int* p = &a;
	// a = 20;
	// p = &b;
	// *p =
	// 	std::cout << p << "\t" << *p;
	// int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// int* p = arr;
	// for (int i = 0; i < 10; ++i)
	// {
	// 	std::cout << p[i] << " ";
	// }

	Student student;
	student.set_name("jief ");
	student.set_num(23);
	student.to_string();
	teacher t(10);
	cout << t.get_id() << endl;
	t.set_id(20);
	t.set_name("john");
	teacher t2(t);
	cout << t2.get_id() << " " << t2.get_name() << endl;
	system("pause");
	// cout << avcodec_configuration() << endl;
	// cout << "FFmpeg 版本 " << av_version_info() << endl;
	// //
	// AVFormatContext* formatContext = avformat_alloc_context();
	//
	// if (avformat_open_input(&formatContext, "D:\\Users\\luv_x\\Desktop\\VID_20200425_214919.mp4", NULL, NULL) != 0)
	// {
	// 	fprintf(stderr, "无法打开媒体文件\n");
	// 	return 1;
	// }
	//
	// if (avformat_find_stream_info(formatContext, NULL) < 0)
	// {
	// 	fprintf(stderr, "无法获取流信息\n");
	// 	return 1;
	// }
	// cout << "视频时长:" << formatContext->duration / 1000000 << "秒" << "\n";
	//
	// avformat_close_input(&formatContext); // 关闭文件
	return 0;
}
