// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Replay/FortReplaySpectatorPawnBase.h"
#include "HoverDronePawn.generated.h"

class UHoverDroneMovementComponent;

UENUM()
enum class EDroneFacingLocationMode : uint8
{
	NotFacingLocation = 0,
	FindingPoint = 1,
	TrackingPoint = 2,
};

UCLASS(HideCategories=("Navigation"))
class AHoverDronePawn : public AFortReplaySpectatorPawnBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="HoverDrone")
	float GetAltitude() const;

	UFUNCTION(BlueprintPure, Category="HoverDrone")
	bool IsMaintainingConstantAltitude() const;

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UHoverDroneMovementComponent> HoverMoveComponent;

};

