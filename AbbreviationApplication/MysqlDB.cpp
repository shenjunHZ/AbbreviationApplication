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
		//��ȡ���һ�е�id��
		int lastId = 0;
		// ���һ����select * from���� order by ��_id desc limit 1
		QString sql = "select * from AbbreviationTable order by id desc limit 1";//��ȡ���һ����Ϣ
		QSqlQuery query = QSqlQuery::QSqlQuery(m_Database);
		query.exec(sql);

		while (query.next())
		{
			lastId = query.value("id").toInt();
		}

		//�����µ�һ����Ϣ
		int newId = lastId + 1;
		QSqlQuery queryTemp = QSqlQuery::QSqlQuery(m_Database);//���湹���˸����󣬺����ֹ����˸�����֪���Ƿ�����
		queryTemp.prepare("INSERT INTO AbbreviationTable (id, name, expression) VALUES (:id, :name, :expression)");
		//http://blog.csdn.net/tian_110/article/details/45151701
		queryTemp.bindValue(":id", newId);//���������
		queryTemp.bindValue(":name", name);
		queryTemp.bindValue(":expression", expression);
		bool bRec = queryTemp.exec();

		return bRec;
	}


	//����4���������ִ����Ĳ���һ����Ϣ�����ǵ�����Ϣ,ʹ�� Prepared Query ���Ա���SQL ע�빥����
		/**
		* ��� ÿ������Ϣ �� name ���ڴ���Ĳ��� name
		* @param username
		*/
		std::map<int, std::string> CMysqlDB::outputWithPreparedQuery(const QString &name)
		{
		    QString sql = "SELECT * FROM AbbreviationTable WHERE name=:name";
		    QSqlQuery query = QSqlQuery::QSqlQuery(m_Database);    // [1] ���Դ������ݿ����ӣ����ǲ��ܴ��� SQL ���
		    query.prepare(sql); // [2] ����ʹ�� prepqred �ķ�ʽ���� SQL ���

		    query.bindValue(":name", name); // [3] ��ռλ���滻Ϊ����Ĳ���
		    query.exec(); // [4] ִ�����ݿ����
		    std::map<int, std::string> outPutExpression;
		    while (query.next())  // [5]���б���
		    {
			    QString output = query.value("expression").toString();

				int iId = query.value("id").toInt();
				outPutExpression[iId] = output.toStdString();
			    //outPutExpression.push_back(output.toStdString());
		    }

		    return  outPutExpression;
	    }

		/*����5��  ɾ
			ɾ����¼��*/
			bool CMysqlDB::deleteQuery(const int id)
			{
				QSqlQuery query = QSqlQuery::QSqlQuery(m_Database);
				//char strSQL[255] = {};
				//sprintf_s(strSQL, "delete from AbbreviationTable where ID = %d", id);

				QString strNum = QString::number(id);
				QString strSQL = "delete from AbbreviationTable where ID = " + strNum;

				return query.exec(strSQL); //delete from abbreviations where ID = '" + id + "' �Լ��Ĺ���
		    }

}