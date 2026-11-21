// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "PapayaTimedEvents.generated.h"

class AActor;
class UMediaPlayer;
class UPapayaTimedEventsResponderComponent;

USTRUCT(BlueprintType)
struct FMediaTimeEventItem : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaTimeEventItem")
	FString EventName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaTimeEventItem")
	int64 Time;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MediaTimeEventItem")
	FString Parameter;

};

USTRUCT()
struct FMediaTimeEventArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FMediaTimeEventItem> Items;

};

UCLASS(BlueprintType, Blueprintable)
class APapayaTimedEvents : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddTimedEvent_Native(const FString& EventName, int64 Time, const FString& EventParam);

	UFUNCTION(BlueprintCallable)
	void ResetTimedEvents_Native();

	UFUNCTION(BlueprintCallable)
	void SetupTimedEvents_Native(const FString& ScreenName);

	UFUNCTION(BlueprintCallable)
	void ShutdownTimedEvents_Native();

	UPROPERTY(EditDefaultsOnly, Category="PapayaTimedEvents")
	TMap<FString, TObjectPtr<UMediaPlayer>> MediaPlayerMap;

private:
	UFUNCTION()
	void OnRep_ScreenName(const FString& PreviousValue);

	UFUNCTION()
	void OnRep_TimedEventsArray(const FMediaTimeEventArray& PreviousValue);

	UPROPERTY(VisibleAnywhere, Export, Category="PapayaTimedEvents", meta=(EditInline="true"))
	TObjectPtr<UPapayaTimedEventsResponderComponent> MeshEventResponder;

	UPROPERTY(EditAnywhere, Category="PapayaTimedEvents")
	TArray<TObjectPtr<AActor>> TimedEventActorTargets;

	UPROPERTY(ReplicatedUsing=OnRep_TimedEventsArray)
	FMediaTimeEventArray TimedEventsArray;

	UPROPERTY(ReplicatedUsing=OnRep_ScreenName)
	FString ScreenName;

};

