// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSocialInteractionMenu.h"
#include "FortSidebarSocialInteractionMenu.generated.h"

class UDynamicEntryBox;
class USpacer;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarSocialInteractionMenu : public UFortSocialInteractionMenu
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortSidebarSocialInteractionMenu")
	int32 MaxContractedMenuInteractionsToDisplay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_ExpandedInteractions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USpacer> Spacer_ExpandedMenuSeparator;

};

