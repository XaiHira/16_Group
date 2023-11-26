class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	void paint();
};