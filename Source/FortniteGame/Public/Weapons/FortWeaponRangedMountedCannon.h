// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Weapons/FortWeaponRangedForVehicle.h"
#include "FortWeaponRangedMountedCannon.generated.h"

class AFortPlayerPawn;
class USkeletalMeshComponent;

UENUM(BlueprintType)
enum class MountedCannonLaunchPlayerMode : uint8
{
	Off = 0 UMETA(DisplayName="Do Not Launch Player"),
	PrimaryFire = 1 UMETA(DisplayName="Primary Fire Launches Player"),
	SecondaryFire = 2 UMETA(DisplayName="Secondary Fire Launches Player"),
	PrimaryWhileTargeting = 3 UMETA(DisplayName="Hold Secondary + Press Primary Fire Launches Player"),
};

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeaponRangedMountedCannon : public AFortWeaponRangedForVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	USkeletalMeshComponent* GetVehicleSkeletalMesh() const;

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerFireActorInCannon(const FVector LaunchDir);

	UPROPERTY(EditDefaultsOnly, Category="MountedCannon")
	int32 FirePlayerInSeat;

	UPROPERTY(EditDefaultsOnly, Category="MountedCannon")
	bool bUseLegacyLaunchLogic;

	UPROPERTY(EditDefaultsOnly, Category="MountedCannon")
	MountedCannonLaunchPlayerMode LaunchMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="MountedCannon")
	bool bCanFireNormalProjectile;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="MountedCannon")
	void OnLaunchPawn(AFortPlayerPawn* Pawn, const FVector LaunchDir);

	UFUNCTION(BlueprintImplementableEvent, Category="MountedCannon")
	void OnPreLaunchPawn(AFortPlayerPawn* Pawn, const FVector LaunchDir);

};

