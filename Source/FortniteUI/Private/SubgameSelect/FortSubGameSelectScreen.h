// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortSubGameSelectScreen.generated.h"

class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UFortCampaignPurchaseScreen;
class UFortConsoleProfileWidget;
class UFortLoadingOnDemandContentModal;
class UFortSubgameTile;
class UImage;
class USoundBase;
class UWidgetAnimation;
enum class EMatchmakingCompleteResult : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSubgameSelectScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category="FortSubgameSelectScreen")
	bool bDebugVariable1;

private:
	UFUNCTION()
	void HandleOnMatchmakingComplete(EMatchmakingCompleteResult Result);

	UFUNCTION()
	void HandleOnPartyLeft();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortSubgameTile> SelectedTile;

	UPROPERTY(EditAnywhere, Category="FortSubgameSelectScreen", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<USoundBase> Sound_OnActivated;

	UPROPERTY(EditAnywhere, Category="FortSubgameSelectScreen", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<USoundBase> Sound_OnSelectedSubGame;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSubgameSelectScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> BoundAnim_Intro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSubgameSelectScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> BoundAnim_Outro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSubgameSelectScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> SelectModeIdle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSubgameSelectScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_SpinnerImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortConsoleProfileWidget> XboxOneProfileWidget_ProfileDisplay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSubgameTile> SubgameTile_BattleRoyale;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSubgameTile> SubgameTile_Creative;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSubgameTile> SubgameTile_Campaign;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_PerfModeWarning;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_AccountPicker;

	UPROPERTY(EditDefaultsOnly, Category="FortSubgameSelectScreen")
	TSubclassOf<UFortCampaignPurchaseScreen> CampaignPurchaseScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="FortSubgameSelectScreen")
	TSubclassOf<UFortLoadingOnDemandContentModal> LoadingContentModal;

};

