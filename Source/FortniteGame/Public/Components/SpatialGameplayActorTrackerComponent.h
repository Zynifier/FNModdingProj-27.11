// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "SpatialGameplayActorTrackerComponent.generated.h"

class AActor;

UENUM(BlueprintType)
enum class ESpatialSceneQueryShape : uint8
{
	Sphere = 0,
	Box = 1,
	Capsule = 2,
	VolumeBounds = 3,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class USpatialGameplayActorTrackerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ActorEnteredVolume(AActor* OverlapingVolume, AActor* EnteringActor);

	UFUNCTION(BlueprintPure)
	const int32 GetNumTrackedActors() const;

protected:
	UPROPERTY(EditAnywhere, Category="SceneQuery")
	ESpatialSceneQueryShape SceneQueryShape;

	UPROPERTY(EditAnywhere, Category="SceneQuery")
	TArray<TEnumAsByte<EObjectTypeQuery>> SceneQueryObjectTypes;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SpatialGameplayActorTrackerComponent")
	TSet<TObjectPtr<AActor>> TrackedActors;

private:
	UFUNCTION()
	void ActorExitVolume(AActor* OverlapingVolume, AActor* LeavingActor);

	UFUNCTION()
	void HandleTrackedActorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

};

