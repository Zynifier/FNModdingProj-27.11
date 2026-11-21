// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortDivisionDetailsScreen.generated.h"

class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortDivisionDetailsInfo;
class UFortDivisionPayoutInfo;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortDivisionDetailsScreen : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void HandleLeftDivisionClicked();

	UFUNCTION(BlueprintCallable)
	void HandleRightDivisionClicked();

	UFUNCTION(BlueprintCallable)
	void SetTournamentAndEventId(const FString& InTournamentId, const FString& InEventId);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortDivisionDetailsScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDivisionDetailsInfo> DetailsInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDivisionDetailsScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDivisionPayoutInfo> PayoutInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDivisionDetailsScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortDivisionDetailsScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> WidgetSwitcher_MainContent;

};

