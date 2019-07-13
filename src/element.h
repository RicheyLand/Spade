#ifndef ELEMENT_H
#define ELEMENT_H

#include <QtWidgets>
#include <QtConcurrent/QtConcurrent>

#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
using namespace std;

namespace Ui {
class Element;
}

/// Represents type of concrete element
enum Type                                               //  represents type of concrete element
{
    regex,
    identifiers,
    comment,
    multiline_comment
};

/// Represents one element of language
class Element : public QWidget                          //  represents one element of language
{
    Q_OBJECT

public:
    /// Class constructor
    ///
    /// @param  Parent widget of instance
    explicit Element(QWidget *parent = 0);              //  class constructor
    Type type;                                          //  type of element
    bool multiline_comment_flag;                        //  holds if element represents multiline comment


    /// Update type label inside element widget
    ///
    /// @param  Desired string of label
    void set_label(QString);


    /// switch all colors to their successors
    ///
    /// @param  Holds number of switched colors
    void switch_all_colors(int value);


    /// Change color of type label to green
    void make_label_green();


    /// Change color of type label to blue
    void make_label_blue();


    /// Swap type of element
    void swap_type();


    /// Highlight first theme and hide rest themes
    void highlight_theme_1();


    /// Highlight second theme and hide rest themes
    void highlight_theme_2();


    /// Highlight third theme and hide rest themes
    void highlight_theme_3();


    /// Highlight fourth theme and hide rest themes
    void highlight_theme_4();


    /// Highlight fifth theme and hide rest themes
    void highlight_theme_5();


    /// Highlight sixth theme and hide rest themes
    void highlight_theme_6();


    /// Load all identifiers from element combobox into string list
    ///
    /// @param  All identifiers saved in a string list
    /// @param  Color of identifier for first color theme
    /// @param  Color of identifier for second color theme
    /// @param  Color of identifier for third color theme
    /// @param  Color of identifier for fourth color theme
    /// @param  Color of identifier for fifth color theme
    /// @param  Color of identifier for sixth color theme
    bool get_identifiers(QStringList &, int &, int &, int &, int &, int &, int &);


    /// Load regex of element into string
    ///
    /// @param  String value of regular expression
    /// @param  Color of regular expression for first color theme
    /// @param  Color of regular expression for second color theme
    /// @param  Color of regular expression for third color theme
    /// @param  Color of regular expression for fourth color theme
    /// @param  Color of regular expression for fifth color theme
    /// @param  Color of regular expression for sixth color theme
    bool get_regex(QString &, int &, int &, int &, int &, int &, int &);


    /// Load comment style of element into string
    ///
    /// @param  String value of comment
    /// @param  Color of comment for first color theme
    /// @param  Color of comment for second color theme
    /// @param  Color of comment for third color theme
    /// @param  Color of comment for fourth color theme
    /// @param  Color of comment for fifth color theme
    /// @param  Color of comment for sixth color theme
    bool get_comment(QString &, int &, int &, int &, int &, int &, int &);


    /// Load multiline comment style of element into string
    ///
    /// @param  String value of multiline comment
    /// @param  Color of multiline comment for first color theme
    /// @param  Color of multiline comment for second color theme
    /// @param  Color of multiline comment for third color theme
    /// @param  Color of multiline comment for fourth color theme
    /// @param  Color of multiline comment for fifth color theme
    /// @param  Color of multiline comment for sixth color theme
    void get_multiline_comment(QString &, QString &, int &, int &, int &, int &, int &, int &);


    /// Set all identifiers from string list into combobox
    ///
    /// @param  All identifiers saved in a string list
    /// @param  Color of identifier for first color theme
    /// @param  Color of identifier for second color theme
    /// @param  Color of identifier for third color theme
    /// @param  Color of identifier for fourth color theme
    /// @param  Color of identifier for fifth color theme
    /// @param  Color of identifier for sixth color theme
    void set_identifiers(QStringList &, int &, int &, int &, int &, int &, int &);


    /// Set regex of element into string
    ///
    /// @param  String value of regular expression
    /// @param  Color of regular expression for first color theme
    /// @param  Color of regular expression for second color theme
    /// @param  Color of regular expression for third color theme
    /// @param  Color of regular expression for fourth color theme
    /// @param  Color of regular expression for fifth color theme
    /// @param  Color of regular expression for sixth color theme
    void set_regex(QString &, int &, int &, int &, int &, int &, int &);


    /// Set comment style of element into string
    ///
    /// @param  String value of comment
    /// @param  Color of comment for first color theme
    /// @param  Color of comment for second color theme
    /// @param  Color of comment for third color theme
    /// @param  Color of comment for fourth color theme
    /// @param  Color of comment for fifth color theme
    /// @param  Color of comment for sixth color theme
    void set_comment(QString &, int &, int &, int &, int &, int &, int &);


    /// Set multiline comment style of element into string
    ///
    /// @param  String value of multiline comment
    /// @param  Color of multiline comment for first color theme
    /// @param  Color of multiline comment for second color theme
    /// @param  Color of multiline comment for third color theme
    /// @param  Color of multiline comment for fourth color theme
    /// @param  Color of multiline comment for fifth color theme
    /// @param  Color of multiline comment for sixth color theme
    void set_multiline_comment(QString &, QString &, int &, int &, int &, int &, int &, int &);


    /// Revert interface of element into default position
    void reset_interface();


    /// Class destructor
    ~Element();

private:
    Ui::Element *ui;

    int color_1;                                        //  holds first selected color in element widget
    int color_2;                                        //  holds second selected color in element widget
    int color_3;                                        //  holds third selected color in element widget
    int color_4;                                        //  holds fourth selected color in element widget
    int color_5;                                        //  holds fifth selected color in element widget
    int color_6;                                        //  holds sixth selected color in element widget

    QIcon * down_icon;                                  //  all icons used inside element widget
    QIcon * close_icon;
    QIcon * color_1_1_icon;
    QIcon * color_1_2_icon;
    QIcon * color_1_3_icon;
    QIcon * color_1_4_icon;
    QIcon * color_1_5_icon;
    QIcon * color_1_6_icon;
    QIcon * color_1_7_icon;
    QIcon * color_2_1_icon;
    QIcon * color_2_2_icon;
    QIcon * color_2_3_icon;
    QIcon * color_2_4_icon;
    QIcon * color_2_5_icon;
    QIcon * color_2_6_icon;
    QIcon * color_2_7_icon;
    QIcon * color_3_1_icon;
    QIcon * color_3_2_icon;
    QIcon * color_3_3_icon;
    QIcon * color_3_4_icon;
    QIcon * color_3_5_icon;
    QIcon * color_3_6_icon;
    QIcon * color_3_7_icon;
    QIcon * color_4_1_icon;
    QIcon * color_4_2_icon;
    QIcon * color_4_3_icon;
    QIcon * color_4_4_icon;
    QIcon * color_4_5_icon;
    QIcon * color_4_6_icon;
    QIcon * color_4_7_icon;
    QIcon * color_5_1_icon;
    QIcon * color_5_2_icon;
    QIcon * color_5_3_icon;
    QIcon * color_5_4_icon;
    QIcon * color_5_5_icon;
    QIcon * color_5_6_icon;
    QIcon * color_5_7_icon;
    QIcon * color_6_1_icon;
    QIcon * color_6_2_icon;
    QIcon * color_6_3_icon;
    QIcon * color_6_4_icon;
    QIcon * color_6_5_icon;
    QIcon * color_6_6_icon;
    QIcon * color_6_7_icon;

signals:
    /// Send this signal if element is marked as a multiline comment
    void multiline_comment_signal();

private slots:
    /// Handle press of type button
    void type_button_pressed();


    /// Handle press of add button
    void add_button_pressed();


    /// handle press of delete button
    void delete_button_pressed();


    /// Handle press of first color button
    void color_1_button_pressed();


    /// Handle press of second color button
    void color_2_button_pressed();


    /// Handle press of third color button
    void color_3_button_pressed();


    /// Handle press of fourth color button
    void color_4_button_pressed();


    /// Handle press of fifth color button
    void color_5_button_pressed();


    /// Handle press of sixth color button
    void color_6_button_pressed();
};

#endif // ELEMENT_H
