/*
@tool    use for search 5G Abbreviation
@author  sj
@data    2017-9-1
@version 1.0
*/
//#include "AbbreviationApplication.h"
#include "Tools/Dir.h"
#include "Tools/File.h"
#include "Common/GlobalDataCenter/GlobalDataCenter.h"
#include "MessageNotify/MessageNotify.h"
#include "DSGuiGlobalData.h"
#include "commonControl.h"
#include "MainAppWidget.h"
#include "DialogTest.h"

#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>
#include <QtCore/QDir>
#include <QtCore/QTime>
#include <QtCore/QFile>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	// 解决库路径问题
	QTextCodec *xcodec = QTextCodec::codecForLocale();
	QString exeDir = xcodec->toUnicode(QByteArray(argv[0]));
	QString BKE_CURRENT_DIR = QFileInfo(exeDir).path();
	BKE_CURRENT_DIR.replace("//", "/");
	QStringList  libpath;

	libpath << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins/platforms");
	libpath << BKE_CURRENT_DIR << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins/imageformats");
	libpath << BKE_CURRENT_DIR + QString::fromLocal8Bit("/plugins");
	libpath << QApplication::libraryPaths();
	QApplication::setLibraryPaths(libpath);


	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	// set current path for this application /* D:/Code/AbbreviationApplication/bin */
	QString strCurPath = QCoreApplication::applicationDirPath();
	QDir::setCurrent(strCurPath);
	DSGUI::DSDir::SetCurrentPath(strCurPath); // 封装库

	// set window interface
	app.setWindowIcon(QIcon("./Nokia.ico"));

	// global common component
	Common::CGlobalDataCenter::GetInstance().SetCurrentDirPath_UTF8(strCurPath.toUtf8().data());
	Common::CGlobalDataCenter::GetInstance().SetCurrentDirPath(strCurPath.toLocal8Bit().data());

	// to do log
	QTime curTime = QTime::currentTime();
	char scLogName[25] = {0};
	sprintf_s(scLogName, sizeof(scLogName), "log\\%02d-%02d-%02d", curTime.hour(), curTime.minute(), curTime.second());

	// app set
	QString strAppName = "5G_U8";
	QString strAppVer = "";
	QString strWindowTitle = strAppName + strAppVer;
	app.setOrganizationName(strAppName);
	app.setApplicationName(strWindowTitle);

	// to do international
	QString strNotifyQmPath = QCoreApplication::applicationDirPath().append("/Language/Language_en/DSMessageNotify_en.qm");
	QString strLang("English");

	// set font
	QFont chnFont("Microsoft YaHei");
	chnFont.setPixelSize(12);
	QFont enFont("Arial");
	enFont.setPixelSize(12);
	app.setFont(enFont);

	// set notify
	DSGUI::DSMessageNotify::Instance().SetParam(QStringList() << strNotifyQmPath, QStringList() << DSGUI::GetSkinVersion(), strLang);
	DSGUI::DSMessageNotify::Instance().StartMessageProcess();
	DSGUI::DSMessageNotify::Instance().SetMessageNotifyTitle(QObject::tr("Notify"));

	// load style
	QString strStyle = "";
	QFile fpStyle(commonSpace::GetSkinPath("public", "style.qss"));
	if (fpStyle.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		strStyle = fpStyle.readAll();
		fpStyle.close();
	}
	QString strCSSFilePath = commonSpace::GetSkinPath("") + QString("/DSGUI/CSS/");
	QStringList strList;
	strList.push_back("*.CSS");
	QStringList strFileList = QDir(strCSSFilePath).entryList(strList, QDir::Files);
	qApp->setStyleSheet(strStyle + DSGUI::DSFile::ReadAll(strFileList, strCSSFilePath));

	// to do uniqueness

	mainApp::MainAppWidget w;
	w.show();

	// do test dialog
	//TestWidget::DialogTest tW;
	//tW.show();

	return app.exec();
}
