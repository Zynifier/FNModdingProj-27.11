// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "FortGameStateComponent_KillFeedExtension.generated.h"

class AFortPlayerStateAthena;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_KillFeedExtension : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortGameStateComponent_KillFeedExtension(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintNativeEvent)
	FString CheckForOverrideKillerStyle(const AFortPlayerStateAthena* KillerPlayerStateAthena, const FString& KillerStyle) const;

	UFUNCTION(BlueprintNativeEvent)
	FString CheckForOverrideVictimStyle(const AFortPlayerStateAthena* VictimPlayerStateAthena, const FString& VictimStyle) const;

};

