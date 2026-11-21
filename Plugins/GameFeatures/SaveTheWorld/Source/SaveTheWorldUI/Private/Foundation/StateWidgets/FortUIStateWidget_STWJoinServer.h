// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Online/FortOnlineSessionTypes.h"
#include "UIManager/FortUIStateWidgetBase.h"
#include "FortUIStateWidget_STWJoinServer.generated.h"

class UFortRejoinWindowBase;
enum class EMatchmakingCompleteResult : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortUIStateWidget_STWJoinServer : public UFortUIStateWidgetBase
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

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortRejoinWindowBase> RejoinWindow;

	UPROPERTY(EditDefaultsOnly, Category="Stats", meta=(AllowPrivateAccess="TRUE"))
	FDataTableRowHandle TutorialCompleteStatHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortUIStateWidget_STWJoinServer")
	TSubclassOf<UFortRejoinWindowBase> RejoinWindowClass;

};

