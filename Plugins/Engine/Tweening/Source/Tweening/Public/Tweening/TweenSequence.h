// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "UObject/NoExportTypes.h"
#include "Tweening/Tween.h"
#include "TweenSequence.generated.h"

class UTweenManager;
class UTweenSequence;
enum class ETweenPlayDirection : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTweenSequenceEvent, UTweenSequence*, TweenSequence);

USTRUCT()
struct FTweenSequenceEntry
{
	GENERATED_BODY()

public:
	// A reference to the Sequence represented by this entry if bIsSequence is true.

	UPROPERTY()
	TObjectPtr<UTweenSequence> EntrySequence;

};

/**
 * A Tween Sequence can have Tweens added to it and can play those Tweens in order.
 * This is useful for combining a number of Tweens into a larger animation so they do not need to be individually controlled.
 * Just like Tweens, Tween Sequences can be played in either direction and can be looped.
 * Unlike Tweens, a Tween Sequence is a UObject that must be stored in a variable to be kept alive. This allows for
 * convenient access when replaying the animation.
 * Additionally, Tween Sequence allows binding to events such as OnPlay and OnComplete even from Blueprint.
 */
UCLASS(BlueprintType)
class TWEENING_API UTweenSequence : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Adds a Tween Sequence that is nested inside of this Sequence and will be played just like a Tween.
	 * It will be played after the most recently-added Tween/Sequence completes.
	 *
	 * @param SequenceToAppend				The Tween Sequence to add to the outer Sequence.
	 * @param AdditionalDelayAtBeginning	A delay inserted before the inner Sequence plays when playing forward
	 * @param AdditionalDelayAtEnd			A delay inserted before the inner Sequence plays when playing backward
	 * @param OutSequence					The Tween Sequence, allowing further calls to be chained together
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Append Sequence"))
	void BP_AppendSequence(UPARAM(ref) UTweenSequence*& SequenceToAppend, float AdditionalDelayAtBeginning, float AdditionalDelayAtEnd, UPARAM(DisplayName="Outer Sequence") UTweenSequence*& OutSequence);

	/**
	 * Adds a Tween that will be played after the most recently-added Tween completes
	 *
	 * @param TweenId						The ID of the Tween to add
	 * @param AdditionalDelayAtBeginning	A delay inserted before this Tween plays (independent of the Tween's built-in delay) when playing forward
	 * @param AdditionalDelayAtEnd			A delay inserted before this Tween plays (independent of the Tween's built-in delay) when playing backward
	 * @param OutSequence					The Tween Sequence, allowing further calls to be chained together
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Append Tween"))
	void BP_AppendTween(UPARAM(ref) int32& TweenId, float AdditionalDelayAtBeginning, float AdditionalDelayAtEnd, UPARAM(DisplayName="Sequence") UTweenSequence*& OutSequence);

	/**
	 * Adds a Tween Sequence that is nested inside of this Sequence and will be played just like a Tween.
	 * It will be played at the same time as the most recently-added Tween/Sequence.
	 *
	 * @param SequenceToAppend				The Tween Sequence to add to the outer Sequence.
	 * @param AdditionalDelayAtBeginning	A delay inserted before the inner Sequence plays when playing forward
	 * @param AdditionalDelayAtEnd			A delay inserted before the inner Sequence plays when playing backward
	 * @param OutSequence					The Tween Sequence, allowing further calls to be chained together
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Join Sequence"))
	void BP_JoinSequence(UPARAM(ref) UTweenSequence*& SequenceToAppend, float AdditionalDelayAtBeginning, float AdditionalDelayAtEnd, UPARAM(DisplayName="Outer Sequence") UTweenSequence*& OutSequence);

	/**
	 * Adds a Tween that will be played at the same time as the most recently-added Tween.
	 *
	 * @param TweenId						The ID of the Tween to add
	 * @param AdditionalDelayAtBeginning	A delay inserted before the inner Sequence plays when playing forward
	 * @param AdditionalDelayAtEnd			A delay inserted before the inner Sequence plays when playing backward
	 * @param OutSequence					The Tween Sequence, allowing further calls to be chained together
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening", meta=(DisplayName="Join Tween"))
	void BP_JoinTween(UPARAM(ref) int32& TweenId, float AdditionalDelayAtBeginning, float AdditionalDelayAtEnd, UPARAM(DisplayName="Sequence") UTweenSequence*& OutSequence);

	/**
	 * Starts the Tween Sequence in the specified direction or restarts it if it is already playing.
	 * 
	 * @param InPlayDirection	The direction to play the Tween Sequence in
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening")
	void Play(UPARAM(DisplayName="Play Direction") ETweenPlayDirection InPlayDirection = ETweenPlayDirection::Forward);

	/**
	 * Stops the Tween Sequence if it is playing.
	 */
	UFUNCTION(BlueprintCallable, Category="Tweening")
	void Stop();

protected:
	// The list of entries in the order they were added

	UPROPERTY(Transient)
	TArray<FTweenSequenceEntry> SequenceEntries;

	UPROPERTY(Transient)
	TObjectPtr<UTweenManager> TweenManager;

	UPROPERTY(Transient)
	TArray<FTimerHandle> TimerHandles;

};

