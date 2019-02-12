#include "element.h"
#include "ui_element.h"

default_random_engine eng((random_device())());
uniform_int_distribution<int> idis(0, 5);               //  integer generator from numbers 0 to 5


/// Class constructor
///
/// @param  Parent widget of instance
Element::Element(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Element)
{
    ui->setupUi(this);

    type = identifiers;                                 //  initialize element widget
    multiline_comment_flag = false;
    ui->combo_box->setCurrentIndex(idis(eng));          //  generate random regex template for combo box
    ui->line_edit_2->hide();

    color_1 = 1;                                        //  set default colors to first set of colors
    color_2 = 1;
    color_3 = 1;
    color_4 = 1;
    color_5 = 1;
    color_6 = 1;

    down_icon = new QIcon(":/resources/down.png");      //  initialize all icons using appropriate image files
    close_icon = new QIcon(":/resources/close.png");
    color_1_1_icon = new QIcon(":/resources/11.png");
    color_1_2_icon = new QIcon(":/resources/12.png");
    color_1_3_icon = new QIcon(":/resources/13.png");
    color_1_4_icon = new QIcon(":/resources/14.png");
    color_1_5_icon = new QIcon(":/resources/15.png");
    color_1_6_icon = new QIcon(":/resources/16.png");
    color_1_7_icon = new QIcon(":/resources/17.png");
    color_2_1_icon = new QIcon(":/resources/21.png");
    color_2_2_icon = new QIcon(":/resources/22.png");
    color_2_3_icon = new QIcon(":/resources/23.png");
    color_2_4_icon = new QIcon(":/resources/24.png");
    color_2_5_icon = new QIcon(":/resources/25.png");
    color_2_6_icon = new QIcon(":/resources/26.png");
    color_2_7_icon = new QIcon(":/resources/27.png");
    color_3_1_icon = new QIcon(":/resources/31.png");
    color_3_2_icon = new QIcon(":/resources/32.png");
    color_3_3_icon = new QIcon(":/resources/33.png");
    color_3_4_icon = new QIcon(":/resources/34.png");
    color_3_5_icon = new QIcon(":/resources/35.png");
    color_3_6_icon = new QIcon(":/resources/36.png");
    color_3_7_icon = new QIcon(":/resources/37.png");
    color_4_1_icon = new QIcon(":/resources/41.png");
    color_4_2_icon = new QIcon(":/resources/42.png");
    color_4_3_icon = new QIcon(":/resources/43.png");
    color_4_4_icon = new QIcon(":/resources/44.png");
    color_4_5_icon = new QIcon(":/resources/45.png");
    color_4_6_icon = new QIcon(":/resources/46.png");
    color_4_7_icon = new QIcon(":/resources/47.png");
    color_5_1_icon = new QIcon(":/resources/51.png");
    color_5_2_icon = new QIcon(":/resources/52.png");
    color_5_3_icon = new QIcon(":/resources/53.png");
    color_5_4_icon = new QIcon(":/resources/54.png");
    color_5_5_icon = new QIcon(":/resources/55.png");
    color_5_6_icon = new QIcon(":/resources/56.png");
    color_5_7_icon = new QIcon(":/resources/57.png");
    color_6_1_icon = new QIcon(":/resources/61.png");
    color_6_2_icon = new QIcon(":/resources/62.png");
    color_6_3_icon = new QIcon(":/resources/63.png");
    color_6_4_icon = new QIcon(":/resources/64.png");
    color_6_5_icon = new QIcon(":/resources/65.png");
    color_6_6_icon = new QIcon(":/resources/66.png");
    color_6_7_icon = new QIcon(":/resources/67.png");
                                                        //  connect signals of all widget graphical elements with appropriate slots
    QObject::connect(ui->line_edit, SIGNAL(returnPressed()), this, SLOT(add_button_pressed()));
    QObject::connect(ui->type_button, SIGNAL(clicked(bool)), this, SLOT(type_button_pressed()));
    QObject::connect(ui->add_button, SIGNAL(clicked(bool)), this, SLOT(add_button_pressed()));
    QObject::connect(ui->delete_button, SIGNAL(clicked(bool)), this, SLOT(delete_button_pressed()));
    QObject::connect(ui->color_1_button, SIGNAL(clicked(bool)), this, SLOT(color_1_button_pressed()));
    QObject::connect(ui->color_2_button, SIGNAL(clicked(bool)), this, SLOT(color_2_button_pressed()));
    QObject::connect(ui->color_3_button, SIGNAL(clicked(bool)), this, SLOT(color_3_button_pressed()));
    QObject::connect(ui->color_4_button, SIGNAL(clicked(bool)), this, SLOT(color_4_button_pressed()));
    QObject::connect(ui->color_5_button, SIGNAL(clicked(bool)), this, SLOT(color_5_button_pressed()));
    QObject::connect(ui->color_6_button, SIGNAL(clicked(bool)), this, SLOT(color_6_button_pressed()));

    setLayout(ui->main_v_layout);                       //  set default layout of widget
}


/// Update type label inside element widget
///
/// @param  Desired string of label
void Element::set_label(QString text)
{
    ui->label->setText(text);                           //  just refresh label value to string value from method parameter
}


/// switch all colors to their successors
///
/// @param  Holds number of switched colors
void Element::switch_all_colors(int value)
{
    if (value >= 1)
    {
        for (int i = 0; i < value; i++)                 //  toggle colors using number of loops
        {
            color_1_button_pressed();                   //  use appropriate method to switch color
            color_2_button_pressed();
            color_3_button_pressed();
            color_4_button_pressed();
            color_5_button_pressed();
            color_6_button_pressed();
        }
    }
}


/// Change color of type label to green
void Element::make_label_green()
{
    ui->label->setStyleSheet("QLabel { color : rgb(0, 180, 0); }");     //  set shade of green color using style sheet
}


/// Change color of type label to blue
void Element::make_label_blue()
{
    ui->label->setStyleSheet("QLabel { color : rgb(42, 88, 255); }");   //  set shade of blue color using style sheet
}


/// Swap type of element
void Element::swap_type()
{
    type_button_pressed();                              //  this is just a wrapper for appropriate method
}


/// Highlight first theme and hide rest themes
void Element::highlight_theme_1()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  handle case when some theme has beeen already highlighted

    if (active)                                         //  some theme has beeen already highlighted
    {
        ui->color_1_button->setVisible(true);           //  show all buttons again
        ui->color_2_button->setVisible(true);
        ui->color_3_button->setVisible(true);
        ui->color_4_button->setVisible(true);
        ui->color_5_button->setVisible(true);
        ui->color_6_button->setVisible(true);
    }
    else                                                //  there is no highlighted theme
    {
        ui->color_2_button->setVisible(true);           //  highlight appropriate theme button and hide other buttons
        ui->color_2_button->setHidden(true);
        ui->color_3_button->setHidden(true);
        ui->color_4_button->setHidden(true);
        ui->color_5_button->setHidden(true);
        ui->color_6_button->setHidden(true);
    }
}


/// Highlight second theme and hide rest themes
void Element::highlight_theme_2()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  handle case when some theme has beeen already highlighted

    if (active)                                         //  some theme has beeen already highlighted
    {
        ui->color_1_button->setVisible(true);           //  show all buttons again
        ui->color_2_button->setVisible(true);
        ui->color_3_button->setVisible(true);
        ui->color_4_button->setVisible(true);
        ui->color_5_button->setVisible(true);
        ui->color_6_button->setVisible(true);
    }
    else                                                //  there is no highlighted theme
    {
        ui->color_1_button->setHidden(true);            //  highlight appropriate theme button and hide other buttons
        ui->color_3_button->setHidden(true);
        ui->color_4_button->setHidden(true);
        ui->color_5_button->setHidden(true);
        ui->color_6_button->setHidden(true);
    }
}


/// Highlight third theme and hide rest themes
void Element::highlight_theme_3()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  handle case when some theme has beeen already highlighted

    if (active)                                         //  some theme has beeen already highlighted
    {
        ui->color_1_button->setVisible(true);           //  show all buttons again
        ui->color_2_button->setVisible(true);
        ui->color_3_button->setVisible(true);
        ui->color_4_button->setVisible(true);
        ui->color_5_button->setVisible(true);
        ui->color_6_button->setVisible(true);
    }
    else                                                //  there is no highlighted theme
    {
        ui->color_1_button->setHidden(true);            //  highlight appropriate theme button and hide other buttons
        ui->color_2_button->setHidden(true);
        ui->color_4_button->setHidden(true);
        ui->color_5_button->setHidden(true);
        ui->color_6_button->setHidden(true);
    }
}


/// Highlight fourth theme and hide rest themes
void Element::highlight_theme_4()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  handle case when some theme has beeen already highlighted

    if (active)                                         //  some theme has beeen already highlighted
    {
        ui->color_1_button->setVisible(true);           //  show all buttons again
        ui->color_2_button->setVisible(true);
        ui->color_3_button->setVisible(true);
        ui->color_4_button->setVisible(true);
        ui->color_5_button->setVisible(true);
        ui->color_6_button->setVisible(true);
    }
    else                                                //  there is no highlighted theme
    {
        ui->color_1_button->setHidden(true);            //  highlight appropriate theme button and hide other buttons
        ui->color_2_button->setHidden(true);
        ui->color_3_button->setHidden(true);
        ui->color_5_button->setHidden(true);
        ui->color_6_button->setHidden(true);
    }
}


/// Highlight fifth theme and hide rest themes
void Element::highlight_theme_5()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  handle case when some theme has beeen already highlighted

    if (active)                                         //  some theme has beeen already highlighted
    {
        ui->color_1_button->setVisible(true);           //  show all buttons again
        ui->color_2_button->setVisible(true);
        ui->color_3_button->setVisible(true);
        ui->color_4_button->setVisible(true);
        ui->color_5_button->setVisible(true);
        ui->color_6_button->setVisible(true);
    }
    else                                                //  there is no highlighted theme
    {
        ui->color_1_button->setHidden(true);            //  highlight appropriate theme button and hide other buttons
        ui->color_2_button->setHidden(true);
        ui->color_3_button->setHidden(true);
        ui->color_4_button->setHidden(true);
        ui->color_6_button->setHidden(true);
    }
}


/// Highlight sixth theme and hide rest themes
void Element::highlight_theme_6()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  handle case when some theme has beeen already highlighted

    if (active)                                         //  some theme has beeen already highlighted
    {
        ui->color_1_button->setVisible(true);           //  show all buttons again
        ui->color_2_button->setVisible(true);
        ui->color_3_button->setVisible(true);
        ui->color_4_button->setVisible(true);
        ui->color_5_button->setVisible(true);
        ui->color_6_button->setVisible(true);
    }
    else                                                //  there is no highlighted theme
    {
        ui->color_1_button->setHidden(true);            //  highlight appropriate theme button and hide other buttons
        ui->color_2_button->setHidden(true);
        ui->color_3_button->setHidden(true);
        ui->color_4_button->setHidden(true);
        ui->color_5_button->setHidden(true);
    }
}


/// Load all identifiers from element combobox into string list
///
/// @param  All identifiers saved in a string list
/// @param  Color of identifier for first color theme
/// @param  Color of identifier for second color theme
/// @param  Color of identifier for third color theme
/// @param  Color of identifier for fourth color theme
/// @param  Color of identifier for fifth color theme
/// @param  Color of identifier for sixth color theme
bool Element::get_identifiers(QStringList & values, int & color_1, int & color_2, int & color_3, int & color_4, int & color_5, int & color_6)
{
    int len = ui->combo_box->count();

    if (len)
    {
        values.clear();

        for (int i = 0; i < len; i++)
            values.push_back(ui->combo_box->itemText(i));   //  load all identifiers from the combo box

        for (int i = 0; i < len; i++)
            values[i] = QRegularExpression::escape(values[i]);  //  escape values of all identifiers to avoid regex conflict

        color_1 = this->color_1 - 1;                    //  load all colors into appropriate parameters of metod
        color_2 = this->color_2 - 1;
        color_3 = this->color_3 - 1;
        color_4 = this->color_4 - 1;
        color_5 = this->color_5 - 1;
        color_6 = this->color_6 - 1;

        return true;                                    //  loading success
    }

    return false;                                       //  loading failure
}


/// Load regex of element into string
///
/// @param  String value of regular expression
/// @param  Color of regular expression for first color theme
/// @param  Color of regular expression for second color theme
/// @param  Color of regular expression for third color theme
/// @param  Color of regular expression for fourth color theme
/// @param  Color of regular expression for fifth color theme
/// @param  Color of regular expression for sixth color theme
bool Element::get_regex(QString & expression, int & color_1, int & color_2, int & color_3, int & color_4, int & color_5, int & color_6)
{
    if (ui->line_edit->text().size())
    {
        expression = ui->line_edit->text();             //  load regex string from line edit

        color_1 = this->color_1 - 1;                    //  load all colors into appropriate parameters of metod
        color_2 = this->color_2 - 1;
        color_3 = this->color_3 - 1;
        color_4 = this->color_4 - 1;
        color_5 = this->color_5 - 1;
        color_6 = this->color_6 - 1;

        return true;                                    //  loading success
    }

    return false;                                       //  loading failure
}


/// Load comment style of element into string
///
/// @param  String value of comment
/// @param  Color of comment for first color theme
/// @param  Color of comment for second color theme
/// @param  Color of comment for third color theme
/// @param  Color of comment for fourth color theme
/// @param  Color of comment for fifth color theme
/// @param  Color of comment for sixth color theme
bool Element::get_comment(QString & from, int & color_1, int & color_2, int & color_3, int & color_4, int & color_5, int & color_6)
{
    if (ui->line_edit->text().size())
    {
        from = ui->line_edit->text();                   //  load comment string from line edit

        color_1 = this->color_1 - 1;                    //  load all colors into appropriate parameters of metod
        color_2 = this->color_2 - 1;
        color_3 = this->color_3 - 1;
        color_4 = this->color_4 - 1;
        color_5 = this->color_5 - 1;
        color_6 = this->color_6 - 1;

        return true;                                    //  loading success
    }

    return false;                                       //  loading failure
}


/// Load multiline comment style of element into string
///
/// @param  String value of multiline comment
/// @param  Color of multiline comment for first color theme
/// @param  Color of multiline comment for second color theme
/// @param  Color of multiline comment for third color theme
/// @param  Color of multiline comment for fourth color theme
/// @param  Color of multiline comment for fifth color theme
/// @param  Color of multiline comment for sixth color theme
void Element::get_multiline_comment(QString & from, QString & to, int & color_1, int & color_2, int & color_3, int & color_4, int & color_5, int & color_6)
{
    from = ui->line_edit->text();                       //  load start comment string from line edit
    to = ui->line_edit_2->text();                       //  load end comment string from line edit

    color_1 = this->color_1 - 1;                        //  load all colors into appropriate parameters of metod
    color_2 = this->color_2 - 1;
    color_3 = this->color_3 - 1;
    color_4 = this->color_4 - 1;
    color_5 = this->color_5 - 1;
    color_6 = this->color_6 - 1;
}


/// Set all identifiers from string list into combobox
///
/// @param  All identifiers saved in a string list
/// @param  Color of identifier for first color theme
/// @param  Color of identifier for second color theme
/// @param  Color of identifier for third color theme
/// @param  Color of identifier for fourth color theme
/// @param  Color of identifier for fifth color theme
/// @param  Color of identifier for sixth color theme
void Element::set_identifiers(QStringList & values, int & color_1, int & color_2, int & color_3, int & color_4, int & color_5, int & color_6)
{
    while (type != identifiers)                         //  repeat toggling of type until correct type is set
        type_button_pressed();

    ui->combo_box->clear();                             //  reset combo box to initial state
    ui->combo_box->insertItems(0, values);

    color_1++;                                          //  increment color value before toggling of color
    color_2++;
    color_3++;
    color_4++;
    color_5++;
    color_6++;

    while (this->color_1 != color_1)                    //  repeat toggling of first color until correct color is set
        color_1_button_pressed();

    while (this->color_2 != color_2)                    //  repeat toggling of second color until correct color is set
        color_2_button_pressed();

    while (this->color_3 != color_3)                    //  repeat toggling of third color until correct color is set
        color_3_button_pressed();

    while (this->color_4 != color_4)                    //  repeat toggling of fourth color until correct color is set
        color_4_button_pressed();

    while (this->color_5 != color_5)                    //  repeat toggling of fifth color until correct color is set
        color_5_button_pressed();

    while (this->color_6 != color_6)                    //  repeat toggling of sixth color until correct color is set
        color_6_button_pressed();
}


/// Set regex of element into string
///
/// @param  String value of regular expression
/// @param  Color of regular expression for first color theme
/// @param  Color of regular expression for second color theme
/// @param  Color of regular expression for third color theme
/// @param  Color of regular expression for fourth color theme
/// @param  Color of regular expression for fifth color theme
/// @param  Color of regular expression for sixth color theme
void Element::set_regex(QString & expression, int & color_1, int & color_2, int & color_3, int & color_4, int & color_5, int & color_6)
{
    while (type != regex)                               //  repeat toggling of type until correct type is set
        type_button_pressed();

    ui->line_edit->setText(expression);                 //  load regex string from parameter into line edit

    color_1++;                                          //  increment color value before toggling of color
    color_2++;
    color_3++;
    color_4++;
    color_5++;
    color_6++;

    while (this->color_1 != color_1)                    //  repeat toggling of first color until correct color is set
        color_1_button_pressed();

    while (this->color_2 != color_2)                    //  repeat toggling of second color until correct color is set
        color_2_button_pressed();

    while (this->color_3 != color_3)                    //  repeat toggling of third color until correct color is set
        color_3_button_pressed();

    while (this->color_4 != color_4)                    //  repeat toggling of fourth color until correct color is set
        color_4_button_pressed();

    while (this->color_5 != color_5)                    //  repeat toggling of fifth color until correct color is set
        color_5_button_pressed();

    while (this->color_6 != color_6)                    //  repeat toggling of sixth color until correct color is set
        color_6_button_pressed();
}


/// Set comment style of element into string
///
/// @param  String value of comment
/// @param  Color of comment for first color theme
/// @param  Color of comment for second color theme
/// @param  Color of comment for third color theme
/// @param  Color of comment for fourth color theme
/// @param  Color of comment for fifth color theme
/// @param  Color of comment for sixth color theme
void Element::set_comment(QString & from, int & color_1, int & color_2, int & color_3, int & color_4, int & color_5, int & color_6)
{
    while (type != comment)                             //  repeat toggling of type until correct type is set
        type_button_pressed();

    ui->line_edit->setText(from);                       //  load comment string from parameter into line edit

    color_1++;                                          //  increment color value before toggling of color
    color_2++;
    color_3++;
    color_4++;
    color_5++;
    color_6++;

    while (this->color_1 != color_1)                    //  repeat toggling of first color until correct color is set
        color_1_button_pressed();

    while (this->color_2 != color_2)                    //  repeat toggling of second color until correct color is set
        color_2_button_pressed();

    while (this->color_3 != color_3)                    //  repeat toggling of third color until correct color is set
        color_3_button_pressed();

    while (this->color_4 != color_4)                    //  repeat toggling of fourth color until correct color is set
        color_4_button_pressed();

    while (this->color_5 != color_5)                    //  repeat toggling of fifth color until correct color is set
        color_5_button_pressed();

    while (this->color_6 != color_6)                    //  repeat toggling of sixth color until correct color is set
        color_6_button_pressed();
}


/// Set multiline comment style of element into string
///
/// @param  String value of multiline comment
/// @param  Color of multiline comment for first color theme
/// @param  Color of multiline comment for second color theme
/// @param  Color of multiline comment for third color theme
/// @param  Color of multiline comment for fourth color theme
/// @param  Color of multiline comment for fifth color theme
/// @param  Color of multiline comment for sixth color theme
void Element::set_multiline_comment(QString & from, QString & to, int & color_1, int & color_2, int & color_3, int & color_4, int & color_5, int & color_6)
{
    while (type != multiline_comment)                   //  repeat toggling of type until correct type is set
        type_button_pressed();

    ui->line_edit->setText(from);                       //  load start comment string from parameter into line edit
    ui->line_edit_2->setText(to);                       //  load end comment string from parameter into line edit

    color_1++;                                          //  increment color value before toggling of color
    color_2++;
    color_3++;
    color_4++;
    color_5++;
    color_6++;

    while (this->color_1 != color_1)                    //  repeat toggling of first color until correct color is set
        color_1_button_pressed();

    while (this->color_2 != color_2)                    //  repeat toggling of second color until correct color is set
        color_2_button_pressed();

    while (this->color_3 != color_3)                    //  repeat toggling of third color until correct color is set
        color_3_button_pressed();

    while (this->color_4 != color_4)                    //  repeat toggling of fourth color until correct color is set
        color_4_button_pressed();

    while (this->color_5 != color_5)                    //  repeat toggling of fifth color until correct color is set
        color_5_button_pressed();

    while (this->color_6 != color_6)                    //  repeat toggling of sixth color until correct color is set
        color_6_button_pressed();
}


/// Revert interface of element into default position
void Element::reset_interface()
{
    while (type != regex)                               //  repeat toggling of type until correct type is set
        type_button_pressed();

    while (type != identifiers)                         //  repeat toggling of type until correct type is set
        type_button_pressed();

    while (color_1 != 1)                                //  repeat toggling of first color until correct color is set
        color_1_button_pressed();

    while (color_2 != 1)                                //  repeat toggling of second color until correct color is set
        color_2_button_pressed();

    while (color_3 != 1)                                //  repeat toggling of third color until correct color is set
        color_3_button_pressed();

    while (color_4 != 1)                                //  repeat toggling of fourth color until correct color is set
        color_4_button_pressed();

    while (color_5 != 1)                                //  repeat toggling of fifth color until correct color is set
        color_5_button_pressed();

    while (color_6 != 1)                                //  repeat toggling of sixth color until correct color is set
        color_6_button_pressed();
}


/// Class destructor
Element::~Element()
{
    delete ui;
}


/// Handle press of type button
void Element::type_button_pressed()
{
    if (type == identifiers)                            //  element represents identifiers type
    {
        type = regex;                                   //  set element type to the regular expression
        ui->type_button->setText("Regular expression");     //  make required sequence of changes to initialize new type inside element
        ui->add_button->hide();
        ui->line_edit->clear();
        ui->line_edit->setToolTip("Regular expression to describe actual element of language");
        ui->delete_button->setIcon(* down_icon);
        ui->delete_button->setToolTip("Insert preset of regular expression into line edit");
        ui->combo_box->clear();
        ui->combo_box->setToolTip("Set of presets for typical elements of programming languages");
        ui->combo_box->addItem("Keyword");
        ui->combo_box->addItem("Integer");
        ui->combo_box->addItem("Float number");
        ui->combo_box->addItem("Function");
        ui->combo_box->addItem("String literal");
        ui->combo_box->addItem("Character literal");
        ui->combo_box->setCurrentIndex(idis(eng));
    }
    else if (type == regex)                             //  element represents regular expression type
    {
        type = comment;                                 //  set element type to the comment
        ui->type_button->setText("Comment");            //  make required sequence of changes to initialize new type inside element
        ui->line_edit->clear();
        ui->line_edit->setToolTip("Starting mark of comment");
        ui->delete_button->setToolTip("Insert preset of multiline comment into line edit");
        ui->combo_box->clear();
        ui->combo_box->setToolTip("Set of presets for typical comments of supported programming languages");
        ui->combo_box->addItem("C++");
        ui->combo_box->addItem("Python");
    }
    else if (type == comment)                           //  element represents comment type
    {
        if (multiline_comment_flag)                     //  multiline comment is active in some element
        {
            type = identifiers;                         //  set element type to the identifiers
            ui->type_button->setText("Identifiers");    //  make required sequence of changes to initialize new type inside element
            ui->add_button->show();
            ui->line_edit->clear();
            ui->line_edit->setToolTip("Text identifier to describe actual element of language");
            ui->delete_button->setIcon(* close_icon);
            ui->delete_button->setToolTip("Remove actual identifier from set of selected identifiers");
            ui->combo_box->clear();
            ui->combo_box->setToolTip("Set of selected identifiers");
        }
        else                                            //  multiline comment is active nowhere
        {
            type = multiline_comment;                   //  set element type to the multiline comment
            ui->type_button->setText("Multiline comment");  //  make required sequence of changes to initialize new type inside element
            ui->line_edit_2->clear();
            ui->line_edit_2->show();
            ui->add_button->hide();
            ui->line_edit->clear();
            ui->line_edit->setToolTip("Starting mark of multiline comment");
            ui->delete_button->setToolTip("Insert preset of multiline comment into line edit");
            ui->combo_box->clear();
            ui->combo_box->setToolTip("Set of presets for typical multiline comments of supported programming languages");
            ui->combo_box->addItem("C++");
            ui->combo_box->addItem("Python");

            emit multiline_comment_signal();            //  emit multiline comment to indicate unique state of actual element
        }
    }
    else                                                //  element represents multiline comment type
    {
        type = identifiers;                             //  set element type to the identifiers
        ui->type_button->setText("Identifiers");        //  make required sequence of changes to initialize new type inside element
        ui->line_edit_2->hide();
        ui->add_button->show();
        ui->line_edit->clear();
        ui->line_edit->setToolTip("Text identifier to describe actual element of language");
        ui->delete_button->setIcon(* close_icon);
        ui->delete_button->setToolTip("Remove actual identifier from selected identifiers");
        ui->combo_box->clear();
        ui->combo_box->setToolTip("Set of selected identifiers");

        emit multiline_comment_signal();                //  emit multiline comment to indicate unique state of actual element
    }
}


/// Handle press of add button
void Element::add_button_pressed()
{
    if (type == identifiers)
    {
        if (ui->line_edit->text().size())               //  line edit cannot be empty
        {
            ui->combo_box->addItem(ui->line_edit->text());  //  push content from line edit into combo box
            ui->combo_box->setCurrentIndex(ui->combo_box->count() - 1);
            ui->line_edit->clear();
        }
    }
}


/// handle press of delete button
void Element::delete_button_pressed()
{
    if (type == identifiers)                            //  element represents identifiers type
    {
        if (ui->combo_box->count())
            ui->combo_box->removeItem(ui->combo_box->currentIndex());
    }
    else if (type == regex)                             //  element represents regex type
    {                                                   //  insert appropriate regex template into line edit
        if (ui->combo_box->currentText() == "Keyword")
            ui->line_edit->setText("\\b[A-Za-z_][A-Za-z0-9_]*\\b");
        else if (ui->combo_box->currentText() == "Integer")
            ui->line_edit->setText("\\b[0-9]+\\b");
        else if (ui->combo_box->currentText() == "Float number")
            ui->line_edit->setText("\\b(((0b|0B)[01]*)|((0x|0X){0,1}[0-9]*\\.?[0-9]+([eE][+-]?[0-9]+)?|[0-9]+\\.?[0-9]*([eE][+-]?[0-9]+)?))\\b");
        else if (ui->combo_box->currentText() == "Function")
            ui->line_edit->setText("[A-Za-z_][A-Za-z0-9_]*(?=\\s*\\()");
        else if (ui->combo_box->currentText() == "String literal")
            ui->line_edit->setText("\"(\\\\.|[^\"])*\"");
        else
            ui->line_edit->setText("'(\\\\.|[^'])*'");
    }
    else if (type == comment)                           //  element represents comment type
    {                                                   //  insert appropriate regex template into line edit
        if (ui->combo_box->currentText() == "C++")
            ui->line_edit->setText("//");
        else if (ui->combo_box->currentText() == "Python")
            ui->line_edit->setText("#");
    }
    else                                                //  element represents multiline comment type
    {
        if (ui->combo_box->currentText() == "C++")
        {                                               //  insert appropriate regex templates into line edit
            ui->line_edit->setText("/*");
            ui->line_edit_2->setText("*/");
        }
        else if (ui->combo_box->currentText() == "Python")
        {                                               //  insert appropriate regex templates into line edit
            ui->line_edit->setText("\"\"\"");
            ui->line_edit_2->setText("\"\"\"");
        }
    }
}


/// Handle press of first color button
void Element::color_1_button_pressed()
{
    switch (color_1)                                    //  check value of first color button inside element
    {
        case 1:
            ui->color_1_button->setIcon(* color_1_2_icon);      //  update icon of color button and color variable value
            color_1 = 2;
            break;
        case 2:
            ui->color_1_button->setIcon(* color_1_3_icon);      //  update icon of color button and color variable value
            color_1 = 3;
            break;
        case 3:
            ui->color_1_button->setIcon(* color_1_4_icon);      //  update icon of color button and color variable value
            color_1 = 4;
            break;
        case 4:
            ui->color_1_button->setIcon(* color_1_5_icon);      //  update icon of color button and color variable value
            color_1 = 5;
            break;
        case 5:
            ui->color_1_button->setIcon(* color_1_6_icon);      //  update icon of color button and color variable value
            color_1 = 6;
            break;
        case 6:
            ui->color_1_button->setIcon(* color_1_7_icon);      //  update icon of color button and color variable value
            color_1 = 7;
            break;
        default:
            ui->color_1_button->setIcon(* color_1_1_icon);      //  update icon of color button and color variable value
            color_1 = 1;
            break;
    }
}


/// Handle press of second color button
void Element::color_2_button_pressed()
{
    switch (color_2)                                    //  check value of second color button inside element
    {
        case 1:
            ui->color_2_button->setIcon(* color_2_2_icon);      //  update icon of color button and color variable value
            color_2 = 2;
            break;
        case 2:
            ui->color_2_button->setIcon(* color_2_3_icon);      //  update icon of color button and color variable value
            color_2 = 3;
            break;
        case 3:
            ui->color_2_button->setIcon(* color_2_4_icon);      //  update icon of color button and color variable value
            color_2 = 4;
            break;
        case 4:
            ui->color_2_button->setIcon(* color_2_5_icon);      //  update icon of color button and color variable value
            color_2 = 5;
            break;
        case 5:
            ui->color_2_button->setIcon(* color_2_6_icon);      //  update icon of color button and color variable value
            color_2 = 6;
            break;
        case 6:
            ui->color_2_button->setIcon(* color_2_7_icon);      //  update icon of color button and color variable value
            color_2 = 7;
            break;
        default:
            ui->color_2_button->setIcon(* color_2_1_icon);      //  update icon of color button and color variable value
            color_2 = 1;
            break;
    }
}


/// Handle press of third color button
void Element::color_3_button_pressed()
{
    switch (color_3)                                    //  check value of third color button inside element
    {
        case 1:
            ui->color_3_button->setIcon(* color_3_2_icon);      //  update icon of color button and color variable value
            color_3 = 2;
            break;
        case 2:
            ui->color_3_button->setIcon(* color_3_3_icon);      //  update icon of color button and color variable value
            color_3 = 3;
            break;
        case 3:
            ui->color_3_button->setIcon(* color_3_4_icon);      //  update icon of color button and color variable value
            color_3 = 4;
            break;
        case 4:
            ui->color_3_button->setIcon(* color_3_5_icon);      //  update icon of color button and color variable value
            color_3 = 5;
            break;
        case 5:
            ui->color_3_button->setIcon(* color_3_6_icon);      //  update icon of color button and color variable value
            color_3 = 6;
            break;
        case 6:
            ui->color_3_button->setIcon(* color_3_7_icon);      //  update icon of color button and color variable value
            color_3 = 7;
            break;
        default:
            ui->color_3_button->setIcon(* color_3_1_icon);      //  update icon of color button and color variable value
            color_3 = 1;
            break;
    }
}


/// Handle press of fourth color button
void Element::color_4_button_pressed()
{
    switch (color_4)                                    //  check value of fourth color button inside element
    {
        case 1:
            ui->color_4_button->setIcon(* color_4_2_icon);      //  update icon of color button and color variable value
            color_4 = 2;
            break;
        case 2:
            ui->color_4_button->setIcon(* color_4_3_icon);      //  update icon of color button and color variable value
            color_4 = 3;
            break;
        case 3:
            ui->color_4_button->setIcon(* color_4_4_icon);      //  update icon of color button and color variable value
            color_4 = 4;
            break;
        case 4:
            ui->color_4_button->setIcon(* color_4_5_icon);      //  update icon of color button and color variable value
            color_4 = 5;
            break;
        case 5:
            ui->color_4_button->setIcon(* color_4_6_icon);      //  update icon of color button and color variable value
            color_4 = 6;
            break;
        case 6:
            ui->color_4_button->setIcon(* color_4_7_icon);      //  update icon of color button and color variable value
            color_4 = 7;
            break;
        default:
            ui->color_4_button->setIcon(* color_4_1_icon);      //  update icon of color button and color variable value
            color_4 = 1;
            break;
    }
}


/// Handle press of fifth color button
void Element::color_5_button_pressed()
{
    switch (color_5)                                    //  check value of fifth color button inside element
    {
        case 1:
            ui->color_5_button->setIcon(* color_5_2_icon);      //  update icon of color button and color variable value
            color_5 = 2;
            break;
        case 2:
            ui->color_5_button->setIcon(* color_5_3_icon);      //  update icon of color button and color variable value
            color_5 = 3;
            break;
        case 3:
            ui->color_5_button->setIcon(* color_5_4_icon);      //  update icon of color button and color variable value
            color_5 = 4;
            break;
        case 4:
            ui->color_5_button->setIcon(* color_5_5_icon);      //  update icon of color button and color variable value
            color_5 = 5;
            break;
        case 5:
            ui->color_5_button->setIcon(* color_5_6_icon);      //  update icon of color button and color variable value
            color_5 = 6;
            break;
        case 6:
            ui->color_5_button->setIcon(* color_5_7_icon);      //  update icon of color button and color variable value
            color_5 = 7;
            break;
        default:
            ui->color_5_button->setIcon(* color_5_1_icon);      //  update icon of color button and color variable value
            color_5 = 1;
            break;
    }
}


/// Handle press of sixth color button
void Element::color_6_button_pressed()
{
    switch (color_6)                                    //  check value of sixth color button inside element
    {
        case 1:
            ui->color_6_button->setIcon(* color_6_2_icon);      //  update icon of color button and color variable value
            color_6 = 2;
            break;
        case 2:
            ui->color_6_button->setIcon(* color_6_3_icon);      //  update icon of color button and color variable value
            color_6 = 3;
            break;
        case 3:
            ui->color_6_button->setIcon(* color_6_4_icon);      //  update icon of color button and color variable value
            color_6 = 4;
            break;
        case 4:
            ui->color_6_button->setIcon(* color_6_5_icon);      //  update icon of color button and color variable value
            color_6 = 5;
            break;
        case 5:
            ui->color_6_button->setIcon(* color_6_6_icon);      //  update icon of color button and color variable value
            color_6 = 6;
            break;
        case 6:
            ui->color_6_button->setIcon(* color_6_7_icon);      //  update icon of color button and color variable value
            color_6 = 7;
            break;
        default:
            ui->color_6_button->setIcon(* color_6_1_icon);      //  update icon of color button and color variable value
            color_6 = 1;
            break;
    }
}
