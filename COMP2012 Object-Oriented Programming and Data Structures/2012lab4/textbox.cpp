#include <iostream>
#include "textbox.h"

const char* TextBox::getText() const
{
    return _text;
}

void TextBox::setText(const char* text)
{
    for(int i=0;i<MAX_TEXTBOX_LENGTH; i++)
    {
        _text[i] = text[i];
        if (text[i] == '\0') break;
    }
}

void TextBox::display() const  //Task 1
{
    std::cout << "\nTextBox";
    this->displayBasic();
    std::cout <<"\n\t\t";
    std::cout <<"TextBoxText=["<<this->getText()<<"]\n";
}

TextBox::TextBox()
{
    _text = new char[MAX_TEXTBOX_LENGTH];
}

TextBox::~TextBox() 
{
    cout<<"\nDestructing TextBox "<< getName();
    delete[] _text;
}
