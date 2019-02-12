#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include "elements.h"

#define builtInLanguages 6


/// Holds list of all by default supported languages
enum LanguageType
{
    c99,
    cplusplus,
    java,
    php,
    plain_text,
    python
};


/// Highlighting rule class
class HighlightingRule
{
public:
    QRegularExpression pattern;                         //  pattern described by regular expression
    QTextCharFormat format;                             //  text char format of pattern
};


/// syntax highlighter class for any language highlighting
class RichHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    /// Class constructor
    ///
    /// @param  Language type for user language cases
    /// @param  Language index
    /// @param  Holds if comments are visible
    /// @param  Holds actual color theme of language
    /// @param  Parent text document
    RichHighlighter(QTextDocument * parent = 0);
    void applyRules(Language *, int, bool, int);

protected:
    /// Highlight desired words in line when it is changed inside text
    ///
    /// @param  Content of changed line is accessed using string parameter
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:
    int language;                                       //  holds language of syntax highlighting

    QVector<HighlightingRule> highlighting_rules;       //  vector of all syntax highlighting rules

    QTextCharFormat multi_line_comment_format;          //  text char format for multiple line comments

    QRegularExpression comment_start_expression;        //  regular expression for beginning of multiple line comment
    QRegularExpression comment_end_expression;          //  regular expression for end of multiple line comment
};

#endif // HIGHLIGHTER_H
