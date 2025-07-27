#include<iostream>
using namespace std;

char space[3][3]={{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'X';
bool tie=false;
string n1,n2;

void functionOne()
{
	cout << "\n";
	cout << "    |     |     \n";
	cout << "  " << space[0][0] << " |  " << space[0][1] << "  |  " << space[0][2] << "\n";
	cout << "____|_____|_____\n";
	cout << "    |     |     \n";
	cout << "  " << space[1][0] << " |  " << space[1][1] << "  |  " << space[1][2] << "\n";
	cout << "____|_____|_____\n";
	cout << "    |     |     \n";
	cout << "  " << space[2][0] << " |  " << space[2][1] << "  |  " << space[2][2] << "\n";
	cout << "    |     |     \n\n";	
}

//assign the value to a position in a grid based on what player enters 
void functionTwo() {
	int digit;

	if (token == 'X') {
		cout << n1 << ", entre un chiffre : ";
	}
	else {
		cout << n2 << ", entre un chiffre : ";
	}
	cin >> digit;

	switch (digit) {
		case 1: row = 0; column = 0; break;
		case 2: row = 0; column = 1; break;
		case 3: row = 0; column = 2; break;
		case 4: row = 1; column = 0; break;
		case 5: row = 1; column = 1; break;
		case 6: row = 1; column = 2; break;
		case 7: row = 2; column = 0; break;
		case 8: row = 2; column = 1; break;
		case 9: row = 2; column = 2; break;
		default:
			cout << "Entrée invalide !! Essaie encore.\n";
			functionTwo(); // reload the entry
			return;
	}

	// Case déjà prise ?
	if (space[row][column] != 'X' && space[row][column] != '0') {
		space[row][column] = token;
		token = (token == 'X') ? '0' : 'X';
	}
	else {
		cout << "Case déjà utilisée ! Choisis une autre.\n";
		functionTwo(); // To be sure each player fill a different place at each turn
	}
}

bool functionThree(){
	for(int i=0;i<3;i++)
	{
		if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i] )
		return true;
	}
	if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0] )
	{
		return true;
	} //Check if there's a win
	  //Precisely a horizontal one and a vertical one 
	  
	if((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
		{
		 	return true;//Checks if there's a diagonal win
	 	 }
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (space[i][j] != 'X' && space[i][j] != '0')
				return false;
		}
	} 
	
	  tie=true;
	  return false;
}

int main(){
	cout<<"Nom du premier joueur :";
	getline(cin,n1);
	cout<<"Nom du second joueur :";
	getline(cin,n2);
	
	cout<<n1<< " joue avec X\n";
	cout<<n2<< " joue avec 0\n";

	while (true) {
		functionOne();
		functionTwo();

		if (functionThree()) {
			functionOne();
			if (token == 'X') {
				cout << n2 << " a gagné ! \n";
			} else {
				cout << n1 << " a gagné ! \n";
			}
			break;
		}
		else if (tie) {
			functionOne();
			cout << "Match nul ! \n";
			break;
		}
	}
	cout <<"\nAppuie sur une touche pour quitter...";
	system("pause");
	return 0;
}
