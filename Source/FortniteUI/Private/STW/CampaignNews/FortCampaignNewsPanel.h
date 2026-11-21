// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortCampaignNewsPanel.generated.h"

class UFortCampaignNewsWidget;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignNewsPanel : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortCampaignNewsPanel")
	void SendMotdInteractionAnalytic(const FString& Interaction) const;

protected:
	UFUNCTION(BlueprintCallable)
	void OnExternalURLOpened();

private:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortCampaignNewsPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortCampaignNewsWidget> NewsWidget_Main;

};

