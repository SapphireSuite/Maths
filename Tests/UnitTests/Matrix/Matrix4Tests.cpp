// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include "Matrix4Tests.hpp"
#include "../Space/QuaternionTests.hpp"

#include <SA/Maths/Matrix/MatrixMajor.hpp>

#include <SA/Maths/Space/Vector3.hpp>
#include <SA/Maths/Space/Vector4.hpp>

namespace Sa::UT::Matrix4
{
	#define TT TypeParam::template Type

	template <typename T, MatMaj major>
	struct TypeDef
	{
		using Type = T;
		static constexpr MatMaj major = major;
	};

	template <typename T>
	class Matrix4Test : public testing::Test
	{
	};

	using TestTypes = testing::Types<
		TypeDef<int32_t, MatMaj::Row>, TypeDef<int32_t, MatMaj::Column>,
		TypeDef<float, MatMaj::Row>, TypeDef<float, MatMaj::Column>,
		TypeDef<double, MatMaj::Row>, TypeDef<double, MatMaj::Column>
	>;
	TYPED_TEST_SUITE(Matrix4Test, TestTypes);

	TYPED_TEST(Matrix4Test, Constants)
	{
		// Zero.
		EXPECT_EQ(Mat4T::Zero.e00, 0);
		EXPECT_EQ(Mat4T::Zero.e01, 0);
		EXPECT_EQ(Mat4T::Zero.e02, 0);
		EXPECT_EQ(Mat4T::Zero.e03, 0);
		EXPECT_EQ(Mat4T::Zero.e10, 0);
		EXPECT_EQ(Mat4T::Zero.e11, 0);
		EXPECT_EQ(Mat4T::Zero.e12, 0);
		EXPECT_EQ(Mat4T::Zero.e13, 0);
		EXPECT_EQ(Mat4T::Zero.e20, 0);
		EXPECT_EQ(Mat4T::Zero.e21, 0);
		EXPECT_EQ(Mat4T::Zero.e22, 0);
		EXPECT_EQ(Mat4T::Zero.e23, 0);
		EXPECT_EQ(Mat4T::Zero.e30, 0);
		EXPECT_EQ(Mat4T::Zero.e31, 0);
		EXPECT_EQ(Mat4T::Zero.e32, 0);
		EXPECT_EQ(Mat4T::Zero.e33, 0);

		// Identity.
		EXPECT_EQ(Mat4T::Identity.e00, 1);
		EXPECT_EQ(Mat4T::Identity.e01, 0);
		EXPECT_EQ(Mat4T::Identity.e02, 0);
		EXPECT_EQ(Mat4T::Identity.e03, 0);
		EXPECT_EQ(Mat4T::Identity.e10, 0);
		EXPECT_EQ(Mat4T::Identity.e11, 1);
		EXPECT_EQ(Mat4T::Identity.e12, 0);
		EXPECT_EQ(Mat4T::Identity.e13, 0);
		EXPECT_EQ(Mat4T::Identity.e20, 0);
		EXPECT_EQ(Mat4T::Identity.e21, 0);
		EXPECT_EQ(Mat4T::Identity.e22, 1);
		EXPECT_EQ(Mat4T::Identity.e23, 0);
		EXPECT_EQ(Mat4T::Identity.e30, 0);
		EXPECT_EQ(Mat4T::Identity.e31, 0);
		EXPECT_EQ(Mat4T::Identity.e32, 0);
		EXPECT_EQ(Mat4T::Identity.e33, 1);
	}

	TYPED_TEST(Matrix4Test, DefaultConstructors)
	{
		const Mat4T m0;
		EXPECT_EQ(m0.e00, 1);
		EXPECT_EQ(m0.e01, 0);
		EXPECT_EQ(m0.e02, 0);
		EXPECT_EQ(m0.e03, 0);
		EXPECT_EQ(m0.e10, 0);
		EXPECT_EQ(m0.e11, 1);
		EXPECT_EQ(m0.e12, 0);
		EXPECT_EQ(m0.e13, 0);
		EXPECT_EQ(m0.e20, 0);
		EXPECT_EQ(m0.e21, 0);
		EXPECT_EQ(m0.e22, 1);
		EXPECT_EQ(m0.e23, 0);
		EXPECT_EQ(m0.e30, 0);
		EXPECT_EQ(m0.e31, 0);
		EXPECT_EQ(m0.e32, 0);
		EXPECT_EQ(m0.e33, 1);
	}

	TYPED_TEST(Matrix4Test, ValueConstructors)
	{
		TT m1e00 = static_cast<TT>(6.314);
		TT m1e01 = static_cast<TT>(165.2);
		TT m1e02 = static_cast<TT>(4236.0);
		TT m1e03 = static_cast<TT>(99.4);
		TT m1e10 = static_cast<TT>(46.25);
		TT m1e11 = static_cast<TT>(77.51);
		TT m1e12 = static_cast<TT>(16.25);
		TT m1e13 = static_cast<TT>(78.25);
		TT m1e20 = static_cast<TT>(653.0);
		TT m1e21 = static_cast<TT>(11.21);
		TT m1e22 = static_cast<TT>(15.36);
		TT m1e23 = static_cast<TT>(9.64);
		TT m1e30 = static_cast<TT>(1.26);
		TT m1e31 = static_cast<TT>(22.32);
		TT m1e32 = static_cast<TT>(56.214);
		TT m1e33 = static_cast<TT>(32.215);

		const Mat4T m1(
			m1e00, m1e01, m1e02, m1e03,
			m1e10, m1e11, m1e12, m1e13,
			m1e20, m1e21, m1e22, m1e23,
			m1e30, m1e31, m1e32, m1e33
		);

		EXPECT_EQ(m1.e00, m1e00);
		EXPECT_EQ(m1.e01, m1e01);
		EXPECT_EQ(m1.e02, m1e02);
		EXPECT_EQ(m1.e03, m1e03);
		EXPECT_EQ(m1.e10, m1e10);
		EXPECT_EQ(m1.e11, m1e11);
		EXPECT_EQ(m1.e12, m1e12);
		EXPECT_EQ(m1.e13, m1e13);
		EXPECT_EQ(m1.e20, m1e20);
		EXPECT_EQ(m1.e21, m1e21);
		EXPECT_EQ(m1.e22, m1e22);
		EXPECT_EQ(m1.e23, m1e23);
		EXPECT_EQ(m1.e30, m1e30);
		EXPECT_EQ(m1.e31, m1e31);
		EXPECT_EQ(m1.e32, m1e32);
		EXPECT_EQ(m1.e33, m1e33);
	}

	TYPED_TEST(Matrix4Test, ValueCastConstructors)
	{
		uint32_t m2e00 = 336u;
		uint32_t m2e01 = 23u;
		uint32_t m2e02 = 11u;
		uint32_t m2e03 = 3u;
		uint32_t m2e10 = 98u;
		uint32_t m2e11 = 462u;
		uint32_t m2e12 = 5u;
		uint32_t m2e13 = 223u;
		uint32_t m2e20 = 796u;
		uint32_t m2e21 = 11u;
		uint32_t m2e22 = 22u;
		uint32_t m2e23 = 795u;
		uint32_t m2e30 = 11u;
		uint32_t m2e31 = 943u;
		uint32_t m2e32 = 13u;
		uint32_t m2e33 = 48u;

		const Mat4T m2(Mat4<uint32_t, TypeParam::major>(
			m2e00, m2e01, m2e02, m2e03,
			m2e10, m2e11, m2e12, m2e13,
			m2e20, m2e21, m2e22, m2e23,
			m2e30, m2e31, m2e32, m2e33
		));

		EXPECT_EQ(m2.e00, static_cast<TypeParam::Type>(m2e00));
		EXPECT_EQ(m2.e01, static_cast<TypeParam::Type>(m2e01));
		EXPECT_EQ(m2.e02, static_cast<TypeParam::Type>(m2e02));
		EXPECT_EQ(m2.e03, static_cast<TypeParam::Type>(m2e03));
		EXPECT_EQ(m2.e10, static_cast<TypeParam::Type>(m2e10));
		EXPECT_EQ(m2.e11, static_cast<TypeParam::Type>(m2e11));
		EXPECT_EQ(m2.e12, static_cast<TypeParam::Type>(m2e12));
		EXPECT_EQ(m2.e13, static_cast<TypeParam::Type>(m2e13));
		EXPECT_EQ(m2.e20, static_cast<TypeParam::Type>(m2e20));
		EXPECT_EQ(m2.e21, static_cast<TypeParam::Type>(m2e21));
		EXPECT_EQ(m2.e22, static_cast<TypeParam::Type>(m2e22));
		EXPECT_EQ(m2.e23, static_cast<TypeParam::Type>(m2e23));
		EXPECT_EQ(m2.e30, static_cast<TypeParam::Type>(m2e30));
		EXPECT_EQ(m2.e31, static_cast<TypeParam::Type>(m2e31));
		EXPECT_EQ(m2.e32, static_cast<TypeParam::Type>(m2e32));
		EXPECT_EQ(m2.e33, static_cast<TypeParam::Type>(m2e33));
	}

	TYPED_TEST(Matrix4Test, CopyConstructors)
	{
		using T = TypeParam::Type;

		TT m1e00 = static_cast<TT>(6.314);
		TT m1e01 = static_cast<TT>(165.2);
		TT m1e02 = static_cast<TT>(4236.0);
		TT m1e03 = static_cast<TT>(99.4);
		TT m1e10 = static_cast<TT>(46.25);
		TT m1e11 = static_cast<TT>(77.51);
		TT m1e12 = static_cast<TT>(16.25);
		TT m1e13 = static_cast<TT>(78.25);
		TT m1e20 = static_cast<TT>(653.0);
		TT m1e21 = static_cast<TT>(11.21);
		TT m1e22 = static_cast<TT>(15.36);
		TT m1e23 = static_cast<TT>(9.64);
		TT m1e30 = static_cast<TT>(1.26);
		TT m1e31 = static_cast<TT>(22.32);
		TT m1e32 = static_cast<TT>(56.214);
		TT m1e33 = static_cast<TT>(32.215);

		const Mat4T m1(
			m1e00, m1e01, m1e02, m1e03,
			m1e10, m1e11, m1e12, m1e13,
			m1e20, m1e21, m1e22, m1e23,
			m1e30, m1e31, m1e32, m1e33
		);

		const Mat4T m3(m1);

		EXPECT_EQ(m3.e00, m1.e00);
		EXPECT_EQ(m3.e01, m1.e01);
		EXPECT_EQ(m3.e02, m1.e02);
		EXPECT_EQ(m3.e03, m1.e03);
		EXPECT_EQ(m3.e10, m1.e10);
		EXPECT_EQ(m3.e11, m1.e11);
		EXPECT_EQ(m3.e12, m1.e12);
		EXPECT_EQ(m3.e13, m1.e13);
		EXPECT_EQ(m3.e20, m1.e20);
		EXPECT_EQ(m3.e21, m1.e21);
		EXPECT_EQ(m3.e22, m1.e22);
		EXPECT_EQ(m3.e23, m1.e23);
		EXPECT_EQ(m3.e30, m1.e30);
		EXPECT_EQ(m3.e31, m1.e31);
		EXPECT_EQ(m3.e32, m1.e32);
		EXPECT_EQ(m3.e33, m1.e33);
	}

	TYPED_TEST(Matrix4Test, FromMat3Constructors)
	{
		//TT m1e00 = static_cast<TT>(6.314);
		//TT m1e01 = static_cast<TT>(165.2);
		//TT m1e02 = static_cast<TT>(4236.0);
		//TT m1e10 = static_cast<TT>(46.25);
		//TT m1e11 = static_cast<TT>(77.51);
		//TT m1e12 = static_cast<TT>(16.25);
		//TT m1e20 = static_cast<TT>(653.0);
		//TT m1e21 = static_cast<TT>(11.21);
		//TT m1e22 = static_cast<TT>(15.36);

		//const Mat3T m1(
		//	m1e00, m1e01, m1e02,
		//	m1e10, m1e11, m1e12,
		//	m1e20, m1e21, m1e22,
		//);


		//const Mat4T m2(m1);

		//EXPECT_EQ(m2.e00, m1.e00);
		//EXPECT_EQ(m2.e01, m1.e01);
		//EXPECT_EQ(m2.e02, m1.e02);
		//EXPECT_EQ(m2.e03, 0);
		//EXPECT_EQ(m2.e10, m1.e10);
		//EXPECT_EQ(m2.e11, m1.e11);
		//EXPECT_EQ(m2.e12, m1.e12);
		//EXPECT_EQ(m2.e13, 0);
		//EXPECT_EQ(m2.e20, m1.e20);
		//EXPECT_EQ(m2.e21, m1.e21);
		//EXPECT_EQ(m2.e22, m1.e22);
		//EXPECT_EQ(m2.e23, 0);
		//EXPECT_EQ(m2.e30, 0);
		//EXPECT_EQ(m2.e31, 0);
		//EXPECT_EQ(m2.e32, 0);
		//EXPECT_EQ(m2.e33, 1); // Default fill with identity.
	}

	TYPED_TEST(Matrix4Test, Equals)
	{
		const Mat4T m1(
			(TT)6.314, (TT)165.2, (TT)4236.0, (TT)99.4,
			(TT)46.25, (TT)77.51, (TT)16.25, (TT)78.25,
			(TT)653.0, (TT)11.21, (TT)15.36, (TT)9.64,
			(TT)1.26, (TT)22.32, (TT)56.214, (TT)32.215
		);

		const Mat4T m2(
			(TT)336.65, (TT)23.6, (TT)11.68, (TT)3.34,
			(TT)98.55, (TT)462.3, (TT)5.984, (TT)223.35,
			(TT)796.335, (TT)11.457, (TT)22.32, (TT)795.354,
			(TT)11.1235, (TT)943.489, (TT)13.324, (TT)48.3335
		);

		EXPECT_FALSE(m1.IsZero());
		EXPECT_TRUE(Mat4T::Zero.IsZero());

		EXPECT_TRUE(m1.Equals(m1));
		EXPECT_FALSE(m1.Equals(m2));

		EXPECT_EQ(m1, m1);
		EXPECT_NE(m1, m2);
	}

	TYPED_TEST(Matrix4Test, Transpose)
	{
		const Mat4T m1(
			(TT)6.314, (TT)165.2, (TT)4236.0, (TT)99.4,
			(TT)46.25, (TT)77.51, (TT)16.25, (TT)78.25,
			(TT)653.0, (TT)11.21, (TT)15.36, (TT)9.64,
			(TT)1.26, (TT)22.32, (TT)56.214, (TT)32.215
		);

		const Mat4T m2 = m1.GetTransposed();

		EXPECT_EQ(m2.e00, m1.e00);
		EXPECT_EQ(m2.e10, m1.e01);
		EXPECT_EQ(m2.e20, m1.e02);
		EXPECT_EQ(m2.e30, m1.e03);
		EXPECT_EQ(m2.e01, m1.e10);
		EXPECT_EQ(m2.e11, m1.e11);
		EXPECT_EQ(m2.e21, m1.e12);
		EXPECT_EQ(m2.e31, m1.e13);
		EXPECT_EQ(m2.e02, m1.e20);
		EXPECT_EQ(m2.e12, m1.e21);
		EXPECT_EQ(m2.e22, m1.e22);
		EXPECT_EQ(m2.e32, m1.e23);
		EXPECT_EQ(m2.e03, m1.e30);
		EXPECT_EQ(m2.e13, m1.e31);
		EXPECT_EQ(m2.e23, m1.e32);
		EXPECT_EQ(m2.e33, m1.e33);

		// Self transpose.
		Mat4T m3 = m1;
		m3.Transpose();
		EXPECT_EQ(m3, m2);
	}

	TYPED_TEST(Matrix4Test, Inverse)
	{
		/**
		*	Precomputed matrix.
		*	https://www.wolframalpha.com/input/?i=%7B%7B5.26%2C+48.25%2C+12.36%2C+6.25%7D%2C%7B148.2%2C+12.36%2C+68.2%2C+17.36%7D%2C%7B9.25%2C+12.3%2C+46.27%2C+9.15%7D%2C%7B27.1%2C+7.4%2C+11.2%2C+4.23%7D%7D
		*/
		const Mat4T m1(
			(TT)5.26, (TT)48.25, (TT)12.36, (TT)6.25,
			(TT)148.2, (TT)12.36, (TT)68.2, (TT)17.36,
			(TT)9.25, (TT)12.3, (TT)46.27, (TT)9.15,
			(TT)27.1, (TT)7.4, (TT)11.2, (TT)4.23
		);

		const TT det = m1.Determinant();

		if constexpr (std::is_same_v<TT, int32_t>)
		{
			/**
			*	Precomputed value
			*	https://www.wolframalpha.com/input/?i=%7B%7B5%2C+48%2C+12%2C+6%7D%2C%7B148%2C+12%2C+68%2C+17%7D%2C%7B9%2C+12%2C+46%2C+9%7D%2C%7B27%2C+7%2C+11%2C+4%7D%7D
			*/
			EXPECT_EQ(det, -209914);
		}
		else if constexpr(std::is_same_v<TT, float>)
			EXPECT_NEAR(det, (TT)-237488.906250, (TT)0.000001);
		else
			EXPECT_NEAR(det, (TT)-237488.906250, (TT)0.1);

		const Mat4T m1_inv = m1.GetInversed();

		// Precomputed matrix.
		const Mat4T m1_resInv(
			(TT)0.00560278, (TT)0.0143744, (TT)-0.013435, (TT)-0.0382097,
			(TT)0.0340719, (TT)0.0173389, (TT)-0.0110158, (TT)-0.0976733,
			(TT)0.0182788, (TT)0.0351108, (TT)0.0134225, (TT)-0.200137,
			(TT)-0.143898, (TT)-0.215389, (TT)0.0698044, (TT)1.18199
		);

		EXPECT_MAT4_NEAR(m1_inv, m1_resInv, (TT)0.00001);

		// Self inverse.
		Mat4T m2 = m1;
		m2.Inverse();
		EXPECT_EQ(m2, m1_inv);
		
		// Check identity.
		if constexpr (std::is_floating_point_v<TT>)
		{
			Mat4T m0 = m1 * m1_inv;
			EXPECT_MAT4_NEAR(m0, Mat4T::Identity, (TT)0.00001);
		}
	}

	TYPED_TEST(Matrix4Test, Lerp)
	{
		const Mat4T m1(
			(TT)2.0, (TT)2.0, (TT)0.0, (TT)30.0,
			(TT)6.0, (TT)10.0, (TT)16.0, (TT)26.0,
			(TT)46.0, (TT)12.0, (TT)70.0, (TT)2.0,
			(TT)9.0, (TT)18.0, (TT)0.0, (TT)31.0
		);

		const Mat4T m2(
			(TT)-2.0, (TT)4.0, (TT)8.0, (TT)94.0,
			(TT)4.0, (TT)-60.0, (TT)10.0, (TT)32.0,
			(TT)1.0, (TT)8.0, (TT)-10.0, (TT)41.0,
			(TT)20.0, (TT)1.0, (TT)4., (TT)13.0
		);


		const Mat4T lerp_res05(
			(TT)0.0, (TT)3.0, (TT)4.0, (TT)62.0,
			(TT)5.0, (TT)-25.0, (TT)13.0, (TT)29.0,
			(TT)23.5, (TT)10.0, (TT)30.0, (TT)21.5,
			(TT)14.5, (TT)9.5, (TT)2.0, (TT)22.0
		);

		EXPECT_EQ(Mat4T::Lerp(m1, m2, 0.5f), lerp_res05);

		EXPECT_EQ(Mat4T::Lerp(m1, m2, 2.0f), m2);


		const Mat4T ulerp_res1(
			(TT)6.0, (TT)0.0, (TT)-8.0f, (TT)-34.0f,
			(TT)8.0, (TT)80.0, (TT)22.0, (TT)20.0,
			(TT)91.0, (TT)16.0, (TT)150.0, (TT)-37.0,
			(TT)-2.0, (TT)35.0, (TT)-4.0, (TT)49.0
		);

		EXPECT_EQ(Mat4T::LerpUnclamped(m1, m2, -1.0f), ulerp_res1);
	}

	TYPED_TEST(Matrix4Test, Transform)
	{
		// Translation.
		const Vec3<TT> vTr((TT)10.0412, (TT)2.361, (TT)12.35);

		const Mat4T mTr(
			1, 0, 0, vTr.x,
			0, 1, 0, vTr.y,
			0, 0, 1, vTr.z,
			0, 0, 0, 1
		);

		EXPECT_EQ(Mat4T::MakeTranslation(vTr), mTr);


		Mat4T mTr2 = Mat4T::Identity;
		mTr2.ApplyTranslation(vTr);
		EXPECT_EQ(mTr2, mTr);


		// Rotation.

		/**
		*	Precomputed values
		*	https://www.wolframalpha.com/input/?i=Quaternion%280.653799%2C+0.491984%2C+-0.573436%2C+-0.0408624%29
		*/
		const Quat<TT> q1(
			(TT)0.65379899684951437,
			(TT)0.49198400932684733,
			(TT)-0.57343602132006610,
			(TT)-0.040862400050191698
		);

		const Mat4T mRot(
			(TT)0.339003, (TT)-0.510811, (TT)-0.790031, 0,
			(TT)-0.617674, (TT)0.512564, (TT)-0.596453, 0,
			(TT)0.709616, (TT)0.690181, (TT)-0.141754, 0,
			0, 0, 0, 1
		);


		if constexpr (std::is_floating_point_v<TT>) // No test for int types.
			EXPECT_MAT4_NEAR(Mat4T::MakeRotation(q1), mRot, 0.000001);


		// Scale.
		const Vec3<TT> vScale((TT)2.215, (TT)5.31, (TT)996.2);

		Mat4T mScale = Mat4T::Identity;
		mScale.e00 *= vScale.x;
		mScale.e11 *= vScale.y;
		mScale.e22 *= vScale.z;
		EXPECT_EQ(Mat4T::MakeScale(vScale), mScale);


		// Translation + Rotation.

		Mat4T mTrRot = mRot;
		mTrRot.e03 = vTr.x;
		mTrRot.e13 = vTr.y;
		mTrRot.e23 = vTr.z;

		if constexpr (std::is_floating_point_v<TT>) // No test for int types.
			EXPECT_MAT4_NEAR(Mat4T::MakeTransform(vTr, q1), mTrRot, 0.000001);


		// Translation + Scale.
		Mat4T mTrScale = mScale;
		mTrScale.e03 = vTr.x;
		mTrScale.e13 = vTr.y;
		mTrScale.e23 = vTr.z;
		EXPECT_EQ(Mat4T::MakeTransform(vTr, vScale), mTrScale);


		// Rotation + Scale.
		const Mat4T mRotScale = mScale * mRot;

		if constexpr (std::is_floating_point_v<TT>) // No test for int types.
			EXPECT_MAT4_NEAR(Mat4T::MakeTransform(q1, vScale), mRotScale, 0.001);


		// Translation + Rotation + Scale.
		Mat4T mTrRotScale = mRotScale;
		mTrRotScale.e03 = vTr.x;
		mTrRotScale.e13 = vTr.y;
		mTrRotScale.e23 = vTr.z;

		if constexpr (std::is_floating_point_v<TT>) // No test for int types.
			EXPECT_MAT4_NEAR(Mat4T::MakeTransform(vTr, q1, vScale), mTrRotScale, 0.001)
	}

	TYPED_TEST(Matrix4Test, Operators)
	{
		const Mat4T m1(
			(TT)6.314, (TT)165.2, (TT)4236.0, (TT)99.4,
			(TT)46.25, (TT)77.51, (TT)16.25, (TT)78.25,
			(TT)653.0, (TT)11.21, (TT)15.36, (TT)9.64,
			(TT)1.26, (TT)22.32, (TT)56.214, (TT)32.215
		);

		// Minus self.
		const Mat4T mm1(
			-m1.e00, -m1.e01, -m1.e02, -m1.e03,
			-m1.e10, -m1.e11, -m1.e12, -m1.e13,
			-m1.e20, -m1.e21, -m1.e22, -m1.e23,
			-m1.e30, -m1.e31, -m1.e32, -m1.e33
		);

		EXPECT_EQ(-m1, mm1);


		// Scale.
		TT scale = (TT)6.21;

		const Mat4T sm1(
			m1.e00 * scale, m1.e01 * scale, m1.e02 * scale, m1.e03 * scale,
			m1.e10 * scale, m1.e11 * scale, m1.e12 * scale, m1.e13 * scale,
			m1.e20 * scale, m1.e21 * scale, m1.e22 * scale, m1.e23 * scale,
			m1.e30 * scale, m1.e31 * scale, m1.e32 * scale, m1.e33 * scale
		);

		EXPECT_EQ(m1 * scale, sm1);
		EXPECT_EQ(scale * m1, sm1);


		// Unscale.
		const Mat4T usm1(
			m1.e00 / scale, m1.e01 / scale, m1.e02 / scale, m1.e03 / scale,
			m1.e10 / scale, m1.e11 / scale, m1.e12 / scale, m1.e13 / scale,
			m1.e20 / scale, m1.e21 / scale, m1.e22 / scale, m1.e23 / scale,
			m1.e30 / scale, m1.e31 / scale, m1.e32 / scale, m1.e33 / scale
		);
		const Mat4T susm1(
			scale / m1.e00, scale / m1.e01, scale / m1.e02, scale / m1.e03,
			scale / m1.e10, scale / m1.e11, scale / m1.e12, scale / m1.e13,
			scale / m1.e20, scale / m1.e21, scale / m1.e22, scale / m1.e23,
			scale / m1.e30, scale / m1.e31, scale / m1.e32, scale / m1.e33
		);

		EXPECT_EQ(m1 / scale, usm1);
		EXPECT_EQ(scale / m1, susm1);


		// Vector transform
		const Vec3<TT> v1((TT)10.0412, (TT)2.361, (TT)12.35);

		Vec3<TT> v1_res(
			m1.e00 * v1.x + m1.e01 * v1.y + m1.e02 * v1.z,
			m1.e10 * v1.x + m1.e11 * v1.y + m1.e12 * v1.z,
			m1.e20 * v1.x + m1.e21 * v1.y + m1.e22 * v1.z
		);

		EXPECT_EQ(m1 * v1, v1_res);

		const Vec4<TT> v2 (v1, (TT)35.21);
		Vec4<TT> v2_res(
			m1.e00 * v2.x + m1.e01 * v2.y + m1.e02 * v2.z + m1.e03 * v2.w,
			m1.e10 * v2.x + m1.e11 * v2.y + m1.e12 * v2.z + m1.e13 * v2.w,
			m1.e20 * v2.x + m1.e21 * v2.y + m1.e22 * v2.z + m1.e23 * v2.w,
			m1.e30 * v2.x + m1.e31 * v2.y + m1.e32 * v2.z + m1.e33 * v2.w
		);

		EXPECT_EQ(m1 * v2, v2_res);


		// Mat4 operators
		const Mat4T m2(
			(TT)336.65, (TT)23.6, (TT)11.68, (TT)3.34,
			(TT)98.55, (TT)462.3, (TT)5.984, (TT)223.35,
			(TT)796.335, (TT)11.457, (TT)22.32, (TT)795.354,
			(TT)11.1235, (TT)943.489, (TT)13.324, (TT)48.3335
		);

		const Mat4T m1pm2(
			m1.e00 + m2.e00, m1.e01 + m2.e01, m1.e02 + m2.e02, m1.e03 + m2.e03,
			m1.e10 + m2.e10, m1.e11 + m2.e11, m1.e12 + m2.e12, m1.e13 + m2.e13,
			m1.e20 + m2.e20, m1.e21 + m2.e21, m1.e22 + m2.e22, m1.e23 + m2.e23,
			m1.e30 + m2.e30, m1.e31 + m2.e31, m1.e32 + m2.e32, m1.e33 + m2.e33
		);
		EXPECT_EQ(m1 + m2, m1pm2);

		const Mat4T m1mm2(
			m1.e00 - m2.e00, m1.e01 - m2.e01, m1.e02 - m2.e02, m1.e03 - m2.e03,
			m1.e10 - m2.e10, m1.e11 - m2.e11, m1.e12 - m2.e12, m1.e13 - m2.e13,
			m1.e20 - m2.e20, m1.e21 - m2.e21, m1.e22 - m2.e22, m1.e23 - m2.e23,
			m1.e30 - m2.e30, m1.e31 - m2.e31, m1.e32 - m2.e32, m1.e33 - m2.e33
		);
		EXPECT_EQ(m1 - m2, m1mm2);

		/**
		*	Precomputed matrix.
		*	https://www.wolframalpha.com/input/?i=%7B%7B5.26%2C+48.25%2C+12.36%2C+6.25%7D%2C%7B148.2%2C+12.36%2C+68.2%2C+17.36%7D%2C%7B9.25%2C+12.3%2C+46.27%2C+9.15%7D%2C%7B27.1%2C+7.4%2C+11.2%2C+4.23%7D%7D
		*/
		const Mat4T m3(
			(TT)5.26, (TT)48.25, (TT)12.36, (TT)6.25,
			(TT)148.2, (TT)12.36, (TT)68.2, (TT)17.36,
			(TT)9.25, (TT)12.3, (TT)46.27, (TT)9.15,
			(TT)27.1, (TT)7.4, (TT)11.2, (TT)4.23
		);

		/**
		*	Precomputed matrix.
		*	https://www.wolframalpha.com/input/?i=%7B%7B98.0%2C+1324.0%2C+3.25%2C+6.21%7D%2C%7B63.25%2C+10.2%2C+1.25%2C+8.12%7D%2C%7B47.2%2C+6.21%2C+614.0%2C+45.31%7D%2C%7B5.36%2C+14.2%2C+3.22%2C+7.25%7D%7D
		*/
		const Mat4T m4(
			(TT)98.0, (TT)1324.0, (TT)3.25, (TT)6.21,
			(TT)63.25, (TT)10.2, (TT)1.25, (TT)8.12,
			(TT)47.2, (TT)6.21, (TT)614.0, (TT)45.31,
			(TT)5.36, (TT)14.2, (TT)3.22, (TT)7.25
		);

		/**
		*	Precomputed matrix.
		*	https://www.wolframalpha.com/input/?i2d=true&i=%7B%7B5.26%2C48.25%2C12.36%2C6.25%7D%2C%7B148.2%2C12.36%2C68.2%2C17.36%7D%2C%7B9.25%2C12.3%2C46.27%2C9.15%7D%2C%7B27.1%2C7.4%2C11.2%2C4.23%7D%7D*%7B%7B98.0%2C1324.0%2C3.25%2C6.21%7D%2C%7B63.25%2C10.2%2C1.25%2C8.12%7D%2C%7B47.2%2C6.21%2C614.0%2C45.31%7D%2C%7B5.36%2C14.2%2C3.22%2C7.25%7D%7D
		*/
		Mat4T m3multm4;
		Mat4T m3divm4;

		if constexpr (std::is_integral_v<TT>)
		{
			m3multm4 = Mat4T(
				4108, 7256, 7449, 996,
				18541, 196718, 42259, 4163,
				3845, 12438, 28310, 2283,
				3624, 35940, 6854, 741
			);

			EXPECT_EQ(m3 * m4, m3multm4);
		}
		else
		{
			m3multm4 = Mat4T(
				(TT)4184.1845, (TT)7621.8956, (TT)7686.5725, (TT)1029.7987,
				(TT)18617.457031, (TT)197012.906250, (TT)42427.796875, (TT)4236.687012,
				(TT)3917.463135, (TT)12789.726562, (TT)28484.681641, (TT)2320.149902,
				(TT)3675.163086, (TT)36085.500000, (TT)6987.745605, (TT)766.518494
			);

			EXPECT_MAT4_NEAR(m3 * m4, m3multm4, 0.003);

			m3divm4 = Mat4T(
				(TT)0.028285, (TT)-0.038804, (TT)0.015961, (TT)0.781553,
				(TT)0.000656, (TT)2.336921, (TT)0.111128, (TT)-0.917945,
				(TT)0.000305, (TT)0.025881, (TT)0.071171, (TT)0.788025,
				(TT)0.002203, (TT)0.411019, (TT)0.017325, (TT)0.012946
			);

			EXPECT_MAT4_NEAR(m3 / m4, m3divm4, 0.003);
		}


		// op *= scalar.
		Mat4T m5 = m1;
		m5 *= scale;
		EXPECT_EQ(m5, sm1);


		// op /= scalar.
		Mat4T m6 = m1;
		m6 /= scale;
		EXPECT_EQ(m6, usm1);


		// op += Mat.
		Mat4T m7 = m1;
		m7 += m2;
		EXPECT_EQ(m7, m1pm2);

		// op -= Mat.
		Mat4T m8 = m1;
		m8 -= m2;
		EXPECT_EQ(m8, m1mm2);


		// op *= Mat.
		Mat4T m9 = m3;
		m9 *= m4;
		EXPECT_MAT4_NEAR(m9, m3multm4, 0.003);


		// op /= Mat.
		if constexpr (std::is_floating_point_v<TT>)
		{
			Mat4T m10 = m3;
			m10 /= m4;
			EXPECT_MAT4_NEAR(m10, m3divm4, 0.003);
		}
	}

	TYPED_TEST(Matrix4Test, Accessors)
	{
		const Mat4T m1(
			(TT)6.314, (TT)165.2, (TT)4236.0, (TT)99.4,
			(TT)46.25, (TT)77.51, (TT)16.25, (TT)78.25,
			(TT)653.0, (TT)11.21, (TT)15.36, (TT)9.64,
			(TT)1.26, (TT)22.32, (TT)56.214, (TT)32.215
		);
	}

	TEST(Matrix4, Majors)
	{
		float e00 = 6.314f;
		float e01 = 165.2f;
		float e02 = 4236.0f;
		float e03 = 99.4f;
		float e10 = 46.25f;
		float e11 = 77.51f;
		float e12 = 16.25f;
		float e13 = 78.25f;
		float e20 = 653.0f;
		float e21 = 11.21f;
		float e22 = 15.36f;
		float e23 = 9.64f;
		float e30 = 1.26f;
		float e31 = 22.32f;
		float e32 = 56.214f;
		float e33 = 32.215f;

		const Mat4<float, MatrixMajor::Row> m1(
			e00, e01, e02, e03,
			e10, e11, e12, e13,
			e20, e21, e22, e23,
			e30, e31, e32, e33
		);
		const Mat4<float, MatrixMajor::Column> m2(
			e00, e01, e02, e03,
			e10, e11, e12, e13,
			e20, e21, e22, e23,
			e30, e31, e32, e33
		);

		// Same value for same name.
		EXPECT_EQ(m1.e00, m2.e00);
		EXPECT_EQ(m1.e01, m2.e01);
		EXPECT_EQ(m1.e02, m2.e02);
		EXPECT_EQ(m1.e03, m2.e03);
		EXPECT_EQ(m1.e10, m2.e10);
		EXPECT_EQ(m1.e11, m2.e11);
		EXPECT_EQ(m1.e12, m2.e12);
		EXPECT_EQ(m1.e13, m2.e13);
		EXPECT_EQ(m1.e20, m2.e20);
		EXPECT_EQ(m1.e21, m2.e21);
		EXPECT_EQ(m1.e22, m2.e22);
		EXPECT_EQ(m1.e23, m2.e23);
		EXPECT_EQ(m1.e30, m2.e30);
		EXPECT_EQ(m1.e31, m2.e31);
		EXPECT_EQ(m1.e32, m2.e32);
		EXPECT_EQ(m1.e33, m2.e33);

		const float* const dm1 = m1.Data();
		const float* const dm2 = m2.Data();

		// Different memory.
		EXPECT_EQ(dm1[0], dm2[0]);
		EXPECT_EQ(dm1[1], dm2[4]);
		EXPECT_EQ(dm1[2], dm2[8]);
		EXPECT_EQ(dm1[3], dm2[12]);

		EXPECT_EQ(dm1[4], dm2[1]);
		EXPECT_EQ(dm1[5], dm2[5]);
		EXPECT_EQ(dm1[6], dm2[9]);
		EXPECT_EQ(dm1[7], dm2[13]);

		EXPECT_EQ(dm1[8], dm2[2]);
		EXPECT_EQ(dm1[9], dm2[6]);
		EXPECT_EQ(dm1[10], dm2[10]);
		EXPECT_EQ(dm1[11], dm2[14]);

		EXPECT_EQ(dm1[12], dm2[3]);
		EXPECT_EQ(dm1[13], dm2[7]);
		EXPECT_EQ(dm1[14], dm2[11]);
		EXPECT_EQ(dm1[15], dm2[15]);
	}

	TEST(Matrix4, AccessorsRow)
	{
		const Mat4<float, MatMaj::Row> m1(
			6.314f, 165.2f, 4236.0f, 99.4f,
			46.25f, 77.51f, 16.25f, 78.25f,
			653.0f, 11.21f, 15.36f, 9.64f,
			1.26f, 22.32f, 56.214f, 32.215f
		);

		EXPECT_EQ(m1[0], m1.e00);
		EXPECT_EQ(m1[1], m1.e01);
		EXPECT_EQ(m1[2], m1.e02);
		EXPECT_EQ(m1[3], m1.e03);
		EXPECT_EQ(m1[4], m1.e10);
		EXPECT_EQ(m1[5], m1.e11);
		EXPECT_EQ(m1[6], m1.e12);
		EXPECT_EQ(m1[7], m1.e13);
		EXPECT_EQ(m1[8], m1.e20);
		EXPECT_EQ(m1[9], m1.e21);
		EXPECT_EQ(m1[10], m1.e22);
		EXPECT_EQ(m1[11], m1.e23);
		EXPECT_EQ(m1[12], m1.e30);
		EXPECT_EQ(m1[13], m1.e31);
		EXPECT_EQ(m1[14], m1.e32);
		EXPECT_EQ(m1[15], m1.e33);

		EXPECT_EQ(m1.At(0), m1.e00);
		EXPECT_EQ(m1.At(1), m1.e01);
		EXPECT_EQ(m1.At(2), m1.e02);
		EXPECT_EQ(m1.At(3), m1.e03);
		EXPECT_EQ(m1.At(4), m1.e10);
		EXPECT_EQ(m1.At(5), m1.e11);
		EXPECT_EQ(m1.At(6), m1.e12);
		EXPECT_EQ(m1.At(7), m1.e13);
		EXPECT_EQ(m1.At(8), m1.e20);
		EXPECT_EQ(m1.At(9), m1.e21);
		EXPECT_EQ(m1.At(10), m1.e22);
		EXPECT_EQ(m1.At(11), m1.e23);
		EXPECT_EQ(m1.At(12), m1.e30);
		EXPECT_EQ(m1.At(13), m1.e31);
		EXPECT_EQ(m1.At(14), m1.e32);
		EXPECT_EQ(m1.At(15), m1.e33);

		EXPECT_EQ(m1.At(0, 0), m1.e00);
		EXPECT_EQ(m1.At(0, 1), m1.e01);
		EXPECT_EQ(m1.At(0, 2), m1.e02);
		EXPECT_EQ(m1.At(0, 3), m1.e03);
		EXPECT_EQ(m1.At(1, 0), m1.e10);
		EXPECT_EQ(m1.At(1, 1), m1.e11);
		EXPECT_EQ(m1.At(1, 2), m1.e12);
		EXPECT_EQ(m1.At(1, 3), m1.e13);
		EXPECT_EQ(m1.At(2, 0), m1.e20);
		EXPECT_EQ(m1.At(2, 1), m1.e21);
		EXPECT_EQ(m1.At(2, 2), m1.e22);
		EXPECT_EQ(m1.At(2, 3), m1.e23);
		EXPECT_EQ(m1.At(3, 0), m1.e30);
		EXPECT_EQ(m1.At(3, 1), m1.e31);
		EXPECT_EQ(m1.At(3, 2), m1.e32);
		EXPECT_EQ(m1.At(3, 3), m1.e33);

		EXPECT_EQ(m1.Data(), &m1.e00);

		// Const.

		const Mat4<float, MatMaj::Row>& cm1 = m1;

		EXPECT_EQ(cm1[0], cm1.e00);
		EXPECT_EQ(cm1[1], cm1.e01);
		EXPECT_EQ(cm1[2], cm1.e02);
		EXPECT_EQ(cm1[3], cm1.e03);
		EXPECT_EQ(cm1[4], cm1.e10);
		EXPECT_EQ(cm1[5], cm1.e11);
		EXPECT_EQ(cm1[6], cm1.e12);
		EXPECT_EQ(cm1[7], cm1.e13);
		EXPECT_EQ(cm1[8], cm1.e20);
		EXPECT_EQ(cm1[9], cm1.e21);
		EXPECT_EQ(cm1[10], cm1.e22);
		EXPECT_EQ(cm1[11], cm1.e23);
		EXPECT_EQ(cm1[12], cm1.e30);
		EXPECT_EQ(cm1[13], cm1.e31);
		EXPECT_EQ(cm1[14], cm1.e32);
		EXPECT_EQ(cm1[15], cm1.e33);

		EXPECT_EQ(cm1.At(0), cm1.e00);
		EXPECT_EQ(cm1.At(1), cm1.e01);
		EXPECT_EQ(cm1.At(2), cm1.e02);
		EXPECT_EQ(cm1.At(3), cm1.e03);
		EXPECT_EQ(cm1.At(4), cm1.e10);
		EXPECT_EQ(cm1.At(5), cm1.e11);
		EXPECT_EQ(cm1.At(6), cm1.e12);
		EXPECT_EQ(cm1.At(7), cm1.e13);
		EXPECT_EQ(cm1.At(8), cm1.e20);
		EXPECT_EQ(cm1.At(9), cm1.e21);
		EXPECT_EQ(cm1.At(10), cm1.e22);
		EXPECT_EQ(cm1.At(11), cm1.e23);
		EXPECT_EQ(cm1.At(12), cm1.e30);
		EXPECT_EQ(cm1.At(13), cm1.e31);
		EXPECT_EQ(cm1.At(14), cm1.e32);
		EXPECT_EQ(cm1.At(15), cm1.e33);

		EXPECT_EQ(cm1.At(0, 0), cm1.e00);
		EXPECT_EQ(cm1.At(0, 1), cm1.e01);
		EXPECT_EQ(cm1.At(0, 2), cm1.e02);
		EXPECT_EQ(cm1.At(0, 3), cm1.e03);
		EXPECT_EQ(cm1.At(1, 0), cm1.e10);
		EXPECT_EQ(cm1.At(1, 1), cm1.e11);
		EXPECT_EQ(cm1.At(1, 2), cm1.e12);
		EXPECT_EQ(cm1.At(1, 3), cm1.e13);
		EXPECT_EQ(cm1.At(2, 0), cm1.e20);
		EXPECT_EQ(cm1.At(2, 1), cm1.e21);
		EXPECT_EQ(cm1.At(2, 2), cm1.e22);
		EXPECT_EQ(cm1.At(2, 3), cm1.e23);
		EXPECT_EQ(cm1.At(3, 0), cm1.e30);
		EXPECT_EQ(cm1.At(3, 1), cm1.e31);
		EXPECT_EQ(cm1.At(3, 2), cm1.e32);
		EXPECT_EQ(cm1.At(3, 3), cm1.e33);

		EXPECT_EQ(cm1.Data(), &cm1.e00);
	}

	TEST(Matrix4, AccessorsColumn)
	{
		const Mat4<float, MatMaj::Column> m1(
			6.314f, 165.2f, 4236.0f, 99.4f,
			46.25f, 77.51f, 16.25f, 78.25f,
			653.0f, 11.21f, 15.36f, 9.64f,
			1.26f, 22.32f, 56.214f, 32.215f
		);

		EXPECT_EQ(m1[0], m1.e00);
		EXPECT_EQ(m1[1], m1.e10);
		EXPECT_EQ(m1[2], m1.e20);
		EXPECT_EQ(m1[3], m1.e30);
		EXPECT_EQ(m1[4], m1.e01);
		EXPECT_EQ(m1[5], m1.e11);
		EXPECT_EQ(m1[6], m1.e21);
		EXPECT_EQ(m1[7], m1.e31);
		EXPECT_EQ(m1[8], m1.e02);
		EXPECT_EQ(m1[9], m1.e12);
		EXPECT_EQ(m1[10], m1.e22);
		EXPECT_EQ(m1[11], m1.e32);
		EXPECT_EQ(m1[12], m1.e03);
		EXPECT_EQ(m1[13], m1.e13);
		EXPECT_EQ(m1[14], m1.e23);
		EXPECT_EQ(m1[15], m1.e33);

		EXPECT_EQ(m1.At(0), m1.e00);
		EXPECT_EQ(m1.At(1), m1.e10);
		EXPECT_EQ(m1.At(2), m1.e20);
		EXPECT_EQ(m1.At(3), m1.e30);
		EXPECT_EQ(m1.At(4), m1.e01);
		EXPECT_EQ(m1.At(5), m1.e11);
		EXPECT_EQ(m1.At(6), m1.e21);
		EXPECT_EQ(m1.At(7), m1.e31);
		EXPECT_EQ(m1.At(8), m1.e02);
		EXPECT_EQ(m1.At(9), m1.e12);
		EXPECT_EQ(m1.At(10), m1.e22);
		EXPECT_EQ(m1.At(11), m1.e32);
		EXPECT_EQ(m1.At(12), m1.e03);
		EXPECT_EQ(m1.At(13), m1.e13);
		EXPECT_EQ(m1.At(14), m1.e23);
		EXPECT_EQ(m1.At(15), m1.e33);

		EXPECT_EQ(m1.At(0, 0), m1.e00);
		EXPECT_EQ(m1.At(0, 1), m1.e10);
		EXPECT_EQ(m1.At(0, 2), m1.e20);
		EXPECT_EQ(m1.At(0, 3), m1.e30);
		EXPECT_EQ(m1.At(1, 0), m1.e01);
		EXPECT_EQ(m1.At(1, 1), m1.e11);
		EXPECT_EQ(m1.At(1, 2), m1.e21);
		EXPECT_EQ(m1.At(1, 3), m1.e31);
		EXPECT_EQ(m1.At(2, 0), m1.e02);
		EXPECT_EQ(m1.At(2, 1), m1.e12);
		EXPECT_EQ(m1.At(2, 2), m1.e22);
		EXPECT_EQ(m1.At(2, 3), m1.e32);
		EXPECT_EQ(m1.At(3, 0), m1.e03);
		EXPECT_EQ(m1.At(3, 1), m1.e13);
		EXPECT_EQ(m1.At(3, 2), m1.e23);
		EXPECT_EQ(m1.At(3, 3), m1.e33);

		EXPECT_EQ(m1.Data(), &m1.e00);


		const Mat4<float, MatMaj::Column>& cm1 = m1;

		EXPECT_EQ(cm1[0], cm1.e00);
		EXPECT_EQ(cm1[1], cm1.e10);
		EXPECT_EQ(cm1[2], cm1.e20);
		EXPECT_EQ(cm1[3], cm1.e30);
		EXPECT_EQ(cm1[4], cm1.e01);
		EXPECT_EQ(cm1[5], cm1.e11);
		EXPECT_EQ(cm1[6], cm1.e21);
		EXPECT_EQ(cm1[7], cm1.e31);
		EXPECT_EQ(cm1[8], cm1.e02);
		EXPECT_EQ(cm1[9], cm1.e12);
		EXPECT_EQ(cm1[10], cm1.e22);
		EXPECT_EQ(cm1[11], cm1.e32);
		EXPECT_EQ(cm1[12], cm1.e03);
		EXPECT_EQ(cm1[13], cm1.e13);
		EXPECT_EQ(cm1[14], cm1.e23);
		EXPECT_EQ(cm1[15], cm1.e33);

		EXPECT_EQ(cm1.At(0), cm1.e00);
		EXPECT_EQ(cm1.At(1), cm1.e10);
		EXPECT_EQ(cm1.At(2), cm1.e20);
		EXPECT_EQ(cm1.At(3), cm1.e30);
		EXPECT_EQ(cm1.At(4), cm1.e01);
		EXPECT_EQ(cm1.At(5), cm1.e11);
		EXPECT_EQ(cm1.At(6), cm1.e21);
		EXPECT_EQ(cm1.At(7), cm1.e31);
		EXPECT_EQ(cm1.At(8), cm1.e02);
		EXPECT_EQ(cm1.At(9), cm1.e12);
		EXPECT_EQ(cm1.At(10), cm1.e22);
		EXPECT_EQ(cm1.At(11), cm1.e32);
		EXPECT_EQ(cm1.At(12), cm1.e03);
		EXPECT_EQ(cm1.At(13), cm1.e13);
		EXPECT_EQ(cm1.At(14), cm1.e23);
		EXPECT_EQ(cm1.At(15), cm1.e33);

		EXPECT_EQ(cm1.At(0, 0), cm1.e00);
		EXPECT_EQ(cm1.At(0, 1), cm1.e10);
		EXPECT_EQ(cm1.At(0, 2), cm1.e20);
		EXPECT_EQ(cm1.At(0, 3), cm1.e30);
		EXPECT_EQ(cm1.At(1, 0), cm1.e01);
		EXPECT_EQ(cm1.At(1, 1), cm1.e11);
		EXPECT_EQ(cm1.At(1, 2), cm1.e21);
		EXPECT_EQ(cm1.At(1, 3), cm1.e31);
		EXPECT_EQ(cm1.At(2, 0), cm1.e02);
		EXPECT_EQ(cm1.At(2, 1), cm1.e12);
		EXPECT_EQ(cm1.At(2, 2), cm1.e22);
		EXPECT_EQ(cm1.At(2, 3), cm1.e32);
		EXPECT_EQ(cm1.At(3, 0), cm1.e03);
		EXPECT_EQ(cm1.At(3, 1), cm1.e13);
		EXPECT_EQ(cm1.At(3, 2), cm1.e23);
		EXPECT_EQ(cm1.At(3, 3), cm1.e33);

		EXPECT_EQ(cm1.Data(), &cm1.e00);
	}
}
