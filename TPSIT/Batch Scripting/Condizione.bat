@echo off
title "zio perone"
:setdir
set /p PERCORSO="Inserire percorso (Desktop, Documents, Downloads ecc.)= "

if exist %USERPROFILE%\%PERCORSO% goto :setfolder
echo Percorso non valido
goto :setdir

:setfolder
set /p NOMECARTELLA= "Inserire nome cartella= "
set /p NOMEFILE= "Inserire il nome del file (SENZA ESTENSIONE)= "
set /p ESTENSIONE= "Inserire estensione (doc, ods, txt)= "
set /p ATTRIBUTI="Inserire attributi (+/-R, +/-A, +/-S, +/-H, +/-I ecc.)= "
mkdir %USERPROFILE%\%PERCORSO%\%NOMECARTELLA%
cd %USERPROFILE%\%PERCORSO%\%NOMECARTELLA%
type nul > %NOMEFILE%.%ESTENSIONE%
attrib %ATTRIBUTI% %NOMEFILE%.%ESTENSIONE%
