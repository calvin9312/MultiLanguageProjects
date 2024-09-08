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
        std::cout << "==============================" << std::endl;
        std::cout << "Select Mode : Try Expression = 0, Exit = 1" << std::endl;
        std::cout << "==============================" << std::endl;
        int input_val = -1;
        std::cin >> input_val;
        if(input_val == 0)
        {
            std::string pattern;
            std::string text;

            std::cout << "Enter Regular Expression : " << std::endl;
            std::cin >> pattern;

            while(true)
            {
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

                std::cout << "------------------------------" << std::endl;
                std::cout << "Select Mode : Try More Text = 0, Exit = 1" << std::endl;
                std::cout << "------------------------------" << std::endl;

                int try_again;
                std::cin >> try_again;

                if(try_again == 0)
                {
                    std::cout << "Trying more text." << std::endl;
                }
                else if(try_again == 1)
                {
                    std::cout << "Done trying text." << std::endl;
                    break;
                }
                else
                {
                    std::cout << "Error bad input : " << std::endl;
                }
            }
        }
        else if(input_val == 1)
        {
            std::cout << "Goodbye" << std::endl;
            break;
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
