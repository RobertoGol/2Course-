#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>


int start(char main_word[10]) //Представление игры передает функции главное слово 
{
	printf("________Игра наборщик________\n");
	printf("Правила игры:\nБерется произвольное слово. Из букв этого слова состовляются другие слова. Игроки называют слова по очереди, тот, кто не смог назвать слово проиграет.\n");

	

	printf("\nПроизвольное слово:\n%s\n", main_word); //вывод главного слова что мы передали функции

	
}

void printf_field(char main_word[], char use_words[10][10], int k) // Вывод игрового поля
{
	int i;

	printf("Главное слово: %s\n", main_word);

	printf("Использованные слова: ");
	for(i=0;i<k;i++)
		printf("%s, ", use_words[i]);
	printf("\n");
}

void sortirovka(char* a, int n) //Сортировка букв
{
	int t=0, i, f;
	char m;
	while(t<n-1)
	{
		f=n-1;
		for(i=n-1; i>t; i--)
			if(a[i-1]>a[i])
			{
				m=a[i];
				a[i]=a[i-1];
				a[i-1]=m;
				f=i;
			}
		t=f;
	}
}

void sortirovka_word(char word[10], char word_sort[10]) //Сортировка слова
{
	int q;
	q=strlen(word);

	strcpy(word_sort, word);
	sortirovka(word_sort, q);
}

void sortirovka_lexicona(char lexicon[82][10], char lexicon_sort[82][10]) //Сортировка лексикона
{
	int i, q;

	for(i=0;i<82;i++)
	{
		q=strlen(lexicon[i]);
		strcpy(lexicon_sort[i], lexicon[i]);
		sortirovka(lexicon_sort[i],q);
	}
}

void end(int turn, char word[10], int f) //Окончание игры
{

	if(f==1)
	{
		if(turn==1)
			printf("%i Игрок  ввел главное слово, поздравляем %i Игрока с победой!!!", turn, turn+1);
		if(turn==2)
			printf("%i Игрок  ввел главное слово, поздравляем %i Игрока с победой!!!", turn, turn-1);
	}

	if(f==2)
	{
		if(turn==1)
			printf("%i Игрок  ввел использованное слово, поздравляем %i Игрока с победой!!!", turn, turn+1);
		if(turn==2)
			printf("%i Игрок  ввел использованное слово, поздравляем %i Игрока с победой!!!", turn, turn-1);
	}
	if(f==3)
	{
		if(turn==1)
			printf("%i Игрок ввел слово: %s, которого нет в словаре, поздравляем %i Игрока с победой!!!", turn, word, turn+1);
		if(turn==2)
			printf("%i Игрок ввел слово: %s, которого нет в словаре, поздравляем %i Игрока с победой!!!", turn, word, turn-1);
	}

	if(f==4)
	{
		if(turn==1)
			printf("%i Игрок ввел слово: %s, которое не совпадает со всеми буквами из главного, поздравляем %i Игрока с победой!!!", turn, word, turn+1);
		if(turn==2)
			printf("%i Игрок ввел слово: %s, которое не совпадает со всеми буквами из главного, поздравляем %i Игрока с победой!!!", turn, word, turn-1);
	}

	
}

int proverka(char lexicon[82][10], char use_words[11][10], char main_word[10], char word[10], char main_word_sort[10], char word_sort[10], int k, int turn) //Проверка слова
{
	int point=1, i=0, f=0;
	if(strcmp(word, main_word)!=0) //Если слово не равно главному
	{
		while(i<k)
		{
			if(strcmp(word, use_words[i])!=0) //Если слово не равно использованным
				i++;
			else
			{
				i=k;
				point=0;
				f=2;
				end(turn, word, f);
			}
		}


		i=0;
		while(i<82 && point==1)
			if(strcmp(word, lexicon[i])==0) //Если слово равно слову что в лексиконе
				i=82;
			else
			{
				i++;
				if(i==82)
				{
					point=0;
					f=3;
					end(turn, word, f);
				}
			}


		if(strcmp(main_word_sort,word_sort)!=0 && point==1)
		{
			point=0;
			f=4;
			end(turn, word, f);
		}
	}
	else
	{
		point=0;
		f=1;

		end(turn, word, f);
	}

	return point;
}
int main() //Программа
{
	char word[10]; //Слово, куда записываем
	char use_words[11][10]={"0","0","0","0","0","0","0"     }; //Использованные слова
	char main_word[10]; //Главное слово
	char word_sort[10]; //Слово, для проверки
	char main_word_sort[10]; //Главное слово для проверки
	//словарь
	char lexicon[82][10]={};


	int e;
	srand(time(NULL));
	e=0 + rand() % 80; //Выбор № главного слова

	strcpy(main_word, lexicon[e]); //Выбираем Главное слово
	sortirovka_word(main_word, main_word_sort);  //Сортируем главное слово для проверки

	int k=0;  //Кол-во слов
	int turn=1; //Ход игрока

	int point=1;
	int Game=1;
	int j;

	 char game=start(main_word); //Определяется режим игры и выходит приветсвующий текст

	while(Game==1)
	{
		if(turn==1 && point==1) //Ход первого игрока
		{
			printf("\nИгрок №1: ");
			gets(word);
			sortirovka_word(word, word_sort); printf("\n"); //Сортируем слово для проверки

			if(proverka(lexicon, use_words, main_word, word, main_word_sort, word_sort, k, turn)==1)
			{
				strcpy(use_words[k], word);

				turn=2;
				k++;
			}
			else
				point=0;


			if(point==1)
				printf_field(main_word, use_words, k);
		}

		if(turn==2 && point==1) //Ход второго игрока
		{
				printf("\nИгрок №2: ");
				gets(word);
				sortirovka_word(word, word_sort); printf("\n"); //Сортируем слово для проверки

				if(proverka(lexicon, use_words, main_word, word, main_word_sort, word_sort, k, turn)==1)
				{
					strcpy(use_words[k], word);

					turn=1;
					k++;
				}
				else
					point=0;


				if(point==1)
					printf_field(main_word, use_words, k);
			}
