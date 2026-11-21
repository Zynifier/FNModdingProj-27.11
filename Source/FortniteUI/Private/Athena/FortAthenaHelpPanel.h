// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortAthenaHelpPanel.generated.h"

class UCommonTreeView;
class UScrollBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortAthenaHelpPanel : public UFortActivatablePanel
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaHelpPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTreeView> TreeView_Help;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaHelpPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_HelpEntry;

};

