%include "asm_io.inc"

segment .data

segment .bss

segment .text
    global asm_main
asm_main:
  enter 0,0
  pusha

  call read_int
  push eax

  call fib_rec
  pop ecx
  call print_int
  call print_nl

  popa
  mov eax, 0
  leave
  ret

fib_rec:
  enter 4,0
  pusha

  mov eax, [ebp + 8]  ;eax = n

  cmp eax, 0          ;if n == 0
  je n_is_zero
  cmp eax, 1          ;if n == 1
  je n_is_one

  dec eax             ; eax = n - 1
  mov ebx, eax        ; ebx = eax wobei ebx = n-2 und eax = n-1 werden soll

  push eax            ; n-1 auf stack pushen
  call fib_rec        ; erste rekursion für fib(n-1) danach ist eax = fib(n-1)
  mov [ebp - 4], eax  ; return wert von fib(n-1) in eax speichern da gleich eax überschrieben wird
  pop ecx             ; oberstes element wieder entfernen

  dec ebx             ; ebx = n-2

  push ebx            ; n-2 auf stack pushen
  call fib_rec        ; zweite rekursion für fib(n-2) danach ist eax = fib(n-2)
  pop ecx             ; oberstes element wieder entfernen

  add eax, [ebp - 4]  ; f(n-1) += f(n-2)
  jmp end_function

n_is_zero:
  mov eax, 0
  jmp end_function

n_is_one:
  mov eax, 1

end_function:
  mov [ebp - 4], eax
  popa
  mov eax, [ebp - 4]
  leave
  ret
