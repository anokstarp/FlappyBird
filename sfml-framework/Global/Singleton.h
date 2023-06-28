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

	//생성자, 대입연산자 자동추가 안되게 delete
	//객체를 밖에서 만들 수 없음
	Singleton(const Singleton&) = delete;	
	Singleton& operator=(const Singleton&) = delete;

protected:
	Singleton() = default;
	virtual ~Singleton() = default;
};

/*
싱글톤의 조건
하나의 클래스만 유지해야함 == 다른데서 객체를 생성할 수 없어야 함, 그 조건이 여기에 있음
코드 어디서든지 접근하기 쉬워야함
*/