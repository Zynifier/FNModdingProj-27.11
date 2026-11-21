// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/FortAthenaTutorialBase.h"
#include "FortAthenaTutorial_Look.generated.h"

class AActor;

UCLASS()
class AFortAthenaTutorial_Look : public AFortAthenaTutorialBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Look Tutorial Actors")
	TObjectPtr<AActor> LookMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Look Tutorial Actors")
	TObjectPtr<AActor> StartArrowsActor;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI Visibility Tags")
	FGameplayTagContainer HUDContainerTag;

};

