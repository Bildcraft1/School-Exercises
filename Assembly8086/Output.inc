MS_PUTC MACRO char
   PUSH AX     ; Salvo il valore nel registro
   ; Utilizza le funzioni VIDEO & SCREEN Service (int10 0Eh):
   ; scrive un carattere in modalità teletype
   MOV AL, char
   MOV AH, 0Eh
   INT 10h
   POP AX     ; Ripristina valore nel registro
ENDM

MS_ACAPO MACRO void
   MOV dl, 10
   MOV ah, 02h
   INT 21h
   MOV dl, 13
   MOV ah, 02h
   INT 21h
ENDM

MS_PRINT_INT MACRO Numero
Local _NonNegativo, _Stampa, _Loop
    PUSHA              ; Salva il contenuto dei registri nello stack
    MOV AX, Numero     ; mette il valore da stampare in AX
    CMP AX, 0
    JNS _NonNegativo   ; salta alla gestione dei positivi se non c'è segno
    NEG AX             ; Se negativo cambio di segno con NEG
    MS_PUTC '-'        ; e stampo il segno

_NonNegativo:
    ; Inizializzazione a 10 per estrarre i singoli numeri
    ; della rappresentazione in base 10
    MOV BX, 10
    MOV CX, 0     ; CX conta il numero di digit presenti nel numero

_Loop:
    MOV DX, 0     ; questa istruzione è necessaria poichè potrei avere un Divide Overflow
    DIV BX        ; effettua la divisione tra il numero nei 32 bit DX:AX e BX (contiene 10d) -
                  ; Essendo BX a 16 bit (1 Word) il resto della divisione va in DX
    ADD DX, 48    ; aggiungo 48 ovvero il codice ASCII di zero
    PUSH DX       ; memorizzo nello stack il resto
    INC CX        ; incremento di CX che conta i digit estratti
    CMP AX, 0
    JNE _Loop     ; se in AX non ho zero ripeto l'operazione

_Stampa:
    POP DX          ; copio il valore in cima allo stack in DX
    MOV AH, 02h     ; stampa di un singolo carattere mediante il
    INT 21h         ; servizio dos INT 21 - 02h
    LOOP _Stampa    ; ripeto CX volte la stampa
    POPA            ; Ripristina i valori nei registri
ENDM
