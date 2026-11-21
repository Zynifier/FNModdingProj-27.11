// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortChatPanel.generated.h"

class UFortChatContainer;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortChatPanel : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnWidgetIsOnFocusedPathChanged(bool bOnFocusPath);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnChatRequested();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortChatPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortChatContainer> ChatContainer;

};

