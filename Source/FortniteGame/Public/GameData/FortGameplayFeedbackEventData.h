// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/AthenaGameMessage.h"
#include "FortGameplayFeedbackEventData.generated.h"

class AActor;

USTRUCT()
struct FGameplayFeedbackEventInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FeedbackEvents")
	FString DisplayText;

	UPROPERTY(EditDefaultsOnly, Category="FeedbackEvents")
	FGameplayTag EventTag;

	UPROPERTY(EditDefaultsOnly, Category="FeedbackEvents")
	EAthenaGameMsgType MsgType;

	UPROPERTY(EditDefaultsOnly, Category="FeedbackEvents")
	bool bTeamBasedEvent;

	UPROPERTY(EditDefaultsOnly, Category="FeedbackEvents", meta=(EditCondition="bTeamBasedEvent"))
	TArray<FText> FriendlyEventMessages;

	UPROPERTY(EditDefaultsOnly, Category="FeedbackEvents", meta=(EditCondition="bTeamBasedEvent"))
	TArray<FText> HostileEventMessages;

	UPROPERTY(EditDefaultsOnly, Category="FeedbackEvents")
	TArray<FText> NeutralEventMessages;

};

USTRUCT(BlueprintType)
struct FGameplayFeedbackEventParams
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="GameplayFeedbackEventParams")
	FGameplayTag EventTag;

	UPROPERTY(BlueprintReadWrite, Transient, Category="GameplayFeedbackEventParams")
	FUniqueNetIdRepl InstigatorPlayerId;

	UPROPERTY(BlueprintReadWrite, Transient, Category="GameplayFeedbackEventParams")
	FVector EventLocation;

};

UCLASS()
class UFortGameplayFeedbackEventData : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FeedbackEvents")
	static void PostFeedbackEventFromGameMessage(AActor* EventSourceActor, const FAthenaGameMessageData& MsgData, const FUniqueNetIdRepl& InstigatorPlayerId, const TMap<FString, FText>& AdditionalArgs);

	UFUNCTION(BlueprintCallable, Category="FeedbackEvents")
	static void PostFeedbackEventMessage(AActor* EventSourceActor, const FGameplayFeedbackEventParams& EventParams, const TMap<FString, FText>& AdditionalArgs);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Feedback Event", meta=(TitleProperty="DisplayText"))
	TArray<FGameplayFeedbackEventInfo> FeedbackEventInfos;

};

