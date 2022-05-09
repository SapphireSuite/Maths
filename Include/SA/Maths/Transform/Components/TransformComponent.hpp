// Copyright (c) 2022 Sapphire Development Team. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_MATHS_TRANSFORM_COMPONENT_GUARD
#define SAPPHIRE_MATHS_TRANSFORM_COMPONENT_GUARD

namespace Sa
{
	/// Helper macro for transform HasComponent check in templated functions.
	#define TrTHasComponent(_trT) _trT::template HasComponent

	/// Helper macro for transform HasComponent check in templated functions.
	#define TrHasComponent Tr<T, TrArgs...>::template HasComponent
}

#endif // GUARD
