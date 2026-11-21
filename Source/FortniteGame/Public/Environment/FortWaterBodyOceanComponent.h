// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WaterBodyOceanComponent.h"
#include "FortWaterBodyOceanComponent.generated.h"

class UFortWaterBodyComponentCommon;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tags", "Activation", "Cooking", "Physics", "Replication", "Input", "AssetUserData", "Mesh", "Mobility", "VirtualTexture", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFortWaterBodyOceanComponent : public UWaterBodyOceanComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Water", meta=(AllowPrivateAccess="true", EditInline="true", ExposeFunctionCategories="Water"))
	TObjectPtr<UFortWaterBodyComponentCommon> FortWaterBodyCommon;

};

