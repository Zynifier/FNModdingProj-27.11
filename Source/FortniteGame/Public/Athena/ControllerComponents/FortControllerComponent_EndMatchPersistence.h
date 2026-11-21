// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/FortItemEntry.h"
#include "FortControllerComponent_EndMatchPersistence.generated.h"

class AFortPlayerControllerAthena;
class UFortControllerComponent_EndMatchPersistence;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEndMatchForPlayer, UFortControllerComponent_EndMatchPersistence*, EndMatchPersistence);

UCLASS()
class UFortControllerComponent_EndMatchPersistence : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="End of Match Persistence")
	void AddEndOfMatchLoot(const TArray<FFortItemEntry>& LootList, const bool bAddToExisting = false);

	UFUNCTION(BlueprintPure, Category="End of Match Persistence")
	const TArray<FFortItemEntry>& GetEndOfMatchLoot() const;

	UFUNCTION(BlueprintCallable, Category="End of Match Persistence")
	static UFortControllerComponent_EndMatchPersistence* GetFromPlayerController(AFortPlayerControllerAthena* PC, bool bCreateIfNotFound);

};

