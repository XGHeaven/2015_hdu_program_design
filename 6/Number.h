#ifndef NUMBER
#define NUMBER

class Number {
private:
	short int num[200];
	Number & _plus(Number &);
	Number & _minus(Number &);
public:
	Number(){}
	Number(char *);

	int length;

	void show();
	bool negative;
	void revert();
	int compare(Number &);
	Number & plus(Number &);
	Number & minus(Number &);
};

#endif