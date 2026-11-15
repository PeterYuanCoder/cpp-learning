#define _CRT_SECURE_NO_WARNINGS
#include "class_partner.h"

//int main()
//{
//	//d1就是我们Date类实例化的对象
//	Date d1;
//	d1.Init(2026, 2, 12);
//	d1.Print();
//
//	// 注意：如果通过⽆参构造函数创建对象时，对象后⾯不⽤跟括号，否则编译器⽆法
//	// 区分这⾥是函数声明还是实例化对象
//
//	Date d2 = d1;       //拷贝构造
//	d2.Print();
//
//	
//	Date d3 = &d1;         //普通拷贝
//	d3.Print();
//
//	Date d4(2026, 11, 14);
//	Date d5(2026, 11, 14);
//	
//	// 运算符重载函数可以显⽰调⽤
//	operator==(d4, d5);
//
//
//// 需要注意这里是拷贝构造，不是赋值重载
//// 请牢牢记住赋值重载完成两个已经存在的对象直接的拷贝赋值
//// 而拷贝构造用于一个对象拷贝初始化给另一个要创建的对象
//	Date d6;
//	d6 = d4;    //赋值运算符重载
//	d6.Print();
//
//
//	//非const对象调用const函数，这是一种权限缩小
//	Date d7(2026, 11, 15);
//	d7.Print();
//
//	const Date d8(2026, 12, 1);      //const调用const函数是一种权限平移
//	d8.Print();
//
//
//	return 0;
//}



//int main()
//{
//    // 1构造一个A的临时对象，再用这个临时对象拷贝构造aa3
//    // 编译器遇到连续构造+拷贝构造->优化为直接构造
//    A aa1 = 1;
//    aa1.Print();
//
//    const A& aa2 = 1;
//
//    return 0;
//}




int main()
{
    cout << B::GetBCount() << endl;
    B b1, b2;
    B b3(b1);
    cout << B::GetBCount() << endl;
    cout << b1.GetBCount() << endl;

    // 编译报错: error C2248: "B::_scount": 无法访问 private 成员(在"B"类中声明)
    //cout << B::_scount << endl;

    return 0;
}
