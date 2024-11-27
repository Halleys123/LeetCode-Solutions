@echo off

set PROBLEM=%1

rem everything else
set SOLUTION=%2 %3 %4 %5 %6 %7 %8 %9

if "%PROBLEM%"=="" (
    echo Error: Please provide the problem code.
    exit /b
)

if exist "%PROBLEM%" (
    if "%SOLUTION%"=="*" (
        echo Building specific solutions for problem %PROBLEM%
        for %%S in (%SOLUTION%) do (
            if exist "%PROBLEM%\%%S.cpp" (
                echo Building solution %%S.cpp for problem %PROBLEM%
                g++ "%PROBLEM%\%%S.cpp" -o "%PROBLEM%_%%S.exe"
            ) else (
                echo Solution %%S.cpp not found for problem %PROBLEM%
            )
        )
    ) else (
        echo Building all solutions for problem %PROBLEM%
        for %%S in ("%PROBLEM%\*.cpp") do (
            g++ "%%S" -o "%%~nS.exe"
        )
        exit /b
    )
) else (
    echo Problem %PROBLEM% not found
)
