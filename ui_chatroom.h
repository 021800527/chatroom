/********************************************************************************
** Form generated from reading UI file 'chatroom.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOM_H
#define UI_CHATROOM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatRoom
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *sendButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *userNumLabel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *exitButton;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QTextBrowser *messageBrowser;
    QHBoxLayout *horizontalLayout_2;
    QFontComboBox *fontComboBox;
    QComboBox *SizeComboBox;
    QToolButton *speechToolBtn;
    QToolButton *skinToolBtn;
    QToolButton *boldToolBtn;
    QToolButton *italicToolBtn;
    QToolButton *underlineToolBtn;
    QToolButton *colorToolBtn1;
    QToolButton *colorToolBtn;
    QToolButton *sendToolBtn;
    QToolButton *saveToolBtn;
    QToolButton *clearToolBtn;
    QTextEdit *messageTextEdit;
    QTableWidget *userTableWidget;

    void setupUi(QWidget *chatRoom)
    {
        if (chatRoom->objectName().isEmpty())
            chatRoom->setObjectName(QString::fromUtf8("chatRoom"));
        chatRoom->setEnabled(true);
        chatRoom->resize(1196, 513);
        chatRoom->setMaximumSize(QSize(1920, 900));
        chatRoom->setWindowOpacity(1.000000000000000);
        gridLayout_2 = new QGridLayout(chatRoom);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sendButton = new QPushButton(chatRoom);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout->addWidget(sendButton);

        horizontalSpacer_2 = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        userNumLabel = new QLabel(chatRoom);
        userNumLabel->setObjectName(QString::fromUtf8("userNumLabel"));

        horizontalLayout->addWidget(userNumLabel);

        horizontalSpacer_3 = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        exitButton = new QPushButton(chatRoom);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout->addWidget(exitButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        messageBrowser = new QTextBrowser(chatRoom);
        messageBrowser->setObjectName(QString::fromUtf8("messageBrowser"));

        verticalLayout->addWidget(messageBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        fontComboBox = new QFontComboBox(chatRoom);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        horizontalLayout_2->addWidget(fontComboBox);

        SizeComboBox = new QComboBox(chatRoom);
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->addItem(QString());
        SizeComboBox->setObjectName(QString::fromUtf8("SizeComboBox"));

        horizontalLayout_2->addWidget(SizeComboBox);

        speechToolBtn = new QToolButton(chatRoom);
        speechToolBtn->setObjectName(QString::fromUtf8("speechToolBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/speak.png"), QSize(), QIcon::Normal, QIcon::Off);
        speechToolBtn->setIcon(icon);
        speechToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(speechToolBtn);

        skinToolBtn = new QToolButton(chatRoom);
        skinToolBtn->setObjectName(QString::fromUtf8("skinToolBtn"));
        skinToolBtn->setToolTipDuration(-1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/skin.png"), QSize(), QIcon::Normal, QIcon::Off);
        skinToolBtn->setIcon(icon1);

        horizontalLayout_2->addWidget(skinToolBtn);

        boldToolBtn = new QToolButton(chatRoom);
        boldToolBtn->setObjectName(QString::fromUtf8("boldToolBtn"));
        boldToolBtn->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolBtn->setIcon(icon2);
        boldToolBtn->setIconSize(QSize(22, 22));
        boldToolBtn->setCheckable(true);
        boldToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(boldToolBtn);

        italicToolBtn = new QToolButton(chatRoom);
        italicToolBtn->setObjectName(QString::fromUtf8("italicToolBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolBtn->setIcon(icon3);
        italicToolBtn->setIconSize(QSize(22, 22));
        italicToolBtn->setCheckable(true);
        italicToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(italicToolBtn);

        underlineToolBtn = new QToolButton(chatRoom);
        underlineToolBtn->setObjectName(QString::fromUtf8("underlineToolBtn"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineToolBtn->setIcon(icon4);
        underlineToolBtn->setIconSize(QSize(22, 22));
        underlineToolBtn->setCheckable(true);
        underlineToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(underlineToolBtn);

        colorToolBtn1 = new QToolButton(chatRoom);
        colorToolBtn1->setObjectName(QString::fromUtf8("colorToolBtn1"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/color1.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolBtn1->setIcon(icon5);

        horizontalLayout_2->addWidget(colorToolBtn1);

        colorToolBtn = new QToolButton(chatRoom);
        colorToolBtn->setObjectName(QString::fromUtf8("colorToolBtn"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolBtn->setIcon(icon6);
        colorToolBtn->setIconSize(QSize(22, 22));
        colorToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(colorToolBtn);

        sendToolBtn = new QToolButton(chatRoom);
        sendToolBtn->setObjectName(QString::fromUtf8("sendToolBtn"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendToolBtn->setIcon(icon7);
        sendToolBtn->setIconSize(QSize(22, 22));
        sendToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(sendToolBtn);

        saveToolBtn = new QToolButton(chatRoom);
        saveToolBtn->setObjectName(QString::fromUtf8("saveToolBtn"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolBtn->setIcon(icon8);
        saveToolBtn->setIconSize(QSize(22, 22));
        saveToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(saveToolBtn);

        clearToolBtn = new QToolButton(chatRoom);
        clearToolBtn->setObjectName(QString::fromUtf8("clearToolBtn"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolBtn->setIcon(icon9);
        clearToolBtn->setIconSize(QSize(22, 22));
        clearToolBtn->setAutoRaise(true);

        horizontalLayout_2->addWidget(clearToolBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        messageTextEdit = new QTextEdit(chatRoom);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        messageTextEdit->setEnabled(true);

        verticalLayout->addWidget(messageTextEdit);

        verticalLayout->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout);

        userTableWidget = new QTableWidget(chatRoom);
        if (userTableWidget->columnCount() < 3)
            userTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        userTableWidget->setObjectName(QString::fromUtf8("userTableWidget"));
        userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userTableWidget->setShowGrid(false);

        horizontalLayout_3->addWidget(userTableWidget);

        horizontalLayout_3->setStretch(0, 6);

        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(chatRoom);

        SizeComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(chatRoom);
    } // setupUi

    void retranslateUi(QWidget *chatRoom)
    {
        chatRoom->setWindowTitle(QCoreApplication::translate("chatRoom", "\350\201\212\345\244\251\345\256\244", nullptr));
        sendButton->setText(QCoreApplication::translate("chatRoom", "\345\217\221\351\200\201", nullptr));
        userNumLabel->setText(QCoreApplication::translate("chatRoom", "\345\234\250\347\272\277\347\224\250\346\210\267\357\274\2320\344\272\272", nullptr));
        exitButton->setText(QCoreApplication::translate("chatRoom", "\351\200\200\345\207\272", nullptr));
        SizeComboBox->setItemText(0, QCoreApplication::translate("chatRoom", "9", nullptr));
        SizeComboBox->setItemText(1, QCoreApplication::translate("chatRoom", "10", nullptr));
        SizeComboBox->setItemText(2, QCoreApplication::translate("chatRoom", "11", nullptr));
        SizeComboBox->setItemText(3, QCoreApplication::translate("chatRoom", "12", nullptr));
        SizeComboBox->setItemText(4, QCoreApplication::translate("chatRoom", "13", nullptr));
        SizeComboBox->setItemText(5, QCoreApplication::translate("chatRoom", "14", nullptr));
        SizeComboBox->setItemText(6, QCoreApplication::translate("chatRoom", "15", nullptr));
        SizeComboBox->setItemText(7, QCoreApplication::translate("chatRoom", "16", nullptr));
        SizeComboBox->setItemText(8, QCoreApplication::translate("chatRoom", "17", nullptr));
        SizeComboBox->setItemText(9, QCoreApplication::translate("chatRoom", "18", nullptr));
        SizeComboBox->setItemText(10, QCoreApplication::translate("chatRoom", "19", nullptr));
        SizeComboBox->setItemText(11, QCoreApplication::translate("chatRoom", "20", nullptr));
        SizeComboBox->setItemText(12, QCoreApplication::translate("chatRoom", "21", nullptr));
        SizeComboBox->setItemText(13, QCoreApplication::translate("chatRoom", "22", nullptr));

#if QT_CONFIG(tooltip)
        speechToolBtn->setToolTip(QCoreApplication::translate("chatRoom", "\350\257\255\351\237\263", nullptr));
#endif // QT_CONFIG(tooltip)
        speechToolBtn->setText(QCoreApplication::translate("chatRoom", "\350\257\255\351\237\263\350\201\212\345\244\251", nullptr));
#if QT_CONFIG(tooltip)
        skinToolBtn->setToolTip(QCoreApplication::translate("chatRoom", "\346\215\242\350\202\244", nullptr));
#endif // QT_CONFIG(tooltip)
        skinToolBtn->setText(QCoreApplication::translate("chatRoom", "...", nullptr));
#if QT_CONFIG(tooltip)
        boldToolBtn->setToolTip(QCoreApplication::translate("chatRoom", "\345\212\240\347\262\227", nullptr));
#endif // QT_CONFIG(tooltip)
        boldToolBtn->setText(QCoreApplication::translate("chatRoom", "...", nullptr));
#if QT_CONFIG(tooltip)
        italicToolBtn->setToolTip(QCoreApplication::translate("chatRoom", "\345\200\276\346\226\234", nullptr));
#endif // QT_CONFIG(tooltip)
        italicToolBtn->setText(QCoreApplication::translate("chatRoom", "...", nullptr));
#if QT_CONFIG(tooltip)
        underlineToolBtn->setToolTip(QCoreApplication::translate("chatRoom", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        underlineToolBtn->setText(QCoreApplication::translate("chatRoom", "...", nullptr));
        colorToolBtn1->setText(QCoreApplication::translate("chatRoom", "...", nullptr));
#if QT_CONFIG(tooltip)
        colorToolBtn->setToolTip(QCoreApplication::translate("chatRoom", "\346\233\264\346\224\271\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        colorToolBtn->setText(QCoreApplication::translate("chatRoom", "...", nullptr));
#if QT_CONFIG(tooltip)
        sendToolBtn->setToolTip(QCoreApplication::translate("chatRoom", "\344\274\240\350\276\223\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        sendToolBtn->setText(QCoreApplication::translate("chatRoom", "...", nullptr));
#if QT_CONFIG(tooltip)
        saveToolBtn->setToolTip(QCoreApplication::translate("chatRoom", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        saveToolBtn->setText(QCoreApplication::translate("chatRoom", "...", nullptr));
#if QT_CONFIG(tooltip)
        clearToolBtn->setToolTip(QCoreApplication::translate("chatRoom", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        clearToolBtn->setText(QCoreApplication::translate("chatRoom", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = userTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("chatRoom", "\347\224\250\346\210\267\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = userTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("chatRoom", "\344\270\273\346\234\272\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = userTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("chatRoom", "IP\345\234\260\345\235\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatRoom: public Ui_chatRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
