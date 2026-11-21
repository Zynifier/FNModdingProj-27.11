// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaReplayActionFeedScreenBase.generated.h"

class AFortPlayerState;
class UCommonButtonLegacy;
class UCommonListView;
enum class EPlayEventType : int32;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaReplayActionFeedScreenBase : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HandleCloseActionFeed();

private:
	UFUNCTION()
	void HandlePlayerBecameRelevant(AFortPlayerState* FortPlayerState);

	UFUNCTION()
	void OnReplayEventsUpdated(EPlayEventType Type);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_Entries;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Close;

};

