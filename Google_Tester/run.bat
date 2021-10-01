devenv %~dp0Grader\Grader.sln /ReBuild

cd Grader\x64\Debug
Grader.exe > ..\..\..\HW1_Solution.txt