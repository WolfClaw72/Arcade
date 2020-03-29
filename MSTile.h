#ifndef MSTile_H
#define MSTile_H
class MSTile {
protected:
	int State;
	enum Label { Hidden, Flagged, Revealed };
	char Value;
public:
	MSTile();
	void setState(int);
	void setValue(char);
	int getState() const;
	char getValue() const;
	~MSTile();
};
#endif;