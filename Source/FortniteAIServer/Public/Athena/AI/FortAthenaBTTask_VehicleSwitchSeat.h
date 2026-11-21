// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortAthenaBTTask_VehicleSwitchSeat.generated.h"

UENUM()
enum SwitchSeatType
{
	ToDriver = 0 UMETA(DisplayName="ToDriver"),
	/** Passenger seat is any seat besides the driver WITH or WITHOUT a gun mount */
	ToPassenger = 1 UMETA(DisplayName="ToPassenger"),
	/** Gunner seat is a passenger seat WITH a gun mount */
	ToGunner = 2 UMETA(DisplayName="ToGunner"),
	/** Spotter seat is a passenger seat WITHOUT a gun mount */
	ToSpotter = 3 UMETA(DisplayName="ToSpotter"),
};

UCLASS()
class UFortAthenaBTTask_VehicleSwitchSeat : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<SwitchSeatType> SwitchSeatType;

};

