INCLUDE Output.inc ; files contenenti le macro di output
.MODEL tiny ; Modello di memoria         
ORG 100h ; il prg inizia all'indirizzo 100h
;--------------------------------------
; segmento dati
;--------------------------------------
.DATA
X db 120d ; Addendo iniziale
Y db 110d ; un addendo
Z db 140d ; altro addendo
S dw ? ; Somma
;--------------------------------------
; segmento codice
;--------------------------------------
.CODE

INIZIO:
; ESEMPIO 1: somma con risultato inferiore al byte
MOV AH, 0 ; Azzero la parte alta del registro AX
MOV AL, X ; Carico il primo addendo dall'indirizzo X
ADD AL, Y ; Aggiungo il secondo addendo dall'indirizzo Y
MOV S, AX ; Salvo la somma (inferiore a 256) nella variabile S
MS_PRINT_INT S ; Stampo la variabile S (vedo 230)
MS_SPAZIO S
; ESEMPIO 2: somma con risultato superiore a 256 (non mi basta un byte!)
; non considero il riporto
MOV AH, 0 ; Azzero la parte alta del registro AX
MOV AL, X ; Carico il primo addendo dall'indirizzo X
ADD AL, Z ; Aggiungo il secondo addendo dall'indirizzo Z
MOV S , AX ; Salvo la somma (superiore a 256) nella variabile S
MS_PRINT_INT S ; Stampo la variabile S (vedo 4: 00000001 00000100)
MS_SPAZIO S
; ESEMPIO 3: somma con risultato superiore a 256 (non mi basta un byte!)
; considero il riporto
MOV AH, 0 ; Azzero la parte alta del registro AX
MOV AL, X ; Carico il primo addendo dall'indirizzo X
ADD AL, Z ; Aggiungo il secondo addendo dall'indirizzo Z
ADC AH, 0 ; Aggiungo il riporto (Carry)
MOV S , AX ; Salvo la somma (superiore a 256) nella variabile S
MS_PRINT_INT S ; Stampo la variabile S (vedo 260: 00000001 00000100)
MS_SPAZIO S
INT 20h ; Termina il programma - equivalente all'int 21h AL=00h
END INIZIO
