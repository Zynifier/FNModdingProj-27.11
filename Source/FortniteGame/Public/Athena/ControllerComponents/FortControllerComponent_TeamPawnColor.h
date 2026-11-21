// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_TeamPawnColor.generated.h"

class AFortAthenaMutator_TeamPawnColor;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_TeamPawnColor : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_TeamPawnColor> TeamPawnColorMutator;

private:
	UFUNCTION()
	void HandleServerTeamChange();

};

