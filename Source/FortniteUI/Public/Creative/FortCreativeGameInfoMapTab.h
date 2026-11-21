// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Athena/AthenaMapScreenContainerTabInterface.h"
#include "FortCreativeGameInfoMapTab.generated.h"

class UAthenaConfirmationWindow;
class UCommonActivatableWidgetSwitcher;
class UCommonButtonBase;
class UCommonButtonGroupBase;
class UFortCreativeCreatorAttributions;
class UFortCreativeMiniGameInfo;
class UFortExpressYourSupportFavoriteButton;
class UFortExpressYourSupportThumbsUpButton;
class UFortIslandDescriptionWidget;
class UTexture2D;
class UWidget;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeGameInfoMapTab : public UCommonActivatableWidget, public IAthenaMapScreenContainerTabInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Fullscreen Map")
	FAthenaMapScreenContainerTabInfo MapTabInfo;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativeMiniGameInfo> MinigameInfo_Header;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_MainContent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortIslandDescriptionWidget> IslandDescription_GameInfoContent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_LikeAndFavoriteContent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_MiscellaneousContent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_CreditsContent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Exit;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortExpressYourSupportFavoriteButton> Button_Favorite;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortExpressYourSupportThumbsUpButton> Button_Like;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Respawn;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ClearSavedData;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GameInfoSubTab;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_LikeAndFavoriteSubTab;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MiscellaneousSubTab;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CreditsSubTab;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup_SubTabs;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeGameInfoMapTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativeCreatorAttributions> CreatorAttributions;

	UPROPERTY(EditDefaultsOnly, Category="ConfirmationWindow")
	TSubclassOf<UAthenaConfirmationWindow> ConfirmationWindowClass;

	UPROPERTY(EditDefaultsOnly, Category="ConfirmationWindow")
	FText RespawnConfirmationTitle;

	UPROPERTY(EditDefaultsOnly, Category="ConfirmationWindow", meta=(Multiline="true"))
	FText RespawnConfirmationDescription;

	UPROPERTY(EditDefaultsOnly, Category="ConfirmationWindow")
	FText RespawnConfirmButtonName;

	UPROPERTY(EditDefaultsOnly, Category="ConfirmationWindow")
	FText ClearSavedDataConfirmationTitle;

	UPROPERTY(EditDefaultsOnly, Category="ConfirmationWindow", meta=(Multiline="true"))
	FText ClearSavedDataConfirmationDescription;

	UPROPERTY(EditDefaultsOnly, Category="ConfirmationWindow")
	FText ClearSavedDataConfirmButtonName;

	UPROPERTY(EditDefaultsOnly, Category="ConfirmationWindow")
	FText ClearSavedDataPostConfirmationText;

	UPROPERTY(EditDefaultsOnly, Category="ConfirmationWindow")
	TSoftObjectPtr<UTexture2D> ClearSavedDataConfirmationIcon;

};

