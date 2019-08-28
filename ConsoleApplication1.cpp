// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "webp/decode.h"
#include "webp/encode.h"
#include "file_downloader.h"
using namespace std;

int WebPGetInfo(const uint8_t* data, size_t data_size, int* width, int* height);



int main()
{
	std::string file_url = "http://192.168.1.102:8888/group1/M00/00/1C/wKgBZl1T5TOAFVYcAAOOynqg_os04.webp";
	std::string local_filename = "aa.webp";
	FileDownloader::FileHandle handle = FileDownloader::download_file(file_url, local_filename);



	ifstream image;
	image.open("E:\\ground\\FFmpeg\\aa.webp", std::ios_base::binary);

	if (!image.is_open())
	{
		cout << "unable to open file";
	}
	else
	{
		cout << "ok" << endl;
	}

	//get length of file:
	image.seekg(0, image.end);
	int n = image.tellg();
	image.seekg(0, image.beg);

	//allocate memory:
	uint8_t* res = new uint8_t[n];
	image.read((char*)res, n);

	int w = 0;
	int h = 0;
	auto result = WebPGetInfo(res, n, &w, &h);
	cout << result << "|" << w << "w:" << w << "|" << h;

	cin.get();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
