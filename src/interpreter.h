#ifndef INTERPRETER_H_
#define INTERPRETER_H_
#include <cstdio>
#include <string>
using namespace std;
//	解释器模式（interpreter）：一种语言，一段语法
//	一个解释器，通过解释器来解释这段语法
//


class PlayContent
{
private:
	string content_;
public:
	void SetContent(string content)
	{
		content_ = content;
	}

	string GetContent()
	{
		return content_;
	}
};


class Express
{
public:
	virtual void Excute(char key, double value) = 0;
};


class Note : public Express
{
public:
	void Excute(char key, double value)
	{
		int note = 0;
		switch (key)
		{
		case 'A':
			note = 1;
			break;
		case 'B':
			note = 2;
			break;
		case 'C':
			note = 3;
			break;
		case 'D':
			note = 4;
			break;
		case 'E':
			note = 5;
			break;
		case 'F':
			note = 6;
			break;
		case 'G':
			note = 7;
			break;
		default:
			break;
		}
		printf("%d ", note);
	}
};



class Scale : public Express
{
public:
	void Excute(char key, double value)
	{
		string scale = "";
		switch (int(value))
		{
		case 1:
			scale = "低音";
			break;
		case 2:
			scale = "中音";
			break;
		case 3:
			scale = "重音";
			break;
		default:
			break;
		}
		printf("%s ", scale.c_str());
	}
};




#endif
