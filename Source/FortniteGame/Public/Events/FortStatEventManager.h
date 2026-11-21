// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Stats/Stat.h"
#include "FortStatEventManager.generated.h"

class AFortClientAnnouncement;
class AFortPlayerController;
class UObject;
class UStat;

UENUM()
namespace EFortCompare
{
	enum Type
	{
		EFC_LessThan = 0,
		EFC_LessThanOrEqual = 1,
		EFC_GreaterThan = 2,
		EFC_GreaterThanOrEqual = 3,
		EFC_Equals = 4,
	};
}

UENUM()
namespace EFortEventConditionType
{
	enum Type
	{
		EFEC_StatCompare = 0,
	};
}

UENUM()
namespace EFortEventRepeat
{
	enum Type
	{
		EFER_Inactive = 0,
		EFER_Always = 1,
		EFER_OncePerPlayer = 2,
		EFER_OncePerCampaign = 3,
		EFER_OncePerMap = 4,
	};
}

USTRUCT(BlueprintType)
struct FFortEventConditional
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConditionalType")
	TEnumAsByte<EFortEventConditionType::Type> ConditionalType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatCompare")
	FName StatToCompare;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatCompare")
	EStatRecordingPeriod RelevantPeriod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatCompare")
	TEnumAsByte<EFortCompare::Type> ComparisonType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatCompare")
	int32 Value;

	UPROPERTY(Transient)
	TObjectPtr<UStat> Stat;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> FPC;

};

USTRUCT(BlueprintType)
struct FFortStatEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EventName")
	FName StatEventName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatEvent")
	TEnumAsByte<EFortEventRepeat::Type> RepeatType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatEvent")
	TArray<FName> StatsToMonitor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatEvent")
	TArray<FFortEventConditional> Conditions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatEvent")
	TSubclassOf<AFortClientAnnouncement> AnnouncementToDisplay;

	UPROPERTY(Transient)
	TObjectPtr<UObject> NotificationParameter;

	UPROPERTY(Transient)
	TObjectPtr<UStat> AssociatedStat;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> FPC;

};

USTRUCT(BlueprintType)
struct FFortStatEventSequence
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EventName")
	FName StatEventName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatEvent")
	TEnumAsByte<EFortEventRepeat::Type> RepeatType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatEvent")
	TArray<FFortStatEvent> EventSequence;

	UPROPERTY(Transient)
	TObjectPtr<UStat> AssociatedStat;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> FPC;

protected:
	UPROPERTY()
	TArray<FName> StatsToMonitor;

	UPROPERTY()
	TArray<FFortEventConditional> Conditions;

};

UCLASS(BlueprintType, Blueprintable)
class UFortStatEventManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> FPC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Events")
	TArray<FFortStatEvent> StatEvents;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sequences")
	TArray<FFortStatEventSequence> StatEventSequences;

};

