// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortAFKComponent.h"
#include "FortCreativeAFKComponent.generated.h"

class ABuildingActor;
class AFortPlayerController;
enum class EFortMinigameEnd : uint8;
enum class EFortMinigameState : uint8;

USTRUCT(BlueprintType)
struct FCreativeAFKDetectionParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeAFKDetectionParameters")
	float TimeUntilConfirmedAFK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeAFKDetectionParameters")
	float TimeUntilRemainedAFK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeAFKDetectionParameters")
	float MinimumMovementPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeAFKDetectionParameters")
	float MinimumCameraRotationPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeAFKDetectionParameters")
	float MaxTimeWithoutInteracting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeAFKDetectionParameters")
	float MaxTimeWithoutInputChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeAFKDetectionParameters")
	float SendInputChangeInterval;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortCreativeAFKComponent : public UFortAFKComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void DisableAFKTracking(AFortPlayerController* InstigatorPC, EFortMinigameEnd EndMethod, EFortMinigameState NextState);

	UFUNCTION()
	void EnableAFKTracking();

protected:
	UFUNCTION()
	void OnPlayerInteracted();

	UFUNCTION()
	void OnPlayerSpawnedBuildingActor(AFortPlayerController* Spawner, ABuildingActor* SpawnedBuilding);

	UFUNCTION()
	void OnRep_LastInputChangeTimestamp();

	UFUNCTION(Server, Reliable)
	void ServerRecordInputChange();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LastInputChangeTimestamp)
	float LastInputChangeTimestamp;

};

