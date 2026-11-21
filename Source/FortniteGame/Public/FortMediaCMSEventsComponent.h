// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "FortMediaCMSEventsComponent.generated.h"

class UMediaCMSEvent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortMediaCMSEventInvalid, const UMediaCMSEvent*, InvalidEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortMediaCMSEventValid, const UMediaCMSEvent*, ValidEvent);

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FMediaCMSEventData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	FString VUID;

	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	FString Name;

	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	bool bEnableLooping;

	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	TArray<FString> PlatformDenylist;

	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	TArray<FString> GameplayTagDenylist;

	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	TArray<FString> GameplayTagAllowlist;

	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	TArray<FString> RegionAllowlist;

	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	TArray<FString> RegionDenylist;

	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	FString PartnerName;

	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	FDateTime StartTime;

	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	FDateTime EndTime;

	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEventData")
	FString EventIconUrl;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortMediaCMSEventsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const TArray<UMediaCMSEvent*>& GetAllMediaEvents() const;

	UFUNCTION(BlueprintPure)
	const TArray<UMediaCMSEvent*>& GetValidMediaEvents() const;

	UFUNCTION(BlueprintCallable)
	void InitializeEventPage(const FString& InEventPageName);

	UFUNCTION(BlueprintCallable)
	void InitializeEventPageCustomData(const FString& InEventPageName, TSubclassOf<UMediaCMSEvent> InCMSType);

	UPROPERTY(BlueprintAssignable)
	FFortMediaCMSEventValid MediaStartedEvent;

	UPROPERTY(BlueprintAssignable)
	FFortMediaCMSEventInvalid MediaEndedEvent;

private:
	UPROPERTY()
	bool bInitialized;

	UPROPERTY(Transient)
	FString CurrentContinent;

	UPROPERTY(Transient)
	FString CurrentCountry;

	UPROPERTY(Transient)
	TArray<FString> CurrentSubdivisions;

	UPROPERTY(Transient)
	FString EventPageName;

	UPROPERTY(Transient)
	TSubclassOf<UMediaCMSEvent> CMSType;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMediaCMSEvent>> ValidMediaEvents;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMediaCMSEvent>> MediaEvents;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UMediaCMSEvent : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MediaCMSEvent")
	FMediaCMSEventData EventData;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UMediaCMSEventDefault : public UMediaCMSEvent
{
	GENERATED_BODY()

};

