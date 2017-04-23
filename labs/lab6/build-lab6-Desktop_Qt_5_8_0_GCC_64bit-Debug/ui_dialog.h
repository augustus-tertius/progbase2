/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *courseNameEdit;
    QLabel *label_3;
    QSpinBox *lengthSpinBox;
    QLabel *label_4;
    QDoubleSpinBox *ratingSpinBox;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lectNameEdit;
    QLabel *label_7;
    QLineEdit *lectSurnameEdit;
    QLabel *label_8;
    QLineEdit *lectMiddlenEdit;
    QLabel *label_9;
    QSpinBox *lectAgeSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(419, 321);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 401, 301));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        courseNameEdit = new QLineEdit(layoutWidget);
        courseNameEdit->setObjectName(QStringLiteral("courseNameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, courseNameEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lengthSpinBox = new QSpinBox(layoutWidget);
        lengthSpinBox->setObjectName(QStringLiteral("lengthSpinBox"));
        lengthSpinBox->setMinimum(0);
        lengthSpinBox->setMaximum(1000);

        formLayout->setWidget(1, QFormLayout::FieldRole, lengthSpinBox);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        ratingSpinBox = new QDoubleSpinBox(layoutWidget);
        ratingSpinBox->setObjectName(QStringLiteral("ratingSpinBox"));
        ratingSpinBox->setMaximum(10);
        ratingSpinBox->setSingleStep(0.1);

        formLayout->setWidget(2, QFormLayout::FieldRole, ratingSpinBox);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        lectNameEdit = new QLineEdit(layoutWidget);
        lectNameEdit->setObjectName(QStringLiteral("lectNameEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lectNameEdit);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        lectSurnameEdit = new QLineEdit(layoutWidget);
        lectSurnameEdit->setObjectName(QStringLiteral("lectSurnameEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lectSurnameEdit);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_8);

        lectMiddlenEdit = new QLineEdit(layoutWidget);
        lectMiddlenEdit->setObjectName(QStringLiteral("lectMiddlenEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lectMiddlenEdit);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_9);

        lectAgeSpinBox = new QSpinBox(layoutWidget);
        lectAgeSpinBox->setObjectName(QStringLiteral("lectAgeSpinBox"));
        lectAgeSpinBox->setMinimum(18);

        formLayout->setWidget(7, QFormLayout::FieldRole, lectAgeSpinBox);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Create new lecture course:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "name:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "length:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "rating:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "Lecturer information", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", "name:", Q_NULLPTR));
        label_7->setText(QApplication::translate("Dialog", "surname:", Q_NULLPTR));
        label_8->setText(QApplication::translate("Dialog", "middlen:", Q_NULLPTR));
        label_9->setText(QApplication::translate("Dialog", "age:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
