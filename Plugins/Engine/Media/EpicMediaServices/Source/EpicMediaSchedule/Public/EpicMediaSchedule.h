// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "EpicMediaSchedule.generated.h"

class ULevelSequence;

UENUM(BlueprintType)
enum class EEpicMediaScheduleRepeat : uint8
{
	None = 0 UMETA(DisplayName="Don't repeat"),
	Hourly = 1 UMETA(DisplayName="Hourly"),
	Daily = 2 UMETA(DisplayName="Daily"),
};

USTRUCT(BlueprintType)
struct FEpicMediaScheduleScheduleEntryAbsolute
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	FString IsoStartTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	FString VUID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	int32 DurationSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	TObjectPtr<ULevelSequence> Sequence;

};

USTRUCT(BlueprintType)
struct FEpicMediaScheduleScheduleEntryDaily
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic", meta=(ClampMax="23", ClampMin="0"))
	int32 Hours;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic", meta=(ClampMax="59", ClampMin="0"))
	int32 Minutes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	FString VUID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	int32 DurationSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	TObjectPtr<ULevelSequence> Sequence;

};

USTRUCT(BlueprintType)
struct FEpicMediaScheduleScheduleEntryHourly
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic", meta=(ClampMax="59", ClampMin="0"))
	int32 Minutes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	FString VUID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	int32 DurationSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	TObjectPtr<ULevelSequence> Sequence;

};

USTRUCT(BlueprintType)
struct FEpicMediaScheduleScheduleInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ScheduleInfo")
	FDateTime StartTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ScheduleInfo")
	FTimespan RelativeStartTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ScheduleInfo")
	FString VUID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ScheduleInfo")
	TObjectPtr<ULevelSequence> Sequence;

};

UCLASS(ClassGroup=("Media"), meta=(BlueprintSpawnableComponent))
class EPICMEDIASCHEDULE_API UEpicMediaSchedule : public UActorComponent
{
	GENERATED_BODY()

};

