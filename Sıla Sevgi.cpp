﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define studentSize 273


typedef struct {
	char name[30];
	int number;
	int grade;

}Student;


int sequentialSecondarySearchForIntArray(int d[],int size,int key,int liss[]);
int sequentialSecondarySearchForStudentGrade(Student d[], int key, int liss[]);
int sequentialSecondarySearchForStudentName(Student d[], char* key, int liss[]);

int sequentialPrimarySearchForIntArray(int d[], int size, int key); 
int sequentialPrimarySearchForStudentNumber(Student d[], int key);
int sequentialPrimarySearchForStudentName(Student d[], char* key);

int binarySecondarySearchForStudentGrade(Student d[], int key,int liss[]);

int binaryPrimarySearchForIntArray(int d[],int size,int key);
int binaryPrimarySearchForStudentNumber(Student d[],int key);
int binaryPrimarySearchForStudentName(Student d[], char*key);

void quickSortForIntArray(int d[], int left, int right);
void quickSortForStudentName(Student d[],int left,int right);
void quickSortForStudentGrade(Student d[], int left, int right);
void quickSortForStudentNumber(Student d[], int left, int right);

void readData(Student *st);
void swap(int& x, int& y);
void swapStudent(Student &x,Student &y);

int main() {
	setlocale(LC_ALL, "Turkish");

	int d1[] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	int d2[] = { 3,44,48,5,47,15,36,26,27,2,48,5,19,50,48 };
	int const size1 = sizeof(d1) / sizeof(d1[0]);
	int const size2 = sizeof(d2) / sizeof(d2[0]);

	
	quickSortForIntArray(d1, 0, size1 - 1);
	int pos = binaryPrimarySearchForIntArray(d1, size1, 3);
	printf("array1-binary-search-3::index:%2d number:%d\n",pos,d1[pos]);
	pos = binaryPrimarySearchForIntArray(d1, size1, 5);
	printf("array1-binary-search-5::index:%2d number:%d\n", pos, d1[pos]);
	pos = binaryPrimarySearchForIntArray(d1, size1, 48);
	printf("array1-binary-search-48::index:%2d number:%d\n\n", pos, d1[pos]);
	
	pos = sequentialPrimarySearchForIntArray(d2, size2, 3);
	printf("array2-linear-search-3 ::index:%d    number:%d\n", pos, d2[pos]);
	int result[size2];
	int num = sequentialSecondarySearchForIntArray(d2, size2, 5, result);
	printf("array2-linear-search-5 ::indexes:");
	for (int i = 0; i < num; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
	int result2[size2];
	num = sequentialSecondarySearchForIntArray(d2, size2, 48, result2);
	printf("array2-linear-search-48::indexes:");
	for (int i = 0; i < num; i++) {
		printf("%d ", result2[i]);
	}
	printf("\n\n");
	


	Student students[studentSize];
	readData(students);
	
	int result21[10];
	char name[] = "MEHMET �PEK";
	pos = sequentialSecondarySearchForStudentName(students, name,result21);
	printf("linear-secondary-search-name:MEHMET �PEK\n");
	for (int i = 0; i < pos; i++) {
		printf("number:%d grade:%d name:%s\n", students[result21[i]].number, students[result21[i]].grade, students[result21[i]].name);
	}
	printf("\n");



	quickSortForStudentName(students, 0, studentSize - 1);
	char name2[]="DEN�Z U�UR";
	pos = binaryPrimarySearchForStudentName(students, name2);
	printf("binary-primary-search-name:DEN�Z U�UR\n");
	printf("number:%d grade:%d name:%s\n\n", students[pos].number, students[pos].grade, students[pos].name);

	pos = sequentialPrimarySearchForStudentNumber(students, 2019556465);
	printf("linear-primary-search-number:2019556465\n");
	printf("number:%d grade:%d name:%s\n\n", students[pos].number, students[pos].grade, students[pos].name);

	quickSortForStudentNumber(students, 0, studentSize - 1);
	pos = binaryPrimarySearchForStudentNumber(students, 2018556011);
	printf("binary-primary-search-number:2018556011\n");
	printf("number:%d grade:%d name:%s\n\n", students[pos].number, students[pos].grade, students[pos].name);


	int results3[10];
	int num2 = sequentialSecondarySearchForStudentGrade(students, 100, results3);
	printf("linear-secondary-grade-100-results:\n");
	for (int i = 0; i < num2; i++) {
		printf("number:%d grade:%d name:%s\n", students[results3[i]].number, students[results3[i]].grade, students[results3[i]].name);
	}
	printf("\n");

	quickSortForStudentGrade(students, 0, studentSize - 1);
	int results4[10];
	num2 = binarySecondarySearchForStudentGrade(students, 73, results4);
	printf("binary-secondary-grade-73-results:\n");
	for (int i = 0; i < num2; i++) {
		printf("number:%d grade:%d name:%s\n", students[results4[i]].number, students[results4[i]].grade, students[results4[i]].name);
	}
	printf("\n");
	
	int results5[10];
	num2 = binarySecondarySearchForStudentGrade(students, 0, results5);
	printf("binary-secondary-grade-0-results:\n");
	for (int i = 0; i < num2; i++) {
		printf("number:%d grade:%d name:%s\n", students[results5[i]].number, students[results5[i]].grade, students[results5[i]].name);

	}

}

int binarySecondarySearchForStudentGrade(Student d[], int key, int liss[]) {
	int left = 0;
	int right = studentSize - 1;
	int q;
	int counter = 0;
	while (left <= right) {
		q = (left + right) / 2;
		if (d[q].grade == key) {
			liss[counter++] = q;
			int upCounter = q + 1, downCounter = q - 1;
			while (d[upCounter].grade == key)
				liss[counter++] = upCounter++;
			while (d[downCounter].grade == key)
				liss[counter++] = downCounter--;
			return counter;                                        
		}
		else if (d[q].grade < key)
			left = q + 1;
		else
			right = q - 1;
	}
	return counter;
}


int sequentialPrimarySearchForStudentName(Student d[], char* key) {
	for (int i = 0; i < studentSize; i++) {
		if (strcmp(d[i].name, key) == 0)
			return i;
	}
	return -1;
}
int sequentialPrimarySearchForStudentNumber(Student d[], int key) {
	for (int i = 0; i < studentSize; i++) {
		if (d[i].number == key)
			return i;
	}
	return -1;
}
int sequentialPrimarySearchForIntArray(int d[], int size, int key) {
	for (int i = 0; i < size; i++) {
		if (d[i] == key)
			return i;
	}
	return -1;
}


int binaryPrimarySearchForStudentName(Student d[], char* key) {
	int q;
	int left = 0;
	int right = studentSize - 1;
	while (left <= right) {
		q = (left + right) / 2;
		if (strcmp(d[q].name,key)==0)
			return q;
		else if (strcmp(d[q].name, key) > 0)
			right = q - 1;
		else
			left = q + 1;     
	}
	return -1;
}
int binaryPrimarySearchForStudentNumber(Student d[], int key) {
	int q;
	int left = 0;
	int right = studentSize - 1;
	while (left <= right) {
		q = (left + right) / 2;
		if (d[q].number == key)
			return q;
		else if (d[q].number > key)
			right = q - 1;
		else
			left = q + 1;
	}
	return -1;
}
int binaryPrimarySearchForIntArray(int d[], int size, int key) {
	int q;
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		q = (left + right) / 2;
		if (d[q] == key)
			return q;
		else if (d[q] > key)    
			right = q - 1;
		else
			left = q + 1;
	}
	return -1;
}


int sequentialSecondarySearchForStudentGrade(Student d[], int key, int liss[]) {
	int c = 0;
	for (int i = 0; i < studentSize; i++) {
		if (d[i].grade == key)
			liss[c++] = i;
	}
	return c;
}
int sequentialSecondarySearchForIntArray(int d[], int size, int key, int liss[]) {
	int c = 0;
	for (int i = 0; i < size; i++) {
		if (d[i] == key) {
			liss[c] = i;
			c++;
		}
			
	}
	return c;
}
int sequentialSecondarySearchForStudentName(Student d[], char* key, int liss[]) {
	int c = 0;
	for (int i = 0; i < studentSize; i++) {
		if (strcmp(d[i].name, key) == 0)
			liss[c++] = i;
	}
	return c;
}


void quickSortForStudentNumber(Student d[], int left, int right) {
	int j = left, k = right;
	int q = d[(left + right) / 2].number;

	while (j <= k) {

		while ((j < right) && d[j].number < q)
			j++;
		while ((k > left) && (d[k].number > q))
			k--;

		if (j <= k) {
			swapStudent(d[j], d[k]);
			k--; j++;
		}
	}

	if (k > left)
		quickSortForStudentNumber(d, left, k);
	if (j < right)
		quickSortForStudentNumber(d, j, right);
}
void quickSortForStudentGrade(Student d[], int left, int right) {
	int j = left, k = right;
	int q = d[(left + right) / 2].grade;

	while (j <= k) {

		while ((j < right) && d[j].grade < q)
			j++;
		while ((k > left) && (d[k].grade > q))
			k--;

		if (j <= k) {
			swapStudent(d[j], d[k]);
			k--; j++;
		}
	}

	if (k > left)
		quickSortForStudentGrade(d, left, k);
	if (j < right)
		quickSortForStudentGrade(d, j, right);
}
void quickSortForStudentName(Student d[], int left, int right) {
	int j = left, k = right;
	int q = d[(left + right) / 2].name[0];

	while (j <= k) {
		
		while ((j < right) && d[j].name[0] < q)
			j++;
		while ((k > left) && (d[k].name[0] > q))
			k--;

		if (j <= k) {
			swapStudent(d[j], d[k]);
			k--; j++;
		}
	}

	if (k > left)
		quickSortForStudentName(d, left, k);
	if (j < right)
		quickSortForStudentName(d, j, right);
}
void quickSortForIntArray(int d[], int left, int right) {
	int j = left, k = right;
	int q = d[(left + right) / 2];

	while (j <= k) {

		while ((j < right) && d[j] < q)
			j++;
		while ((k > left) && (d[k] > q))
			k--;

		if (j <= k) {
			swap(d[j], d[k]);
			k--; j++;
		}
	}

	if (k > left)
		quickSortForIntArray(d, left, k);
	if (j < right)
		quickSortForIntArray(d, j, right);

}


void readData(Student* st) {
	int counter = 0;
	FILE*f;
	f = fopen("data.txt", "r");
	while (!feof(f)) {
		fscanf(f, "%d,%[^,],%d\n", &st[counter].number, st[counter].name, &st[counter].grade);
		counter++;
	}
	fclose(f);

}

void swapStudent(Student& x, Student& y) {
	Student temp = x;
	x = y;
	y = temp;
}

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

