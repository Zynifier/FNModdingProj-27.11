// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RockVehicleAnalytics.generated.h"

class AFortPawn;
class AFortPlayerController;
class ARockVehicle;
class IFortVehicleInterface;
class UActorComponent;

USTRUCT()
struct FRockVehicleAnalyticsSession
{
	GENERATED_BODY()

public:
	UPROPERTY()
	AFortPlayerController* DriverPC;

};

UCLASS()
class URockVehicleAnalyticsComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnDodged(UActorComponent* InComp, bool bInReset);

	UFUNCTION()
	void OnDoubleJumped(UActorComponent* InComp, bool bInReset);

	UFUNCTION()
	void OnJumped(UActorComponent* InComp, bool bInReset);

	UFUNCTION()
	void OnPawnEnteredSeat(const TScriptInterface<IFortVehicleInterface>& InVehicle, AFortPawn* InPlayerPawn, int32 InSeatIndex);

	UFUNCTION()
	void OnPawnExitedSeat(const TScriptInterface<IFortVehicleInterface>& InVehicle, AFortPawn* InPlayerPawn, int32 InSeatIndex);

	UFUNCTION()
	void OnSupersonicEnd(UActorComponent* InComp);

	UFUNCTION()
	void OnSupersonicStart(UActorComponent* InComp, bool bInReset);

	UPROPERTY(Transient)
	FRockVehicleAnalyticsSession CurrentSession;

	UPROPERTY(Transient)
	ARockVehicle* Vehicle;

};

