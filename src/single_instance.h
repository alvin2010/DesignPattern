#pragma once

//	����ģʽ�����������ڵ��߳�
//

class Singleton
{
private:
	Singleton(){}
	~Singleton(){}
	Singleton(const Singleton& s){}
	Singleton& operator = (const Singleton&){}


	static Singleton* instance_;
public:
	static Singleton* GetInstance(){
		if (instance_ == NULL){
			instance_ = new Singleton();
		}
		return instance_;
	}
};

Singleton* Singleton::instance_ = NULL;