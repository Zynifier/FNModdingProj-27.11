// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ValkyriePaletteProviderInterface.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPaletteLinkCodesChanged, const TArray<FString>&, LinkCodes);

UINTERFACE(MinimalAPI)
class UValkyriePaletteProvider : public UInterface
{
	GENERATED_BODY()
};

class IValkyriePaletteProvider
{
	GENERATED_BODY()

};

