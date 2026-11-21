// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FortFallbackCameraFrameTargetProxy.generated.h"

class UFortItem;
class USceneComponent;

UCLASS(MinimalAPI)
class UFortFallbackCameraFrameTargetProxy : public UObject, public IFortUICameraFrameTargetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetItemToRepresent(const UFortItem* ItemToRepresent, const USceneComponent* ComponentToView);

private:
	UPROPERTY()
	FFortOnCameraFrameTargetSettingsChangedDelegate OnSettingsChangedDelegate;

};

