#include <QCoreApplication>

#include <iostream>
#include <windows.h>
#include <QRegularExpression>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Hello Looser" << std::endl;

    while(true)
    {
        std::cout << "Select Mode : " << std::endl;
        std::cout << "Exit : 0" << std::endl;
        std::cout << "Exit : 1" << std::endl;
        int input_val = -1;
        std::cin >> input_val;
        if(input_val == 0)
        {
            std::cout << "Goodbye" << std::endl;
            break;
        }
        else if(input_val == 1)
        {
            std::string pattern;
            std::string text;

            std::cout << "Enter Regular Expression : " << std::endl;
            std::cin >> pattern;
            std::cout << "Enter Text : " << std::endl;
            std::cin >> text;

            std::cout << "Exp = " << pattern << "   : Text = " << text << std::endl;

            Sleep(1000);

            const QString text_qstring(text.c_str());
            const QString pattern_qstring(pattern.c_str());
            const QRegularExpression reg_exp(pattern_qstring);
            const QRegularExpressionMatch match = reg_exp.match(text_qstring);
            if(match.hasMatch())
            {
                std::cout << "Text is a match" << std::endl;
            }
            else
            {
                std::cout << "Text is not a match" << std::endl;
            }

            std::cout << "Press enter to continue" << std::endl;

            char temp = 'x';
            while (temp != '\n')
                std::cin.get(temp);
        }
        else
        {
            std::cout << "Error bad input : " << std::endl;
        }

        Sleep(1000);
    }

    // return a.exec();
    return 0;
}
