TITLE Calculator
setlocal EnableDelayedExpansion
ECHO OFF
CLS
ECHO -by Ravi Raturi, XI B Nirmal Deepmala Pagarani Public School Shyampur, Rishikesh
:TOP
color 3f
Cls
ECHO ----------------------------------------------------
ECHO[
ECHO                    DOS CALCULATOR
ECHO[
ECHO ----------------------------------------------------
ECHO[
ECHO[
ECHO    + = Sum
ECHO[
ECHO    - = Sub
ECHO[
ECHO    / = Division
ECHO[
ECHO    * = Multiply
ECHO[
ECHO    M = POWER
ECHO[
ECHO    P = Scalar Product of two vectors
echo[
ECHO    ~ = Exit
ECHO[
ECHO[
ECHO ----------------------------------------------------
ECHO[
SET/P ch=" Enter Symbol "
IF %ch% EQU + GOTO:SUM
IF %ch% EQU - GOTO:SUB
IF %ch% EQU / GOTO:DIV
IF %ch% EQU * GOTO:MUL
IF %ch% EQU ~ GOTO:EXI
IF %ch% EQU M GOTO:ESP
IF %ch% EQU P GOTO:PRO
IF %ch% GTR . GOTO:Hel
:SUM
CLS
ECHO ---------------------------------------------------
ECHO[
ECHO                         SUM
ECHO[
ECHO ---------------------------------------------------
ECHO[
set /p A=" Enter First Number = "
ECHO[
set /p B=" Enter Second Number = "
SET /A C=A+B
ECHO[
ECHO ---------------------------------------------------
ECHO %A%+%B%=%C%
PAUSE
GOTO:TOP
:SUB
CLS
ECHO ---------------------------------------------------
ECHO[
ECHO                     SUBTRACTION
ECHO[
ECHO ---------------------------------------------------
ECHO[
set /p A=" Enter First Number = "
ECHO[
set /p B=" Enter Second Number = "
SET /A C=A-B
ECHO[
ECHO ---------------------------------------------------
ECHO %A%-%B%=%C%
PAUSE
GOTO:TOP
:DIV
CLS
ECHO ----------------------------------------------------
ECHO[
ECHO                      DIVISION
ECHO[
ECHO -----------------------------------------------------
ECHO[
set /p A=" Enter First Number = "
ECHO[
set /p B=" Enter Second Number = "
SET /A C=A/B
ECHO[
ECHO -----------------------------------------------------
ECHO %A%/%B%=%C%
PAUSE
GOTO:TOP
:ESP
CLS
ECHO ----------------------------------------------------
ECHO[
ECHO                      POWER
ECHO[
ECHO -----------------------------------------------------
ECHO[
set /p x=" Enter First Number = "
ECHO[
set /p n=" Enter Second Number = "
SET result=1
ECHO[
ECHO -----------------------------------------------------
FOR /L %%i IN (1,1,%n%) DO SET /A result*=x
ECHO %x% to the power %n% is %result%
PAUSE
GOTO:TOP
:PRO
CLS
ECHO ----------------------------------------------------
ECHO[
ECHO                      SCALAR PRODUCT
ECHO[
ECHO -----------------------------------------------------
REM Prompt the user for the array sizes
set /p size1=Enter the size of array 1: 
set /p size2=Enter the size of array 2: 
REM Prompt the user for the array elements
set /p arr1=Enter the elements of array 1 (separated by spaces): 
set /p arr2=Enter the elements of array 2 (separated by spaces): 
REM Convert the space-separated input strings into arrays
set i=0
for %%e in (%arr1%) do (
  set /a i+=1
  set arr1[!i!]=%%e
  if !i! equ %size1% goto :done1
)
:done1
set i=0
for %%e in (%arr2%) do (
  set /a i+=1
  set arr2[!i!]=%%e
  if !i! equ %size2% goto :done2
)
:done2
REM Calculate the scalar product
set /a scalar_product=0
for /l %%i in (1, 1, %size1%) do (
  set /a element_product=!arr1[%%i]!*!arr2[%%i]!
  set /a scalar_product+=!element_product!
)

echo Scalar product: %scalar_product%
PAUSE
GOTO:TOP
:MUL
CLS
ECHO ---------------------------------------------------
ECHO[
ECHO                    MULTIPICATION
ECHO[
ECHO ----------------------------------------------------
ECHO[
set /p A=" Enter First Number = "
ECHO[
set /p B=" Enter Second Number = "
SET /A C=A*B
ECHO[
ECHO ----------------------------------------------------
ECHO %A%*%B%=%C%
PAUSE
GOTO:TOP
:EXI
EXIT
:HEL
CLS
ECHO --------------------------------------------------
ECHO[
ECHO                         HELP
ECHO[
ECHO --------------------------------------------------
ECHO Press (+) For Sum, (-) For Sub, (/) for Division, (*) for Multiply.
PAUSE
GOTO:TOP