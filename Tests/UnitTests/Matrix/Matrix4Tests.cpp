// Copyright (c) 2022 Sapphire development team. All Rights Reserved.

#include "Matrix4Tests.hpp"

#include <SA/Maths/Matrix/MatrixMajor.hpp>

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
}
