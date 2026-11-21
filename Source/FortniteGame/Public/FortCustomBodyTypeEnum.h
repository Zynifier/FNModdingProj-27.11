// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCustomBodyTypeEnum.generated.h"

UENUM(BlueprintType)
namespace EFortCustomBodyType
{
	enum Type
	{
		NONE = 0 UMETA(Hidden),
		Small = 1,
		Medium = 2,
		MediumAndSmall = 3,
		Large = 4,
		LargeAndSmall = 5,
		LargeAndMedium = 6,
		All = 7,
		Deprecated = 8,
	};
}

