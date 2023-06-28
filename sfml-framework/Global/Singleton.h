#pragma once

template <typename T>
class Singleton
{
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}

	//������, ���Կ����� �ڵ��߰� �ȵǰ� delete
	//��ü�� �ۿ��� ���� �� ����
	Singleton(const Singleton&) = delete;	
	Singleton& operator=(const Singleton&) = delete;

protected:
	Singleton() = default;
	virtual ~Singleton() = default;
};

/*
�̱����� ����
�ϳ��� Ŭ������ �����ؾ��� == �ٸ����� ��ü�� ������ �� ����� ��, �� ������ ���⿡ ����
�ڵ� ��𼭵��� �����ϱ� ��������
*/