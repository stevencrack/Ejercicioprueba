primera : error1.pdf
error1.pdf : datosrk1.txt  error1.py
	python error1.py

datosrk1.txt : rk4_1.cpp
	c++ rk4_1.cpp -o r
	./r > datosrk1.txt

segunda : error2.pdf
error2.pdf : datosrk2.txt  error2.py
	python error2.py

datosrk2.txt : rk4_2.cpp
	c++ rk4_2.cpp -o s
	./s > datosrk2.txt
