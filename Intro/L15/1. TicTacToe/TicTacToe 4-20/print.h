#ifndef print_h
#define print_h

class printscreen{

public:
			printscreen();
			void clear();
			void intro();
			void map();
			void printmap();
			void stop();
private:
			char grid[3][3];
         int move;
			int a, b;
};
#endif
