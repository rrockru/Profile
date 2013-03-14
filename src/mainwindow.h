#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();
	
protected:
    void closeEvent(QCloseEvent *event);

private:
	QString _configFile;
	QString _sqlServer;
	
	void LoadSettings();
	void SaveSettings();
};

#endif // _MAIN_WINDOW_H_
