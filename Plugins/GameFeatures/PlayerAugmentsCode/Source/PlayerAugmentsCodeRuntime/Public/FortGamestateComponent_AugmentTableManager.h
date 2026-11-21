// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortControllerComponent_DynamicRollPlayerComponent.h"
#include "FortGamestateComponent_DynamicRollTableManager.h"
#include "FortGamestateComponent_AugmentTableManager.generated.h"

USTRUCT(BlueprintType)
struct FFortAugmentBaseWeightTableRow : public FFortDynamicRollBaseWeightTableRow
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortAugmentWeightModificationDataRow : public FFortDynamicRollWeightModifierTableRow
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class PLAYERAUGMENTSCODERUNTIME_API UFortControllerComponent_AugmentDynamicRollPlayerComponent : public UFortControllerComponent_DynamicRollPlayerComponent
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class PLAYERAUGMENTSCODERUNTIME_API UFortGamestateComponent_AugmentTableManager : public UFortGamestateComponent_DynamicRollTableManager
{
	GENERATED_BODY()

};

