#ifndef NUMBER
#define NUMBER

class Number {
private:
	short int num[200];
public:
	Number(){}
	Number(char *);

	int length;
	bool negative;

	void show();
	bool negative();
	Number & plus(Number &);
	Number & minus(Number &);
};

#endif