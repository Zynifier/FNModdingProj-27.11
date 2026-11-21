// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Frontend/Lobby/Social/FortSocialPanelView_UserLists.h"
#include "Frontend/Lobby/Social/FortSocialSidebarPanelInterface.h"
#include "FortSidebarPanelWithTree.generated.h"

class UFortSocialUserTreeView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarPanelWithTree : public UCommonActivatableWidget, public IFortSocialSidebarPanelInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FFortUserListHeaderInfo> ListHeaderInfos;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortSocialUserTreeView>> OwningTreeViews;

};

