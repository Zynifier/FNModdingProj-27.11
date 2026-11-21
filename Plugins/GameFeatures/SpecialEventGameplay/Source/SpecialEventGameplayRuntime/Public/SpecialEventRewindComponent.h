// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "SpecialEventRewindComponent.generated.h"

class USpecialEventRewindComponent;

UENUM()
enum class ESpecialEventRewindComponentState : uint8
{
	/** Not performing any functionality */
	Stop = 0,
	/** Recording information about the owner over time */
	Record = 1,
	/** Playing back the recorded data in reverse */
	Rewind = 2,
};

USTRUCT()
struct FSpecialEventRewindComponentFrame : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ServerWorldTime;

};

USTRUCT()
struct FSpecialEventRewindComponentRecording
{
	GENERATED_BODY()

protected:
	UPROPERTY(NotReplicated, Export, meta=(EditInline="true"))
	TObjectPtr<USpecialEventRewindComponent> RewindComponent;

	UPROPERTY()
	int32 StartFrameIndex;

private:
	UPROPERTY()
	int32 EndFrameIndex;

};

USTRUCT()
struct FSpecialEventRewindComponentStateData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ESpecialEventRewindComponentState State;

	UPROPERTY()
	uint8 StateChangedCount;

	UPROPERTY()
	float ServerWorldTime;

};

UCLASS(Abstract, BlueprintType, HideCategories=("Activation", "AssetUserData", "Collision", "ComponentTick", "ComponentReplication", "Cooking", "Tags", "Variable"))
class USpecialEventRewindComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool TryStartRewinding(const float Duration = -1.000000f, const float PlaybackSpeed = -1.000000f);

protected:
	UPROPERTY(EditDefaultsOnly, Category="SpecialEventRewindComponent")
	float MaxRecordingDuration;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventRewindComponent")
	float LocalRecordingFPS;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventRewindComponent")
	float ReplicatedRecordingFPS;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventRewindComponent")
	bool bAutoStartRecording;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventRewindComponent")
	float RewindLerpTime;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventRewindComponent")
	float DefaultRewindDuration;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventRewindComponent")
	float DefaultRewindPlaybackSpeed;

private:
	UFUNCTION()
	void OnRep_StateData(const FSpecialEventRewindComponentStateData& OldStateData);

	UPROPERTY(ReplicatedUsing=OnRep_StateData)
	FSpecialEventRewindComponentStateData StateData;

	UPROPERTY(Replicated)
	float ReplicatedRewindDuration;

};

