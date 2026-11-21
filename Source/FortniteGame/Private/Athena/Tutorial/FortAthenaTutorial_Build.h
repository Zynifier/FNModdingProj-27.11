// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "FortAthenaTutorial_Build.generated.h"

class AActor;
class ABlockingVolume;
class ABuildingGameplayActor;
class AFortAthenaTutorialMarker;
class ATriggerBox;
class UFortItemDefinition;

UCLASS()
class AFortAthenaTutorial_Build : public AFortAthenaTutorialBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnPlayerEntersChestTrigger(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Actors")
	TObjectPtr<AActor> Chest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Actors")
	TObjectPtr<AFortAthenaTutorialMarker> ChestObjectiveMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Actors")
	TObjectPtr<AActor> ChestLookMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Actors")
	TObjectPtr<AActor> BuildMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Actors")
	TObjectPtr<AActor> BuildMarker2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Actors")
	TObjectPtr<ATriggerBox> ChestTriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Actors")
	TObjectPtr<AFortAthenaTutorialMarker> ChestDirectionArrows;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Actors")
	TObjectPtr<AActor> SecurityTape_Build;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Actors")
	TObjectPtr<ABlockingVolume> Building_BlockingVolume;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Items")
	TObjectPtr<UFortItemDefinition> StairsBuildingItemDef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Build Tutorial Items")
	TObjectPtr<UFortItemDefinition> WoodItemDef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility Tags")
	FGameplayTagContainer BuildElementTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility Tags")
	FGameplayTagContainer WoodTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility Tags")
	TObjectPtr<ABuildingGameplayActor> SecondStairsNoBuildZone;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Chest Tutorial Enabling Interaction Trigger")
	TObjectPtr<ATriggerBox> TriggerBox;

private:
	UFUNCTION()
	void HandleOnItemCountChanged(UFortItemDefinition* Definition, int32 Delta);

	UFUNCTION()
	void OnBeginOverlapChestTriggerBox(AActor* OverlappedActor, AActor* OtherActor);

};

