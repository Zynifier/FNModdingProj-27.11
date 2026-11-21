// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chat/SocialChatManager.h"
#include "FortChatManager.generated.h"

class UFortChatRoomJoinHelper;

UCLASS(MinimalAPI)
class UFortChatManager : public USocialChatManager
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortChatRoomJoinHelper> GlobalChatJoinHelper;

	UPROPERTY()
	TObjectPtr<UFortChatRoomJoinHelper> FoundersChatJoinHelper;

	UPROPERTY(Config)
	bool bShouldJoinGlobalChat;

	UPROPERTY(Config)
	bool bShouldRequestGeneralChatRooms;

	UPROPERTY(Config)
	bool bShouldJoinFounderChat;

	UPROPERTY(Config)
	bool bIsAthenaGlobalChatEnabled;

	UPROPERTY(Config)
	int32 RecommendChatFailureDelay;

	UPROPERTY(Config)
	float RecommendChatBackoffMultiplier;

	UPROPERTY(Config)
	float RecommendChatRandomWindow;

	UPROPERTY(Config)
	int32 RecommendChatFailureCountCap;

	UPROPERTY(Config)
	FString ReserveChatURL;

	UPROPERTY(Config)
	FString GlobalChatName;

	UPROPERTY(Config)
	FString FounderChatName;

	UPROPERTY(Config)
	FString ProfileTokenVerifyURL;

};

