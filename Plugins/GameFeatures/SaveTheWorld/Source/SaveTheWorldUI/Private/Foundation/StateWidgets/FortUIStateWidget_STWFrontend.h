// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUITypes.h"
#include "Social/FortSocialPanelContainerInterface.h"
#include "UIManager/FortUIStateWidgetBase.h"
#include "FortUIStateWidget_STWFrontend.generated.h"

class AFortScriptedAction;
class UCommonUserWidget;
class UFortActivatableChatWidget;
class UFortCampaignTabsScreenBase;
class UFortPlayerBanned;
class UTopBar_STW;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortUIStateWidget_STWFrontend : public UFortUIStateWidgetBase, public IFortSocialPanelContainerInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortUIStateWidget_STWFrontend", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UTopBar_STW> TopBar_STW;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUIStateWidget_STWFrontend", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> BottomBar_STW;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUIStateWidget_STWFrontend", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivatableChatWidget> ChatWidget_STW;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortCampaignTabsScreenBase> MainTabsScreen;

	UPROPERTY(EditDefaultsOnly, Category="FortUIStateWidget_STWFrontend")
	TSubclassOf<UFortPlayerBanned> PlayerBannedScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="FortUIStateWidget_STWFrontend")
	TArray<TSubclassOf<AFortScriptedAction>> ScriptedActionsToRegister;

	UPROPERTY(EditDefaultsOnly, Category="FortUIStateWidget_STWFrontend")
	TArray<EFortStoreState> DeferredSquadAutoSlottingStoreStates;

};

