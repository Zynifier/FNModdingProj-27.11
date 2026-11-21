// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "FortAthenaTutorial_Pickup.generated.h"

class AFortAthenaTutorialMarker;
class AFortStaticMeshActor;

UCLASS()
class AFortAthenaTutorial_Pickup : public AFortAthenaTutorialBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pickup Tutorial Actors")
	TObjectPtr<AFortAthenaTutorialMarker> GunsMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pickup Tutorial Actors")
	TObjectPtr<AFortStaticMeshActor> BlockerCollect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickUp Tutorial Tags")
	FGameplayTag GunToPickUpTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickUp Tutorial Tags")
	FGameplayTag QuickbarTag;

};

