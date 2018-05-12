/*Singly linked list was used for the students, classes and students within class. Credits to Sir Obrero for these functions on how to insert and to delete*/

typedef struct studenttag{
	char firstName[50];
	char lastName[50];
	char studentNumber[20];
	int maxUnitsAllowed;
	int remainingUnits;
	struct studenttag *nextStudent;
}STUDENT;

typedef struct enrolledStudentstag{
	char stdnum[20];
	struct enrolledStudentstag *nextSnum;
}IN_CLASS;

typedef struct classtag{
	char courseCode[20];
	char section[20];
	int courseCredits;
	int classCapacity;
	int remainingSlots;
	IN_CLASS *enrolledStudents;
	struct classtag *nextClass;
}CLASS;

/*-------------------------------------------------------MENU MODULES--------------------------------------------------------------------*/
void header(){
	system("cls||clear");
	printf("\n");
	printf("\t\t   ○○○○○○  ○○  ○○○○○○○  ○○○○○○○○  ○○○○○○○\n");
	printf("\t\t  ○○○      ○○  ○○          ○○     ○○     \n");
	printf("\t\t    ○○○    ○○  ○○○○○○○     ○○     ○○○○○○○\n");
	printf("\t\t      ○○○  ○○  ○○          ○○     ○○     \n");
	printf("\t\t  ○○○○○○   ○○  ○○○○○○○     ○○     ○○○○○○○\n");
	printf("\t\t    Student-To-Class Management System\n\n");
}

void mainMenu(int *opt){
	printf("\t    ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼  ☼  ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼\n");
	printf("\t    ☼                                                 ☼\n");
	printf("\t    ☼\t\t [1] Add a Student                    ☼\n");
	printf("\t    ☼\t\t [2] Add a Class                      ☼\n");
	printf("\t    ☼\t\t [3] Assign Student to Class          ☼\n");
	printf("\t    ☼\t\t [4] View Students                    ☼\n");
	printf("\t    ☼\t\t [5] View Classes                     ☼\n");
	printf("\t    ☼\t\t [6] Delete Student                   ☼\n");
	printf("\t    ☼\t\t [7] Delete Classes                   ☼\n");
	printf("\t    ☼\t\t [8] Edit Class details               ☼\n");
	printf("\t    ☼\t\t [9] Exit                             ☼\n");
	printf("\t    ☼                                                 ☼\n");
	printf("\t    ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼  ☼  ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼\n");
	printf("\t\t\t\tChoice: ");
	scanf("%i", opt);
}

void viewStudentsSubMenu(char *opt){
	getc(stdin);
	printf("\t    ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼  ☼  ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼\n");
	printf("\t    ☼                                                 ☼\n");
	printf("\t    ☼\t  [a] View All Students                       ☼\n");
	printf("\t    ☼\t  [b] View Specific Student                   ☼\n");
	printf("\t    ☼\t  [c] View Students under Class               ☼\n");
	printf("\t    ☼\t  [d] View Students with insufficient units   ☼\n");
	printf("\t    ☼\t  [e] Exit                                    ☼\n");
	printf("\t    ☼                                                 ☼\n");
	printf("\t    ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼  ☼  ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼\n");
	printf("\t\t\t\tChoice: ");
	scanf("%c", opt);
}

void viewClassesSubMenu(char *opt){
	getc(stdin);
	printf("\t\t ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼  ☼  ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼\n");
	printf("\t\t ☼                                         ☼\n");
	printf("\t\t ☼\t  [f] View All Classes             ☼\n");
	printf("\t\t ☼\t  [g] View Specific Class          ☼\n");
	printf("\t\t ☼\t  [h] View Available Classes       ☼\n");
	printf("\t\t ☼\t  [i] Exit                         ☼\n");
	printf("\t\t ☼                                         ☼\n");
	printf("\t\t ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼  ☼  ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼ ☼\n");
	printf("\t\t\t\tChoice: ");
	scanf("%c", opt);
}

/*---------------------------------------------INSERT STUDENT IN STUDENT LINKED LIST-------------------------------------------------*/
void insertStudentAtHead(STUDENT** studentHead, STUDENT* newElement){
	if ((*studentHead) != NULL)
		newElement->nextStudent = (*studentHead);
	(*studentHead) = newElement;
}

void insertStudentAtTail(STUDENT** studentHead, STUDENT* newElement){
	STUDENT* tail = (*studentHead);
	if ((*studentHead) == NULL){
		insertStudentAtHead(studentHead, newElement);
	}else{
		while (tail->nextStudent != NULL)
			tail = tail->nextStudent;
	}
	tail->nextStudent = newElement;
}

void insertStudentAtMiddle(STUDENT **studentHead, STUDENT *newElement){
	STUDENT *stalker = *studentHead, *ptr = NULL;
	ptr = stalker->nextStudent;
	while(strcmp(newElement->firstName, ptr->firstName) > 0){ //strcmp returns >0, <0 or 0
		if(ptr->nextStudent == NULL && strcmp(newElement->firstName, ptr->firstName) > 0){ 
			insertStudentAtTail(studentHead, newElement);
			break;
		}
		ptr = ptr->nextStudent;
		stalker = stalker->nextStudent;
	}
	if(strcmp(newElement->firstName, ptr->firstName) < 0){
		newElement->nextStudent = ptr;
		stalker->nextStudent = newElement;
	}
}

//sorting students' names by their first names 
void insertStudentinList(STUDENT **studentHead, STUDENT *newElement){
	//if list is empty or if newElement name is < studentHead->firstName
	if((*studentHead) == NULL || strcmp(newElement->firstName, (*studentHead)->firstName) < 0)
		insertStudentAtHead(studentHead, newElement);
	else if((*studentHead)->nextStudent == NULL ){ //at least two nodes; last node == NULL
	 insertStudentAtTail(studentHead, newElement);
	}
	else insertStudentAtMiddle(studentHead, newElement); 
}

/*-----------------------------------------------------ADD STUDENT MODULES------------------------------------------------------------*/

//gets the node where the student number is located if there is any
STUDENT* searchStudentNumber(STUDENT **studentHead, char *studentNum){
	STUDENT *ptr = (*studentHead);
	while (ptr != NULL){ //run through the list
		if (strcmp(ptr->studentNumber, studentNum) == 0) //if student number input matches that of the student number in the list
			return ptr;
		ptr = ptr->nextStudent;
	}
	return ptr; //ptr == NULL; student number was not found
}

//checks the standard UP student number format xxxx-xxxxx
int studentNumFormatChecker(char *studentNum){
	if (studentNum[4] == '-' && strlen(studentNum) == 10){
		return 1;
	}else{
		printf("\t\t      Notice: Invalid student number!\n");
		return 0;
	}
}

void askStudentNumber(char *s){
	printf("\t\t\t Student number: ");
	getc(stdin);
	scanf("%[^\n]s", s);
}

void askName(char *f, char *l){
	printf("\t\t\t First name: ");
	getc(stdin);
	scanf("%[^\n]s", f);
	
	printf("\t\t\t Last name: ");
	getc(stdin);
	scanf("%[^\n]s", l);
}

void askStudentUnits(int *u){
	printf("\t\t\t Maximum Units Allowed: ");
	scanf("%i", u);
}

STUDENT* createStudentNode(char *f, char *l, char *s, int u, int r){
	STUDENT *newNode = (STUDENT *) malloc(sizeof(STUDENT));
	strcpy(newNode->firstName, f);
	strcpy(newNode->lastName, l);
	strcpy(newNode->studentNumber, s);
	newNode->maxUnitsAllowed = u;
	newNode->remainingUnits = r;
	newNode->nextStudent = NULL;
	return newNode;
}

void addStudent(STUDENT **studentHead, int *ctr){
	header();
	printf("\n\t\t\t\tADD A STUDENT\n");
	STUDENT *validCheck = NULL;
	char first[50], last[50], stdnum[20];
	int units, formatCheck = 0;
	
	printf("\n\t\t\tPlease fill up the following:\n");
	askStudentNumber(stdnum);
	//check format and search student number
	formatCheck = studentNumFormatChecker(stdnum);
	validCheck = searchStudentNumber(studentHead, stdnum);
	
	//if format is correct and the student number is not yet in the list
	if (formatCheck != 0 && validCheck == NULL){
		askName(first, last);
		askStudentUnits(&units);
		
		//inserts the node created in the sorted student linked list
		insertStudentinList(studentHead, createStudentNode(first, last, stdnum, units, units));

		++(*ctr);
		printf("\n\t\t  Notice: \"%s\" successfully added!\n", stdnum);
	}else if (validCheck != NULL)
		printf("\n\t\t   Notice: \"%s\" already exists!\n", stdnum);
}

/*-------------------------------------------------VIEW STUDENT/S MODULES---------------------------------------------------------------*/
void printStudentInfo(STUDENT *p){
	printf("\t\t\t Name: %s %s\n", p->firstName, p->lastName);
	printf("\t\t\t Student Number: %s\n", p->studentNumber);
	printf("\t\t\t Maximum Units Allowed: %i\n", p->maxUnitsAllowed);
	printf("\t\t\t       Remaining Units: %i\n\n", p->remainingUnits);
}

//prints all the students' information
void viewAllStudents(STUDENT **head){
	header();
	printf("\n\t\t\t     VIEW ALL STUDENTS\n\n");
	if ((*head) != NULL){
		STUDENT *temp = (*head);
		while(temp != NULL) {
			printStudentInfo(temp);
			temp = temp->nextStudent;
		}
	}else printf("\n\t\t\t    Notice: No student(s).\n");
}

void viewSpecificStudent(STUDENT **studentHead){
	header();
	printf("\n\t\t\t    VIEW SPECIFIC STUDENT\n\n");
	if ((*studentHead) != NULL){
		STUDENT *validCheck = NULL;
		char stdnum[20];
		int formatCheck = 0;
	
		askStudentNumber(stdnum);
		//checks format and existence in list
		formatCheck = studentNumFormatChecker(stdnum);
		validCheck = searchStudentNumber(studentHead, stdnum);
		
		//if the format is correct and if the student number exits then the info can be viewed
		if (formatCheck != 0 && validCheck != NULL){
			printf("\n");
			printStudentInfo(validCheck);
		}else printf("\t\t\t \"%s\" does not exist!\n", stdnum);
	}else printf("\n\t\t\t    Notice: No student(s).\n");
}

//returns the node with the same subject and section as that of user's input
CLASS* courseAndSectionNodeLocator(CLASS **classHead, char *subject, char *section){
	CLASS *stalker = NULL;
	if ((*classHead) != NULL){ //if list !empty
		stalker = (*classHead);
		while (stalker != NULL){ //run through the list
			//if there's a courseCode and subject combination match, the node containing that info will be returned
			if (strcmp(stalker->courseCode, subject) == 0 && strcmp(stalker->section, section) == 0)
				return stalker;
			stalker = stalker->nextClass;
		}
		return stalker;	//stalker == NULL; match not found
	}
}

void askCourseCode(char *c){
	printf("\t\t\t   Course code: ");
	getc(stdin);
	scanf("%[^\n]s", c);
}

void askSection(char *s){
	printf("\t\t\t   Section: ");
	getc(stdin);
	scanf("%[^\n]s", s);
}

//prints the information of students under that class
void viewStudentsUnderClass(STUDENT **studentHead, CLASS **classHead){
	header();
	printf("\n\t\t\t VIEW STUDENTS UNDER CLASS\n\n");
	if ((*classHead) != NULL && (*studentHead) != NULL){
		char course[20], sec[20], stdnum[20]; 
		CLASS *n = NULL; 
	
		askCourseCode(course);
		askSection(sec);
		n = courseAndSectionNodeLocator(classHead, course, sec);
		if (n != NULL){	//if user's input matched a node in the class linked list
			IN_CLASS *ptr = (n->enrolledStudents); //class list or the list of students who have enlisted in the class
			STUDENT *s = NULL;
			
			//access the class list
			if (ptr != NULL){ //if the class list is not empty
				while(ptr != NULL){
					s = searchStudentNumber(studentHead, ptr->stdnum); 
					printf("\n");
					printStudentInfo(s);
					ptr = ptr->nextSnum;
				}
			}else printf("\n\t      Notice: No students have enlisted in \"%s %s\"\n", course, sec);
		}else printf("\n\t\t    Notice: \"%s %s\" doesn't exist.\n", course, sec);
	}else if ((*classHead) == NULL) printf("\n\t\t\t  Notice: No class(es).\n");
	else printf("\n\t\t\t   Notice: No student(s).\n");
}

//prints the information of students who still have remaining units to spend
void viewStudentsWithInsufficiency(STUDENT **studentHead){
	header();
	printf("\n\t\t    VIEW STUDENTS WITH INSUFFICIENT UNITS\n\n");
	STUDENT *temp = NULL;
	int ctr; 
	if ((*studentHead) != NULL){
		temp = (*studentHead);
		while(temp != NULL){
			if (temp->remainingUnits != 0){
				printStudentInfo(temp);
				ctr++;
			}
			temp = temp->nextStudent;
		}
		if (ctr == 0) printf("\n\t\t  Notice: All students have complete units.\n");
	}else printf("\n\t\t\t    Notice: No student(s).\n");
}

/*-----------------------------------------------------SAVE STUDENT MODULE-------------------------------------------------------------*/
//saves the student linked list in students.txt even if it doesn't exist in the directory
void saveToStudentTxt(STUDENT **studentHead, int ctr){
	int i;
	STUDENT *n = (*studentHead);
	FILE *fp = fopen("students.txt", "w");
	
	fprintf(fp, "%i\n", ctr); //prints the number of students in the list
	for(i = 0; i < ctr; ++i){
		fprintf(fp, "%s\n", n->firstName);
		fprintf(fp, "%s\n", n->lastName);
		fprintf(fp, "%s\n", n->studentNumber);
		fprintf(fp, "%i\n", n->maxUnitsAllowed);
		fprintf(fp, "%i\n", n->remainingUnits);
		n = n->nextStudent;
	}
	fclose(fp);
}

/*------------------------------------------------------LOAD STUDENT MODULE-----------------------------------------------------------*/
//loads the contents of students.txt if it exists in the directory and stores the data into the student linked list
void loadStudentTxt(STUDENT **studentHead, int *ctr){
	char first[50], last[50], stdnum[20];
	int units, remaining;
	
	FILE *fp = fopen("students.txt", "r");
	if (fp != NULL){ //if students.txt exists
		fscanf(fp, "%i\n", ctr);
		//while the end of file is not yet reached, the data will be read continuously and the following operations will apply
		while(!feof(fp)){ 
			fgets(first, 50, fp);
			first[strlen(first)-1] = '\0';
	
			fgets(last, 50, fp);
			last[strlen(last)-1] = '\0';
			
			fscanf(fp, "%s\n", stdnum);
			fscanf(fp, "%i\n", &units);
			fscanf(fp, "%i\n", &remaining);
			
			//create node and insert in the student linked list
			insertStudentinList(studentHead, createStudentNode(first, last, stdnum, units, remaining));			
		}
		fclose(fp);
	}
}

/*-----------------------------------------------------------DELETE STUDENT-----------------------------------------------------------*/
void deleteStudentAtHead(STUDENT** studentHead){
	STUDENT* toDelete = (*studentHead);
	if ((*studentHead) != NULL){
		(*studentHead) = toDelete->nextStudent; //assign the second element to studentHead
		toDelete->nextStudent = NULL; //isolate toDelete or the original studentHead
		free(toDelete);
	}
}

void deleteStudentAtTail(STUDENT** studentHead){
	STUDENT *stalker = NULL, *toDelete = NULL;
	stalker = *studentHead; //stalker->first node
	toDelete = stalker->nextStudent; //toDelete->node after stalker
	while(toDelete->nextStudent != NULL){
		stalker = toDelete;
		toDelete = toDelete->nextStudent;
	}
	free(toDelete);
	stalker->nextStudent = NULL;
}

void deleteStudentNode(STUDENT** studentHead, STUDENT *found){
	STUDENT *stalker = (*studentHead), *toDelete = stalker->nextStudent;
	if (strcmp(found->studentNumber, stalker->studentNumber) == 0) //at first try, match was found = means the match is at the studentHead
		deleteStudentAtHead(studentHead);
	else{
		while(toDelete != NULL){
			if(strcmp(found->studentNumber, toDelete->studentNumber) == 0) break; //match found; but position is still uncertain
			else{
				stalker = toDelete;
				toDelete = toDelete->nextStudent;
			}
		}
		//will catch the matched name from a while ago if there is any
		if(toDelete->nextStudent == NULL) 
			deleteStudentAtTail(studentHead);
		else{
			stalker->nextStudent = toDelete->nextStudent;
			toDelete->nextStudent = NULL;
			free(toDelete);
		}			
	}
}

//deletes student number in the IN_CLASS enrolledStudents list under CLASS
void deleteStudentNumberINCLASSAtHead(CLASS	*classList){
	IN_CLASS* toDelete = classList->enrolledStudents;
	if (classList != NULL){
		classList->enrolledStudents = toDelete->nextSnum; //assign the second element to head
		toDelete->nextSnum = NULL; //isolate toDelete or the original head
		free(toDelete);
		classList->remainingSlots += 1;
	}
}

void deleteStudentNumberINCLASSAtTail(CLASS *classList){
	IN_CLASS *stalker = NULL, *toDelete = NULL;
	stalker = classList->enrolledStudents; //stalker->first node
	toDelete = stalker->nextSnum; //toDelete->node after stalker
	while(toDelete != NULL){
		stalker = toDelete;
		toDelete = toDelete->nextSnum;
	}
	free(toDelete);
	stalker->nextSnum = NULL;
	classList->remainingSlots += 1;
}

void deleteStudentNumberINCLASS(CLASS *classListToDeleteFrom, char *stdnum){
	IN_CLASS *stalker = classListToDeleteFrom->enrolledStudents, *toDelete = stalker->nextSnum;
	if (strcmp(stdnum, stalker->stdnum) == 0) //matched at first try
		deleteStudentNumberINCLASSAtHead(classListToDeleteFrom);
	else{
		while(toDelete != NULL){
			if(strcmp(stdnum, toDelete->stdnum) == 0) break;
			else{
				stalker = toDelete;
				toDelete = toDelete->nextSnum;
			}
		}
		//will catch the matched name from a while ago if there is any
		if(stalker->nextSnum == NULL) //tail of the list
			deleteStudentNumberINCLASSAtTail(classListToDeleteFrom);
		else{
			stalker->nextSnum = toDelete->nextSnum;
			toDelete->nextSnum = NULL;
			free(toDelete);
			classListToDeleteFrom->remainingSlots += 1;
		}			
	}
}

//search the student number in each IN_CLASS list of each CLASS and delete if it would be detected
void deleteStudentNumberUnderClass(CLASS **classHead, char *stdnum){
	if ((*classHead) != NULL){
		CLASS *ptr = (*classHead);
		while(ptr != NULL){
			if (ptr->enrolledStudents != NULL)
				deleteStudentNumberINCLASS(ptr, stdnum);
			ptr = ptr->nextClass;
		}
	}
}

void deleteStudent(STUDENT **studentHead, CLASS **classHead, int *ctr){
	header();
	printf("\n\t\t\t      DELETE A STUDENT\n\n");
	if ((*studentHead) != NULL){
		char stdnum[20], choice;
		askStudentNumber(stdnum);
		STUDENT *s = searchStudentNumber(studentHead, stdnum);
		if (s != NULL){ //if student number exists
			printf("\n");
			printStudentInfo(s);
			printf("\t   Are you sure you want to delete \"%s\" [Y|N]? ", s->studentNumber);
			getc(stdin);
			scanf("%c", &choice);
            if (toupper(choice) == 'Y'){
				deleteStudentNumberUnderClass(classHead, stdnum);
				deleteStudentNode(studentHead, searchStudentNumber(studentHead, stdnum));
				printf("\n\t\t    Notice: Record successfully deleted!\n");
				--(*ctr);
			}
		}else printf("\n\t\t    Notice: \"%s\" doesn't exist!\n", stdnum);
	}else printf("\n\t\t\t    Notice: No student(s).\n");
}

//executed after saving
void destroyStudentList(STUDENT** studentHead){
	if ((*studentHead) != NULL){ //if list !empty
		while((*studentHead) != NULL)
			deleteStudentAtHead(studentHead);
	}
}

/*------------------------------------------------INSERT CLASS IN CLASS LINKED LIST--------------------------------------------------*/
void insertClassAtHead(CLASS** classHead, CLASS* newElement){
	if ((*classHead) != NULL)
		newElement->nextClass = (*classHead);
	(*classHead) = newElement;
}

void insertClassAtTail(CLASS** classHead, CLASS* newElement){
	CLASS* tail = (*classHead);
	if ((*classHead) == NULL){
		insertClassAtHead(classHead, newElement);
	}else{
		while (tail->nextClass != NULL)
			tail = tail->nextClass;
	}
	tail->nextClass = newElement;
}

void insertClassAtMiddle(CLASS **classHead, CLASS *newElement){
	CLASS *stalker = *classHead, *ptr = NULL;
	ptr = stalker->nextClass;
	while((strcmp(newElement->courseCode, ptr->courseCode) > 0) || strcmp(newElement->courseCode, ptr->courseCode) == 0){ //strcmp returns >0, <0 or 0
		if(ptr->nextClass == NULL && (strcmp(newElement->section, ptr->section) > 0 || strcmp(newElement->courseCode, ptr->courseCode) > 0)){ 
			insertClassAtTail(classHead, newElement);
			break;
		}
		stalker = ptr;
		ptr = ptr->nextClass;
	}
	if((strcmp(newElement->courseCode, ptr->courseCode) < 0) && (strcmp(newElement->section, ptr->section) < 0)){
		newElement->nextClass = ptr;
		stalker->nextClass = newElement;
	}
}

//insert class node; sorted
void insertClassinList(CLASS **classHead, CLASS *newElement){
	if((*classHead) == NULL || (strcmp(newElement->courseCode, (*classHead)->courseCode) < 0) || (strcmp(newElement->courseCode, (*classHead)->courseCode) == 0 && strcmp(newElement->section, (*classHead)->section) < 0)){
		insertClassAtHead(classHead, newElement);
		
	}else if((*classHead)->nextClass == NULL ){ //at least two nodes; last node == NULL
	 insertClassAtTail(classHead, newElement);
	 
	}else insertClassAtMiddle(classHead, newElement); 
}

/*---------------------------------------------------------ADD CLASS MODULE--------------------------------------------------------*/
void askCourseCredits(int *cocr){
	printf("\t\t\t   Course Credits: ");
	scanf("%i", cocr);
}

void askClassCapacity(int *clca){
	printf("\t\t\t   Class Capacity: ");
	scanf("%i", clca);
}

CLASS* createClassNode(char *c, char *s, int cocr, int clca, int rs){
	CLASS *newNode = (CLASS *) malloc(sizeof(CLASS));
	strcpy(newNode->courseCode, c);
	strcpy(newNode->section, s);
	newNode->courseCredits = cocr;
	newNode->classCapacity = clca;
	newNode->remainingSlots = rs;
	newNode->enrolledStudents = NULL;
	newNode->nextClass = NULL;
	return newNode;
}

void addClass(CLASS **classHead, int *ctr){
	header();
	printf("\n\t\t\t\tADD A CLASS\n\n");
	CLASS *validCheck = NULL;
	char course[20], sec[20];
	int units, size;
	
	askCourseCode(course);
	askSection(sec);
	//checks if course code and section combination exists or not
	validCheck = courseAndSectionNodeLocator(classHead, course, sec);
	if (validCheck == NULL){ //if the course code and section combination does not exist, able to add
		askCourseCredits(&units);
		askClassCapacity(&size);
		
		//insert class in the class linked list
		insertClassinList(classHead, createClassNode(course, sec, units, size, size));
		++(*ctr);
		printf("\n\t\t Notice: \"%s %s\" successfully added!\n", course, sec);
	}else printf("\n\t\t   Notice: \"%s %s\" already exists!\n", course, sec);
}

/*----------------------------------------------INSERT STUDENT IN IN_CLASS LINKED LIST---------------------------------------------*/
//insert student number in IN_CLASS linked list within CLASS after assigning the student to that class
//insert at head
void insertStudentNumberINCLASS(IN_CLASS **classList, IN_CLASS *newElement){
	if((*classList) != NULL)
		newElement->nextSnum = (*classList);
	(*classList) = newElement;
}
/*----------------------------------------------ASSIGN STUDENT TO CLASS MODULES------------------------------------------------*/
//looks for the student number in the IN_CLASS linked list of a certain class
int searchStudentNumberinINCLASS(IN_CLASS *classList, char *s){
	IN_CLASS *ptr = classList;
	while (ptr != NULL){ //run through the list
		if (strcmp(ptr->stdnum, s) == 0) //name matched a name in the list
			return 1;
		ptr = ptr->nextSnum;
	}
	return 0;
}

IN_CLASS* createINCLASSNode(char *stdnum){
	IN_CLASS *newNode = (IN_CLASS *) malloc(sizeof(IN_CLASS));
	strcpy(newNode->stdnum, stdnum);
	newNode->nextSnum = NULL;
	return newNode;	
}

void assignStudentToClass(STUDENT **studentHead, CLASS **classHead){
	header();
	printf("\n\t\t\t  ASSIGN STUDENT TO CLASS\n\n");
	if ((*studentHead) != NULL && (*classHead) != NULL){
		STUDENT *validStudentCheck = NULL;
		CLASS *validClassCheck = NULL;
		char stdnum[20], course[20], sec[20];
		int formatCheck, foundINCLASS; 
	
		askStudentNumber(stdnum);
		//checks student number format and check if a node in the student linked list with that student number exists or not
		formatCheck = studentNumFormatChecker(stdnum);
		validStudentCheck = searchStudentNumber(studentHead, stdnum);
	
		//if the format is correct, node from the student linked list with that student number exists and the student's remaining units is greater than 0, then she can be assigned to an available class
		if (formatCheck != 0 && validStudentCheck != NULL && validStudentCheck->remainingUnits > 0){
			askCourseCode(course);
			askSection(sec);
		
			//checks if a node in the class linked list with that course and section combination exists or not
			validClassCheck = courseAndSectionNodeLocator(classHead, course, sec);
		
			//if that class node exists and its remaining slots is greater than 0, then student number can be added to it
			if (validClassCheck != NULL && validClassCheck->remainingSlots > 0){
			
				//checks if the student number is already in the class list
				foundINCLASS = searchStudentNumberinINCLASS(validClassCheck->enrolledStudents, stdnum);
			
				//if the student number was not found in the class list and the student's remaining units can still accomodate the course credits, then the student can be added into the list
				if (foundINCLASS == 0 && ((validStudentCheck->remainingUnits) - (validClassCheck->courseCredits) >= 0)){
					//insert student in the class list
					insertStudentNumberINCLASS(&(validClassCheck->enrolledStudents), createINCLASSNode(stdnum));
				
					//updates the class' remaining slots and the student's remaining units
					validClassCheck->remainingSlots -= 1;
					(validStudentCheck->remainingUnits) -= (validClassCheck->courseCredits);
					printf("\n\t Notice: \"%s\" successfully enlisted to \"%s %s\"\n", stdnum, course, sec);
				}else if(foundINCLASS != 0) 
					printf("\n\t\tNotice: \"%s\" is already in the list!\n", stdnum);
				else if((validStudentCheck->remainingUnits) - (validClassCheck->courseCredits) < 0)
					printf("\n    Notice: Unable to enlist \"%s\" to \"%s %s\" due to unit count.\n", stdnum, course, sec);
			}else if (validClassCheck == NULL) 
				printf("\n\t\t    Notice: \"%s %s\" doesn't exist!\n", course, sec);
			else if (validClassCheck->remainingSlots == 0) 
				printf("\n\t\t   Notice: \"%s %s\" is already full!\n", course, sec);
		}else if ((formatCheck == 0 || formatCheck != 0) && validStudentCheck == NULL) 
			printf("\n\t\t      Notice: \"%s\" doesn't exist!\n", stdnum);
		else if (validStudentCheck->remainingUnits == 0) printf("\"%s\" has complete units already.\n", stdnum);
	}else printf("\n\t\t\t Notice: Insufficient data.\n");
}

/*----------------------------------------------------VIEW CLASS/ES MODULES----------------------------------------------------------*/
void printClassInfo(CLASS *c){
	printf("\t\t\t  Course Code: %s\n", c->courseCode);
	printf("\t\t\t  Section: %s\n", c->section);
	printf("\t\t\t  Course Credits: %i\n", c->courseCredits);
	printf("\t\t\t  Maximum Class Capacity: %i\n", c->classCapacity);
	printf("\t\t\t         Remaining Slots: %i\n\n", c->remainingSlots);
}

//prints all the classes' information
void viewAllClasses(CLASS **head){ //printing all elements of the list
	header();
	printf("\n\t\t\t      VIEW ALL CLASSES\n\n");
	if ((*head) != NULL){
		CLASS *temp;
		temp = (*head);
		while(temp != NULL){
			printClassInfo(temp);
			temp = temp->nextClass;
		}
	}else
		printf("\n\t\t\t    Notice: No Class(es).\n");
}

void viewSpecificClass(CLASS **head){
	header();
	printf("\n\t\t\t    VIEW SPECIFIC CLASS\n\n");
	if ((*head) != NULL){
		char subject[20], section[20];
		askCourseCode(subject);
		askSection(section);
	
		CLASS *n = courseAndSectionNodeLocator(head, subject, section);
		if (n != NULL){ //if the combination exists, print info
			printf("\n");
			printClassInfo(n);
		}else
			printf("\n\t\t    Notice: \"%s %s\" does not exist!\n", subject, section);
	}else printf("\n\t\t\t    Notice: No Class(es).\n");
}

//prints the classes with remaining slots
void viewAvailableClasses(CLASS **head){
	header();
	printf("\n\t\t\t   VIEW AVAILABLE CLASSES\n\n");
	CLASS *temp = NULL;
	int ctr; 
	
	if ((*head) != NULL){
		temp = (*head);
		while(temp != NULL){
			if (temp->remainingSlots > 0){
				printClassInfo(temp);
				ctr++;
			}
			temp = temp->nextClass;
		}
		if (ctr == 0) printf("\n\t\t\t  Notice: No available class(es).\n");
	}else
		printf("\n\t\t\t    Notice: No Class(es).\n");
}

/*---------------------------------------------------EDIT CLASS MODULES-------------------------------------------------------------*/
//counts the students in the class list
int InClassCounter(IN_CLASS *classList){
	int i = 0;
	if(classList != NULL){
		IN_CLASS *temp = classList;
		while (temp != NULL){
			++i;
			temp = temp->nextSnum;
		}
		return i;
	}else return 0;
}

void editClassDetails(CLASS **classHead){
	header();
	printf("\n\t\t\t    EDIT CLASS DETAILS\n\n");
	char course[20], sec[20], choice;
	int temp, i;
	askCourseCode(course);
	askSection(sec);
	
	//identify if course and section combination exists
	CLASS *n = courseAndSectionNodeLocator(classHead, course, sec);
	if (n != NULL){ //if the combination exists
		//if the class list is not empty, only the class capacity can be edited by the user
		if(n->enrolledStudents != NULL){
			printf("\n");
			printClassInfo(n);
			printf("\t   Are you sure you want to edit \"%s %s\"[Y|N]?  ", course, sec);
			getc(stdin);
			scanf("%c", &choice);
            if (toupper(choice) == 'Y'){
				printf("\n\t\t\t  Enter new class capacity: ");
				scanf("%i", &temp);
				i = InClassCounter(n->enrolledStudents);
				if (temp >= i){
					n->classCapacity = temp;
					n->remainingSlots = temp;
					printClassInfo(n);
					printf("\n\t\t  Notice: \"%s %s\" successfully edited!\n", course, sec);
				}else{ 
					printf("\n Notice: Unable to change size due to the %i student/s enlisted in \"%s %s\"\n", i, course, sec);				
				}
			}
		}else{ //else if the class is empty, all the information about the class can be edited
			printf("\n");
			printClassInfo(n);
			printf("\t   Are you sure you want to edit \"%s %s\"[Y|N]? ", course, sec);
			getc(stdin);
			scanf("%c", &choice);
            if (toupper(choice) == 'Y'){
				askCourseCode(course);
				strcpy(n->courseCode, course);	
				askSection(sec);
				strcpy(n->section, sec);
				askCourseCredits(&temp);
				n->courseCredits = temp;
				askClassCapacity(&i);
				n->classCapacity = i;
				n->remainingSlots = i;
				printf("\n");
				printClassInfo(n);
				printf("\n\t\t  Notice: \"%s %s\" successfully edited!\n", course, sec);
			}
		}
	}else printf("\n\t\t      Notice: \"%s %s\" doesn't exist!\n", course, sec);
}

/*--------------------------------------------------------DELETE CLASS MODULES--------------------------------------------------*/
//updates the students' remaining units upon the deletion of the class their enlisted to
void updateStudentsUnderClass(STUDENT **studentHead, CLASS *course){
	STUDENT *s = NULL;
	IN_CLASS *ptr = course->enrolledStudents;
	while (ptr != NULL){
		s = searchStudentNumber(studentHead, ptr->stdnum);
		s->remainingUnits += course->courseCredits;
		ptr = ptr->nextSnum;
	}
}

/*------------------------------------------delete nodes in the IN_CLASS linked list of a class----------------------------------*/
void deleteStudentsUnderClassAtHead(IN_CLASS **classList){
	IN_CLASS* toDelete = (*classList);
	if ((*classList) != NULL){
		(*classList) = toDelete->nextSnum; //assign the second element to head
		toDelete->nextSnum = NULL; //isolate toDelete or the original head
		free(toDelete);
	}
}

void deleteStudentsUnderClass(IN_CLASS **classList){
	if ((*classList) != NULL){
		while((*classList) != NULL) deleteStudentsUnderClassAtHead(classList);
	}
}

//deletes a class node in the class linked list
void deleteClassAtHead(CLASS** classHead){
	CLASS* toDelete = (*classHead);
	if ((*classHead) != NULL){
		(*classHead) = toDelete->nextClass; //assign the second element to head
		toDelete->nextClass = NULL; //isolate toDelete or the original head
		free(toDelete);
	}
}

void deleteClassAtTail(CLASS **classHead){
	CLASS *stalker = NULL, *toDelete = NULL;
	stalker = (*classHead); //stalker->first node
	toDelete = stalker->nextClass; //toDelete->node after stalker
	while(toDelete != NULL){
		stalker = toDelete;
		toDelete = toDelete->nextClass;
	}
	free(toDelete);
	stalker->nextClass = NULL;
}

void deleteClassNode(CLASS **classHead, CLASS *classList){
	CLASS *stalker = (*classHead), *toDelete = stalker->nextClass;
	if (strcmp(classList->courseCode, stalker->courseCode) == 0 && strcmp(classList->section, stalker->section) == 0)
		deleteClassAtHead(classHead);
	else{
		while(toDelete != NULL){
			if(strcmp(classList->courseCode, toDelete->courseCode) == 0 && strcmp(classList->section, toDelete->section) == 0) break;
			else{
				stalker = toDelete;
				toDelete = toDelete->nextClass;
			}
		}
		//will catch the matched name from a while ago if there is any
		if(stalker->nextClass == NULL) 
			deleteClassAtTail(classHead);
		else{
			stalker->nextClass = toDelete->nextClass;
			toDelete->nextClass = NULL;
			free(toDelete);
		}			
	}
}

void deleteClass(CLASS **classHead, STUDENT **studentHead, int *ctr){
	header();
	printf("\n\t\t\t      DELETE A CLASS\n\n");
	if ((*classHead) != NULL){
		char course[20], sec[20], choice;
		askCourseCode(course);
		askSection(sec);
		CLASS *n = courseAndSectionNodeLocator(classHead, course, sec);
		if (n != NULL){ //if the combination exists
			printf("\n");
			printClassInfo(n);
			printf("\t   Are you sure you want to delete \"%s %s\" [Y|N]? ", n->courseCode, n->section);
			getc(stdin);
			scanf("%c", &choice);
            if (toupper(choice) == 'Y'){
				if (n->enrolledStudents != NULL){ //if the class list is not empty
				updateStudentsUnderClass(studentHead, n);
				deleteStudentsUnderClass(&(n->enrolledStudents));
				}
				deleteClassNode(classHead, n);
				printf("\n\t\t    Notice: Record successfully deleted!\n");
				--(*ctr);
			}
		}else printf("\n\t\t   Notice: \"%s %s\" not doesn't exist!\n", course, sec);
	}else printf("\n\t\t\t    Notice: No Class(es).\n");
}

//destroy the class linked list upon saving
void destroyClassListAtHead(CLASS **classHead, STUDENT **studentHead){
	CLASS *toDelete = (*classHead);
	if ((*classHead) != NULL){
		(*classHead) = toDelete->nextClass; //assign the second element to head
		toDelete->nextClass = NULL; //isolate toDelete or the original head
		if (toDelete->enrolledStudents != NULL)
			deleteStudentsUnderClass(&(toDelete->enrolledStudents));
		free(toDelete);
	}
}

void destroyClassList(CLASS **classHead, STUDENT **studentHead){
	if ((*classHead) != NULL)
		while ((*classHead) != NULL) destroyClassListAtHead(classHead, studentHead);
}

/*---------------------------------------------------SAVE TO CLASS TXT MODULES-------------------------------------------------------*/

//saves to class.txt even if it doesn't exist in the directory
void saveToClassTxt(CLASS **classHead, int ctr){
	int i, j, k;
	CLASS *n = (*classHead);
	IN_CLASS *m = NULL;
	FILE *fp = fopen("classes.txt", "w");
	
	fprintf(fp, "%i\n", ctr);
	for(i = 0; i < ctr; ++i){
		fprintf(fp, "%s\n", n->courseCode);
		fprintf(fp, "%s\n", n->section);
		fprintf(fp, "%i\n", n->courseCredits);
		fprintf(fp, "%i\n", n->classCapacity);
		fprintf(fp, "%i\n", n->remainingSlots);
		
		j = InClassCounter(n->enrolledStudents);
		m = n->enrolledStudents;
		fprintf(fp, "%i\n", j);
		//prints (in file) the student numbers listed in the class
		for(k = 0; k < j; ++k){
			fprintf(fp, "%s\n", m->stdnum);
			m = m->nextSnum;
		}
		n = n->nextClass;
	}
	fclose(fp);
}

/*----------------------------------------------------------LOAD CLASS MODULES--------------------------------------------------------*/
//loads classes.txt if it exists in the directory
void loadClassTxt(CLASS **classHead, int *ctr){
	char sec[20], course[20], stdnum[20];
	int i, j, units, size, slots;
	
	CLASS *n = NULL;
	FILE *fp = fopen("classes.txt", "r");
	
	if (fp != NULL){ //the file exists
		fscanf(fp, "%i\n", ctr);
		while(!feof(fp)){ //while the end of file is not reached
			fgets(course, 20, fp);
			course[strlen(course)-1] = '\0';
	
			fgets(sec, 20, fp);
			sec[strlen(sec)-1] = '\0';
			
			fscanf(fp, "%i\n", &units);
			fscanf(fp, "%i\n", &size);
			fscanf(fp, "%i\n", &slots);
			n = createClassNode(course, sec, units, size, slots);
			insertClassinList(classHead, n);
			fscanf(fp, "%i\n", &i);
			//lists down again the student number into the IN_CLASS linked list
			for (j = 0; j < i; ++j){
				fscanf(fp, "%s\n", stdnum);
				insertStudentNumberINCLASS(&(n->enrolledStudents), createINCLASSNode(stdnum));
			}
		}
		fclose(fp);
	}
}
