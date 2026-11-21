// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMtxStoreTypes.generated.h"

UENUM(BlueprintType)
enum class EFortMtxStoreOfferType : uint8
{
	FoundersPack = 0,
	CurrencyPack = 1,
	Unknown = 2,
	Max_None = 3 UMETA(DisplayName="None"),
};

