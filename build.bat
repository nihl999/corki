@echo off

set opts=-FC -GR- -EHa- -nologo -Zi -I%cd%\vendor\Curl\include
set code=%cd%
set vendor=%cd%\vendor
set vcvarsdir="D:\VSC\VC\Auxiliary\Build"
set arch=x64
set libraries=Normaliz.lib Ws2_32.lib wldap32.lib crypt32.lib advapi32.lib libcurl_a.lib Shlwapi.lib

if not exist .\bin\ (
	mkdir .\bin\
)
pushd .\bin\
pushd %vcvarsdir%

echo %vendor%\Curl\lib 
call vcvarsall %arch%
popd
pushd .\bin\
cl %opts% %code%\src\*.cpp -Fesandbox.exe %libraries% /link /LIBPATH:%vendor%\Curl\lib
popd
