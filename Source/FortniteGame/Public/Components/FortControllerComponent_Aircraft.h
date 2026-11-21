// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_Aircraft.generated.h"

class AController;
class AFortAircraft;
class AFortAthenaAircraft;

UCLASS(Config=Game, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_Aircraft : public UFortControllerComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAircraftStateChange);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSimpleAircraftEvent, AController*, Controller);

public:
	UFUNCTION(BlueprintPure, Category="Aircraft")
	bool IsInAircraft() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Aircraft")
	void KickFromAircraft();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Aircraft")
	void PlacePlayerInAircraft(AFortAircraft* AircraftToEnter, const bool bKeepInventory = false);

	UFUNCTION(Server, Reliable)
	void ServerAttemptAircraftJump(FRotator ClientRotation);

	UPROPERTY(BlueprintAssignable)
	FOnAircraftStateChange OnAircraftStateChange;

protected:
	UFUNCTION(Client, Reliable)
	void ClientEnterAircraft(AFortAircraft* InAircraft);

	UFUNCTION(Client, Reliable)
	void ClientExitAircraft();

	UFUNCTION()
	void OnCurrentAircraftEnterDropZone(AFortAthenaAircraft* InAircraft);

	UPROPERTY()
	TObjectPtr<AFortAircraft> CurrentAircraft;

	UPROPERTY(BlueprintAssignable)
	FSimpleAircraftEvent OnEnterAircraftEvent;

	UPROPERTY(BlueprintAssignable)
	FSimpleAircraftEvent OnExitAircraftEvent;

	UPROPERTY(Config)
	FName TargetGrid;

};

