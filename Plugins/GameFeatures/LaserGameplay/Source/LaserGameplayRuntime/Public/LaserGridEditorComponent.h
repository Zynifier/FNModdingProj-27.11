// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LaserGridEditorComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Tags", "Activation", "Cooking", "AssetUserData", "Navigation"))
class ULaserGridEditorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditInstanceOnly, Category="Laser")
	int32 VisualizeLaserGridPatternIndex;

	UPROPERTY(EditInstanceOnly, Category="Laser")
	bool bVisualizeOutletIndex;

};

