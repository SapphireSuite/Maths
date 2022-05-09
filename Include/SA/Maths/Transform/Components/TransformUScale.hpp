// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_USCALE_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_USCALE_GUARD

#include <SA/Maths/Transform/Components/TransformComponent.hpp>

namespace Sa
{
	template <typename T>
	struct TrUScale
	{
		T uScale = T(1);


	//{ Constructors

		TrUScale() = default;

		TrUScale(T _uscale) noexcept :
			uScale{ _uscale }
		{
		}
	
	//}


	//{ Cast

		template <typename TOut>
		operator TrUScale<TOut>() const noexcept
		{
			return TrUScale<TOut>(uScale);
		}

	//}

	protected:

	//{ Equals

		constexpr bool IsZero() const noexcept
		{
			return uScale == T(0);
		}

		constexpr bool IsIdentity() const noexcept
		{
			return uScale == T(1);
		}

		constexpr bool Equals(const TrUScale& _other,
			T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept
		{
			return Maths::Equals(uScale, _other.uScale, _epsilon);
		}

	//}


	//{ Lerp

		static TrUScale LerpUnclamped(const TrUScale& _start, const TrUScale& _end, float _alpha) noexcept
		{
			return TrUScale{ Maths::LerpUnclamped(_start.uScale, _end.uScale, _alpha) };
		}

	//}


	//{ Operators

		template <typename RhsT>
		static TrUScale Multiply(const TrUScale& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<TrUScale>())
			{
				// UScale component found.

				return TrUScale{ _lhs.uScale * _rhs.uScale };
			}
			else
			{
				// Default: forward component (lhs always has this component).

				return _lhs;
			}
		}

		template <typename RhsT>
		static TrUScale Divide(const TrUScale& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<TrUScale>())
			{
				// UScale component found.

				return TrUScale{ _lhs.uScale / _rhs.uScale };
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
			return "UScale: " + Sa::ToString(uScale);
		}

	#endif

	};
}

#endif // GUARD
