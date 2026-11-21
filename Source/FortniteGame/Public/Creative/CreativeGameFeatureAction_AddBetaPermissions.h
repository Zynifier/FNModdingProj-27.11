// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "Online/FortRuntimeOptions.h"
#include "CreativeGameFeatureAction_AddBetaPermissions.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add Beta Permissions"))
class UFortGameFeatureAction_AddBetaPermissions : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Permissions")
	TArray<FCreativeBetaPermissionConfig> CreativeBetaPermissions;

};

