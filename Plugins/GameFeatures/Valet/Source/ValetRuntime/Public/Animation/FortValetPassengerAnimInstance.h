// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Animation/FortVehicleOccupantAnimInstance.h"
#include "FortValetPassengerAnimInstance.generated.h"

class AFortDagwoodVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortValetPassengerAnimInstance : public UFortVehicleOccupantAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortValetPassengerAnimInstance")
	FCachedAnimRelevancyData IntoVehicleCachedData;

	UPROPERTY(EditAnywhere, Category="FortValetPassengerAnimInstance")
	FCachedAnimRelevancyData OutOfVehicleCachedData;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortValetPassengerAnimInstance")
	TSoftObjectPtr<AFortDagwoodVehicle> DagwoodVehicleInstance;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	float TurnYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	float InTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	float OutTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	float NegativeTurnYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	bool bIsReloading;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	bool bIsTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	bool bIsFiring;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	bool bIsUsingConsumable;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	bool bIsInAction;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	bool bIsPassengerBackLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	bool bIsThrowConsumable;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortValetPassengerAnimInstance")
	bool bIsTargetingOrThrowingConsumable;

};

