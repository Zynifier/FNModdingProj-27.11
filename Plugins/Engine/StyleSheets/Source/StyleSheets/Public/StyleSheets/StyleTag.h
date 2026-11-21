// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StyleSheets/StyleSelector.h"
#include "StyleTag.generated.h"

/**
 * Style tag is used for assigning styles to widgets.
 * It is kept as separate type to indicate it only contains
 * style tags and used for assigning style tags to widgets.
 */
USTRUCT()
struct FStyleTag : public FStyleSelectorItem
{
	GENERATED_BODY()

};

