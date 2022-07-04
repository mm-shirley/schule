all: primzahlen.o primzahlen primzahlen_fast.o primzahlen_fast

primzahlen.o:primzahlen.c
        cc -c primzahlen.c

primzahlen:primzahlen.o
        cc -o primzahlen primzahlen.o


primzahlen_fast.o:primzahlen_fast.c
        cc -c primzahlen_fast.c

primzahlen_fast:primzahlen_fast.o
        cc -o primzahlen_fast primzahlen_fast.o
