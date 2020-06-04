.name "(dbendu & ymanilow & ediego & jgroleo)'s champ"
.comment "zork defeated"

init:
	sti		r1, %:cycle, %1
	add		r10, r10, r10

cycle:
	live	%1
	zjmp	%:cycle
