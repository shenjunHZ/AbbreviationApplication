#include "MysqlDB.h"

#include <QtSql/QSqlQuery>
#include <QtCore/QVariant>
#include <QtCore/QDebug>
#include <QtCore/QCoreApplication>

namespace MysqlDB
{

	CMysqlDB::CMysqlDB()
	{
// 		qDebug() << QSqlDatabase::drivers();
// 		qDebug() << QCoreApplication::libraryPaths();

		m_Database = QSqlDatabase::addDatabase("QMYSQL", "MySqlLink");
	}

	CMysqlDB::~CMysqlDB()
	{
		m_Database.close();
	}

	bool CMysqlDB::connectToSql(const QString& strHostName, const int& iPort, const QString& strUserName, const QString& strPassword)
	{
		m_Database.close();
 
		m_Database.setHostName(strHostName);
		m_Database.setPort(iPort);
		m_Database.setDatabaseName("AbbreviationsMysql");
		m_Database.setUserName(strUserName);
		m_Database.setPassword(strPassword);

		return m_Database.open();
	}


	bool CMysqlDB::addQuery(const QString &name, const QString & expression)
	{
		if (!m_Database.isOpen())
		{
			return false;
		}
		//获取最后一行的id号
		int lastId = 0;
		// 最后一条：select * from表名 order by 表_id desc limit 1
		QString sql = "select * from AbbreviationTable order by id desc limit 1";//获取最后一行信息
		QSqlQuery query = QSqlQuery::QSqlQuery(m_Database);
		query.exec(sql);

		while (query.next())
		{
			lastId = query.value("id").toInt();
		}

		//插入新的一行信息
		int newId = lastId + 1;
		QSqlQuery queryTemp = QSqlQuery::QSqlQuery(m_Database);//上面构造了个对象，后面又构造了个对象不知道是否会出错
		queryTemp.prepare("INSERT INTO AbbreviationTable (id, name, expression) VALUES (:id, :name, :expression)");
		//http://blog.csdn.net/tian_110/article/details/45151701
		queryTemp.bindValue(":id", newId);//这个是数字
		queryTemp.bindValue(":name", name);
		queryTemp.bindValue(":expression", expression);
		bool bRec = queryTemp.exec();

		return bRec;
	}


	//函数4：根据名字传出的不是一组信息，而是单个信息,使用 Prepared Query 可以避免SQL 注入攻击。
		/**
		* 输出 每条的信息 其 name 等于传入的参数 name
		* @param username
		*/
		std::map<int, std::string> CMysqlDB::outputWithPreparedQuery(const QString &name)
		{
		    QString sql = "SELECT * FROM AbbreviationTable WHERE name=:name";
		    QSqlQuery query = QSqlQuery::QSqlQuery(m_Database);    // [1] 可以传入数据库连接，但是不能传入 SQL 语句
		    query.prepare(sql); // [2] 声明使用 prepqred 的方式解析 SQL 语句

		    query.bindValue(":name", name); // [3] 把占位符替换为传入的参数
		    query.exec(); // [4] 执行数据库操作
		    std::map<int, std::string> outPutExpression;
		    while (query.next())  // [5]进行遍历
		    {
			    QString output = query.value("expression").toString();

				int iId = query.value("id").toInt();
				outPutExpression[iId] = output.toStdString();
			    //outPutExpression.push_back(output.toStdString());
		    }

		    return  outPutExpression;
	    }

		/*函数5：  删
			删除记录：*/
			bool CMysqlDB::deleteQuery(const int id)
			{
				QSqlQuery query = QSqlQuery::QSqlQuery(m_Database);
				//char strSQL[255] = {};
				//sprintf_s(strSQL, "delete from AbbreviationTable where ID = %d", id);

				QString strNum = QString::number(id);
				QString strSQL = "delete from AbbreviationTable where ID = " + strNum;

				return query.exec(strSQL); //delete from abbreviations where ID = '" + id + "' 自己改过的
		    }

}