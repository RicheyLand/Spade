#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "element.h"

namespace Ui {
class Elements;
}


/// Represents single element of language
class SubElement
{
public:
    QString regex;                                      //  final regular expression of element
    int color_1;                                        //  colors for all themes
    int color_2;
    int color_3;
    int color_4;
    int color_5;
    int color_6;


    /// Initialize default values inside class constructor
    SubElement()
    {
        regex = "";
        color_1 = 0;
        color_2 = 0;
        color_3 = 0;
        color_4 = 0;
        color_5 = 0;
        color_6 = 0;
    }
};


/// Represents single line comment of language
class Comment
{
public:
    QString from;                                       //  start comment string of element
    int color_1;                                        //  colors for all themes
    int color_2;
    int color_3;
    int color_4;
    int color_5;
    int color_6;


    /// Initialize default values inside class constructor
    Comment()
    {
        from = "";
        color_1 = 0;
        color_2 = 0;
        color_3 = 0;
        color_4 = 0;
        color_5 = 0;
        color_6 = 0;
    }
};


/// Represents syntax highlighting for language
class Language
{
public:
    QString name;                                       //  name of language
    QList<SubElement> subElements;                      //  list of all elements represented by regular expression
    QList<Comment> comments;                            //  list of all single line comments

    QString multiline_comment_from;                     //  start comment string of element
    QString multiline_comment_to;                       //  end comment string of element
    int multiline_comment_color_1;                      //  colors of multiline comment for all themes
    int multiline_comment_color_2;
    int multiline_comment_color_3;
    int multiline_comment_color_4;
    int multiline_comment_color_5;
    int multiline_comment_color_6;


    /// Initialize default values inside class constructor
    Language()
    {
        name = "";

        multiline_comment_from = "";
        multiline_comment_to = "";
        multiline_comment_color_1 = 0;
        multiline_comment_color_2 = 0;
        multiline_comment_color_3 = 0;
        multiline_comment_color_4 = 0;
        multiline_comment_color_5 = 0;
        multiline_comment_color_6 = 0;
    }
};


/// Represents collection of all elements of language
class Elements : public QWidget
{
    Q_OBJECT

public:
    /// Class constructor
    ///
    /// @param  Parent widget of instance
    explicit Elements(QWidget *parent = 0);


    /// Set name string of language
    ///
    /// @param  Name of language represented by string
    void set_language_name(QString &);


    /// Load language description into appropriate language type
    ///
    /// @param  Language type as parameter to describe language
    void get_language(Language &);


    /// Open language description inside language editor
    ///
    /// @param  Language type as parameter to describe language
    void open_language(Language &);


    /// Reset interface of all elements inside editor
    void reset_interface();


    /// Class destructor
    ~Elements();

private:
    Ui::Elements *ui;

private slots:
    /// Handle press of first global color button
    void color_1_button_pressed();


    /// Handle press of second global color button
    void color_2_button_pressed();


    /// Handle press of third global color button
    void color_3_button_pressed();


    /// Handle press of fourth global color button
    void color_4_button_pressed();


    /// Handle press of fifth global color button
    void color_5_button_pressed();


    /// Handle press of sixth global color button
    void color_6_button_pressed();


    /// Handle toggle of multiline comment
    void multiline_comment_toggled();


    /// Save created user language
    void save_button_pressed();


    /// Reset process of language creation to default state
    void refresh_button_pressed();


    /// Cancel process of creating language
    void cancel_button_pressed();

signals:
    /// Signal which represents saving of new language
    void save_signal();


    /// Signal which represents cancel of new language
    void cancel_signal();
};

#endif // ELEMENTS_H
