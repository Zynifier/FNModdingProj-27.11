// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "AttachableWheelsComponent.generated.h"

class AAttachableWheel;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UAttachableWheelsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	int32 DetachAllWheels();

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void DrawDebug() const;

	UFUNCTION(BlueprintPure)
	AAttachableWheel* GetAttachedWheelClosestOnAxis(const FVector& Point, float& OutClosetDistanceToAxis, FVector& OutClosestPointOnAxis, FVector& OutClosestAxis) const;

	UFUNCTION(BlueprintPure)
	TArray<AAttachableWheel*> GetAttachedWheels() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnWheelAttached(AAttachableWheel* AttachedWheel);

	UFUNCTION(BlueprintImplementableEvent)
	void OnWheelDetached(AAttachableWheel* AttachedWheel);

protected:
	UFUNCTION()
	bool HandleWheelAttached_Internal(AAttachableWheel* AttachedWheel);

	UFUNCTION()
	bool HandleWheelDetached_Internal(AAttachableWheel* AttachedWheel);

private:
	UPROPERTY()
	TSet<AAttachableWheel*> AttachedWheels;

};

