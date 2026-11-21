// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FortPastaRipperRifleAnimInstance.generated.h"

class AActor;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPastaRipperRifleAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="WeaponAnimationInstances")
	bool bIsTargeting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="WeaponAnimationInstances")
	TObjectPtr<AActor> OwningActor;

};

