	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 4
	.globl	_ft_putchar_fd          ## -- Begin function ft_putchar_fd
	.p2align	4, 0x90
_ft_putchar_fd:                         ## @ft_putchar_fd
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
                                        ## kill: def $dil killed $dil killed $edi
	movb	%dil, -1(%rbp)
	movl	%esi, -8(%rbp)
	movl	-8(%rbp), %edi
	leaq	-1(%rbp), %rsi
	movl	$1, %edx
	callq	_write
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
