all: recorder reader replay logger

recorder : recorder.cpp mem_share.o records.o deter_recorder.hpp ../shared_data_struct/deter_recorder.h ../shared_data_struct/mem_block.h ../shared_data_struct/base_struct.h
	g++ recorder.cpp mem_share.o records.o -o recorder -O3 -std=gnu++11 -lpthread

mem_share.o : mem_share.cpp mem_share.hpp
	g++ mem_share.cpp -c -o mem_share.o -O3 -std=gnu++11

records.o: records.cpp records.hpp deter_recorder.hpp ../shared_data_struct/base_struct.h
	g++ records.cpp -c -o records.o -O3 -std=gnu++11

reader: reader.cpp records.o
	g++ reader.cpp records.o -o reader -O3 -std=gnu++11

replay: replay.cpp replayer.o records.o mem_share.o
	g++ replay.cpp replayer.o records.o mem_share.o -o replay -O3 -std=gnu++11 -lpthread

replayer.o: replayer.cpp replayer.hpp
	g++ replayer.cpp -c -o replayer.o -O3 -std=gnu++11

logger: logger.cpp mem_share.o
	g++ logger.cpp mem_share.o -o logger -O3 -std=gnu++11 -pthread

flow_extractor: flow_extractor.cpp records.o
	g++ flow_extractor.cpp records.o -o flow_extractor -O3 -std=gnu++11 -lpthread

shmem_reader: shmem_reader.cpp mem_share.o deter_recorder.hpp ../shared_data_struct/deter_recorder.h ../shared_data_struct/mem_block.h ../shared_data_struct/base_struct.h
	g++ shmem_reader.cpp mem_share.o -o shmem_reader -O -std=gnu++11 -lpthread

clean_records:
	sudo rm *:*'->'*:*

clean:
	rm recorder || true
	rm replay || true
	rm reader || true
	rm logger || true
	rm *.o
