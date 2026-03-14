.386							; Generación de código para el procesador Intel 80386
.model flat, C					; Modelo de memoria plano usando la convención de llamadas del lenguaje C.

.code							; Comienza la definción de la sección de código

; Complete the procedure
IsValidAssembly PROC

; Prólogo
push ebp
mov ebp,esp

; Salvaguarda de registros
push ebx
push esi

; Acceso a los parámetros
mov eax, [ebp+8]				; a
mov ebx, [ebp+12]				; b
mov ecx, [ebp+16]				; c

; Cuerpo del procedimiento
; Condición 1: comprobar bit 3 de a = 0
mov edx, eax
and edx, 8						; máscara 00001000 (bit 3 de a)
cmp edx, 0
jne fallo

; Condición 2: comprobar bit 5 de b
mov edx, ebx
and edx, 32						; máscara 00100000 (bit 5 de b)

; Obtener bit 2 de c
mov esi, ecx
and esi, 4						; máscara 00000100 (bit 2 de c)

; Comparación de igualdad lógica
cmp edx,0
je b_es_cero					; si bit5(b) = 0

; b = 1 -> c = 1
cmp esi, 0
je fallo						; b = 1 y c = 0 -> fallo
jmp correcto

b_es_cero:
cmp esi,0						; b = 0 y c = 1 -> fallo
jne fallo

correcto:
mov eax, 1
jmp fin

fallo:
mov eax, 0

fin:
; Restauración de registros
pop esi
pop ebx

; Epílogo
pop ebp
ret

IsValidAssembly ENDP

END