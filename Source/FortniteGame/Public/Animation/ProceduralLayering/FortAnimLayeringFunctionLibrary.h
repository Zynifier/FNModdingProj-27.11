// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BoneMaskTypes.h"
#include "FortAnimLayeringFunctionLibrary.generated.h"

class UAnimInstance;
class UBlendProfile;
class UFortAnimationLayeringWeightsDataAsset;

UCLASS()
class UFortAnimLayeringFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Blend Profile", meta=(BlueprintThreadSafe))
	static UBlendProfile* GetBlendProfile(UAnimInstance* AnimInstance, const FName BlendProfileName);

	UFUNCTION(BlueprintCallable, Category="Bone Mask", meta=(BlueprintThreadSafe))
	static void MakeBoneMaskFromAnimLayeringDataAsset(const UAnimInstance* AnimInstance, const UFortAnimationLayeringWeightsDataAsset* DataAsset, FBoneMask& OutBoneMask);

};

