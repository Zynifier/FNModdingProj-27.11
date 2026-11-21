// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortReplayHighlightsWindow.generated.h"

class AFortReplaySpectator;
class UFortReplayHighlightItemBase;
class UVerticalBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortReplayHighlightsWindow : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortReplayHighlightsWindow")
	TSubclassOf<UFortReplayHighlightItemBase> HighlightItemClass;

private:
	UFUNCTION()
	void HandleHighlightItemPlayEvent(UFortReplayHighlightItemBase* Sender);

	UFUNCTION()
	void HandleReplayHighlightsAvailable(AFortReplaySpectator* Sender, bool bIsAvailable);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_ItemContainer;

};

