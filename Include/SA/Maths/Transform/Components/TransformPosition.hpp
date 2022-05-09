// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_POSITION_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_POSITION_GUARD

#include <SA/Maths/Space/Vector3.hpp>

#include <SA/Maths/Transform/Components/TransformComponent.hpp>
#include <SA/Maths/Transform/Components/TransformRotation.hpp>

namespace Sa
{
	template <typename T>
	struct TrPosition
	{
		Vec3<T> position;


	//{ Constructors
	
		TrPosition() = default;

		TrPosition(const Vec3<T>& _pos) noexcept :
			position{ _pos }
		{
		}
	
	//}


	//{ Cast

		template <typename TOut>
		operator TrPosition<TOut>() const noexcept
		{
			return TrPosition<TOut>(position);
		}

	//}

	protected:

	//{ Equals

		constexpr bool IsZero() const noexcept
		{
			return position.IsZero();
		}

		constexpr bool IsIdentity() const noexcept
		{
			// Position is Zero in identity transform.
			return position.IsZero();
		}

		constexpr bool Equals(const TrPosition& _other,
			T _epsilon = std::numeric_limits<T>::epsilon()) const noexcept
		{
			return position.Equals(_other.position, _epsilon);
		}

	//}


	//{ Lerp

		static TrPosition LerpUnclamped(const TrPosition& _start, const TrPosition& _end, float _alpha) noexcept
		{
			return TrPosition{ Vec3<T>::LerpUnclamped(_start.position, _end.position, _alpha) };
		}

	//}


	//{ Operators

		template <typename LhsT, typename RhsT>
		static TrPosition Multiply(const LhsT& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<TrPosition>())
			{
				// Position component found.

				if constexpr (TrTHasComponent(LhsT)<TrRotation>())
				{
					// Self rotation component found.
					// Apply translation with rotation:
					// position + rotation.Rotate(_other.position)

					return TrPosition{ _lhs.position + _lhs.rotation.Rotate(_rhs.position) };
				}
				else
				{
					// No rotation: apply translation.
					return TrPosition{ _lhs.position + _rhs.position };
				}
			}
			else
			{
				// Default: forward component (lhs always has this component).

				return _lhs;
			}
		}


		template <typename LhsT, typename RhsT>
		static TrPosition Divide(const LhsT& _lhs, const RhsT& _rhs) noexcept
		{
			if constexpr (TrTHasComponent(RhsT)<TrPosition>())
			{
				// Position component found.

				if constexpr (TrTHasComponent(LhsT)<TrRotation>())
				{
					// Self rotation component found.
					// Apply inverse translation with rotation:
					// position - rotation.Rotate(_other.position)

					return TrPosition{ _lhs.position - _lhs.rotation.Rotate(_rhs.position) };
				}
				else
				{
					// No rotation: apply inverse translation.
					return TrPosition{ _lhs.position - _rhs.position };
				}
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
			return "Pos: " + Sa::ToString(position);
		}

	#endif

	};
}

#endif // GUARD
