#ifndef battle_h
#define battle_h
//5-22-2012

class battleship{

public:
         battleship();
			void intro();
			void reset();
			void fill();
			void select();
			void print();
			int a, b, c;
			int col;
			char row;

private:
			char playnavy [8][8];
			char compnavy [8][8];

};
#endif