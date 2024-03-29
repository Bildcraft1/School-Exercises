@echo off
set /p folder=Inserisci il percorso della cartella: 

if not exist "%folder%" (
    echo La cartella non esiste
    goto more
)

REM Visualizza i file e i relativi attributi nella cartella selezionata
dir %folder%

REM Chiede all'utente quale azione eseguire
set /p action=Quale azione vuoi eseguire? (C)ancellare, (R)inominare o (S)postare o (A) per attirbuti? 

IF /I "%action%"=="C" (
    REM Cancella i file selezionati
    set /p ext=Inserisci nome file + estensione [supporta anche wildcards] 
    echo %folder%\%ext%
    del %folder%\%ext%
    goto more
) ELSE IF /I "%action%"=="R" (
    REM Rinomina i file selezionati
    set /p ext=Inserisci l'estensione file che vuoi rinominare [senza il punto]  
    set /p oldname=Inserisci il nome file che vuoi rinominare 
    set /p newname=Inserisci il nuovo nome file 
    ren %folder%\%oldname%.%ext% %newname%.%ext%
    goto more
) ELSE IF /I "%action%"=="S" (
    REM Sposta i file selezionati
    set /p ext=Inserisci l'estensione file che vuoi spostare [senza il punto] 
    set /p oldpath=Inserisci il percorso completo file che vuoi spostare 
    set /p newpath=Inserisci il percorso completo della nuova cartella di destinazione 
    move %folder%\%oldpath%.%ext% %newpath%
    goto more
) ELSE IF /I "%action%"=="E" (
    REM Esce dal file batch
    exit
) ELSE IF /I "%action%"=="A" (
    REM Modifica attirbuti dei file selezionati
    set /p ext=Inserisci l'estensione file che vuoi modificare [senza il punto]
    set /p oldname=Inserisci il nome file che vuoi modificare
    set /p newname=Inserisci il nuovo nome file
    set /p newattr=Inserisci i nuovi attributi
    ren %folder%\%oldname%.%ext% %newname%.%ext%
    attrib %folder%\%newname%.%ext% %newattr%
    goto more
) ELSE (
    REM Se l'utente non ha inserito una delle opzioni, esce dal file batch
    echo Hai inserito un'opzione non valida
    exit
)

:more
REM Chiede all'utente se vuole eseguire altre operazioni
set /p more="Vuoi eseguire altre operazioni? (S)i o (N)o? "

IF /I "%more%"=="S" (
    REM Esegue il file batch di nuovo
    call "%~f0"
) ELSE (
    REM Esce dal file batch
    exit
)
