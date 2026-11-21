// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/QuartzQuantizationUtilities.h"
#include "FortQuartzSynchronizer.generated.h"

class UAudioComponent;
class UMediaSoundComponent;
class UQuartzClockHandle;
class USoundWave;

UENUM(BlueprintType)
enum class ETimestampEventType : uint8
{
	NamedEvent = 0,
	ChangeBPM = 1,
	Max_None = 2 UMETA(DisplayName="None"),
};

USTRUCT(BlueprintType)
struct FFortTimestampEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortTimestampEvent")
	ETimestampEventType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortTimestampEvent")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortTimestampEvent")
	float PositionSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortTimestampEvent", meta=(EditCondition="Type == ETimestampEventType::ChangeBPM"))
	float BPM;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimestampEvent, FFortTimestampEvent, Event);

USTRUCT()
struct FFortTimestampEventCollection
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortQuartzSynchronizer : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quartz Synchronizer")
	FString CreateJsonFromTimestampEvents();

	UFUNCTION(BlueprintCallable, Category="Quartz Synchronizer")
	bool CreateTimestampEventsFromJson(const FString& JsonString);

	UFUNCTION(BlueprintCallable, Category="Quartz Synchronizer")
	void SetAudioComponent(UAudioComponent* InAudioComponent);

	UFUNCTION(BlueprintCallable, Category="Quartz Synchronizer")
	void SetMediaSoundComponent(UMediaSoundComponent* InMediaSoundComponent);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Quartz Synchronizer")
	FName QuartzClockName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Quartz Synchronizer")
	FQuartzClockSettings ClockSettings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Quartz Synchronizer")
	TArray<FFortTimestampEvent> TimestampEvents;

	UPROPERTY(BlueprintAssignable, Category="Quartz Synchronizer")
	FOnTimestampEvent OnTimestampEvent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Quartz Synchronizer")
	TObjectPtr<UQuartzClockHandle> QuartzClock;

private:
	UFUNCTION()
	void HandleAudioComponentPlaybackPercent(const USoundWave* PlayingSoundWave, const float PlaybackPercent);

	UFUNCTION()
	void HandleAudioComponentPlayStateChanged(EAudioComponentPlayState PlayState);

	UFUNCTION()
	void HandleMediaPlayerClosed();

	UFUNCTION()
	void HandleMediaPlayerOpened(const FString& OpenedURL);

	UFUNCTION()
	void HandleMediaPlayerResumed();

	UFUNCTION()
	void HandleMediaPlayerSuspended();

};

