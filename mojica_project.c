/*
Author: Jyra Coleen E. Mojica
Project: Student-to-Class Management System
CMSC 21 ST-3L
Dec 9, 2016

Tested to be fully functional on gcc 4.8.4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mojica_project.h"

int main(){
	STUDENT *studentHead = NULL;
	CLASS *classHead = NULL;
	int choice, studentCtr = 0, classCtr = 0;
	char suboption;
	
	loadStudentTxt(&studentHead, &studentCtr);
	loadClassTxt(&classHead, &classCtr);
	header();
	do{
		mainMenu(&choice);
		switch(choice){
			case 1: addStudent(&studentHead, &studentCtr); break;
			case 2: addClass(&classHead, &classCtr); break;
			case 3: assignStudentToClass(&studentHead, &classHead); break;
			case 4:
				do{
					viewStudentsSubMenu(&suboption);
					switch(suboption){
						case 'a': viewAllStudents(&studentHead); break;
						case 'b': viewSpecificStudent(&studentHead); break;
						case 'c': viewStudentsUnderClass(&studentHead, &classHead); break;
						case 'd': viewStudentsWithInsufficiency(&studentHead); break;
						case 'e': break;
						default: printf("\nInvalid input! Choices a-e only.\n"); break;
					}
				}while(suboption != 'e');
				break;
			case 5:
				do{
					viewClassesSubMenu(&suboption);
					switch(suboption){
						case 'f': viewAllClasses(&classHead); break;
						case 'g': viewSpecificClass(&classHead); break;
						case 'h': viewAvailableClasses(&classHead); break;
						case 'i': break;
						default: printf("\nInvalid input! Choices f-i only.\n"); break;
					}
				}while(suboption != 'i');
				break;
			case 6: deleteStudent(&studentHead, &classHead, &studentCtr); break;
			case 7: deleteClass(&classHead, &studentHead, &classCtr); break;
			case 8: editClassDetails(&classHead); break;
			case 9: saveToStudentTxt(&studentHead, studentCtr); destroyStudentList(&studentHead); 
					saveToClassTxt(&classHead, classCtr); destroyClassList(&classHead, &studentHead); break;
			default: printf("\nInvalid input! Choices 1-9 only.\n"); break;
		}
	}while(choice != 9);

	return 0;
}
