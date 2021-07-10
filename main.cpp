#include "MainWidget.h"
#include <QtWidgets/QApplication>
#include "EmployeeClass.h"
#include "functions.h"
list<Employee> employees;
int main(int argc, char *argv[])
{
	if (!isExists("file.txt")) {
		std::ofstream fout("file.txt");// 把对象写到file.txt文件中
		boost::archive::text_oarchive oa(fout); // 文本的输出归档类，使用一个ostream来构造
		list<Employee> li;
		Employee a("zhangsan", "101", "N1", 10000, "MANAGER");
		Employee b("lisi", "102", "N1", 120000, "PSALESMAN");
		Employee c("wangwu", "103", "N2", 9000, "SALESMAN");
		Employee d("zhaoliu", "104", "C9", 7500, "PTECHNOLOGIST");
		li.push_back(a);
		li.push_back(b);
		li.push_back(c);
		li.push_back(d);
		oa << li; // 保存obj对象
		fout.close();// 关闭文件
	}
	//创建一个List集合，装载已经存在的list
	std::ifstream fin("file.txt");
	boost::archive::text_iarchive ia(fin); // 文本的输入归档类
	ia >> employees;
	journal();

    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    return a.exec();
}
