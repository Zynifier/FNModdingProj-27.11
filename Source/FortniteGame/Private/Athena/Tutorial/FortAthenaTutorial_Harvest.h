// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "FortAthenaTutorial_Harvest.generated.h"

class AActor;
class ABuildingProp;
class AFortAthenaTutorialMarker;
class AFortStaticMeshActor;
class ATriggerBox;

UCLASS()
class AFortAthenaTutorial_Harvest : public AFortAthenaTutorialBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Harvest Tutorial Actors")
	TObjectPtr<AFortAthenaTutorialMarker> HarvestMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Harvest Tutorial Actors")
	float DoorTargetAppearDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Harvest Tutorial Actors")
	TObjectPtr<AActor> DoorTargetVisual;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Harvest Tutorial Actors")
	TObjectPtr<ATriggerBox> HarvestTriggerBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Harvest Tutorial Actors")
	TObjectPtr<AFortStaticMeshActor> BlockerHarvest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility Tags")
	FGameplayTagContainer HarvestHUDElementTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Harvest Building")
	TObjectPtr<ABuildingProp> BuildingToDestroy;

private:
	UFUNCTION()
	void OnBeginOverlapHarvestTriggerBox(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnBuildingDestroyed();

};

