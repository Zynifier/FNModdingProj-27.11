// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortCharacterVehicle.h"
#include "PlateHawk.generated.h"

enum class EPlateHawkInputEvents : uint8;

UENUM(BlueprintType)
enum class EPlateHawkInputEvents : uint8
{
	PrimaryFire = 0,
	SecondaryFire = 1,
	Sprint = 2,
	Reload = 3,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AI", "AI", "Movement", "AI", "Movement", "Actor", "Movement", "Game|Damage", "Navigation"))
class APlateHawk : public AFortCharacterVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool IsHawkInputBlocked();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHawkInputEvent(EPlateHawkInputEvents InputEvent);

private:
	UFUNCTION(BlueprintCallable)
	void BlockHawkInput(const float Duration);

	UFUNCTION(Server, Reliable)
	void ServerJump();

	UFUNCTION()
	void UseOrExitPressedFromSeat(const int32 SeatIndex);

	UPROPERTY(Transient)
	int32 BlockedCount;

};

