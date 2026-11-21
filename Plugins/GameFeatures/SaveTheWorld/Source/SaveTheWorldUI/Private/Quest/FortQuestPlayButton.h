// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortQuestPlayButton.generated.h"

class UFortQuestItem;
enum class EMatchmakingCompleteResult : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestPlayButton : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AttemptToPlayQuest();

	UFUNCTION(BlueprintPure)
	bool CanPlayQuest() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleLobbyDisconnected();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleMatchmakingComplete(EMatchmakingCompleteResult Result);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleMatchmakingStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void HandlePlayerStateChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnContentMissing();

	UPROPERTY(BlueprintReadWrite, Category="FortQuestPlayButton")
	TObjectPtr<UFortQuestItem> QuestItem;

};

