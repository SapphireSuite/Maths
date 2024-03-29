// Copyright (c) 2023 Sapphire development team. All Rights Reserved.

namespace SA
{
//{ Constants

	template <typename T>
	const Vec3<T> Vec3<T>::Zero{ T(0), T(0), T(0) };

	template <typename T>
	const Vec3<T> Vec3<T>::One{ T(1), T(1), T(1) };

	template <typename T>
	const Vec3<T> Vec3<T>::Right{ T(1), T(0), T(0) };

	template <typename T>
	const Vec3<T> Vec3<T>::Left{ T(-1), T(0), T(0) };

	template <typename T>
	const Vec3<T> Vec3<T>::Up{ T(0), T(1), T(0) };

	template <typename T>
	const Vec3<T> Vec3<T>::Down{ T(0), T(-1), T(0) };

	template <typename T>
	const Vec3<T> Vec3<T>::Forward{ T(0), T(0), T(1) };

	template <typename T>
	const Vec3<T> Vec3<T>::Backward{ T(0), T(0), T(-1) };

//}

//{ Constructors

	template <typename T>
	constexpr Vec3<T>::Vec3(T _x, T _y, T _z) noexcept :
		x{ _x },
		y{ _y },
		z{ _z }
	{
	}

	template <typename T>
	constexpr Vec3<T>::Vec3(T _scale) noexcept :
		x{ _scale },
		y{ _scale },
		z{ _scale }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Vec3<T>::Vec3(const Vec3<TIn>& _other) noexcept :
		x{ static_cast<T>(_other.x) },
		y{ static_cast<T>(_other.y) },
		z{ static_cast<T>(_other.z) }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Vec3<T>::Vec3(const Vec2<TIn>& _other, T _z) noexcept :
		x{ static_cast<T>(_other.x) },
		y{ static_cast<T>(_other.y) },
		z{ _z }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Vec3<T>::Vec3(const Vec4<TIn>& _other) noexcept :
		x{ static_cast<T>(_other.x) },
		y{ static_cast<T>(_other.y) },
		z{ static_cast<T>(_other.z) }
	{
	}

//}

//{ Equals

	template <typename T>
	constexpr bool Vec3<T>::IsZero() const noexcept
	{
		return Maths::Equals0(x) && Maths::Equals0(y) && Maths::Equals0(z);
	}

	template <typename T>
	constexpr bool Vec3<T>::Equals(const Vec3& _other, T _epsilon) const noexcept
	{
		return Maths::Equals(x, _other.x, _epsilon) && Maths::Equals(y, _other.y, _epsilon) && Maths::Equals(z, _other.z, _epsilon);
	}


	template <typename T>
	constexpr bool Vec3<T>::operator==(const Vec3& _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename T>
	constexpr bool Vec3<T>::operator!=(const Vec3& _rhs) const noexcept
	{
		return !(*this == _rhs);
	}

//}

//{ Accessors

	template <typename T>
	T* Vec3<T>::Data() noexcept
	{
		return &x;
	}

	template <typename T>
	const T* Vec3<T>::Data() const noexcept
	{
		return &x;
	}


	template <typename T>
	T& Vec3<T>::operator[](uint32_t _index)
	{
		SA_ASSERT((OutOfRange, _index, 0u, 2u), SA.Maths);

		return Data()[_index];
	}

	template <typename T>
	const T& Vec3<T>::operator[](uint32_t _index) const
	{
		SA_ASSERT((OutOfRange, _index, 0u, 2u), SA.Maths);

		return Data()[_index];
	}

//}

//{ Length

	template <typename T>
	constexpr T Vec3<T>::Length() const
	{
		return Maths::Sqrt(SqrLength());
	}

	template <typename T>
	constexpr T Vec3<T>::SqrLength() const noexcept
	{
		return x * x + y * y + z * z;
	}


	template <typename T>
	Vec3<T>& Vec3<T>::Normalize()
	{
		SA_ASSERT((NotEquals, *this, Zero), SA.Maths.Vec3, L"Normalize null vector!");

		const T norm = Length();

		x /= norm;
		y /= norm;
		z /= norm;

		return *this;
	}

	template <typename T>
	Vec3<T> Vec3<T>::GetNormalized() const
	{
		Vec3 res = *this;
		res.Normalize();

		return res;
	}

	template <typename T>
	constexpr bool Vec3<T>::IsNormalized() const noexcept
	{
		return Maths::Equals1(SqrLength());
	}

//}

//{ Project

	template <typename T>
	Vec3<T> Vec3<T>::Reflect(const Vec3& _normal, float _elasticity) const noexcept
	{
		return *this - ProjectOnToNormal(_normal) * (1.0f + _elasticity);
	}

	template <typename T>
	Vec3<T> Vec3<T>::ProjectOnTo(const Vec3& _other) const noexcept
	{
		return Dot(*this, _other) / _other.SqrLength() * _other;
	}

	template <typename T>
	Vec3<T> Vec3<T>::ProjectOnToNormal(const Vec3& _normal) const noexcept
	{
		SA_WARN(_normal.IsNormalized(), SA.Maths.Vec3, L"Normal should be normalized or use ProjectOnTo() instead!");

		return Dot(*this, _normal) * _normal;
	}

//}

//{ Dot/Cross

	template <typename T>
	constexpr T Vec3<T>::Dot(const Vec3<T>& _lhs, const Vec3& _rhs) noexcept
	{
		return _lhs.x * _rhs.x +
			_lhs.y * _rhs.y +
			_lhs.z * _rhs.z;
	}

	template <typename T>
	constexpr Vec3<T> Vec3<T>::Cross(const Vec3<T>& _lhs, const Vec3& _rhs) noexcept
	{
		return Vec3(
			_lhs.y * _rhs.z - _lhs.z * _rhs.y,
			_lhs.z * _rhs.x - _lhs.x * _rhs.z,
			_lhs.x * _rhs.y - _lhs.y * _rhs.x
		);
	}

//}

//{ Angle

	template <typename T>
	Deg<T> Vec3<T>::Angle(const Vec3<T>& _start, const Vec3& _end, const Vec3& _normal) noexcept
	{
		Deg<T> angle = AngleUnsigned(_start, _end);

		Vec3 cross = Cross(_start, _end);

		if (Dot(cross, _normal) < 0.0f)
			angle = -angle;

		return angle;
	}

	template <typename T>
	Deg<T> Vec3<T>::AngleUnsigned(const Vec3<T>& _start, const Vec3& _end) noexcept
	{
		return Maths::ACos(Dot(_start, _end));
	}

//}

//{ Dist/Dir

	template <typename T>
	constexpr T Vec3<T>::Dist(const Vec3& _start, const Vec3& _end)
	{
		return (_start - _end).Length();
	}

	template <typename T>
	constexpr T Vec3<T>::SqrDist(const Vec3& _start, const Vec3& _end) noexcept
	{
		return (_start - _end).SqrLength();
	}

	template <typename T>
	constexpr Vec3<T> Vec3<T>::Dir(const Vec3& _start, const Vec3& _end) noexcept
	{
		return _end - _start;
	}

	template <typename T>
	constexpr Vec3<T> Vec3<T>::DirN(const Vec3& _start, const Vec3& _end)
	{
		return Dir(_start, _end).GetNormalized();
	}

//}

//{ Lerp

	template <typename T>
	Vec3<T> Vec3<T>::Lerp(const Vec3& _start, const Vec3& _end, float _alpha) noexcept
	{
		return Maths::Lerp(_start, _end, _alpha);
	}

	template <typename T>
	Vec3<T> Vec3<T>::LerpUnclamped(const Vec3& _start, const Vec3& _end, float _alpha) noexcept
	{
		return Maths::LerpUnclamped(_start, _end, _alpha);
	}

	template <typename T>
	Vec3<T> Vec3<T>::SLerp(const Vec3& _start, const Vec3& _end, float _alpha) noexcept
	{
		return Maths::SLerp(_start, _end, _alpha);
	}

	template <typename T>
	Vec3<T> Vec3<T>::SLerpUnclamped(const Vec3& _start, const Vec3& _end, float _alpha) noexcept
	{
		return Maths::SLerpUnclamped(_start, _end, _alpha);
	}

//}

//{ Operators

	template <typename T>
	constexpr Vec3<T> Vec3<T>::operator-() const noexcept
	{
		return Vec3(-x, -y, -z);
	}

	template <typename T>
	Vec3<T> Vec3<T>::operator*(T _scale) const noexcept
	{
		return Vec3(
			x * _scale,
			y * _scale,
			z * _scale
		);
	}

	template <typename T>
	Vec3<T> Vec3<T>::operator/(T _scale) const
	{
		SA_ASSERT((NotEquals0, _scale), SA.Maths.Vec3, L"Unscale vector by 0 (division by 0).");

		return Vec3(
			x / _scale,
			y / _scale,
			z / _scale
		);
	}

	template <typename T>
	constexpr  Vec3<T> Vec3<T>::operator+(const Vec3& _rhs) const noexcept
	{
		return Vec3(
			x + _rhs.x,
			y + _rhs.y,
			z + _rhs.z
		);
	}

	template <typename T>
	constexpr  Vec3<T> Vec3<T>::operator-(const Vec3& _rhs) const noexcept
	{
		return Vec3(
			x - _rhs.x,
			y - _rhs.y,
			z - _rhs.z
		);
	}

	template <typename T>
	constexpr  Vec3<T> Vec3<T>::operator*(const Vec3& _rhs) const noexcept
	{
		return Vec3(
			x * _rhs.x,
			y * _rhs.y,
			z * _rhs.z
		);
	}

	template <typename T>
	Vec3<T> Vec3<T>::operator/(const Vec3& _rhs) const
	{
		SA_ASSERT((NotEquals0, _rhs.x), SA.Maths.Vec3, L"Divide X Axis value by 0!");
		SA_ASSERT((NotEquals0, _rhs.y), SA.Maths.Vec3, L"Divide Y Axis value by 0!");
		SA_ASSERT((NotEquals0, _rhs.z), SA.Maths.Vec3, L"Divide Z Axis value by 0!");

		return Vec3(
			x / _rhs.x,
			y / _rhs.y,
			z / _rhs.z
		);
	}

	template <typename T>
	constexpr T Vec3<T>::operator|(const Vec3& _rhs) const noexcept
	{
		return Dot(*this, _rhs);
	}

	template <typename T>
	constexpr Vec3<T> Vec3<T>::operator^(const Vec3& _rhs) const noexcept
	{
		return Cross(*this, _rhs);
	}


	template <typename T>
	Vec3<T>& Vec3<T>::operator*=(T _scale) noexcept
	{
		x *= _scale;
		y *= _scale;
		z *= _scale;

		return *this;
	}

	template <typename T>
	Vec3<T>& Vec3<T>::operator/=(T _scale)
	{
		SA_ASSERT((NotEquals0, _scale), SA.Maths.Vec3, L"Unscale vector by 0 (division by 0).");

		x /= _scale;
		y /= _scale;
		z /= _scale;

		return *this;
	}

	template <typename T>
	Vec3<T>& Vec3<T>::operator+=(const Vec3& _rhs) noexcept
	{
		x += _rhs.x;
		y += _rhs.y;
		z += _rhs.z;

		return *this;
	}

	template <typename T>
	Vec3<T>& Vec3<T>::operator-=(const Vec3& _rhs) noexcept
	{
		x -= _rhs.x;
		y -= _rhs.y;
		z -= _rhs.z;

		return *this;
	}

	template <typename T>
	Vec3<T> Vec3<T>::operator*=(const Vec3& _rhs) noexcept
	{
		x *= _rhs.x;
		y *= _rhs.y;
		z *= _rhs.z;

		return *this;
	}

	template <typename T>
	Vec3<T> Vec3<T>::operator/=(const Vec3& _rhs)
	{
		SA_ASSERT((NotEquals0, _rhs.x), SA.Maths.Vec3, L"Divide X Axis value by 0!");
		SA_ASSERT((NotEquals0, _rhs.y), SA.Maths.Vec3, L"Divide Y Axis value by 0!");
		SA_ASSERT((NotEquals0, _rhs.z), SA.Maths.Vec3, L"Divide Z Axis value by 0!");

		x /= _rhs.x;
		y /= _rhs.y;
		z /= _rhs.z;

		return *this;
	}

//}


	template <typename T>
	constexpr Vec3<T> operator*(typename std::remove_cv<T>::type _lhs, const Vec3<T>& _rhs) noexcept
	{
		return _rhs * _lhs;
	}

	template <typename T>
	Vec3<T> operator/(typename std::remove_cv<T>::type _lhs, const Vec3<T>& _rhs)
	{
		SA_ASSERT((NotEquals0, _rhs.x), SA.Maths.Vec3, L"Divide X Axis value by 0!");
		SA_ASSERT((NotEquals0, _rhs.y), SA.Maths.Vec3, L"Divide Y Axis value by 0!");
		SA_ASSERT((NotEquals0, _rhs.z), SA.Maths.Vec3, L"Divide Z Axis value by 0!");

		return Vec3<T>(_lhs / _rhs.x, _lhs / _rhs.y, _lhs / _rhs.z);
	}


#if SA_LOGGER_IMPL

	template <typename T>
	std::string ToString(const Vec3<T>& _v)
	{
		return "X: " + SA::ToString(_v.x) +
			"\tY: " + SA::ToString(_v.y) +
			"\tZ: " + SA::ToString(_v.z);
	}

#endif
}
