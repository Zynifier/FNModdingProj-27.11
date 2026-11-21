// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "Player/FortPlayerState.h"
#include "EliminatedOverlay.generated.h"

class AFortPlayerStateAthena;
class UAthenaPlayerKillsBase;
class UAthenaWinnersList;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortRichTextBlockLegacy;
class UHorizontalBox;
class UOverlay;
class UTextBlock;
class UVerticalBox;
enum class EDeathCause : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UEliminatedOverlay : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FText DeathCauseToText(EDeathCause DeathCause);

	UFUNCTION(BlueprintCallable)
	AFortPlayerStateAthena* GetPlayerState();

	UFUNCTION(BlueprintImplementableEvent)
	bool IsEliminatedByIntroAnimFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEliminatedByIntro();

	UFUNCTION(BlueprintImplementableEvent)
	void OnResetSpectatingForCreative();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowPlacementBox();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateMultiwinner();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWinnerDetermined();

	UFUNCTION(BlueprintImplementableEvent)
	void SetBannerInfo(const FPlayerBannerInfo& BannerInfo);

	UFUNCTION(BlueprintImplementableEvent)
	void SetPlaceTextFont();

	UFUNCTION(BlueprintCallable)
	void StreamingLoadingChanged(bool bLoading);

	UFUNCTION(BlueprintCallable)
	void UpdateMultiwinner();

	UPROPERTY(BlueprintReadWrite, Category="EliminatedOverlay")
	bool bIsWaitingForTeamEliminationForPlacement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="EliminatedOverlay")
	TArray<FText> WinnerNames;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_PlayerName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_EliminatedBy;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_UserId;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_SpectatorName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_PlacementText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_Winner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_WinnerPoints;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortRichTextBlockLegacy> Text_Winner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_MultiWinner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_Placement;

	UPROPERTY(BlueprintReadOnly, Export, Category="EliminatedOverlay", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlaceNumber;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_PlacePoints;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_MultiWinners;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MultiWinner1;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MultiWinner2;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_LoadingBox;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaWinnersList> AthenaWinnersList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaPlayerKillsBase> Widget_KillCounter;

};

