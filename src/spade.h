#ifndef SPADE_H
#define SPADE_H

#include "highlighter.h"

namespace Ui {
class Spade;
}


/// Description class of concrete child of class tree item
class Class_tree_child
{
public:
    QString content;
    int from;                                           //  appropriate starting coordinate of class tree item(can represent declaration of method)
    int to;                                             //  appropriate starting coordinate of class tree item in document(can represent definition of method)
    QString file_path;


    /// Class constructor
    Class_tree_child()
    {                                                   //  value -1 means that declaration or definition has not been found yet
        from = -1;
        to = -1;
        file_path = "";
    }
};


/// Description class of concrete class tree item
class Class_tree_parent
{
public:
    QString content;
    int from;                                           //  appropriate starting coordinate of class tree item in document
    int to;                                             //  appropriate ending coordinate of class tree item in document
    bool is_class;
    QString file_path;
    vector<Class_tree_child> children;


    /// Class constructor
    Class_tree_parent()
    {
        from = -1;
        to = -1;
        is_class = true;
        file_path = "";
    }
};


/// Holds coordinates of start and end of cursor selection in text
class Selection
{
public:
    int from;
    int to;
};


/// Custom label which allows detection of mouse button click
class RichLabel : public QLabel
{
    Q_OBJECT

public:
    /// Class constructor
    ///
    /// @param  Initial text label of element
    /// @param  Parent widget of instance
    explicit RichLabel(const QString & text = "", QWidget * parent = 0);
    int id;                                             //  label identifier


    /// Class destructor
    ~RichLabel();

signals:
    /// Signal with line and field coordinates which is sent when label is clicked
    ///
    /// @param  Parameter which allows concrete recognize of signal sender
    void clicked(int);


    /// Signal is sent when mouse cursor enter label area
    ///
    /// @param  Parameter which allows concrete recognize of signal sender
    void entered(int);


    /// Signal is sent when mouse cursor leave label area
    ///
    /// @param  Parameter which allows concrete recognize of signal sender
    void leaved(int);

protected:
    /// handle mouse press event
    ///
    /// @param  Qt Mouse event reference
    void mousePressEvent(QMouseEvent *);


    /// Handle mouse cursor enter event
    ///
    /// @param  Generic Qt event handler
    void enterEvent(QEvent *);


    /// Handle mouse cursor leave event
    ///
    /// @param  Generic Qt event handler
    void leaveEvent(QEvent *);
};


/// Custom push button which allows detection of mouse enter event
class RichPushButton : public QPushButton
{
    Q_OBJECT

public:
    /// Class constructor
    ///
    /// @param  Initial text label of element
    /// @param  Parent widget of instance
    explicit RichPushButton(const QString & text = "", QWidget * parent = 0);


    /// Class destructor
    ~RichPushButton();

signals:
    /// Signal is sent when mouse cursor enter button area
    void entered();


    /// Signal is sent when mouse cursor leave button area
    void leaved();

protected:
    /// Handle mouse cursor enter event
    ///
    /// @param  Generic Qt event handler
    void enterEvent(QEvent *);


    /// Handle mouse cursor leave event
    ///
    /// @param  Generic Qt event handler
    void leaveEvent(QEvent *);
};


/// Custom label with advanced detection of mouse button click
class RichTreeWidget : public QTreeWidget
{
    Q_OBJECT

public:
    /// Class constructor
    ///
    /// @param  Parent widget of instance
    RichTreeWidget(QWidget * parent = 0);

protected:
    /// Handle mouse release event
    ///
    /// @param  Qt Mouse event reference
    void mouseReleaseEvent(QMouseEvent *);

signals:
    /// Handle left mouse button click to node of tree widget
    ///
    /// @param  Model index of tree widget structure
    void left_mouse_clicked(QModelIndex);


    /// Handle right mouse button click to node of tree widget
    ///
    /// @param  Model index of tree widget structure
    void right_mouse_clicked(QModelIndex);
};


/// Holds definiton and behavior of improved plain text editor with line number area
class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    /// Class constructor
    ///
    /// @param  Parent widget of instance
    CodeEditor(QWidget * parent = 0);

    QString content;                                    //  actual text content of editor
    Selection old_selection;                            //  previous cursor selection in text
    Selection actual_selection;                         //  actual cursor selection in text
    int theme;                                          //  actual color scheme
    QString file_path;                                  //  full path to opened text file
    bool vim_active;                                    //  holds if Vim mode is active
    bool key_press_flag;                                //  holds if key has been pressed during usage of Vim mode
    bool undo_redo_flag;                                //  holds if editor has to ignore text change event on undo and redo
    unsigned differences_index;                         //  actual index in redefined undo history
    vector<vector<bool> > differences;                  //  array which holds differences between file content for all steps of undo history
    vector<bool> actual_difference;                     //  actual file content difference between previous and actual step in editing


    /// Redefined key press event to catch advanced keyboard shortcuts
    ///
    /// @param  Qt key press event handler
    void keyPressEvent(QKeyEvent *);


    /// Event which causes repaint of line number area
    ///
    /// @param  Qt paint event handler
    void lineNumberAreaPaintEvent(QPaintEvent *);


    /// Returns recommended width of line number area
    int lineNumberAreaWidth();


    /// Method with redefined behavior of file content save
    void save_content();


    /// Handle text differences check if lines swapped up
    ///
    /// @param  Affected line integer value
    /// @param  Integer value of lines which must be moved
    /// @param  Boolean value to hold state of moved line
    void handle_swap_line_up(int, int, bool);


    /// Handle text differences check if lines swapped down
    ///
    /// @param  Affected line integer value
    /// @param  Integer value of lines which must be moved
    /// @param  Boolean value to hold state of moved line
    void handle_swap_line_down(int, int, bool);

protected:
    /// Event which represents resize event of text editor
    ///
    /// @param  Overrided Qt resize event handler
    void resizeEvent(QResizeEvent *event) override;

private:
    QWidget * lineNumberArea;                           //  abstract line number area object

public slots:
    /// Handle change of text editor position
    void cursor_position_changed();


    /// Handle change of text editor content
    void editor_text_changed();


    /// Handle change of adding new item into undo history
    void undo_command_added();


    /// Redefined method for undo operation
    void text_undo();


    /// Redefined method for redo operation
    void text_redo();

private slots:
    /// Slot which updates width of line number area
    ///
    /// @param  Holds integer value of text blocks(lines)
    void updateLineNumberAreaWidth(int newBlockCount);


    /// Slot which updates line number area
    ///
    /// @param  Rectangle value of text editor view area
    /// @param  Integer value of vertical axis scroll
    void updateLineNumberArea(const QRect &, int);

signals:                                                //  signals which editor sends as reactiong to pressing one of special keyboard shortcuts
    /// Keypress save signal of text editor
    void save_signal();


    /// Keypress open signal of text editor
    void open_signal();


    /// Keypress new tab signal of text editor
    void new_tab_signal();


    /// Keypress close signal of text editor
    void close_signal();


    /// Keypress fullscreen signal of text editor
    void fullscreen_signal();


    /// Keypress exit signal of text editor
    void exit_signal();


    /// Keypress save all signal of text editor
    void save_all_signal();


    /// Keypress find signal of text editor
    void find_signal();


    /// Keypress swap line up signal of text editor
    void swap_line_up_signal();


    /// Keypress swap line down signal of text editor
    void swap_line_down_signal();


    /// Keypress uppercase signal
    void uppercase_signal();


    /// Keypress lowercase signal
    void lowercase_signal();


    /// Keypress comment signal of text editor
    void comment_signal();


    /// Signal of text editor representing keypress of increase font size
    void increase_font_size_signal();


    /// Signal of text editor representing keypress of decrease font size
    void decrease_font_size_signal();


    /// Keypress tab up signal of text editor
    void move_tab_up_signal();


    /// Keypress tab down signal of text editor
    void move_tab_down_signal();


    /// Keypress of scrollbar up signal of text editor
    void move_scrollbar_up_signal();


    /// Keypress of scrollbar down signal of text editor
    void move_scrollbar_down_signal();


    /// Keypress tab signal of text editor
    void tab_signal();


    /// Keypress untab signal of text editor
    void shift_tab_signal();


    /// Keypress enter signal of text editor
    void enter_signal();


    /// Keypress classic bracket signal of text editor
    void classic_bracket_signal();


    /// Keypress block bracket signal of text editor
    void block_bracket_signal();


    /// Keypress array bracket signal of text editor
    void array_bracket_signal();


    /// Keypress run signal of text editor
    void run_signal();


    /// Keypress build signal of text editor
    void build_signal();


    /// Generic signal fo Vim key press
    ///
    /// @param  Integer representation of concrete key
    /// @param  String representation of concrete key
    void vim_key_press_signal(int, QString);
};


/// Represents line number area class which is derived from native QWidget class
class LineNumberArea : public QWidget
{
public:
    /// Get text editor parent using argument of class constructor
    ///
    /// @param  Parent text editor of instance
    LineNumberArea(CodeEditor *editor) : QWidget(editor)
    {
        codeEditor = editor;                            //  set pointer to parent text editor
    }


    /// Redefine size hint method for line number area
    QSize sizeHint() const override
    {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    /// Redefine paint event behavior and use parent's paint event
    ///
    /// @param  Generic Qt paint event handler
    void paintEvent(QPaintEvent *event) override
    {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor *codeEditor;                             //  pointer to text editor parent
};


/// Holds all required details about one tab opened in text editor
class Tab_details
{
public:
    /// Class constructor
    Tab_details();


    int index_in_tabs;                                  //  index which mapping this to tab to real index in text editor tabs
    int language;                                       //  active programming language for tab
    QString file_path;                                  //  full path to opened file in tab
    QString file_name;                                  //  just filename parsed from full path
    int font_size;                                      //  actual size of font in tab
    int tab_width;                                      //  actual size of tab width in tab
    bool scroll_bars;                                   //  holds if scroll bars in tab are visible or not
    bool comments;                                      //  holds if comments in tab are visible or not
    int theme;                                          //  holds activated color scheme for tab
    bool saved;                                         //  holds if content in editor is same as content saved on disk
    int custom_selections_count;                        //  number of present custom color highlights in content
    QList<QTextEdit::ExtraSelection> extra_selections;  //  list of all custom color highlights
};


/// Holds all required details about one project opened in text editor
class Project_details
{
public:
    int language;                                       //  active programming language for project
    QString name;                                       //  name of project
    QString path;                                       //  full path to the project file
    QStringList files;                                  //  list of all paths to contained files
    QString run_arguments;                              //  run parameters of executable
    QString compile_arguments;                          //  compile parameters of executable
    QString make_arguments;                             //  make parameters of executable


    /// Initialize all attributes inside of class constructor
    Project_details()
    {
        language = cplusplus;
        name = "";
        path = "";
        run_arguments = "";
        compile_arguments = "";
        make_arguments = "";
    }
};


/// Represents complete definition and behavior of Spade code editor
class Spade : public QDialog
{
    Q_OBJECT

public:
    QStringList parameters;                             //  holds all command line parameters as separated strings


    /// Class constructor
    ///
    /// @param  Integer value which holds index of text editor inside window
    /// @param  Parent widget of instance
    explicit Spade(int, QWidget *parent = 0);


    /// Try to open all command line parameters as files in text editor
    void handle_parameters();


    /// Class destructor
    ~Spade();

private:
    Ui::Spade *ui;

    QSysInfo systemInfo;                                //  information about current operating system
    bool isWindows;                                     //  holds if operating system is Windows
    int which;                                          //  index of actual workspace in layout
    int thread_count;                                   //  holds recommended count of threads used for compilation
    QString home_path;                                  //  full path of user's home directory
    QString config_path;                                //  full path of user's config directory
    QString config_file_path;                           //  full path to configuration file
    QString language_file_path;                         //  full path to language file
    QString projects_file_path;                         //  full path to projects file
    bool fullscreen;                                    //  holds if fullscreen mode is active
    bool insert_mode;                                   //  holds if insert mode is active

    int max_tabs;                                       //  maximum number of tabs in text editor
    int max_index;                                      //  maximum index value for tab in editor
    vector<Tab_details> active_tabs;                    //  description of all active tabs in editor
    QList<Project_details> active_projects;             //  description of all active projects in editor
    int theme_count;                                    //  number of available color schemes

    QList<Language> user_languages;                     //  list of languages defined by user
    RichHighlighter ** highlighters;                    //  syntax highlighters for contents of all opened tabs in text editor

    QTimer * cursor_timer;                              //  timer with automatic cycle refresh by text cursor movement
    QTimer * text_change_timer;                         //  timer with automatic cycle refresh by text editor content change

    QTextCursor * text_cursor;                          //  generic text cursor of editor
    CodeEditor * editor;                                //  pointer to array of all text editor tabs
    QPalette * theme_color;                             //  generic color for color scheme of editor setting
    QHBoxLayout * file_tray_h_layout;                   //  horizontal layout of file tray
    QHBoxLayout * paint_tray_h_layout;                  //  horizontal layout of paint tray
    QHBoxLayout * actions_tray_h_layout;                //  horizontal layout of actions tray
    QHBoxLayout * find_tray_h_layout;                   //  horizontal layout of find tray
    QHBoxLayout * template_tray_h_layout;               //  horizontal layout of template tray
    QHBoxLayout * language_tray_h_layout;               //  horizontal layout of language tray
    QHBoxLayout * vim_tray_h_layout;                    //  horizontal layout of vim tray
    QHBoxLayout * projects_tray_h_layout;               //  horizontal layout of projects tray
    QHBoxLayout * parameters_tray_h_layout;             //  horizontal layout of parameters tray
    QHBoxLayout * tray_h_layout;                        //  horizontal layout of main tray

    RichLabel * theme_image;                            //  pointer to array of images of all supported color schemes
    QPixmap * theme_pixmap;                             //  pointer to array of pixmaps of color scheme images

    QFont font;                                         //  generic font for dynamic change of font in concrete tabs of editor
                                                        //  definition of all icons which will be used in application
    QIcon * bold_off_icon;
    QIcon * bold_on_icon;
    QIcon * boundary_off_icon;
    QIcon * boundary_on_icon;
    QIcon * build_icon;
    QIcon * class_off_icon;
    QIcon * class_on_icon;
    QIcon * class_icon;
    QIcon * close_icon;
    QIcon * code_icon;
    QIcon * comments_off_icon;
    QIcon * comments_on_icon;
    QIcon * concept_icon;
    QIcon * diagonal_icon_1;
    QIcon * diagonal_icon_2;
    QIcon * diagonal_icon_3;
    QIcon * diagonal_icon_4;
    QIcon * down_icon;
    QIcon * enum_icon;
    QIcon * file_icon;
    QIcon * find_icon;
    QIcon * folder_icon;
    QIcon * fullscreen_off_icon;
    QIcon * fullscreen_on_icon;
    QIcon * help_icon;
    QIcon * home_icon;
    QIcon * italic_off_icon;
    QIcon * italic_on_icon;
    QIcon * lower_icon;
    QIcon * menu_icon;
    QIcon * new_tab_icon;
    QIcon * paint_icon;
    QIcon * private_attribute_icon;
    QIcon * private_method_icon;
    QIcon * project_icon;
    QIcon * protected_attribute_icon;
    QIcon * protected_method_icon;
    QIcon * public_attribute_icon;
    QIcon * public_method_icon;
    QIcon * redo_icon;
    QIcon * regex_icon;
    QIcon * reload_icon;
    QIcon * replace_all_icon;
    QIcon * replace_icon;
    QIcon * rubber_icon;
    QIcon * save_icon;
    QIcon * scroll_bars_off_icon;
    QIcon * scroll_bars_on_icon;
    QIcon * static_private_attribute_icon;
    QIcon * static_private_method_icon;
    QIcon * static_protected_attribute_icon;
    QIcon * static_protected_method_icon;
    QIcon * static_public_attribute_icon;
    QIcon * static_public_method_icon;
    QIcon * struct_icon;
    QIcon * swap_icon;
    QIcon * text_icon;
    QIcon * theme_icon;
    QIcon * undo_icon;
    QIcon * upper_icon;
    QIcon * up_icon;
    QIcon * vim_icon;
    QIcon * warning_icon;
    QIcon * yes_icon;
                                                        //  all visual elements located in file tray
    QPushButton * undo_button;
    QPushButton * redo_button;
    QPushButton * save_all_button;
    QPushButton * scroll_bars_button;
    QPushButton * reload_button;
    QComboBox * tab_width;
    QComboBox * layouts;
    QPushButton * back_button;
                                                        //  all visual elements located in paint tray
    QColor color;
    QPixmap * color_pixmap;
    QPushButton * color_button;
    QPushButton * apply_button;
    QPushButton * rubber_button;
    QPushButton * undo_button_2;
    QPushButton * clear_button;
    QPushButton * back_button_2;
                                                        //  all visual elements located in actions tray
    QPushButton * find_button;
    QPushButton * swap_line_up_button;
    QPushButton * swap_line_down_button;
    QPushButton * upper_case_button;
    QPushButton * lower_case_button;
    QPushButton * swap_case_button;
    QPushButton * bold_button;
    QPushButton * italic_button;
    QPushButton * vim_button;
    QPushButton * concept_button;
    QPushButton * help_button;
    QPushButton * back_button_3;
                                                        //  all visual elements located in find tray
    QPushButton * find_previous_button;
    QPushButton * find_next_button;
    QLineEdit * find_line_edit;
    QPushButton * replace_button;
    QPushButton * replace_all_button;
    QLineEdit * replace_line_edit;
    QPushButton * regex_button;
    QPushButton * case_button;
    QPushButton * boundary_button;
    QPushButton * back_button_4;
                                                        //  all visual elements located in template tray
    QPushButton * template_style_button_1;
    QPushButton * template_style_button_2;
    QPushButton * template_style_button_3;
    QPushButton * template_style_button_4;
    QPushButton * template_style_button_5;
    QPushButton * template_style_button_6;
    QPushButton * template_style_button_7;
    QPushButton * template_style_button_8;
    QPushButton * template_style_button_9;
    QPushButton * template_style_button_10;
    QComboBox * template_count;
    QPushButton * back_button_5;
                                                        //  all visual elements located in language tray
    QPushButton * send_horizontal_button;
    QPushButton * send_vertical_button;
    QPushButton * send_diagonal_button;
    QPushButton * send_all_button;
    QComboBox * custom_languages;
    QPushButton * change_button;
    QPushButton * add_button;
    QPushButton * delete_button;
    QPushButton * back_button_6;
                                                        //  all visual elements located in vim tray
    QLineEdit * vim_prefix;
    QLineEdit * vim_edit;
    QLineEdit * vim_coordinates;
    QLineEdit * vim_position;
                                                        //  all visual elements located in projects tray
    QComboBox * language;
    QPushButton * new_project_button;
    QPushButton * open_project_button;
    QPushButton * source_button;
    QPushButton * delete_button_2;
    QComboBox * projects;
    QPushButton * class_tree_button;
    QPushButton * makefile_button;
    QPushButton * toggle_button;
    QPushButton * delete_button_3;
    QComboBox * source_files;
    QPushButton * run_button;
    QPushButton * build_button;
    QPushButton * clean_button;
    QPushButton * back_button_7;
                                                        //  all visual elements located in parameters tray
    QLineEdit * run_parameters;
    QLineEdit * compile_parameters;
    QLineEdit * make_parameters;
    QLineEdit * terminal_name;
    QPushButton * back_button_8;
                                                        //  all visual elements located in main tray
    QComboBox * files;
    QPushButton * save_button;
    QFileDialog * file_dialog;
    QPushButton * open_button;
    QPushButton * new_tab_button;
    QPushButton * close_tab_button;
    QComboBox * font_size;
    QPushButton * template_button;
    QPushButton * comments_button;
    QPushButton * paint_button;
    QPushButton * theme_button;
    QComboBox * languages;
    QPushButton * file_button;
    QPushButton * project_button;
    QPushButton * fullscreen_button;
    QPushButton * menu_button;

    bool bold_flag;                                     //  holds if bold font is active for text editor
    bool italic_flag;                                   //  holds if italic font is active for text editor
    bool regex_flag;                                    //  holds if searching using regular expression is active for text editor
    bool case_flag;                                     //  holds if case sensitive searching is active for text editor
    bool boundary_flag;                                 //  holds if searching whole words is active for text editor

    bool interface_visible;
                                                        //  flags which holds if concrete tray is activated
    bool theme_tray_visible;
    bool file_tray_visible;
    bool paint_tray_visible;
    bool actions_tray_visible;
    bool find_tray_visible;
    bool template_tray_visible;
    bool language_tray_visible;
    bool vim_tray_visible;
    bool projects_tray_visible;
    bool parameters_tray_visible;
    bool tray_visible;
    bool help_flag;                                     //  holds if help screen is activated
    bool language_flag;                                 //  holds if language screen is activated
    bool class_tree_visible;                            //  holds if class tree tray is activated

    bool vim_visual_flag;                               //  holds if visual mode is active during usage of Vim mode
    bool vim_replace_flag;                              //  holds if replace mode is active during usage of Vim mode
    QString vim_character_queue;                        //  queue of prefix characters of one Vim command
    QString vim_find_pattern;                           //  holds search pattern of Vim mode

    QFileSystemWatcher * files_watcher;                 //  file system watcher to detect background change of content of desired file opened in editor

    QList<Class_tree_parent> class_tree_parents;        //  holds description of all class items in actual content of class tree


    /// Redefine reactions for click to particular keys
    ///
    /// @param
    /// Generic Qt key press event handler
    void keyPressEvent(QKeyEvent *);


    /// Initialize all color palettes
    ///
    /// @param
    /// Integer value which represents color theme
    void init_palette(int);


    /// Initialize visual interface of text editor
    void init_interface();


    /// Initialize all tabs of text editor
    void init_tabs();
                                                        //  all methods to show concrete tray of interface

    /// Show theme tray in bottom navigation bar
    void show_theme_tray();


    /// Show file tray in bottom navigation bar
    void show_file_tray();


    /// Show paint tray in bottom navigation bar
    void show_paint_tray();


    /// Show actions tray in bottom navigation bar
    void show_actions_tray();


    /// Show find tray in bottom navigation bar
    void show_find_tray();


    /// Show template tray in bottom navigation bar
    void show_template_tray();


    /// Show language tray in bottom navigation bar
    void show_language_tray();


    /// Show Vim tray in bottom navigation bar
    void show_vim_tray();


    /// Show projects tray in bottom navigation bar
    void show_projects_tray();


    /// Show parameters tray in bottom navigation bar
    void show_parameters_tray();


    /// Show main tray in bottom navigation bar
    void show_tray();
                                                        //  all methods to hide concrete tray of interface

    /// Hide theme tray in bottom navigation bar
    void hide_theme_tray();


    /// Hide file tray in bottom navigation bar
    void hide_file_tray();


    /// Hide paint tray in bottom navigation bar
    void hide_paint_tray();


    /// Hide actions tray in bottom navigation bar
    void hide_actions_tray();


    /// Hide find tray in bottom navigation bar
    void hide_find_tray();


    /// Hide template tray in bottom navigation bar
    void hide_template_tray();


    /// Hide language tray in bottom navigation bar
    void hide_language_tray();


    /// Hide Vim tray in bottom navigation bar
    void hide_vim_tray();


    /// Hide projects tray in bottom navigation bar
    void hide_projects_tray();


    /// Hide parameters tray in bottom navigation bar
    void hide_parameters_tray();


    /// Hide main tray in bottom navigation bar
    void hide_tray();


    /// Recognize language text file by file extension or by parsing file content
    ///
    /// @param String parameter which represents file name
    int recognize_language(QString &);


    /// Check if file path is valid
    ///
    /// @param  String parameter which represents file path
    bool check_file_path(QString &);


    /// Remove trailing file extension from filename or file path
    ///
    /// @param  String parameter which represents file path
    QString remove_file_extension(QString &);


    /// Get just filename from full path to file
    ///
    /// @param  String parameter which represents file path
    QString get_filename_from_file_path(QString &);


    /// Get just directory from full path to file
    ///
    /// @param  String parameter which represents file path
    QString get_directory_from_file_path(QString &);


    /// Remove all comments and quotation from source code string
    ///
    /// @param  Desired string content
    /// @param  Language of content
    void remove_comments_and_quotation(QString &, int &);


    /// Refresh all present extra selections in tab content
    ///
    /// @param  Integer value which represents tabs index of file
    void refresh_extra_selections(int);


    /// Enable or disable undo and redo buttons by availability of these operations
    void refresh_undo_redo_buttons();


    /// Find language inside languages list by name string
    ///
    /// @param  Name of language as a string
    int find_language(QString &);


    /// Get language saved on desired index
    ///
    /// @param  Return language type instance
    /// @param  Integer index of language
    void get_language(Language &, int);


    /// Add new language into languages list
    ///
    /// @param  Return language type instance
    void push_language(Language &);


    /// Replace language on desired index
    ///
    /// @param  Return language type instance
    /// @param  Integer index of language
    void update_language(Language &, int);


    /// Remove language on desired index
    ///
    /// @param  Integer index of language
    void remove_language(int);

public slots:
    /// Reaction to application exit
    void handle_exit();


    /// Reaction to fullscreen toggle
    void handle_fullscreen();


    /// Reaction to change of layout
    ///
    /// @param  Integer index of text editor in window
    void handle_layouts(int);


    /// Get language from another layout
    ///
    /// @param  Return language type instance
    void receive_language(Language &);

private slots:
    /// Handle exit of text editor
    void exit_editor();


    /// Slot method to handle cursor movement timeout
    void handle_cursor_timeout();


    /// Slot method to handle text content change timeout
    void handle_text_change_timeout();


    /// Slot method to handle change of document slider position
    void slider_position_changed();


    /// Slot method to handle change of text cursor position
    void cursor_position_changed();


    /// Slot method to handle change of text editor content
    void editor_text_changed();


    /// Slot method to handle press event of clickable label object
    ///
    /// @param  Integer identifier of clickable label
    void clickable_label_pressed(int);


    /// Slot method to handle enter event of clickable label object
    ///
    /// @param  Integer identifier of clickable label
    void clickable_label_entered(int);
                                                        //  slot methods for all visual elements in file tray
    /// Handle press of undo button
    void undo_button_pressed();


    /// Handle press of redo button
    void redo_button_pressed();


    /// Handle press of save all button
    void save_all_button_pressed();


    /// Handle press of scroll bars button
    void scroll_bars_button_pressed();


    /// Handle press of reload button
    void reload_button_pressed();


    /// Handle selection of tab width
    ///
    /// @param  Tab width specified as an integer value
    void tab_width_selected(int);


    /// Handle selection of window layout
    ///
    /// @param  Integer index of layout
    void layout_selected(int);


    /// Handle press of first back button
    void back_button_pressed();
                                                        //  slot methods for all visual elements in paint tray

    /// Handle press of color button
    void color_button_pressed();


    /// Handle press of apply button
    void apply_button_pressed();


    /// Handle press of rubber button
    void rubber_button_pressed();


    /// Handle press of second undo button
    void undo_button_2_pressed();


    /// Handle press of clear button
    void clear_button_pressed();


    /// Handle press of second back button
    void back_button_2_pressed();
                                                        //  slot methods for all visual elements in actions tray

    /// Handle press of find button
    void find_button_pressed();


    /// Handle press of swap line up button
    void swap_line_up_button_pressed();


    /// Handle press of swap line down button
    void swap_line_down_button_pressed();


    /// Handle press of upper case button
    void upper_case_button_pressed();


    /// Handle press of lower case button
    void lower_case_button_pressed();


    /// Handle press of swap case button
    void swap_case_button_pressed();


    /// Handle press of bold button
    void bold_button_pressed();


    /// Handle press of italic button
    void italic_button_pressed();


    /// Handle press of Vim button
    void vim_button_pressed();


    /// Handle press of concept button
    void concept_button_pressed();


    /// Handle press of help button
    void help_button_pressed();


    /// Handle press of third back button
    void back_button_3_pressed();
                                                        //  slot methods for all visual elements in find tray

    /// Handle press of find previous button
    void find_previous_button_pressed();


    /// Handle press of find next button
    void find_next_button_pressed();


    /// Handle press of replace button
    void replace_button_pressed();


    /// Handle press of replace all button
    void replace_all_button_pressed();


    /// Handle press of regex button
    void regex_button_pressed();


    /// Handle press of case button
    void case_button_pressed();


    /// Handle press of boundary button
    void boundary_button_pressed();


    /// Handle press of fourth back button
    void back_button_4_pressed();
                                                        //  slot methods for all visual elements in template tray

    /// Handle press of first template button
    void template_style_button_1_pressed();


    /// Handle press of second template button
    void template_style_button_2_pressed();


    /// Handle press of third template button
    void template_style_button_3_pressed();


    /// Handle press of fourth templatebutton
    void template_style_button_4_pressed();


    /// Handle press of fifth templatebutton
    void template_style_button_5_pressed();


    /// Handle press of sixth template button
    void template_style_button_6_pressed();


    /// Handle press of seventh template button
    void template_style_button_7_pressed();


    /// Handle press of eighth template button
    void template_style_button_8_pressed();


    /// Handle press of ninth template button
    void template_style_button_9_pressed();


    /// Handle press of tenth template button
    void template_style_button_10_pressed();


    /// Handle press of fifth back button
    void back_button_5_pressed();
                                                        //  slot methods for all visual elements in language tray

    /// Handle press of horizontal send button
    void send_horizontal_button_pressed();


    /// Handle press of vertical send button
    void send_vertical_button_pressed();


    /// Handle press of diagonal send button
    void send_diagonal_button_pressed();


    /// Handle press of save all button
    void send_all_button_pressed();


    /// Handle press of change button
    void change_button_pressed();


    /// Handle press of add button
    void add_button_pressed();


    /// Handle press of delete button
    void delete_button_pressed();


    /// Handle press of sixth back button
    void back_button_6_pressed();
                                                        //  slot methods for all visual elements in vim tray

    /// Handle press of Vim accept button
    void vim_edit_accepted();
                                                        //  slot methods for all visual elements in projects tray

    /// Handle selection of project language
    ///
    /// @param  Integer index of project language
    void project_language_selected(int);


    /// Handle press of new project button
    void new_project_button_pressed();


    /// Handle press of open project button
    void open_project_button_pressed();


    /// Handle press of source button
    void source_button_pressed();


    /// Handle press of second delete button
    void delete_button_2_pressed();


    /// Handle selection of project
    ///
    /// @param  Index of concrete project as an integer value
    void project_selected(int);


    /// Handle press of class tree button
    void class_tree_button_pressed();


    /// Handle press of Makefile button
    void makefile_button_pressed();


    /// Handle press of parameters toggle button
    void toggle_button_pressed();


    /// Handle press of third delete button
    void delete_button_3_pressed();


    /// Handle press of run button
    void run_button_pressed();


    /// Handle press of build button
    void build_button_pressed();


    /// Handle press of clean button
    void clean_button_pressed();


    /// Handle press of seventh back button
    void back_button_7_pressed();
                                                        //  slot methods for all visual elements in parameters tray

    /// Handle press of eighth back button
    void back_button_8_pressed();
                                                        //  slot methods for all visual elements in main tray

    /// Handle selection of active file
    ///
    /// @param  Index of concrete file as an integer
    void file_selected(int);


    /// Handle press of save button
    void save_button_pressed();


    /// Handle press of open button
    void open_button_pressed();


    /// Handle press of new tab button
    void new_tab_button_pressed();


    /// Handle press of close tab button
    void close_tab_button_pressed();


    /// Handle selection of font size
    ///
    /// @param  Index of font size as an integer value
    void font_size_selected(int);


    /// Handle press of template button
    void template_button_pressed();


    /// Handle press of comments button
    void comments_button_pressed();


    /// Handle press of paint button
    void paint_button_pressed();


    /// Handle press of theme button
    void theme_button_pressed();


    /// Handle selection of active file language
    ///
    /// @param  Index of concrete language as an integer value
    void language_selected(int);


    /// Handle press of file button
    void file_button_pressed();


    /// Handle press of project button
    void project_button_pressed();


    /// Handle press of menu button
    void menu_button_pressed();


    /// Handle press of fullscreen button
    void fullscreen_button_pressed();


    /// Handle background change of file
    ///
    /// @param  Changed file is specified using its path as a string value
    void handle_file_change(const QString &);           //  slot to handle background content change of file opened in text editor
                                                        //  slot methods for reaction to special keyboard shortcuts sent from code editor

    /// Handle press of direct find button
    void find_now();


    /// Handle press of comment toggle button
    void toggle_comment();


    /// Handle press of font increase button
    void increase_font_size();


    /// Handle press of font decrease button
    void decrease_font_size();


    /// Handle press of move tab up button
    void move_tab_up();


    /// Handle press of move tab down button
    void move_tab_down();


    /// Handle press of scrollbar up button
    void move_scrollbar_up();


    /// Handle press of scrollbar down button
    void move_scrollbar_down();


    /// Handle press of tab key and insert appropriate indentiation to text file
    void handle_tab_press();


    /// Handle press of untab button and remove appropriate indentiation from text file
    void handle_shift_tab_press();


    /// Handle press of return key
    void handle_enter_press();


    /// Handle press of classic bracket key
    void handle_classic_bracket_press();


    /// Handle press of block bracket key
    void handle_block_bracket_press();


    /// Handle press of array bracket key
    void handle_array_bracket_press();


    /// Check if keyword represents C language keyword
    ///
    /// @param  Keyword is represented as a string value
    bool is_c99_keyword(QString &);


    /// Check if keyword represents C++ language keyword
    ///
    /// @param  Keyword is represented as a string value
    bool is_cplusplus_keyword(QString &);


    /// Check if keyword represents Java language keyword
    ///
    /// @param  Keyword is represented as a string value
    bool is_java_keyword(QString &);


    /// Check if keyword represents PHP language keyword
    ///
    /// @param  Keyword is represented as a string value
    bool is_php_keyword(QString &);


    /// Check if keyword represents Python language keyword
    ///
    /// @param  Keyword is represented as a string value
    bool is_python_keyword(QString &);


    /// Check if desired element is correct due to the C++ language syntax
    ///
    /// @param  Class element is represented as a string value
    bool check_class_element(QString &);


    /// Find to which file coresponds desired line number
    ///
    /// @param  Integer value of concrete position inside source code
    int find_appropriate_index(int &);


    /// Jump to appropriate location in code of desired class tree item(declaration item)
    ///
    /// @param  Model index of tree widget
    void class_tree_item_left_clicked(QModelIndex);


    /// Jump to appropriate location in code of desired class tree item(definition item)
    ///
    /// @param  Model index of tree widget
    void class_tree_item_right_clicked(QModelIndex);


    /// Refresh content of class tree by the actual file in text editor tabs
    void refresh_class_tree();


    /// Reaction to key press in Vim mode with description of key in parameters
    ///
    /// @param  Integer representation of concrete key
    /// @param  String representation of concrete key
    void vim_key_press(int, QString);


    /// Handle save of new user language
    void language_saved();


    /// Handle cancel of new user language
    void language_canceled();

signals:
    /// Signal which represents toggle of fullscreen mode
    void fullscreen_signal();


    /// Signal which represents direct exit signal of application
    void exit_signal();


    /// Signal which represents change of window layout
    ///
    /// @param  Index of concrete text editor in window
    void layout_signal(int);


    /// Signal which represents sending existing language to another text editor
    ///
    /// @param  Index of concrete text editor in window
    void send_language_signal(int, Language);
};

#endif // SPADE_H
