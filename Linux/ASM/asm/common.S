.text
.align 2

.macro ASM_FUNC_BEGIN funcName
.align 2
.global \funcName
\funcName:
.endm

.macro ASM_FUNC_END
ret
.endm

.macro SIGN_EXTENSION arg0, arg1
  sxtw \arg0, \arg1
.endm
