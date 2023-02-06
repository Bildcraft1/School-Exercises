# Scheduling e gestione dei processi

## Scheduling

| Job | Durata | Slice |
|---|---|---|
| j1 | 15 | 0 |
| j2 | 20 | 10 |
| j3 | 10 | 15 |
| j4 | 25 | 20 |

### MLFQ

Tslice = 5 ms

| Job | Durata | Slice | Priorità |
|---|---|---|---|
| j1 | 15 | 0 | 0 |
| j2 | 20 | 10 | 1 |
| j3 | 10 | 15 | 2 |
| j4 | 25 | 20 | 3 |