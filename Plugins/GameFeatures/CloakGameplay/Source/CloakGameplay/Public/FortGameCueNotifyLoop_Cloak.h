// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameCueNotifyLoop_Cloak.generated.h"

class AFortPlayerPawn;

USTRUCT(BlueprintType)
struct FFortGameCueCloakModifier
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameCueCloakModifier")
	FScalableFloat bCanBeEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameCueCloakModifier")
	FScalableFloat VisibilityModifierMultiplicative;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameCueCloakModifier")
	FScalableFloat VisibilityModifierAdditive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameCueCloakModifier")
	FScalableFloat AlphaTimeToEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameCueCloakModifier")
	FScalableFloat AlphaTimeToDisabled;

	UPROPERTY(BlueprintReadOnly, Category="FortGameCueCloakModifier")
	uint8 bCurrentlyEnabled : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortGameCueCloakModifier")
	float CurrentAlpha;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"))
class AFortGameCueNotifyLoop_Cloak : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool GetCurrentModifierValues(float& OutVisibilityMultiplier, float& OutVisibilityAddition, const FName& ModifierName) const;

	UFUNCTION(BlueprintCallable)
	bool SetModifierCanBeEnabled(const FName& ModifierName, const bool bNewCanBeEnabled);

	UFUNCTION(BlueprintCallable)
	bool SetModifierEnabled(const FName& ModifierName, const bool bNewEnabled);

	UFUNCTION(BlueprintCallable)
	float TickVisibilityLevel(const float DeltaSeconds);

	UPROPERTY(BlueprintReadWrite, Category="FortGameCueNotifyLoop_Cloak")
	TObjectPtr<AFortPlayerPawn> TargetPlayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameCueNotifyLoop_Cloak")
	float VisibilityLevel;

	UPROPERTY(BlueprintReadWrite, Category="FortGameCueNotifyLoop_Cloak")
	float StationaryVisMult;

	UPROPERTY(BlueprintReadWrite, Category="FortGameCueNotifyLoop_Cloak")
	float MaxSpeedVisMult;

	UPROPERTY(BlueprintReadWrite, Category="FortGameCueNotifyLoop_Cloak")
	float SpeedForMaxVis;

	UPROPERTY(BlueprintReadWrite, Category="FortGameCueNotifyLoop_Cloak")
	float VisibilityMinFriendly;

	UPROPERTY(BlueprintReadWrite, Category="FortGameCueNotifyLoop_Cloak")
	float VisibilityMinNonfriendly;

	UPROPERTY(BlueprintReadWrite, Category="FortGameCueNotifyLoop_Cloak")
	float VisibilityLevelChangeRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameCueNotifyLoop_Cloak")
	TMap<FName, FFortGameCueCloakModifier> CloakModifiersByNameMap;

};

