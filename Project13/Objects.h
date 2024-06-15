#ifndef __OBJECTS_H_
#define __OBJECTS_H_
#include <iostream>
#include <string>
#include <vector>
#include "kernel_export.h"
#include "Vector2D.h"
#include "LineSegment2D.h"

class InputFiler;
class OutputFiler;
class Drawer;

class KERNEL_EXPORT object {
public:

	object() = default;
	object(const std::string& name, const int id);
	virtual ~object() {};

	virtual void input(std::shared_ptr<InputFiler> file);
	virtual void output(std::shared_ptr<OutputFiler> file);
	virtual void draw(std::shared_ptr<Drawer> drawer);

	void setName(const std::string& name);
	void setId(const int id);

	std::string getName() const;
	int getId() const;

    virtual int getType() const;

	void setIsDirty(bool dirty);
	bool isDirty() const;
	void invalidate();

	using ptr = std::shared_ptr<object>;

private:

	std::string mName;
	int mId;

	bool mIsDitry;
};


class KERNEL_EXPORT Line : public object {
public:

	Line() = default;
	Line(const std::string& name, const int id, const vector2D& stat, const vector2D& end);
	~Line() {};

	void setStart(const vector2D& start);
	void setEnd(const vector2D& end);

	vector2D getStart() const;
	vector2D getEnd() const;
	double getLenth();

	void input(std::shared_ptr<InputFiler> file) override;
	void output(std::shared_ptr<OutputFiler> file) override;
	void draw(std::shared_ptr<Drawer> drawer) override;
	
	inline static int Type();
    int getType() const override;

	using ptr = std::shared_ptr<Line>;

private:

	Math::LineSegment2D line;
};


class KERNEL_EXPORT Rectangle : public object {

public:

	Rectangle() = default;
	Rectangle(const std::string& name, const int id, const vector2D& leftDownPoint, const double lenth, const double width);
	~Rectangle() {};

	void setLeftDownPoint(const vector2D& vector2D);
	void setLenth(const double lenth_);
	void setWidth(const double width_);

	vector2D getLeftDownPoint();
	double getLenth();
	double getWidth();

	double getArea() const;
	double getPerimetr() const;

	void input(std::shared_ptr<InputFiler> file) override;
	void output(std::shared_ptr<OutputFiler> file) override;
	void draw(std::shared_ptr<Drawer> drawer) override;
	
	inline static int Type();
	int getType() const override;

	using ptr = std::shared_ptr<Rectangle>;

private:

	vector2D mLeftDownPoint;

	double mLenth, mWidth;
};


class KERNEL_EXPORT Circle : public object {
public:

	Circle() = default;
	Circle(const std::string& name, const int id, const vector2D& center, const double radius);

	void setCenter(const vector2D& center_);
	void setRadius(const double radius_);

	vector2D getCenter() const;
	double getRadius() const;

	double getArea() const;

	void input(std::shared_ptr<InputFiler> file) override;
	void output(std::shared_ptr<OutputFiler> file) override;
	void draw(std::shared_ptr<Drawer> drawer) override;

	inline static int Type();
	int getType() const override;

	using ptr = std::shared_ptr<Circle>;

private:

	vector2D mCenter;
	double mRadius;
	std::vector<Line> createLines();
};

class KERNEL_EXPORT Polyline : public object {
public:

	Polyline() = default;
	Polyline(const std::string& name, const int id, const std::vector<vector2D>& points);

	void setPoint(const vector2D& point);
	void editPoint(const int index, const vector2D& point);

	vector2D getPoint(const int index) const;
	int getPointsCount() const;

	void input(std::shared_ptr<InputFiler> file) override;
	void output(std::shared_ptr<OutputFiler> file) override;
	void draw(std::shared_ptr<Drawer> drawer) override;

	inline static int Type();
	int getType() const override;

	using ptr = std::shared_ptr<Polyline>;

private:

	std::vector<vector2D> mPoints;
	void createLines(std::vector<Line>& lines);
};

#endif __OBJECTS_H_
