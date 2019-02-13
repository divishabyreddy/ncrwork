#include<stdio.h>
int main() {
	char* color[7];
	color[0] = "red";
	color[1] = "green";
	color[2] = "blue";
	color[3] = "white";
	color[4] = "black";
	color[5] = "yellow";
	
	printf("What is the meaning of color: %d\n", color);
	
	printf("b.What is the meaning of(color + 2):%d\n", color + 2);
	
	printf("c.What is the value of *color :%s\n", *color);
	
	printf("	d.What is the value of *(color + 2) :%s\n", *(color + 2));
	 
	printf("e.How do color[5] and *(color + 5) differ :%s %s\n", color[5], *(color + 5));
}