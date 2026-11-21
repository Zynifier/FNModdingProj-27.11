// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tweening/Tween.h"
#include "TweenManager.generated.h"

class UObject;
enum class ETweenLoopType : uint8;
enum class ETweenPlayDirection : uint8;
enum class ETweenResetDestination : uint8;

/**
 * A subsystem for tracking and regularly updating all Tweens
 */
UCLASS(BlueprintType)
class TWEENING_API UTweenManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/**
	 * Indicates whether a Tween with the given ID exists in the Tween Manager.
	 * 
	 * @param InTweenId The ID of the Tween
	 * @return True if the Tween exists in the Tween Manager
	 */
	UFUNCTION(BlueprintPure, Category="Tweening")
	bool HasTween(UPARAM(DisplayName="Tween ID") int32 InTweenId);

	/**
	 * Removes the identified Tween from the Tween Manager.
	 * 
	 * @param InTweenId		The ID of the Tween to kill
	 * @return True if the Tween exists in the Tween Manager
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening")
	bool KillTween(UPARAM(DisplayName="Tween ID") int32 InTweenId);

	/**
	 * Removes the identified Tweens from the Tween Manager.
	 * 
	 * @param InTweenIds		The IDs of the Tweens to kill
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening")
	void KillTweens(UPARAM(DisplayName="Tween IDs") TArray<int32> InTweenIds);

	/**
	 * Starts playing the identified Tween in the specified direction if it exists and is not already playing.
	 * 
	 * @param InTweenId			The ID of the Tween to play
	 * @param InPlayDirection	The direction that the Tween should play in
	 * @return True if the Tween exists in the Tween Manager
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening")
	bool PlayTween(UPARAM(DisplayName="Tween ID") int32 InTweenId, UPARAM(DisplayName="Play Direction") ETweenPlayDirection InPlayDirection = ETweenPlayDirection::Forward);

	/**
	 * Starts playing the identified Tweens in the specified direction if it exists and is not already playing.
	 * 
	 * @param InTweenIds		The IDs of the Tweens to play
	 * @param InPlayDirection	The direction that the Tweens should play in
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening")
	void PlayTweens(UPARAM(DisplayName="Tween IDs") TArray<int32> InTweenIds, UPARAM(DisplayName="Play Direction") ETweenPlayDirection InPlayDirection = ETweenPlayDirection::Forward);

	/**
	 * Starts playing the identified Tween in the specified direction if it exists and is not already playing.
	 * 
	 * @param InTweenId			The ID of the Tween to play
	 * @param InLoopType		The type of loop
	 * @param InLoopCount		The count of loop
	 * @param InPlayDirection	The direction that the Tween should play in
	 * @return True if the Tween exists in the Tween Manager
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening")
	bool PlayTweenWithLooping(UPARAM(DisplayName="Tween ID") int32 InTweenId, UPARAM(DisplayName="Loop Type") ETweenLoopType InLoopType, UPARAM(DisplayName="Loop Count") int32 InLoopCount = -1, UPARAM(DisplayName="Play Direction") ETweenPlayDirection InPlayDirection = ETweenPlayDirection::Forward);

	/**
	 * Stops playing the identified Tween if it is playing and updates the Target to the indicated end of the Tween.
	 
	 * @param InTweenId			The ID of the Tween to reset
	 * @param InDestination		Indicates which end of the Tween to reset to
	 * @return True if the Tween exists in the Tween Manager
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening")
	bool ResetTween(UPARAM(DisplayName="Tween ID") int32 InTweenId, UPARAM(DisplayName="Destination") ETweenResetDestination InDestination = ETweenResetDestination::Beginning);

	/**
	 * Stops playing the identified Tweens if they are playing and updates the Targets to the indicated end of the Tweens.
	 * 
	 * @param InTweenIds		The IDs of the Tweens to reset
	 * @param InDestination		Indicates which end of the Tweens to reset to
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening")
	void ResetTweens(UPARAM(DisplayName="Tween IDs") TArray<int32> InTweenIds, UPARAM(DisplayName="Destination") ETweenResetDestination InDestination = ETweenResetDestination::Beginning);

	/**
	 * Changes the duration and delay options for the identified Tween.
	 * 
	 * @param InTweenId				The ID of the Tween to modify
	 * @param InDuration			The duration of the Tween in seconds
	 * @param InDelayAtBeginning	An optional delay in seconds at the beginning of the Tween
	 * @param InDelayAtEnd			An optional delay in seconds at the end of the Tween
	 * @return True if the Tween exists in the Tween Manager
	 */
	UFUNCTION(BlueprintPure, Category="Tweening")
	bool SetTweenTiming(UPARAM(DisplayName="Tween ID") int32 InTweenId, UPARAM(DisplayName="Duration") float InDuration, UPARAM(DisplayName="Delay At Beginning") float InDelayAtBeginning = 0.000000f, UPARAM(DisplayName="Delay At End") float InDelayAtEnd = 0.000000f) const;

	/**
	 * Stops playing the identified Tween without making any further changes to the Target object.
	 * 
	 * @param InTweenId		The ID of the Tween to stop
	 * @return True if the Tween exists in the Tween Manager
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening")
	bool StopTween(UPARAM(DisplayName="Tween ID") int32 InTweenId);

	/**
	 * Stops playing the identified Tweens without making any further changes to the Target objects.
	 * 
	 * @param InTweenIds	The IDs of the Tweens to stop
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening")
	void StopTweens(UPARAM(DisplayName="Tween IDs") TArray<int32> InTweenIds);

protected:
	// A collection of objects associated with tween instances to provide additional data to the interpolation function.
// These are stored here instead of in the tweens because the Garbage Collector is not aware of the tweens.

	UPROPERTY()
	TMap<int32, TObjectPtr<UObject>> TweenContexts;

};

