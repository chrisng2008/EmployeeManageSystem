#include "MainWidget.h"
#include <QtWidgets/QApplication>
#include "EmployeeClass.h"
#include "functions.h"
list<Employee> employees;
int main(int argc, char *argv[])
{
	if (!isExists("file.txt")) {
		std::ofstream fout("file.txt");// �Ѷ���д��file.txt�ļ���
		boost::archive::text_oarchive oa(fout); // �ı�������鵵�࣬ʹ��һ��ostream������
		list<Employee> li;
		Employee a("zhangsan", "101", "N1", 10000, "MANAGER");
		Employee b("lisi", "102", "N1", 120000, "PSALESMAN");
		Employee c("wangwu", "103", "N2", 9000, "SALESMAN");
		Employee d("zhaoliu", "104", "C9", 7500, "PTECHNOLOGIST");
		li.push_back(a);
		li.push_back(b);
		li.push_back(c);
		li.push_back(d);
		oa << li; // ����obj����
		fout.close();// �ر��ļ�
	}
	//����һ��List���ϣ�װ���Ѿ����ڵ�list
	std::ifstream fin("file.txt");
	boost::archive::text_iarchive ia(fin); // �ı�������鵵��
	ia >> employees;
	journal();

    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    return a.exec();
}
