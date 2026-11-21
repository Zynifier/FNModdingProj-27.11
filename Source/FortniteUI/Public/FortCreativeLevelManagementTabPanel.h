// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "FortCreativeContentBrowserTabPanelBase.h"
#include "FortLevelSaveComponent.h"
#include "FortCreativeLevelManagementTabPanel.generated.h"

class ULevelManagementListView;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeLevelManagementTabPanel : public UFortCreativeContentBrowserTabPanelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClearAllItems();

	UFUNCTION(BlueprintCallable)
	void HandleLevelDeleteClicked(const FLevelInstanceListElement& LevelInstanceListElement);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeLevelManagementTabPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<ULevelManagementListView> LevelManagementListView_Options;

private:
	UFUNCTION()
	void LevelListUpdated();

	UPROPERTY(EditAnywhere, Category="FortCreativeLevelManagementTabPanel")
	FSlateBrush LevelManagementBrush;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeLevelManagementTabPanel")
	bool bIsUsingSidePanel;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeLevelManagementTabPanel", meta=(AllowPrivateAccess="true"))
	FLevelInstanceListElement CurrentLevelEntry;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeLevelManagementTabPanel", meta=(AllowPrivateAccess="true"))
	TArray<FLevelInstanceListElement> LevelEntries;

};

