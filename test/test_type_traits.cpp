#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Reference: https://juejin.cn/post/7112108643209707550

// bool IsPodType(const char* strType)
// {
// 	//列举出来所有的内置类型
// 	const char* arrType[] = { "char", "int", "double", \
// 		"short", "float", "long", "long long", "long double" };
// 	for (int i = 0; i < sizeof(arrType) / sizeof(arrType[0]); i++)
// 	{
// 		if (0 == strcmp(arrType[i], strType))
// 			return true;
// 	}
// 	return false;
// }

// template<class T>
// void Copy(T* dst, T* src, size_t size)
// {
// 	//typeid函数可以进行运行时类型识别，返回类型是type_info的标准库类型的引用，该类中的成员函数name可以返回C类字符串类型的类型名
// 	if (IsPodType(typeid(T).name()))
// 	{
// 		memcpy(dst, src, sizeof(T) * size);
// 	}
// 	else
// 	{
// 		for (int i = 0; i < size; i++)
// 		{
// 			dst[i] = src[i];
// 		}
// 	}
// }




//内置类型
class BuiltInType
{
public:
	static bool Get()
	{
		return true;
	}
};
//自定义类型
class CustomType
{
public:
	static bool Get()
	{
		return false;
	}
};

//定义一个模板类，里边包含对自定义类型和内置类型的重命名
template<class T>
class TypeTraits
{
public:
	typedef CustomType IsPodType;
};
//使用所有内置类型对该模板特化
template<>
class TypeTraits<int>
{
public:
	typedef BuiltInType IsPodType;
};

template<>
class TypeTraits<short>
{
public:
	typedef BuiltInType IsPodType;
};

template<>
class TypeTraits<char>
{
public:
	typedef BuiltInType IsPodType;
};

template<>
class TypeTraits<float>
{
public:
	typedef BuiltInType IsPodType;
};

template<>
class TypeTraits<double>
{
public:
	typedef BuiltInType IsPodType;
};

template<>
class TypeTraits<long>
{
public:
	typedef BuiltInType IsPodType;
};

template<>
class TypeTraits<long long>
{
public:
	typedef BuiltInType IsPodType;
};

template<>
class TypeTraits<long double>
{
public:
	typedef BuiltInType IsPodType;
};

// 通过对TypeTraits类模板重写改写Copy函数模板，来确认所拷贝对象的实际类型：
template<class T>
void Copy(T* dst, T* src, size_t size)
{
	if (TypeTraits<T>::IsPodType::Get())
	{
		memcpy(dst, src, sizeof(T) * size);
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			dst[i] = src[i];
		}
	}
}


int main()
{
	int a1[] = { 1,2,3,4,5,6,7,8,9,0 };
	int a2[10];

	Copy(a2, a1, 10);
	for (const auto& e : a2)
	{
		cout << e << " ";
	}
	cout << endl;

	string s1[] = { "1111", "2222", "3333", "4444" };
	string s2[4];

	// // 方法1
	// memcpy(s2, s1, sizeof(s1));

	// //方法2
	// for (int i = 0; i < 4; i++)
	// {
	// 	s2[i] = s1[i];
	// }

	for (const auto& e : s2)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}

// class Person
// {
// public:
// 	Person(int age)
// 		:_age(age)
// 	{}

// 	int _age;
// };

// int main()
// {
//     // int* pa = new int(10);
//     // int* pb = new int(0);
//     // Copy(pb, pa, sizeof(int*));

//     // cout << pa << endl;
//     // cout << pb << endl;
//     // cout << *pb << endl;

// 	Person* p1 = new Person(5);
// 	Person* p2 = new Person(10);

// 	cout << p1->_age << endl;
	
// 	memcpy(p1, p2, sizeof(Person));

// 	cout << p1->_age << endl;

//     return 0;
// }