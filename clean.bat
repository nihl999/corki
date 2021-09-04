@echo off

if exist .\bin (
	@RD "bin" /S /Q 
	mkdir .\bin\
)

echo Succesfully cleaned build folder.  