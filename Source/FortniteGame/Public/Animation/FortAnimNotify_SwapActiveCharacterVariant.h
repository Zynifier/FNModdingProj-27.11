// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortAnimNotify_SwapActiveCharacterVariant.generated.h"

UCLASS(HideCategories=("Object"), meta=(DisplayName="Swap Active Character Variant"))
class UFortAnimNotify_SwapActiveCharacterVariant : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant")
	FMcpVariantChannelInfo VariantToSwapTo;

};

