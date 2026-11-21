// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SpatialCustomizationSubscreenBase.generated.h"

class UAthenaSpatialCustomizationRoomData;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaSpatialCustomizationSubscreenBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UAthenaSpatialCustomizationRoomData> CustomizationRoomData;

};

