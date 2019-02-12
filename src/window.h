#ifndef WINDOW_H
#define WINDOW_H

#include "spade.h"

namespace Ui {
class Window;
}


/// Represents window of application and implements layout of text editors
class Window : public QWidget
{
    Q_OBJECT

public:
    /// Class constructor
    ///
    /// @param  Parent widget of instance
    explicit Window(QWidget *parent = 0);


    /// Push parameter to text editor to separate it from other sub editors
    ///
    /// @param  String parameter to be pushed
    void push_parameter(QString);


    /// Handle parameters using text editor class method
    void handle_parameters();


    /// Class destructor
    ~Window();

private:
    Ui::Window *ui;

    Spade * widget;                                     //  first text editor widget(top left)
    Spade * widget_2;                                   //  second text editor widget(top right)
    Spade * widget_3;                                   //  third text editor widget(bottom left)
    Spade * widget_4;                                   //  fourth text editor widget(bottom right)

    QSplitter * v_splitter;                             //  vertical splitter located between top editors
    QSplitter * v_splitter_2;                           //  vertical splitter located between bottom editors
    QSplitter * h_splitter;                             //  horizontal splitter located between top and bottom parts of window


    /// Handle application close event
    ///
    /// @param  Generic Qt close event handler
    void closeEvent(QCloseEvent *);

private slots:
    /// Reaction to the user movement of first vertical splitter
    ///
    /// @param  First parameter holds horizontal position of splitter
    /// @param  Second parameter holds horizontal position of splitter
    void handle_splitter_movement(int, int);


    /// Reaction to the user movement of second vertical splitter
    ///
    /// @param  First parameter holds horizontal position of splitter
    /// @param  Second parameter holds horizontal position of splitter
    void handle_splitter_2_movement(int, int);


    /// Activate fullscreen mode of application
    void toggle_fullscreen();


    /// Safely handle application close
    void handle_exit();


    /// Handle selection of concrete layout
    ///
    /// @param  Integer index of concrete text editor
    void handle_layout_selection(int);


    /// Receive incoming language from the first text editor
    ///
    /// @param  Integer index of concrete text editor
    /// @param  Language instance to have to be sent to this text editor
    void handle_language_send_1(int, Language);


    /// Receive incoming language from the second text editor
    ///
    /// @param  Integer index of concrete text editor
    /// @param  Language instance to have to be sent to this text editor
    void handle_language_send_2(int, Language);


    /// Receive incoming language from the third text editor
    ///
    /// @param  Integer index of concrete text editor
    /// @param  Language instance to have to be sent to this text editor
    void handle_language_send_3(int, Language);


    /// Receive incoming language from the fourth text editor
    ///
    /// @param  Integer index of concrete text editor
    /// @param  Language instance to have to be sent to this text editor
    void handle_language_send_4(int, Language);
};

#endif // WINDOW_H
