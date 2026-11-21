// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInstance_GalileoFerryAxe.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGalileoFerryAxeDelegate);

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UAnimInstance_GalileoFerryAxe : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AnimInstance_GalileoFerryAxe")
	float TimeBeforeFolding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AnimInstance_GalileoFerryAxe")
	float VFXDisableTimeOffset;

	UPROPERTY(BlueprintReadWrite, Transient, Category="AnimInstance_GalileoFerryAxe")
	bool ShouldFoldBackWeapon;

	UPROPERTY(BlueprintReadWrite, Transient, Category="AnimInstance_GalileoFerryAxe")
	bool bDesiredIdleParticleVisibility;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Delegates")
	FGalileoFerryAxeDelegate FrontEndIdle;

};

