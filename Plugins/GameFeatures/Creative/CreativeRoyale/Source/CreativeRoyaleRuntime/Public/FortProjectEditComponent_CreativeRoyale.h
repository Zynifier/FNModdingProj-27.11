// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortProjectEditComponent.h"
#include "FortProjectEditComponent_CreativeRoyale.generated.h"

class APlayerController;
class UFortCreativeRealEstatePlotItemDefinition;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class CREATIVEROYALERUNTIME_API UFortProjectEditComponent_CreativeRoyale : public UFortProjectEditComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void LoadPlotFromProject();

	UFUNCTION()
	void OnPlayerLoggedIn(APlayerController* PlayerController);

	UPROPERTY(EditDefaultsOnly, Category="FortProjectEditComponent_CreativeRoyale")
	TObjectPtr<UFortCreativeRealEstatePlotItemDefinition> CreativeRoyaleEditPlotDefinition;

};

