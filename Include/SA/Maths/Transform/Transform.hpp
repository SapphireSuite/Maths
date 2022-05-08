// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_GUARD

#include <SA/Maths/Debug.hpp>

#include <SA/Maths/Transform/TransformOrder.hpp>

namespace Sa
{
	/**
	 * @brief \e Transform Sapphire's class.
	 * 
	 * @tparam T 		Transform type.
	 * @tparam Args 	Transform component types.
	 */
	template <typename T, template <typename> typename... Args>
	struct Tr : public Args<T>...
	{
		using Type = T;

	//{ Equals

		/**
		*	\brief Whether this transform is a zero transform.
		*
		*	\return True if this is a zero transform.
		*/
		bool IsZero() const noexcept;

		/**
		*	\brief Whether this transform is an identity transform.
		*
		*	\return True if this is an identity transform.
		*/
		bool IsIdentity() const noexcept;

		/**
		*	\brief \e Compare 2 transform.
		*
		*	\param[in] _other		Other transform to compare to.
		*	\param[in] _epsilon		Epsilon value for threshold comparison.
		*
		*	\return Whether this and _other are equal.
		*/
		bool Equals(const Tr& _other) const noexcept;


		/**
		*	\brief \e Compare 2 transform equality.
		*
		*	\param[in] _rhs		Other transform to compare to.
		*
		*	\return Whether this and _rhs are equal.
		*/
		bool operator==(const Tr& _rhs) noexcept;

		/**
		*	\brief \e Compare 2 transform inequality.
		*
		*	\param[in] _rhs		Other transform to compare to.
		*
		*	\return Whether this and _rhs are non-equal.
		*/
		bool operator!=(const Tr& _rhs) noexcept;

	//}


	//{ Transformation

		/**
		*	\brief \e Getter of \b right vector (X axis) of this transform.
		*
		*	\return transformed right vector normalized.
		*/
		Vec3<T> Right() const;

		/**
		*	\brief \e Getter of \b up vector (Y axis) of this transform.
		*
		*	\return transformed up vector normalized.
		*/
		Vec3<T> Up() const;

		/**
		*	\brief \e Getter of \b forward vector (Z axis) of this transform.
		*
		*	\return transformed forward vector normalized.
		*/
		Vec3<T> Forward() const;


		template <typename ChildT>
		void ConstructMatrixComponent(Mat4<T>& _out) const noexcept;

		/**
		*	\brief \e Getter of Matrix
		*
		*	\return transformed forward vector normalized.
		*/
		Mat4<T> Matrix() const noexcept;

		/**
		*	\brief \e Getter of Matrix
		*
		*	\return transformed forward vector normalized.
		*/
		template <template <typename> typename... TrOrderArgs>
		Mat4<T> Matrix(TrOrderT<Tr<T, Args...>, TrOrderArgs...> _order) const noexcept;

	//}


	//{ Lerp

		/**
		*	\brief <b> Clamped Lerp </b> from _start to _end at _alpha.
		*
		*	Reference: https://en.wikipedia.org/wiki/Linear_interpolation
		*
		*	\param _start	Starting point of the lerp.
		*	\param _end		Ending point of the lerp.
		*	\param _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		static Tr Lerp(const Tr& _start, const Tr& _end, float _alpha) noexcept;

		/**
		*	\brief <b> Unclamped Lerp </b> from _start to _end at _alpha.
		*
		*	Reference: https://en.wikipedia.org/wiki/Linear_interpolation
		*
		*	\param _start	Starting point of the lerp.
		*	\param _end		Ending point of the lerp.
		*	\param _alpha	Alpha of the lerp.
		*
		*	\return interpolation between _start and _end. return _start when _alpha == 0.0f and _end when _alpha == 1.0f.
		*/
		static Tr LerpUnclamped(const Tr& _start, const Tr& _end, float _alpha) noexcept;

	//}


	//{ Operators

		/**
		*	\brief \b Multiply transform to compute transformation.
		*
		*	\param[in] _rhs		Transform to multiply.
		*
		*	\return new transform result.
		*/
		template <template <typename> typename... InArgs>
		Tr operator*(const Tr<T, InArgs...>& _rhs) const;

		/**
		*	\brief \b Divide transform to compute inverse-transformation.
		*
		*	\param[in] _rhs		Transform to divide.
		*
		*	\return new transform result.
		*/
		template <template <typename> typename... InArgs>
		Tr operator/(const Tr<T, InArgs...>& _rhs) const;

		/**
		*	\brief \b Multiply transform to compute transformation.
		*
		*	\param[in] _rhs		Transform to multiply.
		*
		*	\return self transform result.
		*/
		template <template <typename> typename... InArgs>
		Tr operator*=(const Tr<T, InArgs...>& _rhs) const;

		/**
		*	\brief \b Divide transform to compute inverse-transformation.
		*
		*	\param[in] _rhs		Transform to divide.
		*
		*	\return self transform result.
		*/
		template <template <typename> typename... InArgs>
		Tr operator/=(const Tr<T, InArgs...>& _rhs) const;


		// /**
		// *	\brief \e Cast operator into other Transf type.
		// *
		// *	\tparam TIn		Type of the casted transform.
		// *	\tparam CIn		Type of the casted TrComp.
		// *
		// *	\return \e Casted result.
		// */
		// template <typename TIn, TrComp CIn>
		// constexpr operator Transf<TIn, CIn>() const noexcept;
	//}


	private:

	//{ Packed

		template <typename CurrT, typename... PArgs>
		bool IsZeroPacked() const noexcept;

		template <typename CurrT, typename... PArgs>
		bool IsIdentityPacked() const noexcept;

		template <typename CurrT, typename... PArgs>
		bool EqualsPacked(const Tr& _other) const noexcept;


		template <typename CurrT, typename... PArgs>
		void LerpUnclampedPacked(const Tr& _start, const Tr& _end, float _alpha) noexcept;


		template <typename TrIn, typename CurrT, typename... PArgs>
		void MultiplyPacked(const Tr& _lhs, const TrIn& _rhs) noexcept;

		template <typename TrIn, typename CurrT, typename... PArgs>
		void DividePacked(const Tr& _lhs, const TrIn& _rhs) noexcept;
	
	//}


	#if SA_LOGGER_IMPL

		template <typename CurrT, typename... PArgs>
		std::string ToStringPacked() const noexcept;

	public:

		std::string ToString() const noexcept;

	#endif
	};


#if SA_LOGGER_IMPL

	/**
	*	\brief ToString Transform implementation
	*
	*	Convert Transform as a string.
	*
	*	\tparam T		Input Transform type.
	*	\tparam Args	Input Transform component types.
	*
	*	\param[in] _tr	Input Transform.
	*
	*	\return input transform as a string.
	*/
	template <typename T, template <typename> typename... Args>
	std::string ToString(const Tr<T, Args...>& _tr) { return _tr.ToString(); }

#endif

}

#include <SA/Maths/Transform/Transform.inl>

#endif // GUARD
