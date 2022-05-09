// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_ROTATION_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_ROTATION_GUARD

#include <SA/Maths/Space/Quaternion.hpp>

#include <SA/Maths/Transform/Components/TransformComponent.hpp>

namespace Sa
{
	template <typename T>
	struct TrRotation
	{
		Quat<T> rotation = Quat<T>::Identity;


	//{ Constructors

		TrRotation() = default;

		TrRotation(const Quat<T>& _rot) noexcept :
			rotation{ _rot }
		{
		}
	
	//}

	//{ Cast

		template <typename TOut>
		operator TrRotation<TOut>() const noexcept
		{
			return TrRotation<TOut>(rotation);
		}

	//}

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
			if constexpr (TrTHasComponent(RhsT)<TrRotation>())
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
			if constexpr (TrTHasComponent(RhsT)<TrRotation>())
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
