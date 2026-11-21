// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyLoop_ZiplineTravel.generated.h"

class AFortPlayerPawn;
class UFortLayeredAudioComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"), meta=(DisplayName="GCNL Zipline Travel", ShowWorldContextPin))
class AFortGameplayCueNotifyLoop_ZiplineTravel : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortGameplayCueNotifyLoop_ZiplineTravel", meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> LayeredAudioComp;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortGameplayCueNotifyLoop_ZiplineTravel")
	FGameplayCueParameters CachedGCParameters;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortGameplayCueNotifyLoop_ZiplineTravel")
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

};

