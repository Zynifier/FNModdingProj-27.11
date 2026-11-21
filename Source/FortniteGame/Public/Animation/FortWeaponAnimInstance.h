// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortBaseAnimInstance.h"
#include "FortWeaponAnimInstance.generated.h"

class UAnimNotify;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortWeaponAnimInstance : public UFortBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AnimNotify_FullyBlendedReducedWork(const UAnimNotify* Notify);

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponAnimInstance")
	bool bWantsReducedWork;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponAnimInstance")
	bool bIsTargeting;

};

