// Copyright 2022 Sapphire development team.All Rights Reserved.

namespace Sa
{
	template <typename T>
	constexpr Deg<T>::Deg(T _deg) noexcept : mHandle{ _deg }
	{
	}
	
	template <typename T>
	template <typename TIn>
	constexpr Deg<T>::Deg(Deg<TIn> _other) noexcept : mHandle{ static_cast<T>(_other.Handle()) }
	{
	}

	template <typename T>
	template <typename TIn>
	constexpr Deg<T>::Deg(Rad<TIn> _rad) noexcept : mHandle{ static_cast<T>(_rad.Handle() * Maths::RadToDeg<T>) }
	{
	}


	template <typename T>
	constexpr T Deg<T>::Handle() const noexcept
	{
		return mHandle;
	}

	template <typename T>
	constexpr bool Deg<T>::Equals(Deg<T> _other, T _epsilon) const noexcept
	{
		return std::abs(mHandle - _other.mHandle) <= _epsilon;
	}

	template <typename T>
	void Deg<T>::Clamp() noexcept
	{
		mHandle = std::fmod(mHandle, static_cast<T>(360));

		if (mHandle < -static_cast<T>(180))
			mHandle += static_cast<T>(360);
		else if(mHandle > static_cast<T>(180))
			mHandle -= static_cast<T>(360);
	}


	template <typename T>
	constexpr Deg<T> Deg<T>::operator-() const noexcept
	{
		return -mHandle;
	}

	template <typename T>
	constexpr Deg<T> Deg<T>::operator+(Deg _rhs) const noexcept
	{
		return mHandle + _rhs.mHandle;
	}

	template <typename T>
	constexpr Deg<T> Deg<T>::operator-(Deg _rhs) const noexcept
	{
		return mHandle - _rhs.mHandle;
	}

	template <typename T>
	constexpr Deg<T> Deg<T>::operator*(T _scale) const noexcept
	{
		return Deg(mHandle * _scale);
	}

	template <typename T>
	Deg<T> Deg<T>::operator/(T _scale) const
	{
		//SA_WARN(!Sa::Equals0(_scale), Maths, L"Unscale Degree by 0 (division by 0).");

		return Deg(mHandle / _scale);
	}


	template <typename T>
	Deg<T>& Deg<T>::operator+=(Deg _rhs) noexcept
	{
		mHandle += _rhs.mHandle;

		return *this;
	}

	template <typename T>
	Deg<T>& Deg<T>::operator-=(Deg _rhs) noexcept
	{
		mHandle -= _rhs.mHandle;

		return *this;
	}

	template <typename T>
	Deg<T>& Deg<T>::operator*=(T _scale) noexcept
	{
		mHandle *= _scale;

		return *this;
	}

	template <typename T>
	Deg<T>& Deg<T>::operator/=(T _scale)
	{
		//SA_WARN(!Sa::Equals0(_scale), Maths, L"Unscale Deg<" << typeid(T).name() << "> by 0 (division by 0).");

		mHandle /= _scale;

		return *this;
	}


	template <typename T>
	constexpr bool Deg<T>::operator==(Deg<T> _rhs) const noexcept
	{
		return Equals(_rhs);
	}

	template <typename T>
	constexpr bool Deg<T>::operator!=(Deg<T> _rhs) const noexcept
	{
		return !Equals(_rhs);
	}


#if SA_LOGGING

	template <typename T>
	std::string Deg<T>::ToString() const noexcept
	{
		return std::to_string(mHandle) + "_deg";
	}

#endif


	constexpr Degf operator""_deg(uint64_t _lit) noexcept
	{
		return Degf(static_cast<float>(_lit));
	}

	constexpr Degd operator""_deg(long double _lit) noexcept
	{
		return Degd(static_cast<double>(_lit));
	}
}
