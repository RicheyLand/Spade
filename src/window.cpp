#include "window.h"
#include "ui_window.h"


/// Class constructor
///
/// @param  Parent widget of instance
Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    widget = new Spade(1);                              //  allocate memory for all text editors
    widget_2 = new Spade(2);
    widget_3 = new Spade(3);
    widget_4 = new Spade(4);

    v_splitter = new QSplitter();                       //  allocate memory for the first vertical splitter
    v_splitter->addWidget(widget);
    v_splitter->addWidget(widget_3);
    v_splitter->setOrientation(Qt::Vertical);
    v_splitter->setHandleWidth(0);
    v_splitter->setCollapsible(0, false);
    v_splitter->setCollapsible(1, false);

    v_splitter_2 = new QSplitter();                     //  allocate memory for the second vertical splitter
    v_splitter_2->addWidget(widget_2);
    v_splitter_2->addWidget(widget_4);
    v_splitter_2->setOrientation(Qt::Vertical);
    v_splitter_2->setHandleWidth(0);
    v_splitter_2->setCollapsible(0, false);
    v_splitter_2->setCollapsible(1, false);

    h_splitter = new QSplitter();                       //  allocate memory for the horizontal splitter
    h_splitter->addWidget(v_splitter);
    h_splitter->addWidget(v_splitter_2);
    h_splitter->setOrientation(Qt::Horizontal);
    h_splitter->setHandleWidth(0);
    h_splitter->setCollapsible(0, false);
    h_splitter->setCollapsible(1, false);

    ui->main_g_layout->addWidget(h_splitter);

    setLayout(ui->main_g_layout);                       //  set default layout for window
                                                        //  connect signals from elements with appropriate slots
    QObject::connect(v_splitter, SIGNAL(splitterMoved(int,int)), this, SLOT(handle_splitter_2_movement(int,int)));
    QObject::connect(v_splitter_2, SIGNAL(splitterMoved(int,int)), this, SLOT(handle_splitter_movement(int,int)));

    QObject::connect(widget, SIGNAL(fullscreen_signal()), this, SLOT(toggle_fullscreen()));
    QObject::connect(widget_2, SIGNAL(fullscreen_signal()), this, SLOT(toggle_fullscreen()));
    QObject::connect(widget_3, SIGNAL(fullscreen_signal()), this, SLOT(toggle_fullscreen()));
    QObject::connect(widget_4, SIGNAL(fullscreen_signal()), this, SLOT(toggle_fullscreen()));
    QObject::connect(widget, SIGNAL(exit_signal()), this, SLOT(handle_exit()));
    QObject::connect(widget_2, SIGNAL(exit_signal()), this, SLOT(handle_exit()));
    QObject::connect(widget_3, SIGNAL(exit_signal()), this, SLOT(handle_exit()));
    QObject::connect(widget_4, SIGNAL(exit_signal()), this, SLOT(handle_exit()));
    QObject::connect(widget, SIGNAL(layout_signal(int)), this, SLOT(handle_layout_selection(int)));
    QObject::connect(widget_2, SIGNAL(layout_signal(int)), this, SLOT(handle_layout_selection(int)));
    QObject::connect(widget_3, SIGNAL(layout_signal(int)), this, SLOT(handle_layout_selection(int)));
    QObject::connect(widget_4, SIGNAL(layout_signal(int)), this, SLOT(handle_layout_selection(int)));
    QObject::connect(widget, SIGNAL(send_language_signal(int,Language)), this, SLOT(handle_language_send_1(int,Language)));
    QObject::connect(widget_2, SIGNAL(send_language_signal(int,Language)), this, SLOT(handle_language_send_2(int,Language)));
    QObject::connect(widget_3, SIGNAL(send_language_signal(int,Language)), this, SLOT(handle_language_send_3(int,Language)));
    QObject::connect(widget_4, SIGNAL(send_language_signal(int,Language)), this, SLOT(handle_language_send_4(int,Language)));

    widget_2->setHidden(true);                          //  only first text editor is visible by default
    widget_3->setHidden(true);
    widget_4->setHidden(true);

    v_splitter->handle(1)->setEnabled(false);           //  hide all unnecessary handles
    v_splitter_2->handle(1)->setEnabled(false);
    h_splitter->handle(1)->setEnabled(false);
}


/// Push parameter to text editor to separate it from other sub editors
///
/// @param  String parameter to be pushed
void Window::push_parameter(QString content)
{
    widget->parameters.push_back(content);
}


/// Handle parameters using text editor class method
void Window::handle_parameters()
{
    widget->handle_parameters();
}


/// Class destructor
Window::~Window()
{
    delete ui;
}


/// Handle application close event
///
/// @param  Generic Qt close event handler
void Window::closeEvent(QCloseEvent * event)
{
    handle_exit();
    event->ignore();
}


/// Reaction to the user movement of first vertical splitter
///
/// @param  First parameter holds horizontal position of splitter
/// @param  Second parameter holds horizontal position of splitter
void Window::handle_splitter_movement(int, int)
{
    v_splitter->setSizes(v_splitter_2->sizes());        //  update size of splitter after movement
}


/// Reaction to the user movement of second vertical splitter
///
/// @param  First parameter holds horizontal position of splitter
/// @param  Second parameter holds horizontal position of splitter
void Window::handle_splitter_2_movement(int, int)
{
    v_splitter_2->setSizes(v_splitter->sizes());        //  update size of splitter after movement
}


/// Activate fullscreen mode of application
void Window::toggle_fullscreen()
{
    if (isFullScreen())
        showNormal();                                   //  dectivate fullscreen mode
    else
        showFullScreen();                               //  enable fullscreen mode

    widget->handle_fullscreen();                        //  handle fullscreen toggle for all text editors
    widget_2->handle_fullscreen();
    widget_3->handle_fullscreen();
    widget_4->handle_fullscreen();
}


/// Safely handle application close
void Window::handle_exit()
{                                                       //  handle application close event using appropriate exit method
    widget->handle_exit();                              //  handle exit for all text editors
    widget_2->handle_exit();
    widget_3->handle_exit();
    widget_4->handle_exit();

    QApplication::quit();
}


/// Handle selection of concrete layout
///
/// @param  Integer index of concrete text editor
void Window::handle_layout_selection(int index)
{
    widget->handle_layouts(index);                      //  handle layout change for all text editors
    widget_2->handle_layouts(index);
    widget_3->handle_layouts(index);
    widget_4->handle_layouts(index);

    if (index == 0)                                     //  all text editors are going to be active
    {
        if (isFullScreen())                             //  handle fullscreen mode
            toggle_fullscreen();

        if (isMaximized())
            showNormal();

        widget_2->setVisible(true);                     //  show all rest text editors
        widget_3->setVisible(true);
        widget_4->setVisible(true);

        v_splitter->handle(1)->setEnabled(true);        //  hide all unnecessary handles
        v_splitter_2->handle(1)->setEnabled(true);
        h_splitter->handle(1)->setEnabled(true);

        setMinimumWidth(1500);
        setMinimumHeight(960);

        resize(minimumWidth(), minimumHeight());        //  resize application window to avoid problems with size
    }
    else if (index == 1)                                //  two left text editors are going to be active
    {
        if (isFullScreen())                             //  handle fullscreen mode
            toggle_fullscreen();

        if (isMaximized())
            showNormal();

        widget_2->setHidden(true);                      //  hide rest text editors
        widget_3->setVisible(true);
        widget_4->setHidden(true);

        v_splitter->handle(1)->setEnabled(true);        //  hide all unnecessary handles
        v_splitter_2->handle(1)->setEnabled(false);
        h_splitter->handle(1)->setEnabled(false);

        setMinimumWidth(750);
        setMinimumHeight(960);

        resize(minimumWidth(), minimumHeight());        //  resize application window to avoid problems with size
    }
    else if (index == 2)                                //  two top text editors are going to be active
    {
        if (isFullScreen())                             //  handle fullscreen mode
            toggle_fullscreen();

        if (isMaximized())
            showNormal();

        widget_2->setVisible(true);
        widget_3->setHidden(true);                      //  hide rest text editors
        widget_4->setHidden(true);

        v_splitter->handle(1)->setEnabled(false);       //  hide all unnecessary handles
        v_splitter_2->handle(1)->setEnabled(false);
        h_splitter->handle(1)->setEnabled(true);

        setMinimumWidth(1500);
        setMinimumHeight(480);

        resize(minimumWidth(), minimumHeight());        //  resize application window to avoid problems with size
    }
    else                                                //  only one text editor is going to be active
    {
        if (isFullScreen())                             //  handle fullscreen mode
            toggle_fullscreen();

        if (isMaximized())
            showNormal();

        widget_2->setHidden(true);                      //  hide rest text editors
        widget_3->setHidden(true);
        widget_4->setHidden(true);

        v_splitter->handle(1)->setEnabled(false);       //  hide all unnecessary handles
        v_splitter_2->handle(1)->setEnabled(false);
        h_splitter->handle(1)->setEnabled(false);

        setMinimumWidth(750);
        setMinimumHeight(480);

        resize(minimumWidth(), minimumHeight());        //  resize application window to avoid problems with size
    }
}


/// Receive incoming language from the first text editor
///
/// @param  Integer index of concrete text editor
/// @param  Language instance to have to be sent to this text editor
void Window::handle_language_send_1(int type, Language user_language)
{
    if (type == 1)                                      //  only top right text editor will receive language
        widget_2->receive_language(user_language);
    else if (type == 2)                                 //  only bottom left text editor will receive language
        widget_3->receive_language(user_language);
    else if (type == 3)                                 //  only bottom right text editor will receive language
        widget_4->receive_language(user_language);
    else                                                //  all rest text editors will receive language
    {
        widget_2->receive_language(user_language);
        widget_3->receive_language(user_language);
        widget_4->receive_language(user_language);
    }
}


/// Receive incoming language from the second text editor
///
/// @param  Integer index of concrete text editor
/// @param  Language instance to have to be sent to this text editor
void Window::handle_language_send_2(int type, Language user_language)
{
    if (type == 1)                                      //  only top left text editor will receive language
        widget->receive_language(user_language);
    else if (type == 2)                                 //  only bottom right text editor will receive language
        widget_4->receive_language(user_language);
    else if (type == 3)                                 //  only bottom left text editor will receive language
        widget_3->receive_language(user_language);
    else                                                //  all rest text editors will receive language
    {
        widget->receive_language(user_language);
        widget_3->receive_language(user_language);
        widget_4->receive_language(user_language);
    }
}


/// Receive incoming language from the third text editor
///
/// @param  Integer index of concrete text editor
/// @param  Language instance to have to be sent to this text editor
void Window::handle_language_send_3(int type, Language user_language)
{
    if (type == 1)                                      //  only bottom right text editor will receive language
        widget_4->receive_language(user_language);
    else if (type == 2)                                 //  only top left text editor will receive language
        widget->receive_language(user_language);
    else if (type == 3)                                 //  only top right text editor will receive language
        widget_2->receive_language(user_language);
    else                                                //  all rest text editors will receive language
    {
        widget->receive_language(user_language);
        widget_2->receive_language(user_language);
        widget_4->receive_language(user_language);
    }
}


/// Receive incoming language from the fourth text editor
///
/// @param  Integer index of concrete text editor
/// @param  Language instance to have to be sent to this text editor
void Window::handle_language_send_4(int type, Language user_language)
{
    if (type == 1)                                      //  only bottom left text editor will receive language
        widget_3->receive_language(user_language);
    else if (type == 2)                                 //  only top right text editor will receive language
        widget_2->receive_language(user_language);
    else if (type == 3)                                 //  only top left text editor will receive language
        widget->receive_language(user_language);
    else                                                //  all rest text editors will receive language
    {
        widget->receive_language(user_language);
        widget_2->receive_language(user_language);
        widget_3->receive_language(user_language);
    }
}
