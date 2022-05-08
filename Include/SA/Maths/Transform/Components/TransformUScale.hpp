// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_USCALE_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_USCALE_GUARD

#include <SA/Maths/Matrix/Matrix4.hpp>

namespace Sa
{
	template <typename T>
	struct TrUScale
	{
		T uScale = T(1);

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


	//{ Transformation

		void ConstructMatrix(Mat4<T>& _out) const noexcept
		{
			_out.ApplyScale(uScale);
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
			if constexpr (std::is_base_of<TrUScale, RhsT>::value)
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
			if constexpr (std::is_base_of<TrUScale, RhsT>::value)
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
