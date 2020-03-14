#include <stdio.h>

int main(){
	int book_1,book_2,book_3,book_4,book_5,book_6,book_7,book_8,book_9,book_10;
	scanf("%d %d %d %d %d %d %d %d %d %d",&book_10,&book_1,&book_2,&book_3,&book_4,&book_5,&book_6,&book_7,&book_8,&book_9);
	int a;
	a = book_10 - (book_1 + book_2 + book_3 + book_4 + book_5 + book_6 + book_7 + book_8 + book_9);
	printf("%d\n",a);
}