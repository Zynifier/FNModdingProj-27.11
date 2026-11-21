// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_AddMovementModeExtension.generated.h"

class UFortMovementMode_BaseExtLogic;

UCLASS(meta=(DisplayName="Add Movement Mode Extension"))
class FORTNITEGAME_API UFortGameFeatureAction_AddMovementModeExtension : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGameFeatureAction_AddMovementModeExtension", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UFortMovementMode_BaseExtLogic> MovementModeRuntimeRef;

};

