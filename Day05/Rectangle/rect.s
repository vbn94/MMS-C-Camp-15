	.file	"rect.c"
	.text
	.globl	rectInfo
	.type	rectInfo, @function
rectInfo:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -8(%rbp)
	movsd	%xmm1, -16(%rbp)
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	pxor	%xmm0, %xmm0
	comisd	-8(%rbp), %xmm0
	jnb	.L2
	pxor	%xmm0, %xmm0
	comisd	-16(%rbp), %xmm0
	jb	.L6
.L2:
	movl	$-1, %eax
	jmp	.L5
.L6:
	movsd	-8(%rbp), %xmm0
	addsd	-16(%rbp), %xmm0
	addsd	%xmm0, %xmm0
	movq	-24(%rbp), %rax
	movsd	%xmm0, (%rax)
	movsd	-8(%rbp), %xmm0
	mulsd	-16(%rbp), %xmm0
	movq	-32(%rbp), %rax
	movsd	%xmm0, (%rax)
	movl	$0, %eax
.L5:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	rectInfo, .-rectInfo
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
