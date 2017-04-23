/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *addButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *courseNameLabel;
    QLabel *label_4;
    QLabel *lengthLabel;
    QLabel *label_5;
    QLabel *ratinglabel;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *lectNameLabel;
    QLabel *label_11;
    QLabel *lectSurnameLabel;
    QLabel *label_12;
    QLabel *lectMiddlenLabel;
    QLabel *label_13;
    QLabel *lectAgeLabel;
    QSpacerItem *verticalSpacer_2;
    QPushButton *removeButton;
    QWidget *tab_2;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *label_18;
    QSpinBox *lengthSpinBox;
    QListWidget *resultsListWidget;
    QPushButton *searchButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(567, 453);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(120, 410, 120, 80));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 551, 391));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter = new QSplitter(tab);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_3->addWidget(listWidget);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        verticalLayout_3->addWidget(addButton);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        courseNameLabel = new QLabel(layoutWidget1);
        courseNameLabel->setObjectName(QStringLiteral("courseNameLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, courseNameLabel);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        lengthLabel = new QLabel(layoutWidget1);
        lengthLabel->setObjectName(QStringLiteral("lengthLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lengthLabel);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        ratinglabel = new QLabel(layoutWidget1);
        ratinglabel->setObjectName(QStringLiteral("ratinglabel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ratinglabel);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, label_9);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_10);

        lectNameLabel = new QLabel(layoutWidget1);
        lectNameLabel->setObjectName(QStringLiteral("lectNameLabel"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lectNameLabel);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_11);

        lectSurnameLabel = new QLabel(layoutWidget1);
        lectSurnameLabel->setObjectName(QStringLiteral("lectSurnameLabel"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lectSurnameLabel);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_12);

        lectMiddlenLabel = new QLabel(layoutWidget1);
        lectMiddlenLabel->setObjectName(QStringLiteral("lectMiddlenLabel"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lectMiddlenLabel);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_13);

        lectAgeLabel = new QLabel(layoutWidget1);
        lectAgeLabel->setObjectName(QStringLiteral("lectAgeLabel"));

        formLayout->setWidget(7, QFormLayout::FieldRole, lectAgeLabel);


        verticalLayout_2->addLayout(formLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        removeButton = new QPushButton(layoutWidget1);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setEnabled(false);

        verticalLayout_2->addWidget(removeButton);

        splitter->addWidget(layoutWidget1);

        horizontalLayout->addWidget(splitter);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 521, 341));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget2);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout->addWidget(label_18, 0, 0, 2, 1);

        lengthSpinBox = new QSpinBox(layoutWidget2);
        lengthSpinBox->setObjectName(QStringLiteral("lengthSpinBox"));
        lengthSpinBox->setMaximum(1000);

        gridLayout->addWidget(lengthSpinBox, 0, 1, 1, 1);

        resultsListWidget = new QListWidget(layoutWidget2);
        resultsListWidget->setObjectName(QStringLiteral("resultsListWidget"));
        resultsListWidget->setEnabled(true);
        resultsListWidget->setSelectionMode(QAbstractItemView::NoSelection);

        gridLayout->addWidget(resultsListWidget, 5, 0, 1, 2);

        searchButton = new QPushButton(layoutWidget2);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        gridLayout->addWidget(searchButton, 4, 1, 1, 1);

        resultsListWidget->raise();
        label_18->raise();
        lengthSpinBox->raise();
        searchButton->raise();
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 567, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "Your lecture courses:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        addButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Create new lecture course</p><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addButton->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Selected item information:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "course name:", Q_NULLPTR));
        courseNameLabel->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "length:", Q_NULLPTR));
        lengthLabel->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "rating", Q_NULLPTR));
        ratinglabel->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Lecturer information:", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "name:", Q_NULLPTR));
        lectNameLabel->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "surname:", Q_NULLPTR));
        lectSurnameLabel->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "middlen:", Q_NULLPTR));
        lectMiddlenLabel->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "age:", Q_NULLPTR));
        lectAgeLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        removeButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Remove selected lecture course</p><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        removeButton->setText(QApplication::translate("MainWindow", "Remove", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Lecture Courses", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Search for courses longer than...", Q_NULLPTR));
        lengthSpinBox->setSuffix(QApplication::translate("MainWindow", "  hrs", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        resultsListWidget->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>List of lecture courses found with your parametrs</p><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        searchButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Click to see the list of lecture courses longer than selected value</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        searchButton->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Search", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
