// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingTrapFloor.h"
#include "BuildingTrapFloor_Launch.generated.h"

class AActor;
class UForceFeedbackEffect;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTrapActorClassData)
class ABuildingTrapFloor_Launch : public ABuildingTrapFloor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Launch Trap")
	FVector GetImpulseDirection(AActor* LaunchingActor);

	UPROPERTY(EditDefaultsOnly, Category="Launch Trap", meta=(AssetBundles="ClientCampaign"))
	TSoftObjectPtr<UForceFeedbackEffect> ForceFeedbackClass;

	UPROPERTY(EditDefaultsOnly, Category="Launch Trap")
	FName ForceFeedbackName;

};

