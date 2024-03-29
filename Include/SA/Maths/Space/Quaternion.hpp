// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_QUATERNION_GUARD
#define SAPPHIRE_MATHS_QUATERNION_GUARD

#include <cstdint>

#include <SA/Maths/Debug.hpp>
#include <SA/Maths/Config.hpp>

#include <SA/Maths/Angle/Degree.hpp>
#include <SA/Maths/Algorithms/Cos.hpp>
#include <SA/Maths/Algorithms/Sin.hpp>
#include <SA/Maths/Algorithms/Tan.hpp>
#include <SA/Maths/Algorithms/Sqrt.hpp>
#include <SA/Maths/Algorithms/Lerp.hpp>
#include <SA/Maths/Algorithms/Equals.hpp>

#if SA_MATHS_QUATERNION_SIMD

	#include <SA/Support/Intrinsics.hpp>

#endif

/**
*	\file Quaternion.hpp
*
*	\brief \b Quaternion type implementation.
*
*	\ingroup Maths_Space
*	\{
*/


namespace SA
{
	template <typename T>
	struct Vec3;

	/**
	*	\brief \e Quaternion Sapphire-Maths class.
	*
	*	must be align at 4 * sizeof(T) for intrinsics.
	*	For T = float: align as 16.
	*	For T = double: align as 32.
	* 
	*	\tparam T	Type of the Quaternion.
	*/
	template <typename T>
	struct alignas(sizeof(T) * 4) Quat
	{
		/// Type of the Quaternion.
		using Type = T;


		/// Quaternion's W component (Real value).
		T w = T(1);

		/// Quaternion's X component (i axis).
		T x = T();

		/// Quaternion's Y component (j axis).
		T y = T();

		/// Quaternion's Z component (k axis).
		T z = T();

//{ Constants

		/// Zero quaternion constant { 0, 0, 0, 0 }
		static const Quat Zero;

		/// Identity quaternion constant { 1, 0, 0, 0 }
		static const Quat Identity;

//}

//{ Constructors

		/// \e Default constructor.
		Quat() = default;

		/**
		*	\brief \e Value constructor.
		*
		*	\param[in] _w	W value.
		*	\param[in] _x	X value.
		*	\param[in] _y	Y value.
		*	\param[in] _z	Z value.
		*/
		constexpr Quat(T _w, T _x, T _y, T _z) noexcept;


		/// Default move constructor.
		Quat(Quat&&) = default;

		/// Default copy constructor.
		Quat(const Quat&) = default;

		/**
		*	\brief \e Value constructor from another quaternion type.
		*
		*	\tparam TIn			Type of the input quaternion.
		*
		*	\param[in] _other	Quat to construct from.
		*/
		template <typename TIn>
		constexpr Quat(const Quat<TIn>& _other) noexcept;


		/**
		*	\brief \e Value constructor angle and axis.
		*
		*	\param[in] _angle	Angle rotation in Degree.
		*	\param[in] _axis	Axis rotation.
		*/
		Quat(Deg<T> _angle, const Vec3<T>& _axis) noexcept;

//}

//{ Equals

		/**
		*	\brief Whether this quaternion is a zero quaternion.
		*
		*	\return True if this is a zero quaternion.
		*/
		constexpr bool IsZero() const noexcept;

		/**
		*	\brief Whether this quaternion is an identity quaternion.
		*
		*	\return True if this is an identity quaternion.
		*/
		constexpr bool IsIdentity() const noexcept;

		/**
		*	\brief \e Compare 2 quaternion.
		*
		*	\param[in] _other		Other quaternion to compare to.
		*	\param[in] _threshold	Allowed threshold to accept equality.
		*
		*	\return Whether this and _other are equal.
		*/
		constexpr bool Equals(const Quat& _other, T _threshold = std::numeric_limits<T>::epsilon()) const noexcept;


		/**
		*	\brief \e Compare 2 quaternion equality.
		*
		*	\param[in] _rhs		Other quaternion to compare to.
		*
		*	\return Whether this and _rhs are equal.
		*/
		constexpr bool operator==(const Quat<T>& _rhs) const noexcept;

		/**
		*	\brief \e Compare 2 quaternion inequality.
		*
		*	\param[in] _rhs		Other quaternion to compare to.
		*
		*	\return Whether this and _rhs are non-equal.
		*/
		constexpr bool operator!=(const Quat<T>& _rhs) const noexcept;

//}

//{ Accessors

		/**
		*	\brief \e Getter of quaternion data
		*
		*	\return this quaternion as a T*.
		*/
		T* Data() noexcept;

		/**
		*	\brief <em> Const Getter </em> of quaternion data
		*
		*	\return this quaternion as a const T*.
		*/
		const T* Data() const noexcept;


		/**
		*	\brief \e Access operator by index.
		*
		*	\param[in] _index	Index to access: 0 == w, 1 == x, 2 == y, 3 == z.
		*
		*	\return T value at index.
		*/
		T& operator[](uint32_t _index);

		/**
		*	\brief <em> Const Access </em> operator by index.
		*
		*	\param[in] _index	Index to access: 0 == w, 1 == x, 2 == y, 3 == z.
		*
		*	\return T value at index.
		*/
		T operator[](uint32_t _index) const;

//}

//{ Length

		/**
		*	\brief \e Getter of the \b length of this quaternion.
		*
		*	\return Length of this quaternion.
		*/
		T Length() const;

		/**
		*	\brief \e Getter of the <b> Squared Length </b> of this quaternion.
		*
		*	\return Squared Length of this quaternion.
		*/
		T SqrLength() const noexcept;


		/**
		*	\brief \b Normalize this quaternion.
		*
		*	\return self quaternion normalized.
		*/
		Quat& Normalize();

		/**
		*	\brief \b Normalize this quaternion.
		*
		*	\return new normalized quaternion.
		*/
		Quat GetNormalized() const;

		/**
		*	\brief Whether this quaternion is normalized.
		*
		*	\return True if this quaternion is normalized, otherwise false.
		*/
		bool IsNormalized() const noexcept;

//}

//{ Inverse

		/**
		*	\brief \b Inverse this quaternion.
		*	Quaternion should be normalized.
		*
		*	\return self quaternion inversed.
		*/
		Quat& Inverse() noexcept;

		/**
		*	\brief \b Inverse this quaternion.
		*	Quaternion should be normalized.
		*
		*	\return new quaternion inversed.
		*/
		constexpr Quat GetInversed() const noexcept;

//}

//{ Angle/Axis

		/**
		*	\brief \e Getter of quaternion's imaginary axis.
		*
		*	Get the values of i, j and k axis (x, y, z).
		*
		*	\return Vec3<T> imaginary axis of this quaternion.
		*/
		Vec3<T>& ImgAxis() noexcept;

		/**
		*	\brief \e <em> Const Getter </em> of quaternion's imaginary axis.
		*
		*	Get the values of i, j and k axis (x, y, z).
		*
		*	\return const Vec3<T> imaginary axis of this quaternion.
		*/
		const Vec3<T>& ImgAxis() const noexcept;

		/**
		*	\brief \e Getter of the angle handled by this quaternion.
		*
		*	\return Angle of the quaternion.
		*/
		constexpr Deg<T> GetAngle() const noexcept;

		/**
		*	\brief \e Getter of the axis handled by this quaternion.
		*
		*	\return Axis of the quaternion.
		*/
		constexpr Vec3<T> GetAxis() const noexcept;

//}

//{ Rotate

		/**
		*	\brief \b Rotate _other quaternion by this quaternion.
		*
		*	Multiply two quaternions.
		*	Quaternion must be normalized.
		*
		*	\param[in] _other		Quaternion to rotate.
		*
		*	\return new rotated quaternion.
		*/
		Quat<T> Rotate(const Quat<T>& _other) const noexcept;

		/**
		*	\brief \b Rotate _vec vector by this quaternion.
		*
		*	Apply quaternion rotation to vector.
		*	Quaternion must be normalized.
		*
		*	\param[in] _vec		Vector to rotate.
		*
		*	\return new rotated vector.
		*/
		constexpr Vec3<T> Rotate(const Vec3<T>& _vec) const noexcept;

		/**
		*	\brief \b Un-Rotate _other quaternion by this quaternion.
		*
		*	Apply the inverse rotation multiplication.
		*	Quaternion must be normalized.
		*
		*	\param[in] _other		Quaternion to un-rotate.
		*
		*	\return new un-rotated quaternion.
		*/
		Quat<T> UnRotate(const Quat<T>& _other) const noexcept;

		/**
		*	\brief \b Un-Rotate _vec vector by this quaternion.
		*
		*	Apply the inverse rotation to vector.
		*	Quaternion must be normalized.
		*
		*	\param[in] _vec		Vector to un-rotate.
		*
		*	\return new un-rotated vector.
		*/
		constexpr Vec3<T> UnRotate(const Vec3<T>& _vec) const noexcept;

		/**
		*	\brief \e Getter of Right vector (X axis) rotated by this quaternion.
		*
		*	\return rotated right vector normalized.
		*/
		constexpr Vec3<T> RightVector() const noexcept;

		/**
		*	\brief \e Getter of Up vector (Y axis) rotated by this quaternion.
		*
		*	\return rotated up vector normalized.
		*/
		constexpr Vec3<T> UpVector() const noexcept;

		/**
		*	\brief \e Getter of Forward vector (Z axis) rotated by this quaternion.
		*
		*	\return rotated forward vector normalized.
		*/
		constexpr Vec3<T> ForwardVector() const noexcept;

//}

//{ Euler

		/**
		*	\brief \e Convert this quaternion into euler angles in degrees.
		* 
		*	Euler norm:
		*	X-Axis: Pitch
		*	Y-Axis: Yaw
		*	Z-Axis: Roll
		*
		*	\return Euler angles in degrees.
		*/
		Vec3<Deg<T>> ToEuler() const noexcept;

		/**
		*	\brief \e Create quaternion from euler angles in degrees.
		*
		*	\param[in] _angles	Euler angles in degree (using Engine euler norm).
		* 
		*	Euler norm:
		*	X-Axis: Pitch
		*	Y-Axis: Yaw
		*	Z-Axis: Roll
		*
		*	\return Quaternion from angles.
		*/
		static Quat FromEuler(const Vec3<Deg<T>>& _angles) noexcept;

//}

//{ Dot

		/**
		*	\brief \e Compute the <b> Dot product </b> between _lhs and _rhs.
		*
		*	\param[in] _lhs		Left hand side operand to compute dot product with.
		*	\param[in] _rhs		Right hand side operand to compute dot product with.
		*
		*	\return <b> Dot product </b> between _lhs and _rhs.
		*/
		static T Dot(const Quat& _lhs, const Quat& _rhs) noexcept;

//}

//{ Lerp

		/**
		*	\brief <b> Clamped Lerp </b> from _start to _end at _alpha.
		*
		*	_start and _end should be normalized.
		*	Result quaternion is normalized.
		*	Reference: https://en.wikipedia.org/wiki/Linear_interpolation
		*
		*	\param _start	Starting point of the lerp.
		*	\param _end		Ending point of the lerp.
		*	\param _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		static Quat Lerp(const Quat& _start, const Quat& _end, float _alpha);

		/**
		*	\brief <b> Unclamped Lerp </b> from _start to _end at _alpha.
		*
		*	_start and _end should be normalized.
		*	Result quaternion is normalized.
		*	Reference: https://en.wikipedia.org/wiki/Linear_interpolation
		*
		*	\param _start	Starting point of the lerp.
		*	\param _end		Ending point of the lerp.
		*	\param _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		static Quat LerpUnclamped(const Quat& _start, const Quat& _end, float _alpha);

		/**
		*	\brief <b> Clamped SLerp </b> from _start to _end at _alpha.
		*
		*	_start and _end should be normalized.
		*	Result quaternion is normalized.
		*	Reference: https://en.wikipedia.org/wiki/Slerp
		*
		*	\param _start	Starting point of the lerp.
		*	\param _end		Ending point of the lerp.
		*	\param _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		static Quat SLerp(const Quat& _start, const Quat& _end, float _alpha);

		/**
		*	\brief <b> Unclamped SLerp </b> from _start to _end at _alpha.
		*
		*	_start and _end should be normalized.
		*	Result quaternion is normalized.
		*	Reference: https://en.wikipedia.org/wiki/Slerp
		*
		*	\param _start	Starting point of the lerp.
		*	\param _end		Ending point of the lerp.
		*	\param _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		static Quat SLerpUnclamped(const Quat& _start, const Quat& _end, float _alpha);

//}

//{ Operators

		/**
		*	\brief \e Default assignment move operator.
		* 
		*	\return self vector assigned.
		*/
		Quat& operator=(Quat&&) = default;

		/**
		*	\brief \e Default assignment copy operator.
		*
		*	\return self vector assigned.
		*/
		Quat& operator=(const Quat&) = default;


		/**
		*	\brief \e Getter of the opposite signed quaternion.
		*
		*	\return new opposite signed quaternion.
		*/
		constexpr Quat operator-() const noexcept;

		/**
		*	\brief \b Scale each quaternion components by _scale.
		*
		*	\param[in] _scale	Scale value to apply on components.
		*
		*	\return new quaternion scaled.
		*/
		Quat operator*(T _scale) const noexcept;

		/**
		*	\brief <b> Inverse Scale </b> each quaternion components by _scale.
		*
		*	\param[in] _scale	Inverse scale value to apply on all components.
		*
		*	\return new quaternion inverse-scaled.
		*/
		Quat operator/(T _scale) const;

		/**
		*	\brief \b Add term by term quaternion values.
		*
		*	\param[in] _rhs		Quaternion to add.
		*
		*	\return new quaternion result.
		*/
		Quat operator+(const Quat& _rhs) const noexcept;

		/**
		*	\brief \b Subtract term by term quaternion values.
		*
		*	\param[in] _rhs		Quaternion to substract.
		*
		*	\return new quaternion result.
		*/
		Quat operator-(const Quat& _rhs) const noexcept;

		/**
		*	\brief \b Multiply quaternion to compute rotation.
		*
		*	Rotate _rhs by this (ie: this.Rotate(_rhs)).
		*	Quaternion should be normalized.
		*
		*	\param[in] _rhs		Quaternion to multiply.
		*
		*	\return new quaternion result.
		*/
		Quat operator*(const Quat& _rhs) const noexcept;

		/**
		*	\brief \b Rotate _rhs vector by this quaternion.
		*
		*	Apply quaternion rotation to vector.
		*	Quaternion must be normalized.
		*
		*	\param[in] _rhs		Vector to rotate.
		*
		*	\return new rotated vector.
		*/
		constexpr Vec3<T> operator*(const Vec3<T>& _rhs) const noexcept;

		/**
		*	\brief \b Divide quaternion to compute the inverse rotation.
		*
		*	Unrotate _rhs by this (ie: this.UnRotate(_rhs)).
		*	Quaternion should be normalized.
		*
		*	\param[in] _rhs		Quaternion to divide.
		*
		*	\return new quaternion result.
		*/
		Quat operator/(const Quat& _rhs) const noexcept;

		/**
		*	\brief \b Un-Rotate _rhs vector by this quaternion.
		*
		*	Apply quaternion inverse rotation to vector.
		*	Quaternion must be normalized.
		*
		*	\param[in] _rhs		Vector to un-rotate.
		*
		*	\return new un-rotated vector.
		*/
		constexpr Vec3<T> operator/(const Vec3<T>& _rhs) const noexcept;

		/**
		*	\brief \e Compute the <b> Dot product </b> between this and _rhs.
		*
		*	\param[in] _rhs		Right hand side operand quaternion to compute dot product with.
		*
		*	\return <b> Dot product </b> between this quaternion and _other.
		*/
		constexpr T operator|(const Quat& _rhs) const noexcept;

		/**
		*	\brief \b Scale each quaternion values by _scale.
		*
		*	\tparam TIn			Type of the input scale.
		*	\param[in] _scale	Scale value to apply on all components.
		*
		*	\return self quaternion scaled.
		*/
		Quat& operator*=(T _scale) noexcept;

		/**
		*	\brief <b> Inverse Scale </b> each quaternion values by _scale.
		*
		*	\tparam TIn			Type of the input scale.
		*	\param[in] _scale	Scale value to apply on all components.
		*
		*	\return self quaternion inverse-scaled.
		*/
		Quat& operator/=(T _scale);

		/**
		*	\brief \b Add term by term quaternion values.
		*
		*	\param[in] _rhs		Quaternion to add.
		*
		*	\return self quaternion result.
		*/
		Quat& operator+=(const Quat& _rhs) noexcept;

		/**
		*	\brief \b Substract term by term quaternion values.
		*
		*	\param[in] _rhs		Quaternion to substract.
		*
		*	\return self quaternion result.
		*/
		Quat& operator-=(const Quat& _rhs) noexcept;

		/**
		*	\brief \b Multiply quaternion to compute rotation.
		*
		*	Quaternion should be normalized.
		*
		*	\param[in] _rhs		Quaternion to multiply.
		*
		*	\return self quaternion result.
		*/
		Quat& operator*=(const Quat& _rhs) noexcept;

		/**
		*	\brief \b Divide quaternion to compute the inverse rotation.
		*
		*	Quaternion should be normalized.
		*
		*	\param[in] _rhs		Quaternion to divide.
		*
		*	\return self quaternion result.
		*/
		Quat& operator/=(const Quat& _rhs) noexcept;

//}


#if SA_LOGGING

		/**
		*	\brief ToString implementation
		*
		*	Convert this vector as a string.
		*
		*	\return this as a string.
		*/
		std::string ToString() const noexcept;

#endif
	};


	/**
	*	\brief \b Scale each quaternion components by _lhs.
	*
	*	\param[in] _lhs		Scale value to apply on all axis.
	*	\param[in] _rhs		Quaternion to scale.
	*
	*	\return new vector scaled.
	*/
	template <typename T>
	constexpr Quat<T> operator*(typename std::remove_cv<T>::type _lhs, const Quat<T>& _rhs) noexcept;

	/**
	*	\brief <b> Inverse Scale </b> each quaternion components by _lhs.
	*
	*	\param[in] _lhs		Inverse scale value to apply on all axis.
	*	\param[in] _rhs		Quaternion to scale.
	*
	*	\return new quaternion inverse-scaled.
	*/
	template <typename T>
	Quat<T> operator/(typename std::remove_cv<T>::type _lhs, const Quat<T>& _rhs);

	/**
	*	\brief \b Rotate _lhs vector by _rhs quaternion.
	*
	*	Apply quaternion rotation to vector.
	*	Quaternion must be normalized.
	*
	*	\param[in] _lhs		Vector to rotate.
	*	\param[in] _rhs		Quaternion used for rotation.
	*
	*	\return new rotated vector.
	*/
	template <typename T>
	constexpr Vec3<T> operator*(const Vec3<T>& _lhs, const Quat<T>& _rhs) noexcept;

	/**
	*	\brief <b> Inverse-Rotate </b> _lhs vector by _rhs quaternion.
	*
	*	Apply quaternion rotation to vector.
	*	Quaternion must be normalized.
	*
	*	\param[in] _lhs		Vector to rotate.
	*	\param[in] _rhs		Quaternion used for rotation.
	*
	*	\return new inverse-rotated vector.
	*/
	template <typename T>
	constexpr Vec3<T> operator/(const Vec3<T>& _lhs, const Quat<T>& _rhs) noexcept;


#if SA_LOGGER_IMPL

	/**
	*	\brief ToString Quat implementation
	*
	*	Convert Quat as a string.
	*
	*	\tparam T		Input quaternion type.
	*
	*	\param[in] _q	Input quaternion.
	*
	*	\return input quaternion as a string.
	*/
	template <typename T>
	std::string ToString(const Quat<T>& _q);

#endif


//{ Aliases

	/// Alias for float Quat.
	using Quatf = Quat<float>;

	/// Alias for double Quat.
	using Quatd = Quat<double>;


	/// Template alias of Quat
	template <typename T>
	using Quaternion = Quat<T>;

	/// Alias for float Quaternion.
	using Quaternionf = Quaternion<float>;

	/// Alias for double Quaternion.
	using Quaterniond = Quaternion<double>;

//}


	/// \cond Internal
	

#if SA_MATHS_QUATERNION_SIMD && SA_INTRISC_SSE	// SIMD float

	template <>
	float Quatf::SqrLength() const noexcept;

	template <>
	Quatf& Quatf::Normalize();

	template <>
	Quatf Quatf::GetNormalized() const;


	template <>
	Quatf Quatf::Rotate(const Quatf& _other) const noexcept;


	template <>
	float Quatf::Dot(const Quatf& _lhs, const Quatf& _rhs) noexcept;

	template <>
	Vec3<Degf> Quatf::ToEuler() const noexcept;

	template <>
	Quatf Quatf::FromEuler(const Vec3<Degf>& _angles) noexcept;


	template <>
	Quatf Quatf::operator*(float _scale) const noexcept;

	template <>
	Quatf Quatf::operator/(float _scale) const;

	template <>
	Quatf Quatf::operator+(const Quatf& _rhs) const noexcept;

	template <>
	Quatf Quatf::operator-(const Quatf& _rhs) const noexcept;


	template <>
	Quatf& Quatf::operator*=(float _scale) noexcept;

	template <>
	Quatf& Quatf::operator/=(float _scale);

	template <>
	Quatf& Quatf::operator+=(const Quatf& _rhs) noexcept;

	template <>
	Quatf& Quatf::operator-=(const Quatf& _rhs) noexcept;


	template <>
	Quatf operator/(float _lhs, const Quatf& _rhs);

#endif

#if SA_MATHS_QUATERNION_SIMD && SA_INTRISC_AVX // SIMD double

	template <>
	double Quatd::SqrLength() const noexcept;

	template <>
	Quatd& Quatd::Normalize();

	template <>
	Quatd Quatd::GetNormalized() const;


	template <>
	Quatd Quatd::Rotate(const Quatd& _other) const noexcept;


	template <>
	double Quatd::Dot(const Quatd& _lhs, const Quatd& _rhs) noexcept;


	template <>
	Vec3<Degd> Quatd::ToEuler() const noexcept;

	template <>
	Quatd Quatd::FromEuler(const Vec3<Degd>& _angles) noexcept;


	template <>
	Quatd Quatd::operator*(double _scale) const noexcept;

	template <>
	Quatd Quatd::operator/(double _scale) const;

	template <>
	Quatd Quatd::operator+(const Quatd& _rhs) const noexcept;

	template <>
	Quatd Quatd::operator-(const Quatd& _rhs) const noexcept;


	template <>
	Quatd& Quatd::operator*=(double _scale) noexcept;

	template <>
	Quatd& Quatd::operator/=(double _scale);

	template <>
	Quatd& Quatd::operator+=(const Quatd& _rhs) noexcept;

	template <>
	Quatd& Quatd::operator-=(const Quatd& _rhs) noexcept;


	template <>
	Quatd operator/(double _lhs, const Quatd& _rhs);

#endif

	/// \endcond
}

/**
*	\example QuaternionTests.cpp
*	Examples and Unitary Tests for Quat.
*/


/** \} */

#include <SA/Maths/Space/Quaternion.inl>

#endif // GUARD
