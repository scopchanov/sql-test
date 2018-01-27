#include <QCoreApplication>
#include <QSqlDatabase>
#include <QDebug>

void test1()
{
	// the connection name is "foo"
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "foo");

	db.setHostName("localhost");
	db.setUserName("user");
	db.setPassword("password");
	db.setDatabaseName("bar");
}

void test2()
{
	// the connection name is "moo"
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "moo");

	db.setHostName("something-else");
	db.setUserName("other-user");
	db.setPassword("new-password");
	db.setDatabaseName("d-bar");
}

void test3()
{
	// The name is the key to the connection

	qDebug() << QSqlDatabase::database("foo").userName();
	qDebug() << QSqlDatabase::database("foo").password();
	qDebug() << QSqlDatabase::database("foo").hostName();

	qDebug() << QSqlDatabase::database("moo").userName();
	qDebug() << QSqlDatabase::database("moo").password();
	qDebug() << QSqlDatabase::database("moo").hostName();
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	test1();
	test2();
	test3();

	return a.exec();
}
