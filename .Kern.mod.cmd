cmd_/home/sedxlyfe/Q3/Kern.mod := printf '%s\n'   Kern.o | awk '!x[$$0]++ { print("/home/sedxlyfe/Q3/"$$0) }' > /home/sedxlyfe/Q3/Kern.mod
