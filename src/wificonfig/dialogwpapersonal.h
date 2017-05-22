#ifndef DIALOGWPAPERSONAL_H
#define DIALOGWPAPERSONAL_H

#include <qfile.h>
#include <qmessagebox.h>
#include <qdialog.h>
#include "ui_dialogwpapersonal.h"

class dialogWPAPersonal : public QDialog, private Ui::dialogWPAPersonal
{
        Q_OBJECT

public:
        dialogWPAPersonal() : QDialog()
        {
          setupUi(this);
        }

        void setKey( QString Key );

public slots:

private slots:
    void on_buttonBox_clicked(QAbstractButton *);
    void saveAndClose();
    void on_checkShowKey_clicked(bool checked);

private:

signals:
    void saved(QString);

} ;
#endif // DIALOGWPAENTERPRISE_H

