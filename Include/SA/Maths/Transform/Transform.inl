// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

namespace Sa
{
//{ Equals

	template <typename T, template <typename> typename... Args>
	template <typename CurrT, typename... PArgs>
	bool Tr<T, Args...>::IsZeroPacked() const noexcept
	{
		bool bPack = true;

		if constexpr(sizeof...(PArgs))
			bPack = IsZeroPacked<PArgs...>();

		return bPack && CurrT::IsZero();
	}

	template <typename T, template <typename> typename... Args>
	template <typename CurrT, typename... PArgs>
	bool Tr<T, Args...>::IsIdentityPacked() const noexcept
	{
		bool bPack = true;

		if constexpr(sizeof...(PArgs))
			bPack = IsIdentityPacked<PArgs...>();

		return bPack && CurrT::IsIdentity();
	}

	template <typename T, template <typename> typename... Args>
	template <typename CurrT, typename... PArgs>
	bool Tr<T, Args...>::EqualsPacked(const Tr& _other) const noexcept
	{
		bool bPack = true;

		if constexpr(sizeof...(PArgs))
			bPack = EqualsPacked<PArgs...>();

		return bPack && CurrT::Equals(_other);
	}


	template <typename T, template <typename> typename... Args>
	bool Tr<T, Args...>::IsZero() const noexcept
	{
		return IsZeroPacked<Args<T>...>();
	}

	template <typename T, template <typename> typename... Args>
	bool Tr<T, Args...>::IsIdentity() const noexcept
	{
		return IsIdentityPacked<Args<T>...>();
	}


	template <typename T, template <typename> typename... Args>
	bool Tr<T, Args...>::Equals(const Tr& _other) const noexcept
	{
		return EqualsPacked<Args<T>...>(_other);
	}


	template <typename T, template <typename> typename... Args>
	bool Tr<T, Args...>::operator==(const Tr& _rhs) noexcept
	{
		return Equals(_rhs);
	}

	template <typename T, template <typename> typename... Args>
	bool Tr<T, Args...>::operator!=(const Tr& _rhs) noexcept
	{
		return !(this == _rhs);
	}

//}


//{ Transformation

	template <typename T, template <typename> typename... Args>
	Vec3<T> Tr<T, Args...>::Right() const
	{
		if constexpr (std::is_base_of<TrRotation<T>, Tr<T, Args...>>::value)
			return TrRotation<T>::rotation.RightVector();
		else
			return Vec3<T>::Right;
	}

	template <typename T, template <typename> typename... Args>
	Vec3<T> Tr<T, Args...>::Up() const
	{
		if constexpr (std::is_base_of<TrRotation<T>, Tr<T, Args...>>::value)
			return TrRotation<T>::rotation.UpVector();
		else
			return Vec3<T>::Up;
	}

	template <typename T, template <typename> typename... Args>
	Vec3<T> Tr<T, Args...>::Forward() const
	{
		if constexpr (std::is_base_of<TrRotation<T>, Tr<T, Args...>>::value)
			return TrRotation<T>::rotation.ForwardVector();
		else
			return Vec3<T>::Forward;
	}


	template <typename T, template <typename> typename... Args>
	template <typename ChildT>
	void Tr<T, Args...>::ConstructMatrixComponent(Mat4<T>& _out) const noexcept
	{
		ChildT::ConstructMatrix(_out);
	}

	template <typename T, template <typename> typename... Args>
	Mat4<T> Tr<T, Args...>::Matrix() const noexcept
	{
		return Matrix(TrDefaultOrderT<Tr<T, Args...>>(*this));
	}

	template <typename T, template <typename> typename... Args>
	template <template <typename> typename... TrOrderArgs>
	Mat4<T> Tr<T, Args...>::Matrix(TrOrderT<Tr<T, Args...>, TrOrderArgs...> _order) const noexcept
	{
		Mat4<T> out = Mat4<T>::Identity;

		_order.template MatrixOrderPacked<Args<T>...>(out);
		_order.template MatrixOthersPacked<Args<T>...>(out);

		return out;
	}

//}


//{ Lerp

	template <typename T, template <typename> typename... Args>
	template <typename CurrT, typename... PArgs>
	void Tr<T, Args...>::LerpUnclampedPacked(const Tr& _start, const Tr& _end, float _alpha) noexcept
	{
		((CurrT&)*this) = CurrT::LerpUnclamped(_start, _end, _alpha);

		if constexpr(sizeof...(PArgs))
			LerpUnclampedPacked<PArgs...>(_start, _end, _alpha);
	}


	template <typename T, template <typename> typename... Args>
	Tr<T, Args...> Tr<T, Args...>::Lerp(const Tr& _start, const Tr& _end, float _alpha) noexcept
	{
		SA_WARN(_alpha >= 0.0f && _alpha <= 1.0f, SA/Maths, L"Alpha[" << _alpha << L"] clamped to range [0, 1]! Use LerpUnclamped if intended instead.");


		return LerpUnclamped(_start, _end, _alpha);
	}

	template <typename T, template <typename> typename... Args>
	Tr<T, Args...> Tr<T, Args...>::LerpUnclamped(const Tr& _start, const Tr& _end, float _alpha) noexcept
	{
		Tr res;

		res.LerpUnclampedPacked<Args<T>...>(_start, _end, _alpha);

		return res;
	}

//}


//{ Operators

	template <typename T, template <typename> typename... Args>
	template <typename TrIn, typename CurrT, typename... PArgs>
	void Tr<T, Args...>::MultiplyPacked(const Tr& _lhs, const TrIn& _rhs) noexcept
	{
		((CurrT&)*this) = CurrT::Multiply(_lhs, _rhs);

		if constexpr(sizeof...(PArgs))
			MultiplyPacked<TrIn, PArgs...>(_lhs, _rhs);
	}

	template <typename T, template <typename> typename... Args>
	template <typename TrIn, typename CurrT, typename... PArgs>
	void Tr<T, Args...>::DividePacked(const Tr& _lhs, const TrIn& _rhs) noexcept
	{
		((CurrT&)*this) = CurrT::Divide(_lhs, _rhs);

		if constexpr(sizeof...(PArgs))
			DividePacked<TrIn, PArgs...>(_lhs, _rhs);
	}


	template <typename T, template <typename> typename... Args>
	template <template <typename> typename... InArgs>
	Tr<T, Args...> Tr<T, Args...>::operator*(const Tr<T, InArgs...>& _rhs) const
	{
		Tr res;

		res.MultiplyPacked<Tr<T, InArgs...>, Args<T>...>(*this, _rhs);

		return res;
	}
	
	template <typename T, template <typename> typename... Args>
	template <template <typename> typename... InArgs>
	Tr<T, Args...> Tr<T, Args...>::operator/(const Tr<T, InArgs...>& _rhs) const
	{
		Tr res;

		res.DividePacked<Tr<T, InArgs...>, Args<T>...>(*this, _rhs);

		return res;
	}


	template <typename T, template <typename> typename... Args>
	template <template <typename> typename... InArgs>
	Tr<T, Args...> Tr<T, Args...>::operator*=(const Tr<T, InArgs...>& _rhs) const
	{
		*this = *this * _rhs;
	}

	template <typename T, template <typename> typename... Args>
	template <template <typename> typename... InArgs>
	Tr<T, Args...> Tr<T, Args...>::operator/=(const Tr<T, InArgs...>& _rhs) const
	{
		*this = *this * _rhs;
	}

//}


#if SA_LOGGER_IMPL

	template <typename T, template <typename> typename... Args>
	template <typename CurrT, typename... PArgs>
	std::string Tr<T, Args...>::ToStringPacked() const noexcept
	{
		std::string res = CurrT::ToString();

		if constexpr (sizeof...(PArgs))
		{
			res += "\n\t";
			res += ToStringPacked<PArgs...>();
		}

		return res;
	}

	template <typename T, template <typename> typename... Args>
	std::string Tr<T, Args...>::ToString() const noexcept
	{
		return ToStringPacked<Args<T>...>();
	}


#endif

}
