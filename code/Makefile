<<<<<<< HEAD
comp1: cg.c expr.c gen.c main.c misc.c scan.c stmt.c tree.c
	cc -o comp1 -g cg.c expr.c gen.c main.c misc.c scan.c stmt.c tree.c
=======
comp1: cg.c expr.c gen.c interp.c main.c scan.c tree.c
	cc -o comp1 -g cg.c expr.c gen.c interp.c main.c scan.c tree.c
>>>>>>> dbb1bd9c1f55a964abea3638f439ef50ef2d730e

clean:
	rm -f comp1 *.o *.s out

<<<<<<< HEAD
test: comp1 input01
	./comp1 input01
	cc -o out out.s
	./out
=======
test: comp1
	./comp1 input01
	cc -o out out.s
	./out
	./comp1 input02
	cc -o out out.s
	./out
>>>>>>> dbb1bd9c1f55a964abea3638f439ef50ef2d730e
