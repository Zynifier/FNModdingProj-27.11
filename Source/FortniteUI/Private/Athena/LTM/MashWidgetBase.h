// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "MashWidgetBase.generated.h"

class AFortAthenaMutator_Mash;
class AFortPlayerStateAthena;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UMashWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerScoreUpdated(const int32 Index, const FString& PlayerName, int32 Score, int32 StreakLevel, int32 MaxStreakLevel, float StreakMultiplier, bool IsLocalPlayer);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSquadScoreUpdated(int32 Score);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamScoreMultiplierChanged(uint8 TeamScoreMultiplier);

protected:
	UFUNCTION()
	void OnPlayerDataChanged();

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaMutator_Mash> MashMutatorRef;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> CachedLocalPlayerState;

};

