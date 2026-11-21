// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Misc/DateTime.h"
#include "Misc/Guid.h"
#include "DynamicXp/FortDynamicXpCalculatorData.h"
#include "OnlineLinkId.h"
#include "FortCreativeDynamicXpComponent.generated.h"

class AFortMinigame;
class UFortControllerComponent_EndMatchPersistence;
class UFortCreativeAccoladesComponent;
class UFortDynamicXpCalculator;

UCLASS(MinimalAPI, meta=(BlueprintSpawnableComponent))
class UFortCreativeDynamicXpComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortDynamicXpCalculator> XpCalculator;

	UPROPERTY(Export)
	TMap<FGuid, TWeakObjectPtr<UFortCreativeAccoladesComponent>> AccoladeDevices;

	UPROPERTY(Transient)
	TMap<FUniqueNetIdRepl, FDynamicXpPlayerSession> AllPlayers;

	UPROPERTY()
	FDateTime CalibrationTimestamp;

	UPROPERTY()
	FDateTime AggregatedStatsTimestamp;

	UPROPERTY()
	FDateTime SeasonStartTimestamp;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeDynamicXpComponent")
	FOnlineLinkId LinkId;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeDynamicXpComponent")
	FString LinkType;

private:
	UFUNCTION()
	void OnEndMatchForPlayer(UFortControllerComponent_EndMatchPersistence* EndMatchPersistence);

	UFUNCTION()
	void OnMinigameEnded();

	UFUNCTION()
	void OnMinigameSetup(AFortMinigame* NewMinigame);

	UFUNCTION()
	void OnMinigameStarted();

	UFUNCTION()
	void OnPlayerAddedMinigame(FUniqueNetIdRepl UniqueNetId, bool bIsLocalPlayer);

	UFUNCTION()
	void OnPlayerRemovedMinigame(FUniqueNetIdRepl UniqueNetId, bool bIsLocalPlayer);

};

