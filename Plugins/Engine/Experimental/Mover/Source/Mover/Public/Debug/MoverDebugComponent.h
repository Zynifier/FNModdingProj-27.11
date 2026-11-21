// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveLibrary/MovementUtils.h"
#include "MoverTypes.h"
#include "MoverDebugComponent.generated.h"

/** Component to help display debug information for actors using the Mover Component. Is expected to be attached to the actor that has the mover component.
 *  Currently supports trajectory functionality and trailing functionality. Is also used in the gameplay debugger under the mover category. */
UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class MOVER_API UMoverDebugComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Get a sampling of where the actor is projected to be in the future, based on a current state. Note that this is projecting ideal movement without doing full simulation and collision. */
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Mover")
	TArray<FTrajectorySampleInfo> GetFutureTrajectory(float FutureSeconds, float SamplesPerSecond) const;

	/** Get a read-only sampling of where the actor has recently been, ordered by ascending age. Will be empty unless history tracking is enabled. @see SetHistoryTracking */
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Mover")
	TArray<FTrajectorySampleInfo> GetPastTrajectory() const;

	/** Change history tracking feature settings. Anything <= 0 for SecondsToTrack will disable the feature. */
	UFUNCTION(BlueprintCallable, Category="Mover")
	void SetHistoryTracking(float SecondsToTrack, float SamplesPerSecond);

	/** Number of seconds to lookahead and show the current trajectory */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MoverDebug")
	float LookaheadSeconds;

	/** Number of times trajectory will be sampled each second */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MoverDebug")
	int32 LookaheadSamplesPerSecond;

	/** Whether this component should show the trajectory of the movement component of the Actor it's attached too */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MoverDebug")
	bool bShowTrajectory;

	/** Whether this component should show the trail of the movement component of the Actor it's attached too */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MoverDebug")
	bool bShowTrail;

	/** Whether this component should show the corrections and rollbacks applied to the Actor it's attached too */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MoverDebug")
	bool bShowCorrections;

protected:
	UFUNCTION()
	void OnHistoryTrackingRollback(const FMoverTimeStep& NewTimeStep, const FMoverTimeStep& InvalidatedTimeStep);

	// Begin Motion history tracking
// Max age of tracked samples. Feature is disabled for values <= 0. @see SetHistoryTracking

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float HistoryTrackingSeconds;

	// Target sampling rate for history tracking. Note that sampling rate is variable and may be higher during times of rapid change. @see SetHistoryTracking

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	int32 HistorySamplesPerSecond;

private:
	UFUNCTION()
	void OnMovementSimRollback(const FMoverTimeStep& NewTimeStep, const FMoverTimeStep& InvalidatedTimeStep);

	// Begin Trail simulation

	UFUNCTION()
	void OnMovementSimTick(const FMoverTimeStep& TimeStep);

};

