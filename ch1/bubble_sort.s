	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 4
	.globl	_bubble_sort                    ; -- Begin function bubble_sort
	.p2align	2
_bubble_sort:                           ; @bubble_sort
	.cfi_startproc
; %bb.0:
	cset	w8, ge
	tbnz	w8, #0, LBB0_8
	b	LBB0_4
LBB0_4:                                 ;   in Loop: Header=BB0_3 Depth=2
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #12]
	ldr	w8, [x8, x9, lsl #2]
	ldr	x9, [sp, #24]
	ldr	w10, [sp, #12]
	add	w10, w10, #1
	ldr	w9, [x9, w10, sxtw #2]
	subs	w8, w8, w9
	cset	w8, le
	tbnz	w8, #0, LBB0_6
	b	LBB0_5
LBB0_5:                                 ;   in Loop: Header=BB0_3 Depth=2
	ldr	x8, [sp, #24]
	ldrsw	x9, [sp, #12]
	ldr	w8, [x8, x9, lsl #2]
	str	w8, [sp, #8]
	ldr	x8, [sp, #24]
	ldr	w9, [sp, #12]
	add	w9, w9, #1
	ldr	w8, [x8, w9, sxtw #2]
	ldr	x9, [sp, #24]
	ldrsw	x10, [sp, #12]
	str	w8, [x9, x10, lsl #2]
	ldr	w8, [sp, #8]
	ldr	x9, [sp, #24]
	ldr	w10, [sp, #12]
	add	w10, w10, #1
	str	w8, [x9, w10, sxtw #2]
	b	LBB0_6
LBB0_6:                                 ;   in Loop: Header=BB0_3 Depth=2
	b	LBB0_7
LBB0_7:                                 ;   in Loop: Header=BB0_3 Depth=2
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB0_3
LBB0_8:                                 ;   in Loop: Header=BB0_1 Depth=1
	b	LBB0_9
LBB0_9:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #16]
	add	w8, w8, #1
	str	w8, [sp, #16]
	b	LBB0_1
LBB0_10:
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_print_array                    ; -- Begin function print_array
	.p2align	2
_print_array:                           ; @print_array
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	str	wzr, [sp, #16]
	b	LBB1_1
LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #16]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB1_4
	b	LBB1_2
LBB1_2:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldur	x8, [x29, #-8]
	ldrsw	x9, [sp, #16]
	ldr	w9, [x8, x9, lsl #2]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	b	LBB1_3
LBB1_3:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #16]
	add	w8, w8, #1
	str	w8, [sp, #16]
	b	LBB1_1
LBB1_4:
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	.cfi_def_cfa_offset 80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	str	wzr, [sp, #12]
	adrp	x8, l___const.main.arr@PAGE
	add	x8, x8, l___const.main.arr@PAGEOFF
	ldr	q0, [x8]
	add	x0, sp, #16
	str	x0, [sp]                        ; 8-byte Folded Spill
	str	q0, [sp, #16]
	ldur	q0, [x8, #12]
	stur	q0, [x0, #12]
	mov	w8, #7
	str	w8, [sp, #8]
	ldr	w1, [sp, #8]
	bl	_bubble_sort
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldr	w1, [sp, #8]
	bl	_print_array
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB2_2
	b	LBB2_1
LBB2_1:
	bl	___stack_chk_fail
LBB2_2:
	mov	w0, #0
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%d "

l_.str.1:                               ; @.str.1
	.asciz	"\n"

	.section	__TEXT,__const
	.p2align	2, 0x0                          ; @__const.main.arr
l___const.main.arr:
	.long	64                              ; 0x40
	.long	34                              ; 0x22
	.long	25                              ; 0x19
	.long	12                              ; 0xc
	.long	22                              ; 0x16
	.long	11                              ; 0xb
	.long	90                              ; 0x5a

.subsections_via_symbols
