// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_ORDER_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_ORDER_GUARD

#include <SA/Maths/Transform/Components/TransformPosition.hpp>
#include <SA/Maths/Transform/Components/TransformRotation.hpp>
#include <SA/Maths/Transform/Components/TransformScale.hpp>
#include <SA/Maths/Transform/Components/TransformUScale.hpp>

namespace Sa
{
	namespace Intl
	{
		template <typename FindT, typename FirstT, typename... PArgs>
		constexpr bool ContainsT()
		{
			if constexpr (std::is_same<FindT, FirstT>::value)
				return true;
			else if constexpr (sizeof...(PArgs))
				return ContainsT<FindT, PArgs...>();
			else
				return false;
		}
	}

	template <typename TrT, template <typename> typename FirstOrderT, template <typename> typename... OrderArgs>
	struct TrOrderT
	{
		const TrT& handle;

		using T = typename TrT::Type;


		TrOrderT(const TrT& _handle) noexcept : handle { _handle}
		{
		}


		template <typename... PArgs>
		void MatrixOrderPacked(Mat4<T>& _out)
		{
			if constexpr (Intl::ContainsT<FirstOrderT<T>, PArgs...>())
				handle.template ConstructMatrixComponent<FirstOrderT<T>>(_out);

			if constexpr (sizeof...(OrderArgs))
				TrOrderT<TrT, OrderArgs...>(handle).template MatrixOrderPacked<PArgs...>(_out);
		}

		template <typename CurrT, typename... PArgs>
		void MatrixOthersPacked(Mat4<T>& _out)
		{
			if constexpr (!Intl::ContainsT<CurrT, FirstOrderT<T>, OrderArgs<T>...>())
				handle.template ConstructMatrixComponent<CurrT>(_out);

			if constexpr (sizeof...(PArgs))
				MatrixOthersPacked<PArgs...>(_out);
		}
	};

	template <typename TrT>
	using TrDefaultOrderT = TrOrderT<TrT, TrRotation, TrScale, TrUScale, TrPosition>;
}

#endif // GUARD
