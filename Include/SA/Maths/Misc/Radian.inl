// Copyright 2020 Sapphire development team.All Rights Reserved.

namespace Sa
{
	template <typename T>
	constexpr Rad<T>::Rad(T _rad) noexcept : mHandle{ _rad }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Rad<T>::Rad(Rad<TIn> _other) noexcept : mHandle{ static_cast<T>(_other.Handle()) }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Rad<T>::Rad(Deg<TIn> _deg) noexcept : mHandle{ static_cast<T>(_deg.Handle() * Maths::DegToRad) }
	{
	}


	template <typename T>
	constexpr T Rad<T>::Handle() const noexcept
	{
		return mHandle;
	}

	template <typename T>
	constexpr bool Rad<T>::Equals(Rad<T> _other, T _epsilon) const noexcept
	{
		return std::abs(mHandle - _other.mHandle) <= _epsilon;
	}


	template <typename T>
	void Rad<T>::Clamp() noexcept
	{
		mHandle = std::fmod(mHandle, static_cast<T>(Maths::PiX2));

		if (mHandle < -static_cast<T>(Maths::Pi))
			mHandle += static_cast<T>(Maths::PiX2);
		else if (mHandle > static_cast<T>(Maths::Pi))
			mHandle -= static_cast<T>(Maths::PiX2);
	}


	template <typename T>
	constexpr Rad<T> Rad<T>::operator-() const noexcept
	{
		return -mHandle;
	}

	template <typename T>
	constexpr Rad<T> Rad<T>::operator+(Rad _rhs) const noexcept
	{
		return mHandle + _rhs.mHandle;
	}

	template <typename T>
	constexpr Rad<T> Rad<T>::operator-(Rad _rhs) const noexcept
	{
		return mHandle - _rhs.mHandle;
	}

	template <typename T>
	constexpr Rad<T> Rad<T>::operator*(T _scale) const noexcept
	{
		return Rad(mHandle * _scale);
	}

	template <typename T>
	Rad<T> Rad<T>::operator/(T _scale) const
	{
		//SA_WARN(!Sa::Equals0(_scale), Maths, L"Unscale Radian by 0 (division by 0).");

		return Rad(mHandle / _scale);
	}


	template <typename T>
	Rad<T>& Rad<T>::operator+=(Rad _rhs) noexcept
	{
		mHandle += _rhs.mHandle;

		return *this;
	}

	template <typename T>
	Rad<T>& Rad<T>::operator-=(Rad _rhs) noexcept
	{
		mHandle -= _rhs.mHandle;

		return *this;
	}

	template <typename T>
	Rad<T>& Rad<T>::operator*=(T _scale) noexcept
	{
		mHandle *= _scale;

		return *this;
	}

	template <typename T>
	Rad<T>& Rad<T>::operator/=(T _scale)
	{
		//SA_WARN(!Sa::Equals0(_scale), Maths, L"Unscale Rad<" << typeid(T).name() << "> by 0 (division by 0).");

		mHandle /= _scale;

		return *this;
	}


	template <typename T>
	constexpr bool Rad<T>::operator==(Rad<T> _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename T>
	constexpr bool Rad<T>::operator!=(Rad<T> _rhs) const noexcept
	{
		return !Equals(_rhs);
	}


#if SA_LOGGING

	template <typename T>
	std::string Rad<T>::ToString() const noexcept
	{
		return std::to_string(mHandle) + "_rad";
	}

#endif


	constexpr Radf operator""_rad(uint64_t _lit) noexcept
	{
		return Radf(static_cast<float>(_lit));
	}

	constexpr Radd operator""_rad(long double _lit) noexcept
	{
		return Radd(static_cast<double>(_lit));
	}
}
