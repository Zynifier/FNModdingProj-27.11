// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Online/FortOnlineSessionTypes.h"
#include "UIManager/FortUIStateWidget_NUI.h"
#include "FortUIStateWidget_JoinServer.generated.h"

class UCommonWidgetStackLegacy;
class UFortRejoinWindowBase;
enum class EMatchmakingCompleteResult : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UFortUIStateWidget_JoinServer : public UFortUIStateWidget_NUI
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowTutorialDialog();

private:
	UFUNCTION()
	void HandleLobbyDisconnected();

	UFUNCTION()
	void HandleLobbyTimeUpdated(int32 TimeRemaining);

	UFUNCTION()
	void HandleMatchmakingComplete(EMatchmakingCompleteResult MatchmakingResult);

	UFUNCTION()
	void HandleMatchmakingStateChange(EMatchmakingState::Type OldState, EMatchmakingState::Type NewState);

	UPROPERTY(Export, meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetStackLegacy> Stack_MainContent;

	UPROPERTY(EditDefaultsOnly, Category="Stats", meta=(AllowPrivateAccess="TRUE"))
	FDataTableRowHandle TutorialCompleteStatHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortUIStateWidget_JoinServer")
	TSubclassOf<UFortRejoinWindowBase> RejoinWindowClass;

};

