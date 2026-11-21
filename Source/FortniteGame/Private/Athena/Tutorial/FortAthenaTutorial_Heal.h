// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "FortAthenaTutorial_Heal.generated.h"

class AActor;
class UFortItemDefinition;

UCLASS()
class AFortAthenaTutorial_Heal : public AFortAthenaTutorialBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SpawnAmbushLoot();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Heal Tutorial Items")
	TArray<TObjectPtr<UFortItemDefinition>> ItemsToCollect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Heal Tutorial Actors")
	TObjectPtr<AActor> LootPositionMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Heal Tutorial Items")
	TObjectPtr<UFortItemDefinition> MedkitItem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Heal Tutorial Items")
	TObjectPtr<UFortItemDefinition> ShieldPotionItem;

};

