// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGender.generated.h"

UENUM(BlueprintType)
namespace EFortCustomGender
{
	enum Type
	{
		Invalid = 0,
		// Unknown gender, default value

		Male = 1,
		Female = 2,
		Both = 3,
	};
}

UENUM()
namespace EFortDisplayGender
{
	enum Type
	{
		Unknown = 0,
		Male = 1,
		Female = 2,
		NumTypes = 3 UMETA(Hidden),
	};
}

