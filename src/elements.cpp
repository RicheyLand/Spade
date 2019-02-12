#include "elements.h"
#include "ui_elements.h"

/// Class constructor
///
/// @param  Parent widget of instance
Elements::Elements(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Elements)
{
    ui->setupUi(this);

    ui->widget_2->set_label("Element 2");               //  set main labels of all language elements
    ui->widget_3->set_label("Element 3");
    ui->widget_4->set_label("Element 4");
    ui->widget_5->set_label("Element 5");
    ui->widget_6->set_label("Element 6");
    ui->widget_7->set_label("Element 7");
    ui->widget_8->set_label("Element 8");
    ui->widget_9->set_label("Element 9");
    ui->widget_10->set_label("Element 10");
    ui->widget_11->set_label("Element 11");
    ui->widget_12->set_label("Element 12");
    ui->widget_13->set_label("Element 13");
    ui->widget_14->set_label("Element 14");
    ui->widget_15->set_label("Element 15");
    ui->widget_16->set_label("Element 16");
    ui->widget_17->set_label("Element 17");
    ui->widget_18->set_label("Element 18");
    ui->widget_19->set_label("Element 19");
    ui->widget_20->set_label("Element 20");
    ui->widget_21->set_label("Element 21");

    ui->widget_2->switch_all_colors(1);                 //  switch colors of first seven elements to color sequence
    ui->widget_3->switch_all_colors(2);
    ui->widget_4->switch_all_colors(3);
    ui->widget_5->switch_all_colors(4);
    ui->widget_6->switch_all_colors(5);
    ui->widget_7->switch_all_colors(6);

    ui->widget_9->switch_all_colors(1);                 //  switch colors of second seven elements to color sequence
    ui->widget_10->switch_all_colors(2);
    ui->widget_11->switch_all_colors(3);
    ui->widget_12->switch_all_colors(4);
    ui->widget_13->switch_all_colors(5);
    ui->widget_14->switch_all_colors(6);

    ui->widget_16->switch_all_colors(1);                //  switch colors of third seven elements to color sequence
    ui->widget_17->switch_all_colors(2);
    ui->widget_18->switch_all_colors(3);
    ui->widget_19->switch_all_colors(4);
    ui->widget_20->switch_all_colors(5);
    ui->widget_21->switch_all_colors(6);

    ui->widget_2->make_label_green();                   //  switch color of main labels inside some elements
    ui->widget_3->make_label_blue();

    ui->widget_5->make_label_green();
    ui->widget_6->make_label_blue();

    ui->widget_8->make_label_green();
    ui->widget_9->make_label_blue();

    ui->widget_11->make_label_green();
    ui->widget_12->make_label_blue();

    ui->widget_14->make_label_green();
    ui->widget_15->make_label_blue();

    ui->widget_17->make_label_green();
    ui->widget_18->make_label_blue();

    ui->widget_20->make_label_green();
    ui->widget_21->make_label_blue();

    ui->widget->swap_type();                            //  swap type of elements on some positions
    ui->widget_3->swap_type();
    ui->widget_4->swap_type();
    ui->widget_6->swap_type();
    ui->widget_7->swap_type();
    ui->widget_9->swap_type();
    ui->widget_10->swap_type();
    ui->widget_12->swap_type();
    ui->widget_13->swap_type();
    ui->widget_15->swap_type();
    ui->widget_16->swap_type();
    ui->widget_18->swap_type();
    ui->widget_19->swap_type();
    ui->widget_21->swap_type();
                                                        //  connect signals of graphical elements with appropriate slots
    QObject::connect(ui->widget, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_2, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_3, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_4, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_5, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_6, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_7, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_8, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_9, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_10, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_11, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_12, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_13, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_14, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_15, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_16, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_17, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_18, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_19, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_20, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));
    QObject::connect(ui->widget_21, SIGNAL(multiline_comment_signal()), this, SLOT(multiline_comment_toggled()));

    QObject::connect(ui->color_1_button, SIGNAL(clicked(bool)), this, SLOT(color_1_button_pressed()));
    QObject::connect(ui->color_2_button, SIGNAL(clicked(bool)), this, SLOT(color_2_button_pressed()));
    QObject::connect(ui->color_3_button, SIGNAL(clicked(bool)), this, SLOT(color_3_button_pressed()));
    QObject::connect(ui->color_4_button, SIGNAL(clicked(bool)), this, SLOT(color_4_button_pressed()));
    QObject::connect(ui->color_5_button, SIGNAL(clicked(bool)), this, SLOT(color_5_button_pressed()));
    QObject::connect(ui->color_6_button, SIGNAL(clicked(bool)), this, SLOT(color_6_button_pressed()));

    QObject::connect(ui->save_button, SIGNAL(clicked(bool)), this, SLOT(save_button_pressed()));
    QObject::connect(ui->refresh_button, SIGNAL(clicked(bool)), this, SLOT(refresh_button_pressed()));
    QObject::connect(ui->cancel_button, SIGNAL(clicked(bool)), this, SLOT(cancel_button_pressed()));

    setLayout(ui->main_v_layout);
}


/// Set name string of language
///
/// @param  Name of language represented by string
void Elements::set_language_name(QString & name)
{
    ui->name_line_edit->setText(name);                  //  refresh line edito value to parameter value
}


/// Load language description into appropriate language type
///
/// @param  Language type as parameter to describe language
void Elements::get_language(Language & language)
{
    language.name = ui->name_line_edit->text();
    language.subElements.clear();

    if (ui->widget->type == identifiers)                //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget->type == regex)                 //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget->type == comment)               //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                    language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                    language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_2->type == identifiers)              //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_2->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_2->type == regex)               //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_2->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_2->type == comment)             //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_2->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_2->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_3->type == identifiers)              //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_3->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_3->type == regex)               //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_3->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_3->type == comment)             //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_3->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_3->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_4->type == identifiers)              //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_4->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_4->type == regex)               //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_4->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_4->type == comment)             //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_4->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_4->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_5->type == identifiers)              //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_5->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_5->type == regex)               //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_5->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_5->type == comment)             //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_5->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_5->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_6->type == identifiers)              //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_6->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_6->type == regex)               //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_6->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_6->type == comment)             //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_6->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_6->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_7->type == identifiers)              //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_7->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_7->type == regex)               //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_7->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_7->type == comment)             //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_7->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_7->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_8->type == identifiers)              //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_8->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_8->type == regex)               //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_8->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_8->type == comment)             //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_8->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_8->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_9->type == identifiers)              //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_9->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_9->type == regex)               //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_9->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_9->type == comment)             //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_9->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_9->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_10->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_10->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_10->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_10->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_10->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_10->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_10->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_11->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_11->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_11->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_11->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_11->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_11->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_11->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_12->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_12->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_12->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_12->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_12->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_12->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_12->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_13->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_13->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_13->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_13->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_13->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_13->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_13->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_14->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_14->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_14->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_14->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_14->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_14->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_14->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_15->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_15->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_15->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_15->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_15->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_15->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_15->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_16->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_16->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_16->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_16->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_16->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_16->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_16->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_17->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_17->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_17->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_17->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_17->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_17->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_17->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_18->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_18->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_18->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_18->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_18->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_18->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_18->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_19->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_19->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_19->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_19->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_19->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_19->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_19->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_20->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_20->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                new_element.color_1 = color_1;          //  load all colors of editor into element of language
                new_element.color_2 = color_2;
                new_element.color_3 = color_3;
                new_element.color_4 = color_4;
                new_element.color_5 = color_5;
                new_element.color_6 = color_6;
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_20->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_20->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_20->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_20->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_20->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }

    if (ui->widget_21->type == identifiers)             //  active type of element is list of identifiers
    {
        QStringList values;
        int color_1;
        int color_2;
        int color_3;
        int color_4;
        int color_5;
        int color_6;

        if (ui->widget_21->get_identifiers(values, color_1, color_2, color_3, color_4, color_5, color_6))
        {
            SubElement new_element;                     //  create new sub element to push next regular expresion

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            new_element.color_1 = color_1;              //  load all colors of editor into element of language
            new_element.color_2 = color_2;
            new_element.color_3 = color_3;
            new_element.color_4 = color_4;
            new_element.color_5 = color_5;
            new_element.color_6 = color_6;
            language.subElements.push_back(new_element);    //  push back new element into language type

            int len = values.size();

            for (int i = 0; i < len; i++)
            {
                new_element.regex = values[i];
                language.subElements.push_back(new_element);    //  push back new element into language type
            }

            new_element.regex = "";                     //  push back separator of elements to indicate new element
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_21->type == regex)              //  active type of element is regular expression
    {
        SubElement new_element;                         //  create new sub element to push next regular expresion

        if (ui->widget_21->get_regex(new_element.regex, new_element.color_1, new_element.color_2, new_element.color_3,
                                    new_element.color_4, new_element.color_5, new_element.color_6))
        {
            language.subElements.push_back(new_element);    //  push back new element into language type
        }
    }
    else if (ui->widget_21->type == comment)            //  active type of element is single line comment
    {
        Comment new_comment;                            //  create new object to save single line comment

        if (ui->widget_21->get_comment(new_comment.from, new_comment.color_1, new_comment.color_2, new_comment.color_3,
                                    new_comment.color_4, new_comment.color_5, new_comment.color_6))
        {
            language.comments.push_back(new_comment);
        }
    }
    else                                                //  active type of element is multiline comment
    {
        ui->widget_21->get_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);
    }
}


/// Open language description inside language editor
///
/// @param  Language type as parameter to describe language
void Elements::open_language(Language & language)
{
    reset_interface();

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_2->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_2->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_2->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_2->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_3->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_3->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_3->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_3->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_4->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_4->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_4->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_4->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_5->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_5->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_5->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_5->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_6->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_6->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_6->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_6->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_7->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_7->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_7->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_7->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_8->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_8->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_8->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_8->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_9->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_9->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_9->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_9->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_10->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_10->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_10->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_10->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_11->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_11->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_11->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_11->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_12->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_12->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_12->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_12->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_13->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_13->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_13->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_13->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_14->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_14->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_14->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_14->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_15->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_15->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_15->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_15->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_16->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_16->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_16->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_16->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_17->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_17->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_17->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_17->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_18->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_18->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_18->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_18->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_19->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_19->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_19->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_19->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_20->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_20->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_20->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_20->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;

    if (language.subElements.size())                    //  check if there is some subelement inside language
    {
        if (language.subElements[0].regex.size())
        {
            ui->widget_21->set_regex(language.subElements[0].regex, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                    language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
        else
        {
            language.subElements.pop_front();           //  remove first item from sub elements of language

            QStringList identifiers;

            while (language.subElements[0].regex.size())
            {
                identifiers.push_back(language.subElements[0].regex);
                language.subElements.pop_front();       //  remove first item from sub elements of language
            }

            ui->widget_21->set_identifiers(identifiers, language.subElements[0].color_1, language.subElements[0].color_2, language.subElements[0].color_3,
                                        language.subElements[0].color_4, language.subElements[0].color_5, language.subElements[0].color_6);

            language.subElements.pop_front();           //  remove first item from sub elements of language
        }
    }
    else if (language.comments.size())                  //  check if there is some single line comment inside language
    {
        ui->widget_21->set_comment(language.comments[0].from, language.comments[0].color_1, language.comments[0].color_2, language.comments[0].color_3,
                                language.comments[0].color_4, language.comments[0].color_5, language.comments[0].color_6);

        language.comments.pop_front();
    }
    else if (language.multiline_comment_from.size())    //  check if there is multiline comment inside language
    {
        ui->widget_21->set_multiline_comment(language.multiline_comment_from, language.multiline_comment_to, language.multiline_comment_color_1,
                                            language.multiline_comment_color_2, language.multiline_comment_color_3, language.multiline_comment_color_4,
                                            language.multiline_comment_color_5, language.multiline_comment_color_6);

        language.multiline_comment_from = "";           //  remove multiline comment mark from language
    }
    else
        return;
}


/// Reset interface of all elements inside editor
void Elements::reset_interface()
{
    ui->widget->reset_interface();                      //  reset interface of all sub elements
    ui->widget_2->reset_interface();
    ui->widget_3->reset_interface();
    ui->widget_4->reset_interface();
    ui->widget_5->reset_interface();
    ui->widget_6->reset_interface();
    ui->widget_7->reset_interface();
    ui->widget_8->reset_interface();
    ui->widget_9->reset_interface();
    ui->widget_10->reset_interface();
    ui->widget_11->reset_interface();
    ui->widget_12->reset_interface();
    ui->widget_13->reset_interface();
    ui->widget_14->reset_interface();
    ui->widget_15->reset_interface();
    ui->widget_16->reset_interface();
    ui->widget_17->reset_interface();
    ui->widget_18->reset_interface();
    ui->widget_19->reset_interface();
    ui->widget_20->reset_interface();
    ui->widget_21->reset_interface();

    ui->name_line_edit->clear();                        //  clear content of line edit

    ui->widget_2->switch_all_colors(1);                 //  switch colors of first seven elements to color sequence
    ui->widget_3->switch_all_colors(2);
    ui->widget_4->switch_all_colors(3);
    ui->widget_5->switch_all_colors(4);
    ui->widget_6->switch_all_colors(5);
    ui->widget_7->switch_all_colors(6);

    ui->widget_9->switch_all_colors(1);                 //  switch colors of second seven elements to color sequence
    ui->widget_10->switch_all_colors(2);
    ui->widget_11->switch_all_colors(3);
    ui->widget_12->switch_all_colors(4);
    ui->widget_13->switch_all_colors(5);
    ui->widget_14->switch_all_colors(6);

    ui->widget_16->switch_all_colors(1);                //  switch colors of third seven elements to color sequence
    ui->widget_17->switch_all_colors(2);
    ui->widget_18->switch_all_colors(3);
    ui->widget_19->switch_all_colors(4);
    ui->widget_20->switch_all_colors(5);
    ui->widget_21->switch_all_colors(6);

    ui->widget->swap_type();                            //  swap type of elements on some positions
    ui->widget_3->swap_type();
    ui->widget_4->swap_type();
    ui->widget_6->swap_type();
    ui->widget_7->swap_type();
    ui->widget_9->swap_type();
    ui->widget_10->swap_type();
    ui->widget_12->swap_type();
    ui->widget_13->swap_type();
    ui->widget_15->swap_type();
    ui->widget_16->swap_type();
    ui->widget_18->swap_type();
    ui->widget_19->swap_type();
    ui->widget_21->swap_type();
}


/// Class destructor
Elements::~Elements()
{
    delete ui;
}


/// Handle press of first global color button
void Elements::color_1_button_pressed()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  swap type of elements on some positions

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

    ui->widget->highlight_theme_1();                    //  highlight just first theme in all sub elements
    ui->widget_2->highlight_theme_1();
    ui->widget_3->highlight_theme_1();
    ui->widget_4->highlight_theme_1();
    ui->widget_5->highlight_theme_1();
    ui->widget_6->highlight_theme_1();
    ui->widget_7->highlight_theme_1();
    ui->widget_8->highlight_theme_1();
    ui->widget_9->highlight_theme_1();
    ui->widget_10->highlight_theme_1();
    ui->widget_11->highlight_theme_1();
    ui->widget_12->highlight_theme_1();
    ui->widget_13->highlight_theme_1();
    ui->widget_14->highlight_theme_1();
    ui->widget_15->highlight_theme_1();
    ui->widget_16->highlight_theme_1();
    ui->widget_17->highlight_theme_1();
    ui->widget_18->highlight_theme_1();
    ui->widget_19->highlight_theme_1();
    ui->widget_20->highlight_theme_1();
    ui->widget_21->highlight_theme_1();
}


/// Handle press of second global color button
void Elements::color_2_button_pressed()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  swap type of elements on some positions

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

    ui->widget->highlight_theme_2();                    //  highlight just second theme in all sub elements
    ui->widget_2->highlight_theme_2();
    ui->widget_3->highlight_theme_2();
    ui->widget_4->highlight_theme_2();
    ui->widget_5->highlight_theme_2();
    ui->widget_6->highlight_theme_2();
    ui->widget_7->highlight_theme_2();
    ui->widget_8->highlight_theme_2();
    ui->widget_9->highlight_theme_2();
    ui->widget_10->highlight_theme_2();
    ui->widget_11->highlight_theme_2();
    ui->widget_12->highlight_theme_2();
    ui->widget_13->highlight_theme_2();
    ui->widget_14->highlight_theme_2();
    ui->widget_15->highlight_theme_2();
    ui->widget_16->highlight_theme_2();
    ui->widget_17->highlight_theme_2();
    ui->widget_18->highlight_theme_2();
    ui->widget_19->highlight_theme_2();
    ui->widget_20->highlight_theme_2();
    ui->widget_21->highlight_theme_2();
}


/// Handle press of third global color button
void Elements::color_3_button_pressed()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  swap type of elements on some positions

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

    ui->widget->highlight_theme_3();                    //  highlight just third theme in all sub elements
    ui->widget_2->highlight_theme_3();
    ui->widget_3->highlight_theme_3();
    ui->widget_4->highlight_theme_3();
    ui->widget_5->highlight_theme_3();
    ui->widget_6->highlight_theme_3();
    ui->widget_7->highlight_theme_3();
    ui->widget_8->highlight_theme_3();
    ui->widget_9->highlight_theme_3();
    ui->widget_10->highlight_theme_3();
    ui->widget_11->highlight_theme_3();
    ui->widget_12->highlight_theme_3();
    ui->widget_13->highlight_theme_3();
    ui->widget_14->highlight_theme_3();
    ui->widget_15->highlight_theme_3();
    ui->widget_16->highlight_theme_3();
    ui->widget_17->highlight_theme_3();
    ui->widget_18->highlight_theme_3();
    ui->widget_19->highlight_theme_3();
    ui->widget_20->highlight_theme_3();
    ui->widget_21->highlight_theme_3();
}


/// Handle press of fourth global color button
void Elements::color_4_button_pressed()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  swap type of elements on some positions

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

    ui->widget->highlight_theme_4();                    //  highlight just fourth theme in all sub elements
    ui->widget_2->highlight_theme_4();
    ui->widget_3->highlight_theme_4();
    ui->widget_4->highlight_theme_4();
    ui->widget_5->highlight_theme_4();
    ui->widget_6->highlight_theme_4();
    ui->widget_7->highlight_theme_4();
    ui->widget_8->highlight_theme_4();
    ui->widget_9->highlight_theme_4();
    ui->widget_10->highlight_theme_4();
    ui->widget_11->highlight_theme_4();
    ui->widget_12->highlight_theme_4();
    ui->widget_13->highlight_theme_4();
    ui->widget_14->highlight_theme_4();
    ui->widget_15->highlight_theme_4();
    ui->widget_16->highlight_theme_4();
    ui->widget_17->highlight_theme_4();
    ui->widget_18->highlight_theme_4();
    ui->widget_19->highlight_theme_4();
    ui->widget_20->highlight_theme_4();
    ui->widget_21->highlight_theme_4();
}


/// Handle press of fifth global color button
void Elements::color_5_button_pressed()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  swap type of elements on some positions

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

    ui->widget->highlight_theme_5();                    //  highlight just fifth theme in all sub elements
    ui->widget_2->highlight_theme_5();
    ui->widget_3->highlight_theme_5();
    ui->widget_4->highlight_theme_5();
    ui->widget_5->highlight_theme_5();
    ui->widget_6->highlight_theme_5();
    ui->widget_7->highlight_theme_5();
    ui->widget_8->highlight_theme_5();
    ui->widget_9->highlight_theme_5();
    ui->widget_10->highlight_theme_5();
    ui->widget_11->highlight_theme_5();
    ui->widget_12->highlight_theme_5();
    ui->widget_13->highlight_theme_5();
    ui->widget_14->highlight_theme_5();
    ui->widget_15->highlight_theme_5();
    ui->widget_16->highlight_theme_5();
    ui->widget_17->highlight_theme_5();
    ui->widget_18->highlight_theme_5();
    ui->widget_19->highlight_theme_5();
    ui->widget_20->highlight_theme_5();
    ui->widget_21->highlight_theme_5();
}


/// Handle press of sixth global color button
void Elements::color_6_button_pressed()
{
    bool active = true;

    if (ui->color_1_button->isVisible() && ui->color_2_button->isVisible() && ui->color_3_button->isVisible() &&
        ui->color_4_button->isVisible() && ui->color_5_button->isVisible() && ui->color_6_button->isVisible())
        active = false;                                 //  swap type of elements on some positions

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

    ui->widget->highlight_theme_6();                    //  highlight just sixth theme in all sub elements
    ui->widget_2->highlight_theme_6();
    ui->widget_3->highlight_theme_6();
    ui->widget_4->highlight_theme_6();
    ui->widget_5->highlight_theme_6();
    ui->widget_6->highlight_theme_6();
    ui->widget_7->highlight_theme_6();
    ui->widget_8->highlight_theme_6();
    ui->widget_9->highlight_theme_6();
    ui->widget_10->highlight_theme_6();
    ui->widget_11->highlight_theme_6();
    ui->widget_12->highlight_theme_6();
    ui->widget_13->highlight_theme_6();
    ui->widget_14->highlight_theme_6();
    ui->widget_15->highlight_theme_6();
    ui->widget_16->highlight_theme_6();
    ui->widget_17->highlight_theme_6();
    ui->widget_18->highlight_theme_6();
    ui->widget_19->highlight_theme_6();
    ui->widget_20->highlight_theme_6();
    ui->widget_21->highlight_theme_6();
}


/// Handle toggle of multiline comment
void Elements::multiline_comment_toggled()
{
    bool flag = ui->widget->multiline_comment_flag;
    flag = !flag;

    ui->widget->multiline_comment_flag = flag;          //  set multiline comment flag in all sub elements
    ui->widget_2->multiline_comment_flag = flag;
    ui->widget_3->multiline_comment_flag = flag;
    ui->widget_4->multiline_comment_flag = flag;
    ui->widget_5->multiline_comment_flag = flag;
    ui->widget_6->multiline_comment_flag = flag;
    ui->widget_7->multiline_comment_flag = flag;
    ui->widget_8->multiline_comment_flag = flag;
    ui->widget_9->multiline_comment_flag = flag;
    ui->widget_10->multiline_comment_flag = flag;
    ui->widget_11->multiline_comment_flag = flag;
    ui->widget_12->multiline_comment_flag = flag;
    ui->widget_13->multiline_comment_flag = flag;
    ui->widget_14->multiline_comment_flag = flag;
    ui->widget_15->multiline_comment_flag = flag;
    ui->widget_16->multiline_comment_flag = flag;
    ui->widget_17->multiline_comment_flag = flag;
    ui->widget_18->multiline_comment_flag = flag;
    ui->widget_19->multiline_comment_flag = flag;
    ui->widget_20->multiline_comment_flag = flag;
    ui->widget_21->multiline_comment_flag = flag;
}


/// Save created user language
void Elements::save_button_pressed()
{                                                       //  name of new language cannot be same as name of built-in language
    if (ui->name_line_edit->text().size())
    {
        if (ui->name_line_edit->text().toLower() != "c" &&
            ui->name_line_edit->text().toLower() != "c++" &&
            ui->name_line_edit->text().toLower() != "java" &&
            ui->name_line_edit->text().toLower() != "php" &&
            ui->name_line_edit->text().toLower() != "plain text" &&
            ui->name_line_edit->text().toLower() != "python")
        {
            emit save_signal();
        }
    }
}


/// Reset process of language creation to default state
void Elements::refresh_button_pressed()
{
    reset_interface();
}


/// Cancel process of creating language
void Elements::cancel_button_pressed()
{
    emit cancel_signal();
}
