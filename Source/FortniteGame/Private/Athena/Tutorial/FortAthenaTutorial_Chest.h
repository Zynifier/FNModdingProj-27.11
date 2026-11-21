// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "FortAthenaTutorial_Chest.generated.h"

class AActor;
class ABuildingContainer;
class ATriggerBox;
class UFortItemDefinition;
class UUserWidget;

UCLASS()
class AFortAthenaTutorial_Chest : public AFortAthenaTutorialBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnPlayerEntersTrigger(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Chest Tutorial Actors")
	TObjectPtr<ABuildingContainer> Chest;

	UPROPERTY(EditAnywhere, Category="Chest Tutorial Items")
	TArray<TObjectPtr<UFortItemDefinition>> ItemsToCollect;

	UPROPERTY(EditAnywhere, Category="Chest Tutorial Items")
	FGameplayTag InteractButtonTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Actors")
	TObjectPtr<AActor> ChestLookMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Chest Tutorial Items")
	TSubclassOf<UUserWidget> InteractButtonHighlightType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Chest Tutorial Enabling Interaction Trigger")
	TObjectPtr<ATriggerBox> TriggerBox;

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaTutorial_Chest")
	float ShowEasyInteractIconDelay;

};

