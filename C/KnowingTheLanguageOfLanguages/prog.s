	.file	"prog.c"
	.text
	.def	scanf;	.scl	3;	.type	32;	.endef
	.seh_proc	scanf
scanf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfscanf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "**********************************\12\0"
	.align 8
.LC1:
	.ascii "Bem vindo ao jogo de adivinha\303\247\303\243o\12\0"
.LC2:
	.ascii "chute um numero\12\0"
.LC3:
	.ascii "%d\0"
	.align 8
.LC4:
	.ascii "Voc\303\252 acertou o numero secreto!\0"
	.align 8
.LC5:
	.ascii "O n\303\272mero que voc\303\252 colocou \303\251 MENOR que o n\303\272mero correto\0"
	.align 8
.LC6:
	.ascii "O n\303\272mero que voc\303\252 colocou \303\251 MAIOR que o n\303\272mero correto\0"
.LC7:
	.ascii "N\303\272mero errado!\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rcx
	call	printf
	leaq	.LC1(%rip), %rcx
	call	printf
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$42, -8(%rbp)
	movl	$5, -4(%rbp)
	jmp	.L6
.L11:
	leaq	.LC2(%rip), %rcx
	call	printf
	leaq	-16(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rcx
	call	scanf
	movl	-16(%rbp), %eax
	cmpl	%eax, -8(%rbp)
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -12(%rbp)
	cmpl	$0, -12(%rbp)
	je	.L7
	leaq	.LC4(%rip), %rcx
	call	printf
	jmp	.L8
.L7:
	movl	-16(%rbp), %eax
	cmpl	%eax, -8(%rbp)
	jle	.L9
	leaq	.LC5(%rip), %rcx
	call	printf
	jmp	.L10
.L9:
	leaq	.LC6(%rip), %rcx
	call	printf
.L10:
	leaq	.LC7(%rip), %rcx
	call	printf
.L6:
	movl	-4(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -4(%rbp)
	testl	%eax, %eax
	jne	.L11
.L8:
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 10.3.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
