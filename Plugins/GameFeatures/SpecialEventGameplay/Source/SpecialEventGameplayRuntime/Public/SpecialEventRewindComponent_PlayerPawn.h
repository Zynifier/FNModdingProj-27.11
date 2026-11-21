// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "SpecialEventRewindComponent.h"
#include "SpecialEventRewindComponent_PlayerPawn.generated.h"

USTRUCT()
struct FSpecialEventRewindComponentFrame_PlayerPawn : public FSpecialEventRewindComponentFrame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector_NetQuantize Location;

private:
	UPROPERTY()
	uint8 CompressedYaw;

	UPROPERTY()
	uint8 CompressedControlRotationPitch;

};

USTRUCT()
struct FSpecialEventRewindComponentRecordingFastArray_PlayerPawn : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FSpecialEventRewindComponentFrame_PlayerPawn> Frames;

};

USTRUCT()
struct FSpecialEventRewindComponentRecording_PlayerPawn : public FSpecialEventRewindComponentRecording
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Activation", "AssetUserData", "Collision", "ComponentTick", "ComponentReplication", "Cooking", "Tags", "Variable"))
class USpecialEventRewindComponent_PlayerPawn : public USpecialEventRewindComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="SpecialEventRewindComponent_PlayerPawn")
	bool bStartServerRecordingOnLastGroundFrame;

private:
	UFUNCTION()
	void OnServerLanded(const FHitResult& Hit);

	UPROPERTY(Replicated)
	FSpecialEventRewindComponentRecording_PlayerPawn ReplicatedRecording;

	UPROPERTY(Replicated)
	FSpecialEventRewindComponentRecordingFastArray_PlayerPawn ReplicatedRecordingFastArray;

};

