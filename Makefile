
er.out: emergencyRoomMain.o linked_list_hospital.o patient.o
		gcc -o er.out emergencyRoomMain.o patient.o linked_list_hospital.o
emergencyRoomMain.o: emergencyRoomMain.c patient.h linked_list_hospital.h
	gcc -c emergencyRoomMain.c
linked_list_hospital.o: linked_list_hospital.h linked_list_hospital.c patient.h
	gcc -c linked_list_hospital.c
patient.o: patient.c patient.h
	gcc -c patient.c
clean:
	rm -f *.o er.out
