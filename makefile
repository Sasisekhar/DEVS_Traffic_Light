# -DNO_LOG_STATE
# -DDEBUG_DELAY
sim:
	mkdir -p sim_output
	g++ -std=gnu++20 -I main/ main/main.cpp -o main/run && cd sim_output && ../main/run

clean:
	rm -f *.o
	rm -f *.csv
	rm -f run


embedded:
	idf.py build
	idf.py flash -p /dev/ttyACM0
	idf.py monitor -p /dev/ttyACM0

e_clean:
	idf.py clean