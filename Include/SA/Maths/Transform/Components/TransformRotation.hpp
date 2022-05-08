// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_ROTATION_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_ROTATION_GUARD

#include <SA/Maths/Space/Quaternion.hpp>
#include <SA/Maths/Matrix/Matrix4.hpp>

namespace Sa
{
	template <typename T>
	struct TrRotation
	{
		Quat<T> rotation = Quat<T>::Identity;

	protected:

	//{ Equals

		constexpr bool IsZero() const noexcept
		{
			return rotation.IsZero();
		}

		constexpr bool IsIdentity() const noexcept
		{
			return rotation.IsIdentity();
		}

		constexpr bool Equals(const TrRotation& _other,
			T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept
		{
			return rotation.Equals(_other.rotation, _epsilon);
		}

	//}


	//{ Transformation

		void ConstructMatrix(Mat4<T>& _out) const noexcept
		{
			SA_WARN(_out == Mat4<T>::Identity, L"Construct rotation matrix from non-identity. Previous values erased.");

			_out = Mat4<T>::MakeRotation(rotation);
		}

	//}


	//{ Lerp

		static TrRotation LerpUnclamped(const TrRotation& _start, const TrRotation& _end, float _alpha) noexcept
		{
			return TrRotation{ Quat<T>::SLerpUnclamped(_start.rotation, _end.rotation, _alpha) };
		}

	//}


	//{ Operators

		template <typename RhsT>
		static TrRotation Multiply(const TrRotation& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (std::is_base_of<TrRotation, RhsT>::value)
			{
				// Rotation component found.

				return TrRotation{ _lhs.rotation * _rhs.rotation };
			}
			else
			{
				// Default: forward component (lhs always has this component).

				return _lhs;
			}
		}

		template <typename RhsT>
		static TrRotation Divide(const TrRotation& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (std::is_base_of<TrRotation, RhsT>::value)
			{
				// Rotation component found.

				return TrRotation{ _lhs.rotation / _rhs.rotation };
			}
			else
			{
				// Default: forward component (lhs always has this component).

				return _lhs;
			}
		}

	//}

	#if SA_LOGGER_IMPL

		std::string ToString() const
		{
			return "Rot: " + Sa::ToString(rotation);
		}

	#endif

	};
}

#endif // GUARD
