// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "FortPhysicsAnalytics.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortPlayerController;

UENUM(BlueprintType)
enum EDamageCauserType
{
	Undefined = 0,
	// non-categorized

	Pickaxe = 1,
	// chopped down by pickaxe

	RangedWeapon = 2,
	// ranged weapon damage

	Fire = 3,
	// fire

	Vehicle = 4,
	// driven through by a vehicle

	Vehicle_Empty = 5,
	// driven through by a vehicle (driver exists prior to collision)

	IndirectCauser = 6,
	// e.g. physics tree chain reaction, Fortanium, etc.

	Inactivation = 7,
	// physics snowball will be killed when inactivated

	EnteringWater = 8,
	// plugin contents

	ShockwaveMace = 9,
	Katana = 10,
	ForcePower = 11,
	ODMGear = 12,
};

UCLASS(Abstract, MinimalAPI)
class UFortPhysicsAnalytics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fort Physics Analytics")
	static EDamageCauserType CategorizeByDamageCauser(AActor* DamageCauser, const FGameplayTagContainer& DamageTags);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Analytics")
	static void FireTelemetryEvent_OnPhysicsFellableDestroyed(AFortPlayerController* FortPC, AActor* FellableActor, AActor* DamageCauser, const FGameplayTagContainer& DamageTags, const bool bFallTowardsEnemy);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Analytics")
	static void FireTelemetryEvent_OnPhysicsRidingActorLifeEnd(ABuildingActor* PhysicsActor, const int32 NumberOfCachedPlayers, TArray<FVector> OnBoardLocations, TArray<FVector> OffBoardLocations, TArray<float> SessionLengths);

	UFUNCTION(BlueprintCallable, Category="Fort Physics Analytics")
	static void FireTelemetryEvent_OnPhysicsSnowballDestroyed(ABuildingActor* SnowballActor, AController* Killer, const EDamageCauserType DamageCauserType = Undefined);

};

