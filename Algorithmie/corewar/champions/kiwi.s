.name "kiwi"
.comment "kiwi powa"

entry:
	sti		r1, %:live, %1
	ld		%0, r16
	fork	%:move

live:
	live	%1337
	zjmp	%:live

move:
	ld		%57672448, r1
	ld		%134443012, r2
	ld		%459632, r3
	ld		%83887619, r4
	ld		%1879113733, r5
	st		r1, 200
	st		r2, 199
#03700300   r1 push r3
#	     08037004   r2 push r4
#                00070370   r3
#					     05000603   r4 push r5
#								 70010005   r5 push r1
