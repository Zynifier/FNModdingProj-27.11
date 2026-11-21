// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "FortSkyTubeAnchor.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortSkyTubeAnchor : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="SkyTube")
	bool IsEnabled() const;

	UFUNCTION(BlueprintPure, Category="SkyTube")
	bool IsExemptFromShutdown() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnEnabledChanged();

protected:
	UPROPERTY()
	bool bEnabled;

	UPROPERTY(EditAnywhere, Category="SkyTube")
	bool bExemptFromShutdown;

};

