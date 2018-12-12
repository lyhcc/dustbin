#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

/******************************
* func: 同现标签数据(对应于tag_cooccurrence.csv文件格式)
* @para id: 数据的id编号
* @para tags: 标签列表
******************************/
struct Tag_cooccurrence
{
	int id;
	string tags;
};

/******************************
* func: 开发者标签数据(user_tag.csv文件格式)
* @para id: :唯一标记一个开发者
* @para origin_tags: 标记该开发者对应的多个标签
* @para tag_value: 标记该开发者每个标签的值
******************************/
struct User_tag
{
	int id;
	string origin_tags;
	string tag_value;
};

/******************************
* func: 推荐标签数据(user_recommand.csv文件格式)
* @para id: 数据的id编号
* @para recommad_tags: 推荐标签列表
******************************/
struct User_recommand
{
	int id;
	string recommad_tags;
};

/****************************
* func: 提供对实验用到的数据文件进行简单的读写操作
*****************************/
class Base
{
public:
	vector<struct Tag_cooccurrence> ReadTag_cooccurrence(string tag_cooccurrencePath);
	vector<struct User_tag> ReadUser_tag(string user_tagPath);
	void WriteUser_recommand(vector<struct User_recommand> user_recommand, string user_recommandPath);
};

/*********************************
* func: 对存放同现标签数据的文件进行读取操作
* return: 将数据存放到vector中
* @para tag_cooccurrencePath: 存放同现标签数据的文件路径(src/step1/tag_cooccurrence.csv)
**********************************/
vector<struct Tag_cooccurrence> Base::ReadTag_cooccurrence(string tag_cooccurrencePath)
{
	// 读文件
	ifstream inFile(tag_cooccurrencePath.c_str(), ios::in);
	string lineStr;
	vector<struct Tag_cooccurrence> strArray;
	//读取第一行标签
	getline(inFile, lineStr);
	//从第二个行开始读取内容
	while (getline(inFile, lineStr))
	{
		// 存成二维表结构
		stringstream ss(lineStr);
		string str;
		struct Tag_cooccurrence lineArray;
		// 按"分隔
		getline(ss, str, '"');
		lineArray.id = atoi(str.c_str());
		getline(ss, str, '"');
		lineArray.tags = str;
		strArray.push_back(lineArray);
	}

	inFile.close();

	return strArray;
}

/*********************************
* func: 对存放开发者标签数据的文件进行读取操作
* return: 将数据存放到vector中
* @para user_tagPath: 存放开发者标签数据的文件路径(src/step1/user_tag.csv)
**********************************/
vector<struct User_tag> Base::ReadUser_tag(string user_tagPath)
{
	// 读文件
	ifstream inFile(user_tagPath.c_str(), ios::in);
	string lineStr;
	vector<struct User_tag> strArray;
	//读取第一行标签
	getline(inFile, lineStr);
	//从第二个行开始读取内容
	while (getline(inFile, lineStr))
	{
		// 存成二维表结构
		stringstream ss(lineStr);
		string str;
		struct User_tag lineArray;
		// 按"分隔
		getline(ss, str, '"');
		lineArray.id = atoi(str.c_str());
		getline(ss, str, '"');
		lineArray.origin_tags = str;
		//跳过第二个,号
		getline(ss, str, '"');
		getline(ss, str, '"');
		lineArray.tag_value = str;
		strArray.push_back(lineArray);
	}

	inFile.close();

	return strArray;
}

/*********************************
* func: 将推荐出来的数据写入到文件中
* return: void
* @para user_recommand: 存放推荐标签的数据
* @para user_recommandPath: 存放推荐标签数据的文件路径(src/step2/user_recommand.csv)
**********************************/
void Base::WriteUser_recommand(vector<struct User_recommand> user_recommand, string user_recommandPath)
{
	// 写文件
	ofstream outFile;
	outFile.open(user_recommandPath.c_str(), ios::out); // 打开模式可省略
														//写入标签标示
	outFile << "id" << ',' << "recommand_tags" << endl;
	//写入数据
	for (vector<struct User_recommand>::iterator iter = user_recommand.begin(); iter != user_recommand.end(); ++iter)
	{
		outFile << iter->id << ",\"" << iter->recommad_tags << '\"' << endl;
	}

	outFile.close();
}

/*********************数据说明***********************
* 训练数据：src/step1/tag_cooccurrence.csv
* 测试数据：src/step1/user_tag.csv
* 结果文件：src/step1/user_recommand.csv
****************************************************/
void func()
{
	/*********************** BEGIN **********************/

	Base base;
	//打开开发者标签数据文件
	vector<struct User_tag> user_tag = base.ReadUser_tag("user_tag.csv");
	vector<struct User_recommand> user_recommand;
	//直接将开发者的Id和该开发者的使用标签拷贝出来作为推荐标签
	for (vector<struct User_tag>::iterator iter = user_tag.begin(); iter != user_tag.end(); ++iter)
	{
		struct User_recommand tmp;
		tmp.id = iter->id;
		tmp.recommad_tags = iter->origin_tags;
		user_recommand.push_back(tmp);
	}

	//将推荐标签写入到指定文件中
	base.WriteUser_recommand(user_recommand, "user_recommand.csv");


	/*********************** END **********************/
}
int main() {
	func();
	return 0;
}


