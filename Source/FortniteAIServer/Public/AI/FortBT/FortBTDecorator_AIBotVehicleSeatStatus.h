// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "FortBTDecorator_AIBotVehicleSeatStatus.generated.h"

UENUM()
enum SeatStatusType
{
	Driver = 0 UMETA(DisplayName="Driver"),
	/** Passenger seat is any seat besides the driver WITH or WITHOUT a gun mount */
	Passenger = 1 UMETA(DisplayName="Passenger"),
	/** Gunner seat is a passenger seat WITH a gun mount */
	Gunner = 2 UMETA(DisplayName="Gunner"),
	/** Spotter seat is a passenger seat WITHOUT a gun mount */
	Spotter = 3 UMETA(DisplayName="Spotter"),
};

UCLASS()
class UFortBTDecorator_AIBotVehicleSeatStatus : public UBTDecorator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<SeatStatusType> SeatType;

};

