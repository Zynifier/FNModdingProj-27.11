// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSidebarPanelWithTree.h"
#include "FortSidebarPanelFindFriends.generated.h"

class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UFortFriendSearchButton;
class UFortSocialUserTreeView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarPanelFindFriends : public UFortSidebarPanelWithTree
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialUserTreeView> UserTree_FindFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFriendSearchButton> Button_Search_FindFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_FindFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialUserTreeView> UserTree_FindFriends_SearchResults;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SearchingForUsers;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SearchFailed;

};

