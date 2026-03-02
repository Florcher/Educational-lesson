#ifndef __Math_H_
#define __Math_H_
#include "Vector2D.h"
#include "kernel_export.h"
#include <vector>
#include <iostream>

namespace Math {

	struct KERNEL_EXPORT LineSegment2D {

		LineSegment2D() = default;
		LineSegment2D(const vector2D& start_, const vector2D& end_) : start(start_), end(end_) {};

		vector2D start = { 0,0 };
		vector2D end = { 0,0 };

		using ptr = std::shared_ptr<LineSegment2D>;
	};

	struct scalingParam {
		double scX;
		double scY;
		double scZ;
	};

	struct transferParam {
		double Tx;
		double Ty;
		double Tz;
	};

	struct axisOfRotation {
		double x;
		double y;
		double z;
	};

	class Matrix3D;
	class Matrix4D;

	class KERNEL_EXPORT Matrix {
	public:

		Matrix() = default;
		Matrix(const std::vector<double> dt);
		virtual ~Matrix();

		virtual void setElement(const int row, const int col, const double el) = 0;
		virtual double getElement(const int row, const int col) const = 0;
		virtual int getSize() const = 0;

	protected:
		int size;
		std::vector<double> data;

		void util(Matrix&, const Matrix&, const Matrix&);
	};

	class KERNEL_EXPORT Matrix2D : public Matrix {
	public:

		friend std::ostream& operator<< (std::ostream&, const Matrix2D&);

		Matrix2D() = default;
		Matrix2D(const std::vector<double> dt);
		~Matrix2D();

		friend Matrix2D operator* (const Matrix2D& lhs, const Matrix2D& rhs);
		Matrix2D operator= (const Matrix2D& rhs);
		Matrix2D operator*= (const Matrix2D& rhs);

		void setElement(const int row, const int col, const double el) override;
		double getElement(const int row, const int col) const override;
		int getSize() const override;

		Matrix3D createTransferMatrix(const transferParam& transferData);
		static Matrix2D createIdentityMatix();
		static Matrix2D createScalingMatix(const scalingParam& scalingData);
		static Matrix2D createRotationMatix(const double rotationAngel);

	};

	class KERNEL_EXPORT Matrix3D : public Matrix {
	public:
		Matrix3D() = default;
		Matrix3D(const std::vector<double> dt);
		~Matrix3D();

		friend Matrix3D operator* (const Matrix3D& lhs, const Matrix3D& rhs);
		Matrix3D operator= (const Matrix3D& rhs);
		Matrix3D operator*= (const Matrix3D& rhs);

		void setElement(const int row, const int col, const double el) override;
		double getElement(const int row, const int col) const override;
		int getSize() const override;

		static Matrix3D createIdentityMatix();
		static Matrix3D createScalingMatix(const scalingParam& scalingData);
		static Matrix3D createRotationMatix(const axisOfRotation& axisOfRotation, const double rotationAngel);
		Matrix4D createTransferMatrix(const transferParam& transferData);
	};

	class KERNEL_EXPORT Matrix4D : public Matrix {
	public:
		Matrix4D() = default;
		Matrix4D(const std::vector<double> dt);
		~Matrix4D();

		friend Matrix4D operator* (const Matrix4D& lhs, const Matrix4D& rhs) = delete;;
		Matrix4D operator= (const Matrix4D& rhs);
		Matrix4D operator*= (const Matrix4D& rhs) = delete;

		void setElement(const int row, const int col, const double el) override;
		double getElement(const int row, const int col) const override;
		int getSize() const override;

		static Matrix4D createIdentityMatix();
	};
	

}

#endif __Math_H_
