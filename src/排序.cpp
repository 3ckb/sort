#define _WIN32_WINNT 0x0A00
#define _WIN32_NO_WINBYTE
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "../include/counting_sort.h"
#include "../include/insertion_sort.h"
using namespace std;

int g_lang = 0;  // 0=简体中文  1=English  2=日本語  3=繁體中文

// 从注册表读取安装时选择的语言
void load_language()
{
    HKEY key;
    g_lang = 0;
    if(RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\排序", 0, KEY_READ, &key) == ERROR_SUCCESS)
    {
        wchar_t buf[64] = {};
        DWORD sz = sizeof(buf);
        if(RegQueryValueExW(key, L"Language", NULL, NULL, (LPBYTE)buf, &sz) == ERROR_SUCCESS)
        {
            if(wcscmp(buf, L"english") == 0)
                g_lang = 1;
            else if(wcscmp(buf, L"japanese") == 0)
                g_lang = 2;
            else if(wcscmp(buf, L"chinesetraditional") == 0)
                g_lang = 3;
        }
        RegCloseKey(key);
    }
}

int main()
{
    SetConsoleOutputCP(65001); // 把控制台输出代码页切到UTF-8，防止中文乱码
    SetConsoleCP(65001);      // 输入代码页同步切换
    load_language();          // 读安装时选的语言

    while(true)
    {
        string op;
        if(g_lang == 1)
        {
            cout << "\n=====Sort Menu=====\n";
            cout << "1 Counting Sort\n";
            cout << "2 Insertion Sort\n";
            cout << "Select sort method (any other key to exit): ";
        }
        else if(g_lang == 2)
        {
            cout << "\n=====並べ替え選択=====\n";
            cout << "1 計数ソート\n";
            cout << "2 挿入ソート\n";
            cout << "ソート方法を選択してください（他のキーで終了）：";
        }
        else if(g_lang == 3)
        {
            cout << "\n=====排序選擇=====\n";
            cout << "1 計數排序\n";
            cout << "2 插入排序\n";
            cout << "請選擇排序方式（任意鍵退出（1、2除外））：";
        }
        else
        {
            cout << "\n=====排序选择=====\n";
            cout << "1 计数排序\n";
            cout << "2 插入排序\n";
            cout << "请选择排序方式（任意键退出（1、2除外））：";
        }

        i:
        cin >> op;
        try
        {
            if(stoi(op) == 1)
                ji_shu_pai_xu();
            else if(stoi(op) == 2)
                cha_ru_pai_xu();
            else
                break;
        }
        catch(...)
        {
            break;   // 输入的不是 1 或 2（包括字母）：直接退出
        }
        // 判断是否退出程序
        if(g_lang == 1)
            cout << "\nQuit? (y/n): ";
        else if(g_lang == 2)
            cout << "\n終了しますか(y/n)？";
        else if(g_lang == 3)
            cout << "\n退出嗎(y/n)？";
        else
            cout << "\n退出吗(y/n)？";
        char e;
        cin >> e;
        if (e == 'y')
            break;
        if(g_lang == 1)
            cout << "Continue~\n\n";
        else if(g_lang == 2)
            cout << "続行~\n\n";
        else if(g_lang == 3)
            cout << "繼續~\n\n";
        else
            cout << "继续~\n\n";
    }
    if(g_lang == 1)
        cout << "\nExited~";
    else if(g_lang == 2)
        cout << "\n終了しました~";
    else if(g_lang == 3)
        cout << "\n已退出~";
    else
        cout << "\n已退出~";
    return 0;
}
