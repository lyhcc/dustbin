#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

/******************************
* func: ͬ�ֱ�ǩ����(��Ӧ��tag_cooccurrence.csv�ļ���ʽ)
* @para id: ���ݵ�id���
* @para tags: ��ǩ�б�
******************************/
struct Tag_cooccurrence
{
	int id;
	string tags;
};

/******************************
* func: �����߱�ǩ����(user_tag.csv�ļ���ʽ)
* @para id: :Ψһ���һ��������
* @para origin_tags: ��Ǹÿ����߶�Ӧ�Ķ����ǩ
* @para tag_value: ��Ǹÿ�����ÿ����ǩ��ֵ
******************************/
struct User_tag
{
	int id;
	string origin_tags;
	string tag_value;
};

/******************************
* func: �Ƽ���ǩ����(user_recommand.csv�ļ���ʽ)
* @para id: ���ݵ�id���
* @para recommad_tags: �Ƽ���ǩ�б�
******************************/
struct User_recommand
{
	int id;
	string recommad_tags;
};

/****************************
* func: �ṩ��ʵ���õ��������ļ����м򵥵Ķ�д����
*****************************/
class Base
{
public:
	vector<struct Tag_cooccurrence> ReadTag_cooccurrence(string tag_cooccurrencePath);
	vector<struct User_tag> ReadUser_tag(string user_tagPath);
	void WriteUser_recommand(vector<struct User_recommand> user_recommand, string user_recommandPath);
};

/*********************************
* func: �Դ��ͬ�ֱ�ǩ���ݵ��ļ����ж�ȡ����
* return: �����ݴ�ŵ�vector��
* @para tag_cooccurrencePath: ���ͬ�ֱ�ǩ���ݵ��ļ�·��(src/step1/tag_cooccurrence.csv)
**********************************/
vector<struct Tag_cooccurrence> Base::ReadTag_cooccurrence(string tag_cooccurrencePath)
{
	// ���ļ�
	ifstream inFile(tag_cooccurrencePath.c_str(), ios::in);
	string lineStr;
	vector<struct Tag_cooccurrence> strArray;
	//��ȡ��һ�б�ǩ
	getline(inFile, lineStr);
	//�ӵڶ����п�ʼ��ȡ����
	while (getline(inFile, lineStr))
	{
		// ��ɶ�ά��ṹ
		stringstream ss(lineStr);
		string str;
		struct Tag_cooccurrence lineArray;
		// ��"�ָ�
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
* func: �Դ�ſ����߱�ǩ���ݵ��ļ����ж�ȡ����
* return: �����ݴ�ŵ�vector��
* @para user_tagPath: ��ſ����߱�ǩ���ݵ��ļ�·��(src/step1/user_tag.csv)
**********************************/
vector<struct User_tag> Base::ReadUser_tag(string user_tagPath)
{
	// ���ļ�
	ifstream inFile(user_tagPath.c_str(), ios::in);
	string lineStr;
	vector<struct User_tag> strArray;
	//��ȡ��һ�б�ǩ
	getline(inFile, lineStr);
	//�ӵڶ����п�ʼ��ȡ����
	while (getline(inFile, lineStr))
	{
		// ��ɶ�ά��ṹ
		stringstream ss(lineStr);
		string str;
		struct User_tag lineArray;
		// ��"�ָ�
		getline(ss, str, '"');
		lineArray.id = atoi(str.c_str());
		getline(ss, str, '"');
		lineArray.origin_tags = str;
		//�����ڶ���,��
		getline(ss, str, '"');
		getline(ss, str, '"');
		lineArray.tag_value = str;
		strArray.push_back(lineArray);
	}

	inFile.close();

	return strArray;
}

/*********************************
* func: ���Ƽ�����������д�뵽�ļ���
* return: void
* @para user_recommand: ����Ƽ���ǩ������
* @para user_recommandPath: ����Ƽ���ǩ���ݵ��ļ�·��(src/step2/user_recommand.csv)
**********************************/
void Base::WriteUser_recommand(vector<struct User_recommand> user_recommand, string user_recommandPath)
{
	// д�ļ�
	ofstream outFile;
	outFile.open(user_recommandPath.c_str(), ios::out); // ��ģʽ��ʡ��
														//д���ǩ��ʾ
	outFile << "id" << ',' << "recommand_tags" << endl;
	//д������
	for (vector<struct User_recommand>::iterator iter = user_recommand.begin(); iter != user_recommand.end(); ++iter)
	{
		outFile << iter->id << ",\"" << iter->recommad_tags << '\"' << endl;
	}

	outFile.close();
}

/*********************����˵��***********************
* ѵ�����ݣ�src/step1/tag_cooccurrence.csv
* �������ݣ�src/step1/user_tag.csv
* ����ļ���src/step1/user_recommand.csv
****************************************************/
void func()
{
	/*********************** BEGIN **********************/

	Base base;
	//�򿪿����߱�ǩ�����ļ�
	vector<struct User_tag> user_tag = base.ReadUser_tag("user_tag.csv");
	vector<struct User_recommand> user_recommand;
	//ֱ�ӽ������ߵ�Id�͸ÿ����ߵ�ʹ�ñ�ǩ����������Ϊ�Ƽ���ǩ
	for (vector<struct User_tag>::iterator iter = user_tag.begin(); iter != user_tag.end(); ++iter)
	{
		struct User_recommand tmp;
		tmp.id = iter->id;
		tmp.recommad_tags = iter->origin_tags;
		user_recommand.push_back(tmp);
	}

	//���Ƽ���ǩд�뵽ָ���ļ���
	base.WriteUser_recommand(user_recommand, "user_recommand.csv");


	/*********************** END **********************/
}
int main() {
	func();
	return 0;
}


