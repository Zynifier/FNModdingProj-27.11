// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Misc/Guid.h"
#include "FortAnimNotify_RemoveCosmeticSwap.generated.h"

UCLASS(HideCategories=("Object"), meta=(DisplayName="Disable Existing Swap"))
class UFortAnimNotify_RemoveCosmeticSwap : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotify_RemoveCosmeticSwap")
	TArray<FGuid> SwapIds;

};

