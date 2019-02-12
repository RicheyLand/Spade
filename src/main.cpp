#include "window.h"


/// Main function of application to allow start of program
///
/// @param  Integer value holds number of application parameters
/// @param  Second parameter is pointer to pointer where application parameters are saved
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window * w = new Window;
    w->show();

    for (int i = 1; i < argc; i++)
        w->push_parameter(argv[i]);

    if (argc > 1)
        w->handle_parameters();

    return a.exec();
}
