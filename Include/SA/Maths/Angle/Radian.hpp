// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_RADIAN_GUARD
#define SAPPHIRE_MATHS_RADIAN_GUARD

#include <cmath>

#include <SA/Maths/Debug.hpp>

#include <SA/Maths/Angle/Constants.hpp>
#include <SA/Maths/Algorithms/Equals.hpp>

/**
*	\file Radian.hpp
*
*	\brief \b Radian type implementation.
*
*	\ingroup Maths_Angle
*	\{
*/

namespace SA
{
	template <typename T>
	class Deg;

	/**
	*	\brief Maths \b Radian type.
	* 
	*	Handle Degree / Radian \b conversion.
	*/
	template <typename T>
	class Rad
	{
		/// Handled value.
		T mHandle = T(0.0);

	public:
		/// \b Default contructor.
		Rad() = default;

		/**
		*	\brief \e Value constructor without conversion.
		*
		*	\param[in] _rad		The value in radian to assign.
		*/
		constexpr Rad(T _rad) noexcept;

		/**
		*	\brief \e Value constructor without conversion.
		*
		*	\param[in] _other		The value in radian to assign.
		*/
		template <typename TIn>
		constexpr Rad(Rad<TIn> _other) noexcept;

		/**
		*	\brief \e Value constructor from radian.
		*
		*	\param[in] _deg		The value in degree to assign.
		*/
		template <typename TIn>
		constexpr Rad(Deg<TIn> _deg) noexcept;


		/**
		*	\brief Access the handled value.
		*
		*	\return handle as \c T without conversion.
		*/
		constexpr T Handle() const noexcept;

		/**
		*	\brief \e Compare 2 Rad.
		*
		*	\param[in] _other		Other Rad to compare to.
		*	\param[in] _epsilon		Epsilon value for threshold compare.
		*
		*	\return Whether this and _other are equal.
		*/
		constexpr bool Equals(Rad _other, T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept;


		/**
		*	\brief clamp this angle between [-Pi, Pi].
		*/
		void Clamp() noexcept;


		/**
		*	\brief \e Getter of the opposite signed radian.
		*
		*	\return new opposite signed radian.
		*/
		constexpr Rad operator-() const noexcept;

		/**
		*	\brief \b Add Radian to handle.
		*
		*	\param[in] _rhs		radian to add.
		*
		*	\return new Radian result.
		*/
		constexpr Rad operator+(Rad _rhs) const noexcept;

		/**
		*	\brief \b Substract Radian to handle.
		*
		*	\param[in] _rhs		radian to substract.
		*
		*	\return new Radian result.
		*/
		constexpr Rad operator-(Rad _rhs) const noexcept;

		/**
		*	\brief \b Scale angle.
		*
		*	\param[in] _scale	scale to apply.
		*
		*	\return new radian result.
		*/
		constexpr Rad operator*(T _scale) const noexcept;

		/**
		*	\brief \b Unscale angle.
		*
		*	\param[in] _scale	un-scale to apply.
		*
		*	\return new radian result.
		*/
		Rad operator/(T _scale) const;


		/**
		*	\brief \b Add Radian to handle.
		*
		*	\param[in] _rhs		radian to add.
		*
		*	\return self Radian.
		*/
		Rad& operator+=(Rad _rhs) noexcept;

		/**
		*	\brief \b Substract Radian to handle.
		*
		*	\param[in] _rhs		radian to substract.
		*
		*	\return self Radian.
		*/
		Rad& operator-=(Rad _rhs) noexcept;

		/**
		*	\brief \b Scale angle.
		*
		*	\param[in] _scale	scale to apply.
		*
		*	\return this radian scaled.
		*/
		Rad& operator*=(T _scale) noexcept;

		/**
		*	\brief \b Unscale angle.
		*
		*	\param[in] _scale	un-scale to apply.
		*
		*	\return this radian unscaled.
		*/
		Rad& operator/=(T _scale);


		/**
		*	\brief \e Compare 2 radian equality.
		*
		*	\param[in] _rhs		Other radian to compare to.
		*
		*	\return Whether this and _rhs are equal.
		*/
		constexpr bool operator==(Rad _rhs) const noexcept;

		/**
		*	\brief \e Compare 2 radian inequality.
		*
		*	\param[in] _rhs		Other radian to compare to.
		*
		*	\return Whether this and _rhs are non-equal.
		*/
		constexpr bool operator!=(Rad _rhs) const noexcept;


		/**
		*	\brief Access the handled value.
		*
		*	\return handle as \c float without conversion.
		*/
		explicit constexpr operator T() const noexcept;
	};

#if SA_LOGGER_IMPL

	/**
	*	\brief ToString Rad implementation
	*
	*	Convert Rad as a string.
	*
	*	\tparam T		Input radian type.
	*
	*	\param[in] _r	Input radian.
	*
	*	\return input radian as a string.
	*/
	template <typename T>
	std::string ToString(const Rad<T>& _r);

#endif


//{ Aliases

	/// Alias for float Rad.
	using Radf = Rad<float>;

	/// Alias for double Rad.
	using Radd = Rad<double>;

	/// Template alias of Rad
	template <typename T>
	using Radian = Rad<T>;

//}


	/**
	*	\brief _rad \b literal operator.
	*
	*	\param[in] _lit		Operand to convert to Radian.
	*
	*	\return \c Radian without maths-conversion.
	*/
	constexpr Radf operator""_rad(unsigned long long _lit) noexcept;

	/**
	*	\brief _rad \b literal operator.
	*
	*	\param[in] _lit		Operand to convert to Radian.
	*
	*	\return \c Radian without maths-conversion.
	*/
	constexpr Radd operator""_rad(long double _lit) noexcept;
}

/**
*	\example RadianTests.cpp
*	Examples and Unitary Tests for Rad.
*/


/** \} */

#include <SA/Maths/Angle/Radian.inl>

#endif // GUARD
