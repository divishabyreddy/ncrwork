#include<stdio.h>
int main()
{
	enum operations{
		addition=1,
	     substraction,
		 multiplication,
		 division
	};
 	int choice;
	float real1, img1,real2,img2;
	printf_s("enter the real and imaginary part of the first number");
	scanf_s("%f %f", &real1, &img1);
	printf_s("enter the real and imaginary part of the second number");
	scanf_s("%f %f", &real2, &img2);
	printf_s("the numbers you entered are \n 1.%f + %fi \n 2.%f + %fi", real1, img1, real2, img2);
	printf_s("\n 1.addition \n 2.substraction \n 3.multilication \n 4.division\n");
	printf_s("enter your choice");
	scanf_s("%d", &choice);
	switch(choice)
	{
	case 1:
		printf_s("the addition of the two comlex numbers is\n");
		printf_s("%f+i%f", (real1 + real2), (img1 + img2));
		break;
	case 2:
		printf_s("the substraction of the two comlex numbers is\n");
		printf_s("%f+i%f", (real1 - real2), (img1 - img2));
		break;
	case 3:
		printf_s("the multiplication of the two complex numbers is\n");
		printf_s("%f+i%f", (real1*real2 - img1 * img2), (real1*img2 + real2 * img1));
		break;
	case 4:
		{
		int x, y, z;
			if (real2 == 0 && img2 == 0)
				printf("Division by 0 + 0i isn't allowed.");
			else
			{
				x = real1*real2 + img1*img2;
				y = img1*real2 - real1*img2;
				z = real2*real2 + img2*img2;

				if ((x%z  == 0 )&& (y%z == 0))
				{
					if (y / z >= 0)
						printf("Division of the complex numbers = %d + %di", x / z, y / z);
					else
						printf("Division of the complex numbers = %d- %di", x / z, y / z);
				}
				else if (x%z == 0 && y%z != 0)
				{
					if (y / z >= 0)
						printf("Division of two complex numbers = %d + %d/%di", x / z, y, z);
					else
						printf("Division of two complex numbers = %d- %d/%di", x / z, y, z);
				}
				else if (x%z != 0 && y%z == 0)
				{
					if (y / z >= 0)
						printf("Division of two complex numbers = %d/%d + %di", x, z, y / z);
					else
						printf("Division of two complex numbers = %d -%d/%di", x, z, y / z);
				}
				else
				{
					if (y / z >= 0)
						printf("Division of two complex numbers = %d/%d + %d/%di", x, z, y, z);
					else
						printf("Division of two complex numbers = %d/%d -%d/%di", x, z, y, z);
				}
			}
		}

	}
	scanf_s("%d", &choice);
	return 0;

}