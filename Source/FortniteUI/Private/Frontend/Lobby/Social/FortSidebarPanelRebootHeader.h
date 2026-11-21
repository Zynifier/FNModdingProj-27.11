// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortSidebarPanelRebootHeader.generated.h"

class UCommonButtonBase;
class URebootRallyQuestDataAsset;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarPanelRebootHeader : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortSidebarPanelRebootHeader(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRebootRallyEligibilityUpdated(bool bEligible);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Quests Data")
	TSoftObjectPtr<URebootRallyQuestDataAsset> RebootRallyQuestDataPtr;

private:
	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> RebootButton;

};

