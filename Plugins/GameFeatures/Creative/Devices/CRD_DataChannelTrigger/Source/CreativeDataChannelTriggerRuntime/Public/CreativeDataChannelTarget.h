// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ElectraDataChannelTarget.h"
#include "CreativeDataChannelTarget.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FCreativeDataChannelEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelEvent")
	FName EventName;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelEvent")
	FName Parameters;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelEvent")
	FName TriggerCondition;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FCreativeDataChannelEvents
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelEvents")
	TArray<FCreativeDataChannelEvent> Events;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventsRep, FCreativeDataChannelEvents, Events);

UCLASS(Config=Creative, BlueprintType, Blueprintable, ClassGroup=("Creative"))
class CREATIVEDATACHANNELTRIGGERRUNTIME_API ACreativeDataChannelTarget : public AElectraDataChannelTarget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void FireEvent(FName EventName);

	UFUNCTION()
	void OnRep_Events();

	UFUNCTION(BlueprintCallable)
	void TestCreativeDataChannelTarget(FCreativeDataChannelEvents TestEvents);

	UPROPERTY()
	int8 VersionByte;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTarget")
	FCreativeDataChannelEvents Events;

	UPROPERTY(BlueprintAssignable)
	FOnEventsRep OnEventsRep;

	UPROPERTY()
	FCreativeDataChannelEvents EventsCache;

};

