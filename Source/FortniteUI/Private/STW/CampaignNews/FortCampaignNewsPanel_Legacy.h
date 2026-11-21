// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCampaignNewsPanel_Legacy.generated.h"

class UFortCampaignNewsWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignNewsPanel_Legacy : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortCampaignNewsPanel_Legacy")
	void SendMotdInteractionAnalytic(const FString& Interaction) const;

protected:
	UFUNCTION(BlueprintCallable)
	void OnExternalURLOpened();

private:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortCampaignNewsPanel_Legacy", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortCampaignNewsWidget> NewsWidget_Main;

};

