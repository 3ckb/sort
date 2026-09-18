; 架构由命令行传入：ISCC /DMyArch=x64 排序.iss 或 /DMyArch=x86 排序.iss
#ifndef MyArch
#define MyArch "x64"
#endif

[Setup]
AppName=排序
AppVersion=3.0
AppPublisher=MySort
DefaultDirName={pf64}\排序
DefaultGroupName=排序
OutputDir=releases
OutputBaseFilename=sort_v1.0.0_windows_{#MyArch}
Compression=lzma
SolidCompression=yes
WizardStyle=modern
SetupIconFile=assets\排序.ico
UsePreviousLanguage=no
LanguageDetectionMethod=none

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "chinesesimplified"; MessagesFile: "compiler:Languages\ChineseSimplified.isl"
Name: "chinesetraditional"; MessagesFile: "compiler:Languages\ChineseTraditional.isl"
Name: "japanese"; MessagesFile: "compiler:Languages\Japanese.isl"

[Tasks]
Name: "startmenu"; Description: "加入开始菜单"; GroupDescription: "附加选项:"; Flags: checkedonce
Name: "desktopicon"; Description: "创建桌面图标"; GroupDescription: "附加选项:"; Flags: checkedonce

[Files]
Source: "bin\排序_{#MyArch}.exe"; DestDir: "{app}"; DestName: "排序.exe"; Flags: ignoreversion
Source: "assets\排序.ico"; DestDir: "{app}"; Flags: ignoreversion

[Registry]
Root: HKCU; Subkey: "Software\排序"; ValueType: string; ValueName: "Language"; ValueData: "{language}"; Flags: uninsdeletekey

[Icons]
Name: "{group}\排序"; Filename: "{app}\排序.exe"; IconFilename: "{app}\排序.ico"; Tasks: startmenu
Name: "{group}\卸载排序"; Filename: "{uninstallexe}"; Tasks: startmenu
Name: "{autodesktop}\排序"; Filename: "{app}\排序.exe"; IconFilename: "{app}\排序.ico"; Tasks: desktopicon

[Run]
Filename: "{app}\排序.exe"; Description: "立即运行排序程序"; Flags: nowait postinstall skipifsilent
