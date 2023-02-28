@echo off
set /p folder=Inserisci il percorso della cartella: 

REM Visualizza i file e i relativi attributi nella cartella selezionata
dir %folder%

REM Chiede all'utente quale azione eseguire
set /p action=Quale azione vuoi eseguire? (C)ancellare, (R)inominare o (S)postare?

IF /I "%action%"=="C" (
    REM Cancella i file selezionati
    set /p ext=Inserisci l'estensione del file che vuoi cancellare (senza il punto): 
    del %folder%\*.%ext%
) ELSE IF /I "%action%"=="R" (
    REM Rinomina i file selezionati
    set /p ext=Inserisci l'estensione del file che vuoi rinominare (senza il punto): 
    set /p oldname=Inserisci il nome del file che vuoi rinominare: 
    set /p newname=Inserisci il nuovo nome del file: 
    ren %folder%\%oldname%.%ext% %newname%.%ext%
) ELSE IF /I "%action%"=="S" (
    REM Sposta i file selezionati
    set /p ext=Inserisci l'estensione del file che vuoi spostare (senza il punto): 
    set /p oldpath=Inserisci il percorso completo del file che vuoi spostare: 
    set /p newpath=Inserisci il percorso completo della nuova cartella di destinazione: 
    move %folder%\%oldpath%.%ext% %newpath%
)

REM Chiede all'utente se vuole eseguire altre operazioni
set /p more=Vuoi eseguire altre operazioni? (S)i o (N)o: 

IF /I "%more%"=="S" (
    REM Esegue il file batch di nuovo
    call "%~f0"
) ELSE (
    REM Esce dal file batch
    exit
)
