@echo off
cls
title Calculator

setlocal EnableDelayedExpansion

REM Variables
set "date=%date:/=-%-%time::=-%"
set "log_file=log_%date%.txt"
set /a output_count=1

REM Create output directory if it doesn't exist
if not exist output mkdir output

REM Append to log file
echo Calculator started -- %date% >> %log_file%

:TOP
color 3f
cls

REM Main Menu
echo ----------------------------------------------------
echo.
echo                     DOS CALCULATOR
echo.
echo ----------------------------------------------------
echo.
echo.
echo    + = Sum
echo.
echo    - = Sub
echo.
echo    / = Division
echo.
echo    * = Multiply
echo.
echo    M = Power
echo.
echo    P = Scalar Product of two vectors
echo.
echo    I = Inverse of a 2x2 matrix
echo.
echo    V = Vector Cross Product (3D)
echo.
echo    E = Exit
echo.
echo.
echo ----------------------------------------------------
echo.
set /p ch=" Enter Symbol "

REM Handle user input
if "%ch%"=="+" (
    call :SUM
) else if "%ch%"=="-" (
    call :SUB
) else if "%ch%"=="/" (
    call :DIV
) else if "%ch%"=="*" (
    call :MUL
) else if "%ch%"=="M" (
    call :POWER
) else if "%ch%"=="P" (
    call :SCALAR_PRODUCT
) else if "%ch%"=="I" (
    call :INVERSE_MATRIX
) else if "%ch%"=="V" (
    call :VECTOR_CROSS_PRODUCT
) else if "%ch%"=="E" (
    exit
) else (
    goto :HELP
)

goto :TOP

:SUM
cls
echo ---------------------------------------------------
echo.
echo                         SUM
echo.
echo ---------------------------------------------------
echo.
echo Sum >> %log_file%
set /p "A=Enter First Number = "
echo.
set /p "B=Enter Second Number = "
set /a "C=A+B"
echo.
echo ---------------------------------------------------
echo %A% + %B% = %C%
echo %A% + %B% = %C% >> %log_file%
echo.
pause
goto :EOF

:SUB
cls
echo ---------------------------------------------------
echo.
echo                     SUBTRACTION
echo.
echo ---------------------------------------------------
echo.
echo Subtraction >> %log_file%
set /p "A=Enter First Number = "
echo.
set /p "B=Enter Second Number = "
set /a "C=A-B"
echo.
echo ---------------------------------------------------
echo %A% - %B% = %C%
echo %A% - %B% = %C% >> %log_file%
echo.
pause
goto :EOF

:DIV
cls
echo ----------------------------------------------------
echo.
echo                      DIVISION
echo.
echo -----------------------------------------------------
echo.
echo Division >> %log_file%
set /p "A=Enter First Number = "
echo.
set /p "B=Enter Second Number = "
set /a "C=A/B"
echo.
echo -----------------------------------------------------
echo %A% / %B% = %C%
echo %A% / %B% = %C% >> %log_file%
echo.
pause
goto :EOF

:POWER
cls
echo ----------------------------------------------------
echo.
echo                      POWER
echo.
echo -----------------------------------------------------
echo.
echo Power >> %log_file%
set /p "x=Enter Base Number = "
echo.
set /p "n=Enter Exponent = "
set "result=1"
echo.
echo -----------------------------------------------------
for /L %%i in (1,1,%n%) do set /a "result*=x"
echo %x% to the power of %n% is %result%
echo %x% to the power of %n% is %result% >> %log_file%
echo.
pause
goto :EOF

:SCALAR_PRODUCT
cls
echo ----------------------------------------------------
echo.
echo                  SCALAR PRODUCT
echo.
echo -----------------------------------------------------
echo.
echo Scalar Product >> %log_file%

REM Prompt the user for the array size
set /p "size=Enter the size of the vectors: "

REM Prompt the user for the vector elements
set /p "arr1=Enter the elements of vector 1 (separated by spaces): "
set /p "arr2=Enter the elements of vector 2 (separated by spaces): "

REM Convert the space-separated input strings into arrays
set "i=0"
for %%e in (%arr1%) do (
  set /a "i+=1"
  set "arr1[!i!]=%%e"
  if !i! equ %size% goto :done1
)
:done1
set "i=0"
for %%e in (%arr2%) do (
  set /a "i+=1"
  set "arr2[!i!]=%%e"
  if !i! equ %size% goto :done2
)
:done2

REM Calculate the scalar product
set /a "scalar_product=0"
for /l %%i in (1, 1, %size%) do (
  set /a "element_product=!arr1[%%i]!*!arr2[%%i]!"
  set /a "scalar_product+=element_product"
)

echo Scalar product: %scalar_product%
echo Scalar product: %scalar_product% >> %log_file%
echo.

REM Write the result to an output file
set "output_file=output\output_%output_count%.txt"
echo Scalar Product Calculation >> %output_file%
echo Vector 1: %arr1% >> %output_file%
echo Vector 2: %arr2% >> %output_file%
echo Scalar Product: %scalar_product% >> %output_file%

set /a "output_count+=1"

pause
goto :EOF

:MUL
cls
echo ---------------------------------------------------
echo.
echo                    MULTIPICATION
echo.
echo ----------------------------------------------------
echo.
echo Multiplication
set /p "A=Enter First Number = "
echo.
set /p "B=Enter Second Number = "
set /a "C=A*B"
echo.
echo ----------------------------------------------------
echo %A% * %B% = %C%
echo %A% * %B% = %C% >> %log_file%
echo.
pause
goto :EOF

:INVERSE_MATRIX
cls
echo ----------------------------------------------------
echo.
echo                    INVERSE MATRIX (2x2)
echo.
echo -----------------------------------------------------
echo.
echo Inverse Matrix >> %log_file%

REM Prompt the user for the matrix elements
echo Enter the elements of the matrix (separated by spaces):
set /p "m11=Enter element (1,1): "
set /p "m12=Enter element (1,2): "
set /p "m21=Enter element (2,1): "
set /p "m22=Enter element (2,2): "

REM Calculate the determinant
set /a "determinant=(m11*m22)-(m12*m21)"

REM Check if the matrix is invertible
if %determinant% equ 0 (
    echo The matrix is not invertible.
    echo The matrix is not invertible. >> %log_file%
) else (
    REM Calculate the inverse
    set /a "inv_determinant=1/determinant"
    set /a "inv_m11=(m22*inv_determinant)"
    set /a "inv_m12=(-m12*inv_determinant)"
    set /a "inv_m21=(-m21*inv_determinant)"
    set /a "inv_m22=(m11*inv_determinant)"

    REM Output the inverse matrix
    echo Inverse matrix:
    echo %inv_m11% %inv_m12%
    echo %inv_m21% %inv_m22%
    echo.
    echo Inverse matrix: >> %log_file%
    echo %inv_m11% %inv_m12% >> %log_file%
    echo %inv_m21% %inv_m22% >> %log_file%

    REM Write the result to an output file
    set "output_file=output\output_%output_count%.txt"
    echo Inverse Matrix Calculation >> %output_file%
    echo Matrix: >> %output_file%
    echo %m11% %m12% >> %output_file%
    echo %m21% %m22% >> %output_file%
    echo Inverse Matrix: >> %output_file%
    echo %inv_m11% %inv_m12% >> %output_file%
    echo %inv_m21% %inv_m22% >> %output_file%

    set /a "output_count+=1"
)

pause
goto :TOP

:VECTOR_CROSS_PRODUCT
cls
echo ----------------------------------------------------
echo.
echo                  VECTOR CROSS PRODUCT (3D)
echo.
echo -----------------------------------------------------
echo.
echo Vector Cross Product >> %log_file%

REM Prompt the user for the vector elements
set /p "x1=Enter x component of vector 1: "
set /p "y1=Enter y component of vector 1: "
set /p "z1=Enter z component of vector 1: "
set /p "x2=Enter x component of vector 2: "
set /p "y2=Enter y component of vector 2: "
set /p "z2=Enter z component of vector 2: "

REM Calculate the cross product
set /a "cross_x=(y1*z2)-(z1*y2)"
set /a "cross_y=(z1*x2)-(x1*z2)"
set /a "cross_z=(x1*y2)-(y1*x2)"

REM Output the cross product
echo Cross product: %cross_x% %cross_y% %cross_z%
echo Cross product: %cross_x% %cross_y% %cross_z% >> %log_file%
echo.

REM Write the result to an output file
set "output_file=output\output_%output_count%.txt"
echo Vector Cross Product Calculation >> %output_file%
echo Vector 1: %x1% %y1% %z1% >> %output_file%
echo Vector 2: %x2% %y2% %z2% >> %output_file%
echo Cross Product: %cross_x% %cross_y% %cross_z% >> %output_file%

set /a "output_count+=1"

pause
goto :TOP

:HELP
cls
echo --------------------------------------------------
echo.
echo                         HELP
echo.
echo --------------------------------------------------
echo Press (+) for Sum, (-) for Subtraction, (/) for Division, (*) for Multiplication, (M) for Power, (P) for Scalar Product, (I) for Inverse Matrix, (V) for Vector Cross Product, or (E) to Exit.
echo.
pause
goto :TOP
