#include "highlighter.h"


/// Returns appropriate color for selected combination of language a color theme
///
/// @param  Integer index in color themes
/// @param  Integer index of concrete color
/// @param  Holds if comments are visible
/// @param  Holds if returned color coresponds to the comment
QColor return_color(int & theme, int color_index, bool & comments_visible, bool is_comment)
{
    if (comments_visible == false && is_comment)
    {
        switch (theme)
        {
            case 0:
                return QColor(38, 38, 38);
                break;
            case 1:
                return QColor(253, 246, 227);
                break;
            case 2:
                return QColor(0, 0, 0);
                break;
            case 3:
                return QColor(242, 241, 240);
                break;
            case 4:
                return QColor(2, 9, 28);
                break;
            default:
                return QColor(255, 255, 255);
                break;
        }
    }

    switch (theme)
    {
        case 0:
            switch (color_index)
            {
                case 0:
                    return QColor(0, 255, 127);
                    break;
                case 1:
                    return QColor(255, 215, 0);
                    break;
                case 2:
                    return QColor(0, 210, 255);
                    break;
                case 3:
                    return QColor(255, 20, 147);
                    break;
                case 4:
                    return QColor(255, 211, 155);
                    break;
                case 5:
                    return QColor(245, 140, 0);
                    break;
                default:
                    return QColor(109, 105, 87);
                    break;
            }

            break;
        case 1:
            switch (color_index)
            {
                case 0:
                    return QColor(0, 150, 0);
                    break;
                case 1:
                    return QColor(0, 110, 255);
                    break;
                case 2:
                    return QColor(170, 0, 255);
                    break;
                case 3:
                    return QColor(225, 55, 0);
                    break;
                case 4:
                    return QColor(220, 20, 60);
                    break;
                case 5:
                    return QColor(139, 0, 0);
                    break;
                default:
                    return QColor(150, 150, 150);
                    break;
            }

            break;
        case 2:
            switch (color_index)
            {
                case 0:
                    return QColor(0, 210, 255);
                    break;
                case 1:
                    return QColor(255, 20, 147);
                    break;
                case 2:
                    return QColor(255, 215, 0);
                    break;
                case 3:
                    return QColor(0, 255, 127);
                    break;
                case 4:
                    return QColor(255, 211, 155);
                    break;
                case 5:
                    return QColor(245, 140, 0);
                    break;
                default:
                    return QColor(170, 170, 170);
                    break;
            }

            break;
        case 3:
            switch (color_index)
            {
                case 0:
                    return QColor(0, 150, 0);
                    break;
                case 1:
                    return QColor(200, 0, 0);
                    break;
                case 2:
                    return QColor(170, 0, 200);
                    break;
                case 3:
                    return QColor(0, 110, 255);
                    break;
                case 4:
                    return QColor(199, 97, 20);
                    break;
                case 5:
                    return QColor(240, 0, 0);
                    break;
                default:
                    return QColor(160, 160, 160);
                    break;
            }

            break;
        case 4:
            switch (color_index)
            {
                case 0:
                    return QColor(255, 20, 60);
                    break;
                case 1:
                    return QColor(255, 255, 255);
                    break;
                case 2:
                    return QColor(127, 255, 0);
                    break;
                case 3:
                    return QColor(255, 215, 0);
                    break;
                case 4:
                    return QColor(255, 211, 155);
                    break;
                case 5:
                    return QColor(30, 144, 255);
                    break;
                default:
                    return QColor(110, 110, 110);
                    break;
            }

            break;
        default:
            switch (color_index)
            {
                case 0:
                    return QColor(220, 20, 60);
                    break;
                case 1:
                    return QColor(0, 0, 0);
                    break;
                case 2:
                    return QColor(0, 160, 0);
                    break;
                case 3:
                    return QColor(0, 110, 255);
                    break;
                case 4:
                    return QColor(199, 80, 0);
                    break;
                case 5:
                    return QColor(139, 0, 0);
                    break;
                default:
                    return QColor(230, 190, 148);
                    break;
            }

            break;
    }

    return QColor(0, 0, 0);
}


/// Class constructor
///
/// @param  Language type for user language cases
/// @param  Language index
/// @param  Holds if comments are visible
/// @param  Holds actual color theme of language
/// @param  Parent text document
RichHighlighter::RichHighlighter(QTextDocument * parent) : QSyntaxHighlighter(parent)
{
    language = plain_text;
}

void RichHighlighter::applyRules(Language * user_language, int _language, bool comments, int theme)
{
    highlighting_rules.clear();
    language = _language;

    if (language == c99)
    {
        HighlightingRule rule;                              //  single instance of highlighting rule

//        rule.pattern = QRegularExpression("(?<include)([ \t]*[<][^\n]*[>])");  //  regular expression to parse text in include quotes
//        rule.format.setForeground(return_color(theme, 4, comments, false));
//        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("\\b(((0b|0B)[01]*)|((0x|0X){0,1}[0-9]*\\.?[0-9]+([eE][+-]?[0-9]+)?|[0-9]+\\.?[0-9]*([eE][+-]?[0-9]+)?))\\b");
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 2, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        QStringList type_patterns;                          //  string list of standard C99 types
        type_patterns << "\\bauto\\b"                       //  fill string list by all standard C99 types
                    << "\\bchar\\b"
                    << "\\bbool\\b"
                    << "\\bdouble\\b"
                    << "\\benum\\b"
                    << "\\bfloat\\b"
                    << "\\bint\\b"
                    << "\\blong\\b"
                    << "\\bshort\\b"
                    << "\\bsigned\\b"
                    << "\\bstruct\\b"
                    << "\\btypedef\\b"
                    << "\\bunion\\b"
                    << "\\bunsigned\\b"
                    << "\\bvoid\\b";

        foreach (const QString &pattern, type_patterns)     //  iterate through string list of standard C99 types
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 0, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList keyword_patterns;                       //  string list of C99 keywords
        keyword_patterns << "\\bbreak\\b"                   //  fill string list by all C99 keywords
                        << "\\bcase\\b"
                        << "\\bconst\\b"
                        << "\\bcontinue\\b"
                        << "\\bdefault\\b"
                        << "\\bdo\\b"
                        << "\\belse\\b"
                        << "\\bextern\\b"
                        << "\\bfor\\b"
                        << "\\bgoto\\b"
                        << "\\bif\\b"
                        << "\\binline\\b"
                        << "\\bregister\\b"
                        << "\\brestrict\\b"
                        << "\\breturn\\b"
                        << "\\bsizeof\\b"
                        << "\\bstatic\\b"
                        << "\\bswitch\\b"
                        << "\\bvolatile\\b"
                        << "\\bwhile\\b"
                        << "\\B#include\\b"
                        << "\\B#define\\b"
                        << "\\B#undef\\b"
                        << "\\B#if\\b"
                        << "\\B#ifdef\\b"
                        << "\\B#ifndef\\b"
                        << "\\B#error\\b"
                        << "\\B#pragma\\b";

        foreach (const QString &pattern, keyword_patterns)  //  iterate through string list of C99 keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 1, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList nullptr_patterns;                       //  string list next three C99 keywords
        nullptr_patterns << "\\bNULL\\b" << "\\btrue\\b" << "\\bfalse\\b";   //  fill string list by next three C99 keywords

        foreach (const QString &pattern, nullptr_patterns)  //  iterate through string list of next three C99 keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 2, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        rule.pattern = QRegularExpression("[A-Za-z_][A-Za-z0-9_]*(?=\\s*\\()");  //  regular expression to parse C99 function or method identifier
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 3, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("'(\\\\.|[^'])*'");   //  regular expression to parse text in single quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("\"(\\\\.|[^\"])*\"");    //  regular expression to parse text in double quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("//[^\n]*");      //  regular expression to parse single line comments
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("/\\*.*?\\*/");   //  regular expression to parse multi line comments on single line
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        multi_line_comment_format.setForeground(return_color(theme, 6, comments, true));

        comment_start_expression = QRegularExpression("/\\*");  //  regular expression for beginning of multiple line comment
        comment_start_expression.optimize();
        comment_end_expression = QRegularExpression("\\*/");    //  regular expression for end of multiple line comment
        comment_end_expression.optimize();
    }
    else if (language == cplusplus)
    {
        HighlightingRule rule;                              //  single instance of highlighting rule

//        rule.pattern = QRegularExpression("(?<include)([ \t]*[<][^\n]*[>])");  //  regular expression to parse text in include quotes
//        rule.pattern.optimize();
//        rule.format.setForeground(return_color(theme, 4, comments, false));
//        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("\\b(((0b|0B)[01]*)|((0x|0X){0,1}[0-9]*\\.?[0-9]+([eE][+-]?[0-9]+)?|[0-9]+\\.?[0-9]*([eE][+-]?[0-9]+)?))\\b");
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 2, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        QStringList type_patterns;                          //  string list of standard C++ types
        type_patterns << "\\bdouble\\b"                     //  fill string list by all standard C++ types
                    << "\\bfloat\\b"
                    << "\\bint\\b"
                    << "\\bchar\\b"
                    << "\\bchar16_t\\b"
                    << "\\bchar32_t\\b"
                    << "\\bbool\\b"
                    << "\\blong\\b"
                    << "\\bshort\\b"
                    << "\\bwchar_t\\b"
                    << "\\bauto\\b"
                    << "\\bsigned\\b"
                    << "\\bunsigned\\b"
                    << "\\bclass\\b"
                    << "\\bstruct\\b"
                    << "\\bunion\\b"
                    << "\\benum\\b"
                    << "\\bvoid\\b"
                    << "\\btemplate\\b"
                    << "\\basm\\b"
                    << "\\btypedef\\b";

        foreach (const QString &pattern, type_patterns)     //  iterate through string list of standard C++ types
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 0, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList keyword_patterns;                       //  string list of C++ keywords
        keyword_patterns << "\\balignas\\b"                 //  fill string list by all C++ keywords
                        << "\\balignof\\b"
                        << "\\band\\b"
                        << "\\band_eq\\b"
                        << "\\batomic_cancel\\b"
                        << "\\batomic_commit\\b"
                        << "\\batomic_noexcept\\b"
                        << "\\bbitand\\b"
                        << "\\bbitor\\b"
                        << "\\bbreak\\b"
                        << "\\bcatch\\b"
                        << "\\bcompl\\b"
                        << "\\bconcept\\b"
                        << "\\bconst\\b"
                        << "\\bconstexpr\\b"
                        << "\\bconst_cast\\b"
                        << "\\bcontinue\\b"
                        << "\\bdecltype\\b"
                        << "\\bdelete\\b"
                        << "\\bdynamic_cast\\b"
                        << "\\bexport\\b"
                        << "\\bextern\\b"
                        << "\\bfriend\\b"
                        << "\\bgoto\\b"
                        << "\\bexplicit\\b"
                        << "\\binline\\b"
                        << "\\bregister\\b"
                        << "\\bvolatile\\b"
                        << "\\bimport\\b"
                        << "\\bmodule\\b"
                        << "\\bmutable\\b"
                        << "\\bnamespace\\b"
                        << "\\bnew\\b"
                        << "\\bnoexcept\\b"
                        << "\\bnot\\b"
                        << "\\bnot_eq\\b"
                        << "\\boperator\\b"
                        << "\\bor\\b"
                        << "\\bor_eq\\b"
                        << "\\bprivate\\b"
                        << "\\bprotected\\b"
                        << "\\bpublic\\b"
                        << "\\breinterpret_cast\\b"
                        << "\\brequires\\b"
                        << "\\breturn\\b"
                        << "\\bsizeof\\b"
                        << "\\bstatic\\b"
                        << "\\bstatic_assert\\b"
                        << "\\bstatic_cast\\b"
                        << "\\bsynchronized\\b"
                        << "\\bthread_local\\b"
                        << "\\bthrow\\b"
                        << "\\btry\\b"
                        << "\\btypeid\\b"
                        << "\\btypename\\b"
                        << "\\busing\\b"
                        << "\\bvirtual\\b"
                        << "\\bxor\\b"
                        << "\\bxor_eq\\b"
                        << "\\bif\\b"
                        << "\\belse\\b"
                        << "\\bswitch\\b"
                        << "\\bcase\\b"
                        << "\\bdefault\\b"
                        << "\\bdo\\b"
                        << "\\bfor\\b"
                        << "\\bwhile\\b"
                        << "\\boverride\\b"
                        << "\\B#if\\b"
                        << "\\B#elif\\b"
                        << "\\B#else\\b"
                        << "\\B#endif\\b"
                        << "\\B#defined\\b"
                        << "\\B#ifdef\\b"
                        << "\\B#ifndef\\b"
                        << "\\B#define\\b"
                        << "\\B#undef\\b"
                        << "\\B#include\\b"
                        << "\\B#line\\b"
                        << "\\B#error\\b"
                        << "\\B#pragma\\b";

        foreach (const QString &pattern, keyword_patterns)  //  iterate through string list of C++ keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 1, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList rest_patterns;                          //  string list of C++ keywords
        rest_patterns << "\\bthis\\b";

        foreach (const QString &pattern, rest_patterns)     //  iterate through string list of C++ keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 5, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList nullptr_patterns;                       //  string list next three C++ keywords
        nullptr_patterns << "\\bnullptr\\b" << "\\bNULL\\b" << "\\btrue\\b" << "\\bfalse\\b";   //  fill string list by next three C++ keywords

        foreach (const QString &pattern, nullptr_patterns)  //  iterate through string list of next three C++ keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 2, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        rule.pattern = QRegularExpression("[A-Za-z_][A-Za-z0-9_]*(?=\\s*\\()");  //  regular expression to parse C++ function or method identifier
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 3, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("'(\\\\.|[^'])*'");   //  regular expression to parse text in single quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("\"(\\\\.|[^\"])*\"");    //  regular expression to parse text in double quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("//[^\n]*");      //  regular expression to parse single line comments
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("/\\*.*?\\*/");   //  regular expression to parse multi line comments on single line
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        multi_line_comment_format.setForeground(return_color(theme, 6, comments, true));

        comment_start_expression = QRegularExpression("/\\*");  //  regular expression for beginning of multiple line comment
        comment_start_expression.optimize();
        comment_end_expression = QRegularExpression("\\*/");    //  regular expression for end of multiple line comment
        comment_end_expression.optimize();
    }
    else if (language == java)
    {
        HighlightingRule rule;                              //  single instance of highlighting rule

        rule.pattern = QRegularExpression("\\b(((0b|0B)[01]*)|((0x|0X){0,1}[0-9]*\\.?[0-9]+([eE][+-]?[0-9]+)?|[0-9]+\\.?[0-9]*([eE][+-]?[0-9]+)?))\\b");
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 2, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        QStringList type_patterns;                          //  string list of standard Java types
        type_patterns << "\\bboolean\\b"                    //  fill string list by all standard Java types
                    << "\\bdouble\\b"
                    << "\\bbyte\\b"
                    << "\\bclass\\b"
                    << "\\benum\\b"
                    << "\\binterface\\b"
                    << "\\bint\\b"
                    << "\\bshort\\b"
                    << "\\bchar\\b"
                    << "\\bvoid\\b"
                    << "\\blong\\b"
                    << "\\bvolatile\\b"
                    << "\\bconst\\b"
                    << "\\bfloat\\b";

        foreach (const QString &pattern, type_patterns)     //  iterate through string list of standard Java types
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 0, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList keyword_patterns;                       //  string list of Java keywords
        keyword_patterns << "\\babstract\\b"                //  fill string list by all Java keywords
                        << "\\bcontinue\\b"
                        << "\\bfor\\b"
                        << "\\bnew\\b"
                        << "\\bswitch\\b"
                        << "\\bassert\\b"
                        << "\\bdefault\\b"
                        << "\\bgoto\\b"
                        << "\\bpackage\\b"
                        << "\\bsynchronized\\b"
                        << "\\bdo\\b"
                        << "\\bif\\b"
                        << "\\bprivate\\b"
                        << "\\bbreak\\b"
                        << "\\bprotected\\b"
                        << "\\bthrow\\b"
                        << "\\belse\\b"
                        << "\\bimport\\b"
                        << "\\bpublic\\b"
                        << "\\bcase\\b"
                        << "\\binstanceof\\b"
                        << "\\breturn\\b"
                        << "\\btransient\\b"
                        << "\\bcatch\\b"
                        << "\\btry\\b"
                        << "\\bfinal\\b"
                        << "\\bstatic\\b"
                        << "\\bfinally\\b"
                        << "\\bstrictfp\\b"
                        << "\\bnative\\b"
                        << "\\bwhile\\b"
                        << "\\bimplements\\b"
                        << "\\bthrows\\b"
                        << "\\bextends\\b";

        foreach (const QString &pattern, keyword_patterns)  //  iterate through string list of Java keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 1, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList rest_patterns;                          //  string list of Java keywords
        rest_patterns << "\\bthis\\b" << "\\bsuper\\b";

        foreach (const QString &pattern, rest_patterns)     //  iterate through string list of Java keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 5, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList nullptr_patterns;                       //  string list next four Java keywords
        nullptr_patterns << "\\bnull\\b" << "\\bNULL\\b" << "\\btrue\\b" << "\\bfalse\\b";   //  fill string list by next four Java keywords

        foreach (const QString &pattern, nullptr_patterns)  //  iterate through string list of next three Java keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 2, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        rule.pattern = QRegularExpression("[A-Za-z_][A-Za-z0-9_]*(?=\\s*\\()");  //  regular expression to parse Java function or method identifier
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 3, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("\\b[A-Z][A-Za-z0-9_]*\\b");  //  regular expression to parse Java data type
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 0, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("'(\\\\.|[^'])*'");   //  regular expression to parse text in single quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("\"(\\\\.|[^\"])*\"");    //  regular expression to parse text in double quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("//[^\n]*");      //  regular expression to parse single line comments
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("/\\*.*?\\*/");   //  regular expression to parse multi line comments on single line
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        multi_line_comment_format.setForeground(return_color(theme, 6, comments, true));

        comment_start_expression = QRegularExpression("/\\*");  //  regular expression for beginning of multiple line comment
        comment_start_expression.optimize();
        comment_end_expression = QRegularExpression("\\*/");    //  regular expression for end of multiple line comment
        comment_end_expression.optimize();
    }
    else if (language == javascript)
    {
        HighlightingRule rule;                              //  single instance of highlighting rule

        rule.pattern = QRegularExpression("\\b(((0b|0B)[01]*)|((0x|0X){0,1}[0-9]*\\.?[0-9]+([eE][+-]?[0-9]+)?|[0-9]+\\.?[0-9]*([eE][+-]?[0-9]+)?))\\b");
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 2, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        QStringList type_patterns;                          //  string list of standard JavaScript types
        type_patterns << "\\blong\\b"                       //  fill string list by all standard JavaScript types
                    << "\\bshort\\b"
                    << "\\bvar\\b"
                    << "\\bboolean\\b"
                    << "\\bbyte\\b"
                    << "\\bchar\\b"
                    << "\\bdouble\\b"
                    << "\\bfloat\\b"
                    << "\\bint\\b"
                    << "\\bclass\\b"
                    << "\\bconst\\b"
                    << "\\benum\\b"
                    << "\\binterface\\b"
                    << "\\bvolatile\\b"
                    << "\\bvoid\\b";

        foreach (const QString &pattern, type_patterns)     //  iterate through string list of standard JavaScript types
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 0, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList keyword_patterns;                       //  string list of JavaScript keywords
        keyword_patterns << "\\babstract\\b"                //  fill string list by all JavaScript keywords
                        << "\\barguments\\b"
                        << "\\bawait\\b"
                        << "\\bbreak\\b"
                        << "\\bcase\\b"
                        << "\\bcatch\\b"
                        << "\\bcontinue\\b"
                        << "\\bdebugger\\b"
                        << "\\bdefault\\b"
                        << "\\bdelete\\b"
                        << "\\bdo\\b"
                        << "\\belse\\b"
                        << "\\beval\\b"
                        << "\\bexport\\b"
                        << "\\bextends\\b"
                        << "\\bfinal\\b"
                        << "\\bfinally\\b"
                        << "\\bfor\\b"
                        << "\\bfunction\\b"
                        << "\\bgoto\\b"
                        << "\\bif\\b"
                        << "\\bimplements\\b"
                        << "\\bimport\\b"
                        << "\\bin\\b"
                        << "\\binstanceof\\b"
                        << "\\blet\\b"
                        << "\\bnative\\b"
                        << "\\bnew\\b"
                        << "\\bpackage\\b"
                        << "\\bprivate\\b"
                        << "\\bprotected\\b"
                        << "\\bpublic\\b"
                        << "\\breturn\\b"
                        << "\\bstatic\\b"
                        << "\\bswitch\\b"
                        << "\\bsynchronized\\b"
                        << "\\bthrow\\b"
                        << "\\bthrows\\b"
                        << "\\btransient\\b"
                        << "\\btry\\b"
                        << "\\btypeof\\b"
                        << "\\bwhile\\b"
                        << "\\bwith\\b"
                        << "\\byield\\b";

        foreach (const QString &pattern, keyword_patterns)  //  iterate through string list of JavaScript keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 1, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList rest_patterns;                          //  string list of JavaScript keywords
        rest_patterns << "\\bsuper\\b" << "\\bthis\\b";     //  string list of JavaScript keywords

        foreach (const QString &pattern, rest_patterns)     //  iterate through string list of JavaScript keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 5, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList nullptr_patterns;                       //  string list next four JavaScript keywords
        nullptr_patterns << "\\bfalse\\b" << "\\btrue\\b" << "\\bnull\\b";  //  string list next four JavaScript keywords

        foreach (const QString &pattern, nullptr_patterns)  //  iterate through string list of next three JavaScript keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 2, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        rule.pattern = QRegularExpression("[A-Za-z_][A-Za-z0-9_]*(?=\\s*\\()");  //  regular expression to parse JavaScript function or method identifier
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 3, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("\\b[A-Z][A-Za-z0-9_]*\\b");  //  regular expression to parse JavaScript data type
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 0, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("'(\\\\.|[^'])*'");   //  regular expression to parse text in single quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("\"(\\\\.|[^\"])*\"");    //  regular expression to parse text in double quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("//[^\n]*");      //  regular expression to parse single line comments
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("/\\*.*?\\*/");   //  regular expression to parse multi line comments on single line
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        multi_line_comment_format.setForeground(return_color(theme, 6, comments, true));

        comment_start_expression = QRegularExpression("/\\*");  //  regular expression for beginning of multiple line comment
        comment_start_expression.optimize();
        comment_end_expression = QRegularExpression("\\*/");    //  regular expression for end of multiple line comment
        comment_end_expression.optimize();
    }
    else if (language == php)
    {
        HighlightingRule rule;                              //  single instance of highlighting rule

        rule.pattern = QRegularExpression("\\b(((0b|0B)[01]*)|((0x|0X){0,1}[0-9]*\\.?[0-9]+([eE][+-]?[0-9]+)?|[0-9]+\\.?[0-9]*([eE][+-]?[0-9]+)?))\\b");
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 2, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        QStringList type_patterns;                          //  string list of standard PHP types
        type_patterns << "\\barray\\b"                      //  fill string list by all standard PHP types
                    << "\\bclass\\b"
                    << "\\bclone\\b"
                    << "\\becho\\b"
                    << "\\bfunction\\b"
                    << "\\binterface\\b"
                    << "\\bprint\\b"
                    << "\\bvar\\b"
                    << "\\bint\\b"
                    << "\\bfloat\\b"
                    << "\\bbool\\b"
                    << "\\bstring\\b"
                    << "\\bobject\\b"
                    << "\\bPHP_VERSION\\b"
                    << "\\bPHP_MAJOR_VERSION\\b"
                    << "\\bPHP_MINOR_VERSION\\b"
                    << "\\bPHP_RELEASE_VERSION\\b"
                    << "\\bPHP_VERSION_ID\\b"
                    << "\\bPHP_EXTRA_VERSION\\b"
                    << "\\bPHP_ZTS\\b"
                    << "\\bPHP_DEBUG\\b"
                    << "\\bPHP_MAXPATHLEN\\b"
                    << "\\bPHP_OS\\b"
                    << "\\bPHP_SAPI\\b"
                    << "\\bPHP_EOL\\b"
                    << "\\bPHP_INT_MAX\\b"
                    << "\\bPHP_INT_SIZE\\b"
                    << "\\bDEFAULT_INCLUDE_PATH\\b"
                    << "\\bPEAR_INSTALL_DIR\\b"
                    << "\\bPEAR_EXTENSION_DIR\\b"
                    << "\\bPHP_EXTENSION_DIR\\b"
                    << "\\bPHP_PREFIX\\b"
                    << "\\bPHP_BINDIR\\b"
                    << "\\bPHP_LIBDIR\\b"
                    << "\\bPHP_DATADIR\\b"
                    << "\\bPHP_SYSCONFDIR\\b"
                    << "\\bPHP_LOCALSTATEDIR\\b"
                    << "\\bPHP_CONFIG_FILE_PATH\\b"
                    << "\\bPHP_CONFIG_FILE_SCAN_DIR\\b"
                    << "\\bPHP_SHLIB_SUFFIX\\b"
                    << "\\bE_ERROR\\b"
                    << "\\bE_WARNING\\b"
                    << "\\bE_PARSE\\b"
                    << "\\bE_NOTICE\\b"
                    << "\\bE_CORE_ERROR\\b"
                    << "\\bE_CORE_WARNING\\b"
                    << "\\bE_COMPILE_ERROR\\b"
                    << "\\bE_COMPILE_WARNING\\b"
                    << "\\bE_USER_ERROR\\b"
                    << "\\bE_USER_WARNING\\b"
                    << "\\bE_USER_NOTICE\\b"
                    << "\\bE_RECOVERABLE_ERROR\\b"
                    << "\\bE_DEPRECATED\\b"
                    << "\\bE_USER_DEPRECATED\\b"
                    << "\\bE_ALL\\b"
                    << "\\bE_STRICT\\b"
                    << "\\b__COMPILER_HALT_OFFSET__\\b"
                    << "\\bSTDIN\\b"
                    << "\\bSTDOUT\\b"
                    << "\\bSTDERR\\b";

        foreach (const QString &pattern, type_patterns)     //  iterate through string list of standard PHP types
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 0, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList keyword_patterns;                       //  string list of PHP keywords
        keyword_patterns << "\\babstract\\b"                //  fill string list by all PHP keywords
                        << "\\band\\b"
                        << "\\bas\\b"
                        << "\\bbreak\\b"
                        << "\\bcase\\b"
                        << "\\bcatch\\b"
                        << "\\bconst\\b"
                        << "\\bcontinue\\b"
                        << "\\bdeclare\\b"
                        << "\\bdefault\\b"
                        << "\\bdie\\b"
                        << "\\bdo\\b"
                        << "\\belse\\b"
                        << "\\belseif\\b"
                        << "\\benddeclare\\b"
                        << "\\bendfor\\b"
                        << "\\bendforeach\\b"
                        << "\\bendif\\b"
                        << "\\bendswitch\\b"
                        << "\\bendwhile\\b"
                        << "\\bexit\\b"
                        << "\\bextends\\b"
                        << "\\bfinal\\b"
                        << "\\bfor\\b"
                        << "\\bforeach\\b"
                        << "\\bglobal\\b"
                        << "\\bif\\b"
                        << "\\bimplements\\b"
                        << "\\binclude\\b"
                        << "\\binclude_once\\b"
                        << "\\bnamespace\\b"
                        << "\\bnew\\b"
                        << "\\bor\\b"
                        << "\\bprivate\\b"
                        << "\\bprotected\\b"
                        << "\\bpublic\\b"
                        << "\\brequire\\b"
                        << "\\brequire_once\\b"
                        << "\\breturn\\b"
                        << "\\bstatic\\b"
                        << "\\bswitch\\b"
                        << "\\bthrow\\b"
                        << "\\btry\\b"
                        << "\\buse\\b"
                        << "\\bwhile\\b"
                        << "\\bxor\\b"
                        << "\\bstatic\\b";

        foreach (const QString &pattern, keyword_patterns)  //  iterate through string list of PHP keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 1, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList rest_patterns;                          //  string list of PHP keywords
        rest_patterns << "\\B[$]this\\b" << "\\bself\\b" << "\\bparent\\b";

        foreach (const QString &pattern, rest_patterns)     //  iterate through string list of PHP keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 5, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList nullptr_patterns;                       //  string list of next PHP keywords
        nullptr_patterns << "\\b__halt_compiler\\b"         //  fill string list by next PHP keywords
                        << "\\bcallable\\b"
                        << "\\bempty\\b"
                        << "\\beval\\b"
                        << "\\bgoto\\b"
                        << "\\binstanceof\\b"
                        << "\\binsteadof\\b"
                        << "\\bisset\\b"
                        << "\\blist\\b"
                        << "\\btrait\\b"
                        << "\\bunset\\b"
                        << "\\btrue\\b"
                        << "\\bfalse\\b"
                        << "\\bnull\\b"
                        << "\\bvoid\\b"
                        << "\\biterable\\b"
                        << "\\bresource\\b"
                        << "\\bmixed\\b"
                        << "\\bnumeric\\b"
                        << "\\bDirectory\\b"
                        << "\\bstdClass\\b"
                        << "\\b__PHP_Incomplete_Class\\b"
                        << "\\bException\\b"
                        << "\\bErrorException\\b"
                        << "\\bphp_user_filter\\b"
                        << "\\bArithmeticError\\b"
                        << "\\bAssertionError\\b"
                        << "\\bDivisionByZeroError\\b"
                        << "\\bError\\b"
                        << "\\bThrowable\\b"
                        << "\\bParseError\\b"
                        << "\\bTypeError\\b"
                        << "\\bPHP_OS_FAMILY\\b"
                        << "\\bPHP_INT_MIN\\b"
                        << "\\bPHP_FLOAT_DIG\\b"
                        << "\\bPHP_FLOAT_EPSILON\\b"
                        << "\\bPHP_FLOAT_MIN\\b"
                        << "\\bPHP_FLOAT_MAX\\b"
                        << "\\bPHP_BINARY\\b"
                        << "\\bPHP_MANDIR\\b"
                        << "\\bPHP_FD_SETSIZE\\b"
                        << "\\bTRUE\\b"
                        << "\\bFALSE\\b"
                        << "\\bNULL\\b";

        foreach (const QString &pattern, nullptr_patterns)  //  iterate through string list of next three PHP keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 2, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        rule.pattern = QRegularExpression("[A-Za-z_][A-Za-z0-9_]*(?=\\s*\\()");  //  regular expression to parse PHP function or method identifier
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 3, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("'(\\\\.|[^'])*'");   //  regular expression to parse text in single quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("\"(\\\\.|[^\"])*\"");    //  regular expression to parse text in double quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("#[^\n]*");       //  regular expression to parse single line comments
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("//[^\n]*");      //  regular expression to parse single line comments
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("/\\*.*?\\*/");   //  regular expression to parse multi line comments on single line
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        multi_line_comment_format.setForeground(return_color(theme, 6, comments, true));

        comment_start_expression = QRegularExpression("/\\*");  //  regular expression for beginning of multiple line comment
        comment_start_expression.optimize();
        comment_end_expression = QRegularExpression("\\*/");    //  regular expression for end of multiple line comment
        comment_end_expression.optimize();
    }
    else if (language == python)
    {
        HighlightingRule rule;                              //  single instance of highlighting rule

        rule.pattern = QRegularExpression("\\b(((0b|0B)[01]*)|((0x|0X){0,1}[0-9]*\\.?[0-9]+([eE][+-]?[0-9]+)?|[0-9]+\\.?[0-9]*([eE][+-]?[0-9]+)?))\\b");
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 2, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        QStringList type_patterns;                          //  string list of standard python types

        type_patterns << "\\bbool\\b"                       //  fill string list by all standard python types
                    << "\\bint\\b"
                    << "\\blong\\b"
                    << "\\bdouble\\b"
                    << "\\bfloat\\b"
                    << "\\bstr\\b"
                    << "\\bcomplex\\b"
                    << "\\bdict\\b"
                    << "\\bIndexError\\b"
                    << "\\bTypeError\\b"
                    << "\\bSyntaxError\\b"
                    << "\\bAttributeError\\b"
                    << "\\blist\\b";

        foreach (const QString &pattern, type_patterns)     //  iterate through string list of standard python types
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 0, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList keyword_patterns;                       //  string list of python keywords

        keyword_patterns << "\\band\\b"                     //  fill string list by all python keywords
                    << "\\band\\b"
                    << "\\bas\\b"
                    << "\\bassert\\b"
                    << "\\bbreak\\b"
                    << "\\bclass\\b"
                    << "\\bcontinue\\b"
                    << "\\bdef\\b"
                    << "\\bdel\\b"
                    << "\\belif\\b"
                    << "\\belse\\b"
                    << "\\bexcept\\b"
                    << "\\bfinally\\b"
                    << "\\bfor\\b"
                    << "\\bfrom\\b"
                    << "\\bglobal\\b"
                    << "\\bif\\b"
                    << "\\bimport\\b"
                    << "\\bin\\b"
                    << "\\bis\\b"
                    << "\\blambda\\b"
                    << "\\bnonlocal\\b"
                    << "\\bnot\\b"
                    << "\\bor\\b"
                    << "\\bpass\\b"
                    << "\\braise\\b"
                    << "\\breturn\\b"
                    << "\\bsuper\\b"
                    << "\\btry\\b"
                    << "\\bwhile\\b"
                    << "\\bwith\\b"
                    << "\\byield\\b";

        foreach (const QString &pattern, keyword_patterns)  //  iterate through string list of python keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 1, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList rest_patterns;                          //  string list of C++ keywords

        rest_patterns << "\\bself\\b";

        foreach (const QString &pattern, rest_patterns)     //  iterate through string list of C++ keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 5, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        QStringList nullptr_patterns;                       //  string list next three python keywords

        nullptr_patterns << "\\bNone\\b" << "\\bTrue\\b" << "\\bFalse\\b";   //  fill string list by next three python keywords

        foreach (const QString &pattern, nullptr_patterns)  //  iterate through string list of next three python keywords
        {
            rule.pattern = QRegularExpression(pattern);     //  set regular expression for new highlighting rule
            rule.pattern.optimize();
            rule.format.setForeground(return_color(theme, 2, comments, false));
            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        rule.pattern = QRegularExpression("[A-Za-z_][A-Za-z0-9_]*(?=\\s*\\()");  //  regular expression to parse python function or method identifier
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 3, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("'(\\\\.|[^'])*'");   //  regular expression to parse text in single quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("\"(\\\\.|[^\"])*\"");    //  regular expression to parse text in double quotes
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 4, comments, false));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("#[^\n]*");       //  regular expression to parse single line comments
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("\"\"\".*?\"\"\"");   //  regular expression to parse multi line comments on single line
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        rule.pattern = QRegularExpression("'''.*?'''");     //  regular expression to parse multi line comments on single line
        rule.pattern.optimize();
        rule.format.setForeground(return_color(theme, 6, comments, true));
        highlighting_rules.append(rule);                    //  push new highlighting rule

        multi_line_comment_format.setForeground(return_color(theme, 6, comments, true));    //  set color for multiple line comments
    }
    else if (language >= builtInLanguages)
    {
        HighlightingRule rule;                              //  single instance of highlighting rule
        int len = user_language->subElements.size();

        bool identifier = false;

        for (int i = 0; i < len; i++)
        {
            if (user_language->subElements[i].regex.size())
            {
                if (identifier)
                    rule.pattern = QRegularExpression("\\b" + user_language->subElements[i].regex + "\\b");
                else
                    rule.pattern = QRegularExpression(user_language->subElements[i].regex);

                rule.pattern.optimize();

                switch (theme)
                {
                    case 0:
                        rule.format.setForeground(return_color(theme, user_language->subElements[i].color_1, comments, false));
                        break;
                    case 1:
                        rule.format.setForeground(return_color(theme, user_language->subElements[i].color_2, comments, false));
                        break;
                    case 2:
                        rule.format.setForeground(return_color(theme, user_language->subElements[i].color_3, comments, false));
                        break;
                    case 3:
                        rule.format.setForeground(return_color(theme, user_language->subElements[i].color_4, comments, false));
                        break;
                    case 4:
                        rule.format.setForeground(return_color(theme, user_language->subElements[i].color_5, comments, false));
                        break;
                    default:
                        rule.format.setForeground(return_color(theme, user_language->subElements[i].color_6, comments, false));
                        break;
                }

                highlighting_rules.append(rule);                    //  push new highlighting rule
            }
            else
                identifier = !identifier;
        }

        len = user_language->comments.size();

        for (int i = 0; i < len; i++)
        {
            if (user_language->comments[i].from.size())
            {
                rule.pattern = QRegularExpression(QRegularExpression::escape(user_language->comments[i].from) + "[^\n]*");
                rule.pattern.optimize();

                switch (theme)
                {
                    case 0:
                        rule.format.setForeground(return_color(theme, user_language->comments[i].color_1, comments, true));
                        break;
                    case 1:
                        rule.format.setForeground(return_color(theme, user_language->comments[i].color_2, comments, true));
                        break;
                    case 2:
                        rule.format.setForeground(return_color(theme, user_language->comments[i].color_3, comments, true));
                        break;
                    case 3:
                        rule.format.setForeground(return_color(theme, user_language->comments[i].color_4, comments, true));
                        break;
                    case 4:
                        rule.format.setForeground(return_color(theme, user_language->comments[i].color_5, comments, true));
                        break;
                    default:
                        rule.format.setForeground(return_color(theme, user_language->comments[i].color_6, comments, true));
                        break;
                }

                highlighting_rules.append(rule);                    //  push new highlighting rule
            }
        }

        comment_start_expression = QRegularExpression(QRegularExpression::escape(user_language->multiline_comment_from));
        comment_start_expression.optimize();
        comment_end_expression = QRegularExpression(QRegularExpression::escape(user_language->multiline_comment_to));
        comment_end_expression.optimize();

        if (comment_start_expression.pattern().size() && comment_end_expression.pattern().size())
        {                                                   //  regular expression to parse multi line comments on single line
            rule.pattern = QRegularExpression(comment_start_expression.pattern() + ".*?" + comment_end_expression.pattern());
            rule.pattern.optimize();

            switch (theme)
            {
                case 0:
                    rule.format.setForeground(return_color(theme, user_language->multiline_comment_color_1, comments, true));
                    break;
                case 1:
                    rule.format.setForeground(return_color(theme, user_language->multiline_comment_color_2, comments, true));
                    break;
                case 2:
                    rule.format.setForeground(return_color(theme, user_language->multiline_comment_color_3, comments, true));
                    break;
                case 3:
                    rule.format.setForeground(return_color(theme, user_language->multiline_comment_color_4, comments, true));
                    break;
                case 4:
                    rule.format.setForeground(return_color(theme, user_language->multiline_comment_color_5, comments, true));
                    break;
                default:
                    rule.format.setForeground(return_color(theme, user_language->multiline_comment_color_6, comments, true));
                    break;
            }

            highlighting_rules.append(rule);                //  push new highlighting rule
        }

        switch (theme)
        {
            case 0:
                multi_line_comment_format.setForeground(return_color(theme, user_language->multiline_comment_color_1, comments, true));
                break;
            case 1:
                multi_line_comment_format.setForeground(return_color(theme, user_language->multiline_comment_color_2, comments, true));
                break;
            case 2:
                multi_line_comment_format.setForeground(return_color(theme, user_language->multiline_comment_color_3, comments, true));
                break;
            case 3:
                multi_line_comment_format.setForeground(return_color(theme, user_language->multiline_comment_color_4, comments, true));
                break;
            case 4:
                multi_line_comment_format.setForeground(return_color(theme, user_language->multiline_comment_color_5, comments, true));
                break;
            default:
                multi_line_comment_format.setForeground(return_color(theme, user_language->multiline_comment_color_6, comments, true));
                break;
        }
    }

    rehighlight();
}

/// Highlight desired words in line when it is changed inside text
///
/// @param  Content of changed line is accessed using string parameter
void RichHighlighter::highlightBlock(const QString &text)
{
    emit block_signal(currentBlock().blockNumber());

    if (language == c99 || language == cplusplus || language == java || language == javascript || language == php)
    {
        QString line = text;

        int N = highlighting_rules.size();
        QRegularExpression multi_line_regex("/\\*[^\n]*");
        multi_line_regex.optimize();
        QRegularExpressionMatch match;

        int offset = 0;

        while (true)
        {
            int index = -1;
            int from = -1;
            int to = -1;
            int len = -1;

            for (int i = 0; i < N; i++)
            {
                if (highlighting_rules[i].pattern.isValid())
                {
                    match = highlighting_rules[i].pattern.match(line, offset);

                    if (match.hasMatch())
                    {
                        int temp = match.capturedStart();

                        if (from == -1 || temp < from)
                        {
                            index = i;
                            from = temp;
                            to = match.capturedEnd();
                            len = match.capturedLength();
                        }
                    }
                }
            }

            if (multi_line_regex.isValid())
            {
                match = multi_line_regex.match(line);

                if (match.hasMatch())
                {
                    int temp = match.capturedStart();

                    if (from == -1 || temp < from)
                        break;
                }
            }

            if (from == -1)
                break;

            offset = from;

            setFormat(from, len, highlighting_rules[index].format);

            for (int j = from; j < to; j++)
                line[j] = ' ';
        }

        if (comment_start_expression.isValid() && comment_end_expression.isValid())     //  check if regular expressions are valid
        {
            setCurrentBlockState(0);                        //  set new state of current text block

            int startIndex = 0;                             //  holds start index value

            if (previousBlockState() != 1)                  //  check if last block state was not one
                startIndex = line.indexOf(comment_start_expression);    //  find pattern match in text editor content

            while (startIndex >= 0)                         //  repeat until pattern match found in text editor content
            {
                QRegularExpressionMatch match = comment_end_expression.match(line, startIndex);     //  find ending match from starting match position
                int endIndex = match.capturedStart();       //  holds length of multiple line comment
                int commentLength = 0;

                if (endIndex == -1)                         //  check if offset was not at last character
                {
                    setCurrentBlockState(1);                //  set new state of current text block
                    commentLength = line.length() - startIndex;     //  calculate length of actual multiple line comment
                }
                else
                    commentLength = endIndex - startIndex + match.capturedLength();     //  calculate length of actual multiple line comment

                setFormat(startIndex, commentLength, multi_line_comment_format);    //  set color format for matched multiple line comment
                startIndex = line.indexOf(comment_start_expression, startIndex + commentLength);    //  get new start index from rest of text
            }
        }
    }
    else if (language == python)
    {
        QString line = text;

        int N = highlighting_rules.size();
        QRegularExpression multi_line_regex("\"\"\"[^\n]*");
        multi_line_regex.optimize();
        QRegularExpression multi_line_regex_2("'''[^\n]*");
        multi_line_regex_2.optimize();
        QRegularExpressionMatch match;

        int offset = 0;

        while (true)
        {
            int index = -1;
            int from = -1;
            int to = -1;
            int len = -1;

            for (int i = 0; i < N; i++)
            {
                if (highlighting_rules[i].pattern.isValid())
                {
                    match = highlighting_rules[i].pattern.match(line, offset);

                    if (match.hasMatch())
                    {
                        int temp = match.capturedStart();

                        if (from == -1 || temp < from)
                        {
                            index = i;
                            from = temp;
                            to = match.capturedEnd();
                            len = match.capturedLength();
                        }
                    }
                }
            }

            if (multi_line_regex.isValid())
            {
                match = multi_line_regex.match(line);

                if (match.hasMatch())
                {
                    int temp = match.capturedStart();

                    if (from == -1 || temp < from)
                        break;
                }
            }

            if (multi_line_regex_2.isValid())
            {
                match = multi_line_regex_2.match(line);

                if (match.hasMatch())
                {
                    int temp = match.capturedStart();

                    if (from == -1 || temp < from)
                        break;
                }
            }

            if (from == -1)
                break;

            offset = from;

            setFormat(from, len, highlighting_rules[index].format);

            for (int j = from; j < to; j++)
                line[j] = ' ';
        }

        comment_start_expression = QRegularExpression("(''')|(\"\"\")");   //  regular expression for beginning of multiple line comment
        comment_start_expression.optimize();
        comment_end_expression = QRegularExpression("(''')|(\"\"\")");     //  regular expression for end of multiple line comment
        comment_end_expression.optimize();

        if (comment_start_expression.isValid() && comment_end_expression.isValid())     //  check if regular expressions are valid
        {
            setCurrentBlockState(0);                        //  set new state of current text block

            int start_found = -1;
            int startIndex = 0;                             //  holds start index value

            if (previousBlockState() != 1)                  //  check if last block state was not one
            {
                startIndex = line.indexOf(comment_start_expression);    //  find pattern match in text editor content
                start_found = startIndex;
            }

            if (startIndex >= 0 && start_found >= 0)
            {
                if (line[startIndex] == '\'')
                {
                    comment_start_expression = QRegularExpression("'''");
                    comment_start_expression.optimize();
                    comment_end_expression = QRegularExpression("'''");
                    comment_end_expression.optimize();
                }
                else
                {
                    comment_start_expression = QRegularExpression("\"\"\"");
                    comment_start_expression.optimize();
                    comment_end_expression = QRegularExpression("\"\"\"");
                    comment_end_expression.optimize();
                }
            }

            while (startIndex >= 0)                         //  repeat until pattern match found in text editor content
            {
                QRegularExpressionMatch match;

                if (start_found == startIndex)
                    match = comment_end_expression.match(line, startIndex + 3);     //  find ending match from starting match position
                else
                    match = comment_end_expression.match(line, startIndex);     //  find ending match from starting match position

                int endIndex = match.capturedStart();       //  holds length of multiple line comment
                int commentLength = 0;

                if (endIndex == -1)                         //  check if offset was not at last character
                {
                    setCurrentBlockState(1);                //  set new state of current text block
                    commentLength = line.length() - startIndex;     //  calculate length of actual multiple line comment
                }
                else
                    commentLength = endIndex - startIndex + match.capturedLength();     //  calculate length of actual multiple line comment

                setFormat(startIndex, commentLength, multi_line_comment_format);    //  set color format for matched multiple line comment
                startIndex = line.indexOf(comment_start_expression, startIndex + commentLength);    //  get new start index from rest of text
            }
        }
    }
    else if (language >= builtInLanguages)
    {
        QString line = text;

        int N = highlighting_rules.size();
        QRegularExpression multi_line_regex(comment_start_expression.pattern() + "[^\n]*");
        multi_line_regex.optimize();
        QRegularExpressionMatch match;

        int offset = 0;

        while (true)
        {
            int index = -1;
            int from = -1;
            int to = -1;
            int len = -1;

            for (int i = 0; i < N; i++)
            {
                if (highlighting_rules[i].pattern.isValid())
                {
                    match = highlighting_rules[i].pattern.match(line, offset);

                    if (match.hasMatch())
                    {
                        int temp = match.capturedStart();

                        if (from == -1 || temp < from)
                        {
                            index = i;
                            from = temp;
                            to = match.capturedEnd();
                            len = match.capturedLength();
                        }
                    }
                }
            }

            if (comment_start_expression.pattern().size() && comment_end_expression.pattern().size())
            {
                if (multi_line_regex.isValid())
                {
                    match = multi_line_regex.match(line);

                    if (match.hasMatch())
                    {
                        int temp = match.capturedStart();

                        if (from == -1 || temp < from)
                            break;
                    }
                }
            }

            if (from == -1)
                break;

            offset = from;

            setFormat(from, len, highlighting_rules[index].format);

            for (int j = from; j < to; j++)
                line[j] = ' ';
        }

        if (comment_start_expression.pattern().size() && comment_end_expression.pattern().size())
        {
            if (comment_start_expression.isValid() && comment_end_expression.isValid())     //  check if regular expressions are valid
            {
                setCurrentBlockState(0);                        //  set new state of current text block

                int startIndex = 0;                             //  holds start index value

                if (previousBlockState() != 1)                  //  check if last block state was not one
                    startIndex = line.indexOf(comment_start_expression);    //  find pattern match in text editor content

                while (startIndex >= 0)                         //  repeat until pattern match found in text editor content
                {
                    QRegularExpressionMatch match = comment_end_expression.match(line, startIndex);     //  find ending match from starting match position
                    int endIndex = match.capturedStart();       //  holds length of multiple line comment
                    int commentLength = 0;

                    if (endIndex == -1)                         //  check if offset was not at last character
                    {
                        setCurrentBlockState(1);                //  set new state of current text block
                        commentLength = line.length() - startIndex;     //  calculate length of actual multiple line comment
                    }
                    else
                        commentLength = endIndex - startIndex + match.capturedLength();     //  calculate length of actual multiple line comment

                    setFormat(startIndex, commentLength, multi_line_comment_format);    //  set color format for matched multiple line comment
                    startIndex = line.indexOf(comment_start_expression, startIndex + commentLength);    //  get new start index from rest of text
                }
            }
        }
    }
}
