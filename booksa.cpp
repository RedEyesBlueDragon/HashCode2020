#include <iostream>
#include <vector>
#include <random>
#include <cassert>

class library
{

public:
	int bookNumber;
	int proccesDay;
	int shipDay;
	int bookArray[1000000];
	std::vector<int> sendbookArray;
	int sendBook;
	bool isSign;


	
};



int Scan(std::vector<library>& v){
	int size = v.size();

	for (int i = 0; i < size; i++)
	{
		
		if (v[i].isSign == false)
		{
			v[i].proccesDay--;

			if (v[i].proccesDay == 0)
			{
				v[i].isSign = true;
				
			}

			return i;	
		}
	}

	return -1;

}




    
int main()
{
	int bNumber, libs, days, lbook, lsign, lship;
	int bookScore[1000000];

	

	
	
	std::vector<library> vect;

	

	scanf("%d",&bNumber);
	scanf("%d",&libs);
	scanf("%d",&days);

	for (int i = 0; i < bNumber; i++)
	{
		scanf("%d",&bookScore[i]);
	}

	for (int i = 0; i < libs; i++)
	{
		
		scanf("%d",&lbook);
		scanf("%d",&lsign);
		scanf("%d",&lship);

		library lb;
        lb.bookNumber = lbook;
        lb.proccesDay = lsign;
        lb.shipDay = lship;
        lb.isSign = false;
        lb.sendBook = 0;

		for (int i = 0; i < lbook; i++)
		{
			scanf("%d",&lb.bookArray[i]);
		}
    	
            
		vect.push_back( lb );
	}


	for (int j = days; j > 0; j--)
	{
		Scan(vect);


		for (int i = 0; i < libs; i++)
		{
			
			if (vect[i].isSign = true)
			{
				int shipDayL =  vect[i].shipDay;
				for (int z = 0; z < shipDayL; z++)
				{
					int limit = vect[i].bookNumber;
					for (int k = 0; k < limit; k++)
					{
						if (vect[i].bookArray[k] != -1)
						{
							vect[i].sendbookArray.push_back(vect[i].bookArray[k]);
							vect[i].bookArray[k] = -1;
							vect[i].sendBook ++;
							break;
						}

					}
					

				}


			}


		}



		


	}





	int libCount = 0;
	for (int i = 0; i < libs; i++)
	{
		if(vect[i].isSign == true)
		{
			libCount++;	
		}
	}


	printf("%d\n", libCount);

	for (int i = 0; i < libs; i++)
	{
		printf("%d %d\n", i, vect[i].sendBook);

		for (int k = 0; k < vect[i].sendBook-1; k++)
		{
			printf("%d ", vect[i].sendbookArray[k]);
		}
        printf("%d", vect[i].sendbookArray[vect[i].sendBook-1]);

		printf("\n");

	}


}
