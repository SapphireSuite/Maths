// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_SCALE_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_SCALE_GUARD

#include <SA/Maths/Space/Vector3.hpp>

#include <SA/Maths/Transform/Components/TransformComponent.hpp>
#include <SA/Maths/Transform/Components/TransformUScale.hpp>

namespace Sa
{
	template <typename T>
	struct TrScale
	{
		Vec3<T> scale = Vec3<T>::One;


	//{ Constructors
	
		TrScale() = default;

		TrScale(const Vec3<T>& _scale) noexcept :
			scale{ _scale }
		{
		}
	
	//}


	//{ Cast

		template <typename TOut>
		operator TrScale<TOut>() const noexcept
		{
			return TrScale<TOut>(scale);
		}

	//}


	protected:

	//{ Equals

		constexpr bool IsZero() const noexcept
		{
			return scale.IsZero();
		}

		constexpr bool IsIdentity() const noexcept
		{
			return scale == Vec3<T>::One;
		}

		constexpr bool Equals(const TrScale& _other,
			T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept
		{
			return scale.Equals(_other.scale, _epsilon);
		}

	//}


	//{ Lerp

		static TrScale LerpUnclamped(const TrScale& _start, const TrScale& _end, float _alpha) noexcept
		{
			return TrScale{ Vec3<T>::LerpUnclamped(_start.scale, _end.scale, _alpha) };
		}

	//}


	//{ Operators

		template <typename RhsT>
		static TrScale Multiply(const TrScale& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<Sa::TrScale>())
			{
				// Scale component found.
				return TrScale{ _lhs.scale * _rhs.scale };
			}
			else if constexpr (TrTHasComponent(RhsT)<Sa::TrUScale>())
			{
				// UScale component found instead.
				return TrScale{ _lhs.scale * _rhs.uScale };
			}
			else
			{
				// Default: forward component (lhs always has this component).

				return _lhs;
			}
		}

		
		template <typename RhsT>
		static TrScale Divide(const TrScale& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<Sa::TrScale>())
			{
				// Scale component found.
				return TrScale{ _lhs.scale / _rhs.scale };
			}
			else if constexpr (TrTHasComponent(RhsT)<Sa::TrUScale>())
			{
				// UScale component found instead.
				return TrScale{ _lhs.scale / _rhs.uScale };
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
			return "Scale: " + Sa::ToString(scale);
		}

	#endif

	};
}

#endif // GUARD
