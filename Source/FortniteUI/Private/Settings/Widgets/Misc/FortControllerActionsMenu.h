// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonPopupMenuLegacy.h"
#include "FortControllerActionsMenu.generated.h"

class UDynamicEntryBox;
class UFortControllerActionsMenuEntry;

UCLASS(Abstract)
class UFortControllerActionsMenu : public UCommonPopupMenuLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Menu")
	TSubclassOf<UFortControllerActionsMenuEntry> MenuEntryClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortControllerActionsMenu", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_BindableActions;

};

