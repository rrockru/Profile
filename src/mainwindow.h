#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include "controls.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    MainWindow(Controls* controls);
	~MainWindow();
	
protected:
    void closeEvent(QCloseEvent *event);

private:
    Controls *_controls;

	QString _configFile;
	QString _sqlServer;
	
	void LoadSettings();
	void SaveSettings();
};

#endif // _MAIN_WINDOW_H_
