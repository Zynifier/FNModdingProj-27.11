// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSidebarPanelWithTree.h"
#include "FortSidebarPanelPartyUp.generated.h"

class UFortSidebarSpecialNavWidgetBase;
class UFortSocialUserTreeView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarPanelPartyUp : public UFortSidebarPanelWithTree
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSidebarSpecialNavWidgetBase> SpecialNavWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialUserTreeView> UserTree_PartyUp;

};

