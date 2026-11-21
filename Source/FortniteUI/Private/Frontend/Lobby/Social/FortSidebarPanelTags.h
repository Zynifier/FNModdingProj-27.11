// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FrontEnd/IFortDebounceInterface.h"
#include "Frontend/Lobby/Social/FortSidebarPanelWithTree.h"
#include "FortSidebarPanelTags.generated.h"

class UFortSidebarLfgState2Widget;
class UFortSocialUserTreeView;

UCLASS(Config=Game, meta=(DisableNativeTick))
class UFortSidebarPanelTags : public UFortSidebarPanelWithTree, public IFortDebounceInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialUserTreeView> UserTree_Friends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSidebarLfgState2Widget> LfgStateWidget;

	UPROPERTY(Config)
	float QueryLfgTimeSeconds;

	UPROPERTY(Config)
	float DebounceLfgTimeSeconds;

	UPROPERTY(Config)
	float RateLimitTickSeconds;

	UPROPERTY(Config)
	bool bLfgExactMatch;

	UPROPERTY(Config)
	int32 MaxNumberOfPlayersToShow;

};

