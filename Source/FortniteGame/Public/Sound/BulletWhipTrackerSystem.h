// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameFramework/Actor.h"
#include "BulletWhipTrackerSystem.generated.h"

class AActor;
class UAudioComponent;
class UBulletWhipTrackerAudioData;
class USceneComponent;
class USoundBase;

USTRUCT()
struct FBulletWhipTrackerSystemData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UBulletWhipTrackerAudioData> WhipTrackerData;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> CachedPassByPawn;

	UPROPERTY(Transient)
	TObjectPtr<AActor> Instigator;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> WhipAudioComponent;

};

UCLASS()
class ABulletWhipTrackerSystem : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TMap<uint16, FBulletWhipTrackerSystemData> SystemDataMap;

};

UCLASS(BlueprintType)
class UBulletWhipTrackerAudioData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerAudioData")
	TObjectPtr<USoundBase> PassBySound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerAudioData")
	float PassByDistanceMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerAudioData")
	float MinimumTriggerDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BulletWhipTrackerAudioData")
	float TriggerAheadTime;

};

