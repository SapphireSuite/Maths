// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_RECT2D_GUARD
#define SAPPHIRE_MATHS_RECT2D_GUARD

#include <SA/Maths/Space/Vector2.hpp>

namespace Sa
{
	template <typename T>
	struct Rect2D
	{
		union
		{
			Vec2<T> offset = Vec2<T>();

			struct
			{
				T x;
				T y;
			};
		};

		union
		{
			Vec2<T> extent = Vec2<T>();

			struct
			{
				T width;
				T height;
			};
		};

		Rect2D() = default;

		Rect2D(const Vec2<T>& _offset, const Vec2<T>& _extent) noexcept :
			offset{ _offset },
			extent{ _extent }
		{
		}

		Rect2D(T _x, T _y, T _width, T _height) noexcept :
			offset{ _x, _y },
			extent{ _width, _height }
		{
		}
	};


//{ Aliases

	/// Alias for int32 Rect2D.
	using Rect2Di = Rect2D<int32_t>;

	/// Alias for uint32 Rect2D.
	using Rect2Dui = Rect2D<uint32_t>;

	/// Alias for float Rect2D.
	using Rect2Df = Rect2D<float>;

	/// Alias for double Rect2D.
	using Rect2Dd = Rect2D<double>;


	/// Template alias of Rect2D.
	template <typename T>
	using Rectangle2D = Rect2D<T>;

	/// Alias for int32 Rect2D.
	using Rectangle2Di = Rectangle2D<int32_t>;

	/// Alias for uint32 Rect2D.
	using Rectangle2Dui = Rectangle2D<uint32_t>;

	/// Alias for float Rect2D.
	using Rectangle2Df = Rectangle2D<float>;

	/// Alias for double Rect2D.
	using Rectangle2Dd = Rectangle2D<double>;


//}
}

#endif // GUARD
