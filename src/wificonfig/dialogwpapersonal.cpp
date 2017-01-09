/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/
#include "dialogwpapersonal.h"
#include "ui_dialogwpapersonal.h"
#include <QDialogButtonBox>


void dialogWPAPersonal::setKey( QString Key )
{
    lineKey->setText(Key);
}

void dialogWPAPersonal::on_buttonBox_clicked(QAbstractButton *button)
{
    if (buttonBox->standardButton(button) == QDialogButtonBox::Ok) {
        saveAndClose();
    } else { // the cancel button
        close();
    }
}

void dialogWPAPersonal::saveAndClose()
{
  if ( lineKey->text().length() < 8 || lineKey->text().length() > 63 ) {
     QMessageBox::warning( this, "Network Key Error", "Error: The network key must be between 8-63 characters in length!\n" );
     return;
  }

  emit saved(lineKey->text());
  close();
}

void dialogWPAPersonal::on_checkShowKey_clicked(bool checked)
{
   if(checked) {
      lineKey->setEchoMode(QLineEdit::Normal);
   } else {
      lineKey->setEchoMode(QLineEdit::Password);
   }
}

