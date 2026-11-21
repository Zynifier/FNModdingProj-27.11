// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaBattleBusItemDefinition.generated.h"

class ABattleBusCosmeticInstanceBase;
class USoundBase;

UCLASS(BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaBattleBusItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Athena")
	TSoftClassPtr<ABattleBusCosmeticInstanceBase> GetBusPrefabClass() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	USoundBase* GetFlightLoopingMusic() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	USoundBase* GetFlightLoopingSound() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	USoundBase* GetIgnitionSound() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	USoundBase* GetLobbyLoopingMusic() const;

	UFUNCTION(BlueprintPure, Category="Athena")
	USoundBase* GetLobbyLoopingSound() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="ClientAthena"))
	TSoftObjectPtr<USoundBase> IgnitionSound;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="ClientAthena"))
	TSoftObjectPtr<USoundBase> LobbyLoopingMusic;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="ClientAthena"))
	TSoftObjectPtr<USoundBase> LobbyLoopingSound;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> FlightLoopingMusic;

	UPROPERTY(EditDefaultsOnly, Category="Audio", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> FlightLoopingSound;

	UPROPERTY(EditAnywhere, Category="Visual", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<ABattleBusCosmeticInstanceBase> BusPrefabClass;

};

