	.file	"aspace.c"
	.comm	global,4,4
	.section	.rodata
.LC0:
	.string	"Address of main is %p\n"
.LC1:
	.string	"Address of global is %p\n"
.LC2:
	.string	"Address of local is %p\n"
.LC3:
	.string	"Address of p is %p\n"
.LC4:
	.string	"Address of d is %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$5, -20(%rbp)
	movl	$128, %edi
	call	malloc
	movq	%rax, -16(%rbp)
	movl	$5, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movl	$main, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$global, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
