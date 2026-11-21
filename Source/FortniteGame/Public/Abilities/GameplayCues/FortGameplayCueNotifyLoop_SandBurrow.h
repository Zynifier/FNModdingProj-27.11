// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyLoop_SandBurrow.generated.h"

class AFortPlayerPawn;
class UFXSystemComponent;
class UFortLayeredAudioComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"), meta=(DisplayName="GCNL Sand Burrow", ShowWorldContextPin))
class AFortGameplayCueNotifyLoop_SandBurrow : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortGameplayCueNotifyLoop_SandBurrow", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> LayeredAudioComp;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortGameplayCueNotifyLoop_SandBurrow")
	FGameplayCueParameters CachedGCParameters;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortGameplayCueNotifyLoop_SandBurrow", meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> FXSpeedLinesComp;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortGameplayCueNotifyLoop_SandBurrow")
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameplayCueNotifyLoop_SandBurrow")
	float CurrentSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameplayCueNotifyLoop_SandBurrow")
	bool bShouldShowTrailFX;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameplayCueNotifyLoop_SandBurrow")
	bool bShouldShowSpeedLines;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameplayCueNotifyLoop_SandBurrow")
	FScalableFloat MinimumSpeedToDamageBuildings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameplayCueNotifyLoop_SandBurrow")
	FScalableFloat MinimumSpeedToShowTrailFX;

};

