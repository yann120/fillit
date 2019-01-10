commit:
	git add .
	git commit -m "On avance! (ce commit a été créé automatiquement)"

pull:
	git pull 42 master
	git pull github master

push:
	git push 42 master
	git push github master

sync: commit pull push 
