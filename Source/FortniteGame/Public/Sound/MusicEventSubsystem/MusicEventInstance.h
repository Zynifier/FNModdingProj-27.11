// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "Sound/MusicEventSubsystem/MusicEventTypes.h"
#include "MusicEventInstance.generated.h"

class AActor;
class UAudioComponent;
class UMusicEventInstance;
class UMusicEventSubsystem;
class UMusicEventSubsystemData;
class USoundBase;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMusicEventInstanceAudibleChanged, UMusicEventInstance*, Instance, bool, bIsAudible);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMusicEventInstancePlaybackCompleted, UMusicEventInstance*, Instance);

UCLASS(BlueprintType)
class UMusicEventInstance : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Runtime Data")
	USoundBase* GetAsset() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	float GetAttenuationEval() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	UAudioComponent* GetComponent() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	float GetDistSqToListener() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	const FMusicEventData& GetEventData() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	bool GetIsAudible() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	bool GetIsInFront() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	bool GetIsPlaying() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	bool GetIsTickable() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	bool GetIsWithinAttenuationThreshold() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	float GetMaxDistance() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	AActor* GetOwner() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	int32 GetPriority() const;

	UFUNCTION(BlueprintPure, Category="Runtime Data")
	float GetVolume() const;

	UFUNCTION()
	void OnComponentOwnerEndPlay(AActor* Owner, EEndPlayReason::Type Reason);

	UPROPERTY(Export)
	TWeakObjectPtr<UAudioComponent> Component;

	UPROPERTY(Transient)
	TObjectPtr<UMusicEventSubsystem> Subsystem;

	UPROPERTY(Transient)
	TObjectPtr<UMusicEventSubsystemData> SubsystemData;

	UPROPERTY(BlueprintAssignable)
	FOnMusicEventInstanceAudibleChanged OnAudibleChanged;

	UPROPERTY()
	FOnMusicEventInstancePlaybackCompleted OnPlaybackCompleted;

private:
	UFUNCTION()
	void OnAudioComponentFinished();

};

