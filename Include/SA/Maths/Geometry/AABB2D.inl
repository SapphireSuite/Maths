// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

namespace SA
{
//{ Constructors

	template <typename T>
	AABB2D<T>::AABB2D(const Vec2<T>& _min, const Vec2<T>& _max) :
		min{ _min },
		max{ _max }
	{
		SA_ASSERT(Default, SA/Maths/AABB, IsValid(), L"Initialize AABB with invalid parameters: min must be < to max.", ToWString(*this));
	}

	template <typename T>
	AABB2D<T>::AABB2D(const AABB2D& _first, const AABB2D& _second) noexcept
	{
		*this = Merge(_first, _second);
	}

	template <typename T>
	AABB2D<T>::AABB2D(const AABB3D<T>& _aabb3D) noexcept :
		min{ _aabb3D.min },
		max{ _aabb3D.max }
	{
		
	}

//}


//{ Equals

	template <typename T>
	bool AABB2D<T>::IsValid() const noexcept
	{
		return min.x <= max.x && min.y <= max.y;
	}


	template <typename T>
	constexpr bool AABB2D<T>::Equals(const AABB2D& _other, T _epsilon) const noexcept
	{
		return min.Equals(_other.min, _epsilon) && max.Equals(_other.max, _epsilon);
	}


	template <typename T>
	constexpr bool AABB2D<T>::operator==(const AABB2D& _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename T>
	constexpr bool AABB2D<T>::operator!=(const AABB2D& _rhs) const noexcept
	{
		return !(*this == _rhs);
	}

//}


//{ Collisions

	template <typename T>
	bool AABB2D<T>::IsCollidingX(const AABB2D& _other) const
	{
		SA_ASSERT(Default, SA/Maths/AABB, IsValid(), L"Invalid AABB: min must be < to max.", ToWString(*this));

		// Check out of X bound.
		return !(min.x > _other.max.x || max.x < _other.min.x);
	}
	
	template <typename T>
	bool AABB2D<T>::IsCollidingY(const AABB2D& _other) const
	{
		SA_ASSERT(Default, SA/Maths/AABB, IsValid(), L"Invalid AABB: min must be < to max.", ToWString(*this));

		// Check out of Y bound.
		return !(min.y > _other.max.y || max.y < _other.min.y);
	}
	
	template <typename T>
	bool AABB2D<T>::IsColliding(const AABB2D& _other) const
	{
		return IsCollidingX(_other) || IsCollidingY(_other);
	}

//}


//{ Geometry

	template <typename T>
	float AABB2D<T>::Width() const
	{
		SA_ASSERT(Default, SA/Maths/AABB, IsValid(), L"Invalid AABB: min must be < to max.", ToWString(*this));

		return max.x - min.x;
	}

	template <typename T>
	float AABB2D<T>::Height() const
	{
		SA_ASSERT(Default, SA/Maths/AABB, IsValid(), L"Invalid AABB: min must be < to max.", ToWString(*this));

		return max.y - min.y;
	}

	template <typename T>
	Vec2<T> AABB2D<T>::Center() const
	{
		SA_ASSERT(Default, SA/Maths/AABB, IsValid(), L"Invalid AABB: min must be < to max.", ToWString(*this));

		return min + (max - min) / 2.0f;
	}

	template <typename T>
	float AABB2D<T>::Area() const
	{
		return Width() * Height();
	}

//}


	template <typename T>
	AABB2D<T> AABB2D<T>::Merge(const AABB2D& _first, const AABB2D& _second) noexcept
	{
		SA_ASSERT(Default, SA/Maths/AABB, _first.IsValid(), L"Invalid AABB: min must be < to max.", ToWString(_first));
		SA_ASSERT(Default, SA/Maths/AABB, _second.IsValid(), L"Invalid AABB: min must be < to max.", ToWString(_second));

		AABB2D merged;

		merged.min.x = std::min(_first.min.x, _second.min.x);
		merged.min.y = std::min(_first.min.y, _second.min.y);

		merged.max.x = std::max(_first.max.x, _second.max.x);
		merged.max.y = std::max(_first.max.y, _second.max.y);

		return merged;
	}


#if SA_LOGGER_IMPL

	template <typename T>
	std::string ToString(const AABB2D<T>& _aabb)
	{
		return "Min {" + SA::ToString(_aabb.min) + "}\tMax {" + SA::ToString(_aabb.max) + '}';
	}

#endif

}
