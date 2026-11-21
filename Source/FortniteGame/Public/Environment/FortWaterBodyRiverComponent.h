// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WaterBodyRiverComponent.h"
#include "FortWaterBodyRiverComponent.generated.h"

class UFortWaterBodyComponentCommon;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tags", "Activation", "Cooking", "Physics", "Replication", "Input", "AssetUserData", "Mesh", "Mobility", "VirtualTexture", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFortWaterBodyRiverComponent : public UWaterBodyRiverComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Water", meta=(AllowPrivateAccess="true", EditInline="true", ExposeFunctionCategories="Water"))
	TObjectPtr<UFortWaterBodyComponentCommon> FortWaterBodyCommon;

};

