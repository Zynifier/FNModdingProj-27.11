// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Creative/FortCreativeDeviceProp.h"
#include "FortCreativeTeleporter.generated.h"

class AActor;
class UFortGameplayReceiverMessageComponent;
class UGameplayAbility;

UENUM(BlueprintType)
enum class EFortCreativeTeleporterEvent : uint8
{
	Entered = 0,
	Exited = 1,
	Enabled = 2,
	Disabled = 3,
	None = 4,
};

UENUM(BlueprintType)
enum class EFortCreativeTeleporterGroup : uint8
{
	// Used as array indexes, do not explicitly define.

	Group_A = 0,
	Group_B = 1,
	Group_C = 2,
	Group_D = 3,
	Group_E = 4,
	Group_F = 5,
	Group_G = 6,
	Group_H = 7,
	Group_I = 8,
	Group_J = 9,
	Group_K = 10,
	Group_L = 11,
	Group_M = 12,
	Group_N = 13,
	Group_O = 14,
	Group_P = 15,
	Group_Q = 16,
	Group_R = 17,
	Group_S = 18,
	Group_T = 19,
	Group_U = 20,
	Group_V = 21,
	Group_W = 22,
	Group_X = 23,
	Group_Y = 24,
	Group_Z = 25,
	// Group_None must be the last enum.

	Group_None = 26,
};

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortCreativeTeleporter : public AFortCreativeDeviceProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Teleporter")
	bool IsLocationBlocked(const AActor* ActorToTeleport, FVector LocationToTeleport, const FRotator& InPawnTeleportedRotation) const;

	UFUNCTION(BlueprintPure)
	bool IsPortalDebuggingEnabled() const;

	UFUNCTION(BlueprintPure, Category="Teleporter")
	bool IsTeleporterBlocked(const AActor* ActorToTeleport, const FRotator& InPawnTeleportedRotation) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TSubclassOf<UGameplayAbility> TeleporterAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic", meta=(DisplayName="Teleporter Group"))
	EFortCreativeTeleporterGroup Knob_TeleporterGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic", meta=(DisplayName="Teleporter Target Group"))
	EFortCreativeTeleporterGroup Knob_TargetTeleporterGroup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Export, Category="Teleporter", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayReceiverMessageComponent> TeleportToWhenReceived;

};

