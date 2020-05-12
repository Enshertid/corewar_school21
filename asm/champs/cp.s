.name           "42"
.comment        "Just a basic Winner Program"











entree:	live	%1		# entree
	ld	:tirf,r5
	zjmp	%1
	ld	%0,r5
#comment
      #comment
check:
tir:	sti	r1,%:tirf,%1
	ld	%2304,r10
	ld	%1,r5
	ld	%0,r11
	ld	%4,r3
tirf:	live	%42
	fork	%:tir
