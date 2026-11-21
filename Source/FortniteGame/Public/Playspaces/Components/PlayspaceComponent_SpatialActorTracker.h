// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Building/SpatialGameplay/SpatialActorTrackerContext.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_SpatialActorTracker.generated.h"

class AActor;

UENUM(BlueprintType)
enum class ESceneQueryShape : uint8
{
	Sphere = 0,
	Box = 1,
	Capsule = 2,
	VolumeBounds = 3,
};

USTRUCT(BlueprintType)
struct FActorTrackerInitialScanContext : public FActorTrackerBaseContext
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_SpatialActorTracker : public UFortPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ActorEnteredVolume(AActor* OverlapingVolume, AActor* EnteringActor);

	UFUNCTION(BlueprintPure)
	const int32 GetNumTrackedActors() const;

	UFUNCTION(BlueprintPure)
	const TSet<AActor*>& GetTrackedActors() const;

protected:
	UPROPERTY(EditAnywhere, Category="Usage")
	bool bAlwaysBroadcastPerActorAdded;

	UPROPERTY(EditAnywhere, Category="InitialScan")
	bool bCheckOverlapsOnStartup;

	UPROPERTY(EditAnywhere, Category="InitialScan")
	bool bSceneQueryOnStartup;

	UPROPERTY(EditAnywhere, Category="SceneQuery")
	ESceneQueryShape SceneQueryShape;

	UPROPERTY(EditAnywhere, Category="SceneQuery")
	TArray<TEnumAsByte<EObjectTypeQuery>> SceneQueryObjectTypes;

	UPROPERTY(EditAnywhere, Category="BadPerformanceWillBeDeprecated")
	bool bEnableReScanTimer;

	UPROPERTY(EditAnywhere, Category="BadPerformanceWillBeDeprecated", meta=(EditCondition="bEnableReScanTimer"))
	float ReScanFrequencyInSeconds;

private:
	UFUNCTION()
	void ActorExitVolume(AActor* OverlapingVolume, AActor* LeavingActor);

	UFUNCTION()
	void HandleTrackedActorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UPROPERTY(Transient)
	TSet<AActor*> TrackedActors;

};

