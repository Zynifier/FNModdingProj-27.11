// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DevicesDataTrackingComponent.generated.h"

class UDeviceTrackedData;
class UObject;

UCLASS()
class UDevicesDataTrackingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UDeviceTrackedData* AddNewTracker(UClass* DataTrackedClass);

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UDeviceTrackedData>> DevicesTrackedData;

};

