// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortWeaponComponent.h"
#include "FortWeaponComponent_ScopeAnimation.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortWeaponComponent_ScopeAnimation : public UFortWeaponComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Scope")
	FGameplayTag TargetingTag;

	UPROPERTY(EditDefaultsOnly, Category="Scope")
	float SignificantRotation;

	UPROPERTY(EditDefaultsOnly, Category="Scope")
	float SignificantStrafe;

	UPROPERTY(EditDefaultsOnly, Category="Scope")
	float XRotOffsetMax;

	UPROPERTY(EditDefaultsOnly, Category="Scope")
	float YRotOffsetMax;

	UPROPERTY(EditDefaultsOnly, Category="Scope")
	float XStrafeOffsetMax;

	UPROPERTY(EditDefaultsOnly, Category="Scope")
	float InterpSpeed;

protected:
	UFUNCTION(BlueprintCallable, Category="Scope")
	void CalcScopeOffset(const float DeltaSeconds, const float XRecoilOffset, const float YRecoilOffset, const float XADSOffset, const float YADSOffset, UPARAM(ref) float& OutScopeCameraOffsetX, UPARAM(ref) float& OutScopeCameraOffsetY);

	UFUNCTION(BlueprintCallable, Category="Scope")
	void ResetScopeRotation();

	UFUNCTION(BlueprintPure, Category="Scope")
	bool UseNativeCalcScopeOffset() const;

};

