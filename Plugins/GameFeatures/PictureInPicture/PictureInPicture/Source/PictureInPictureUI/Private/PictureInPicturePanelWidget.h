// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "Layout/Margin.h"
#include "Math/MathFwd.h"
#include "FortMediaEventsSubsystem.h"
#include "PictureInPicturePartnerSource.h"
#include "UIManager/FortFrontendOverlayInterface.h"
#include "PictureInPicturePanelWidget.generated.h"

class UAudioComponent;
class UCommonActionWidget;
class UCommonActivatableWidget;
class UCommonLazyImage;
class UImage;
class UNamedSlot;
class UOverlay;
class UPictureInPicturePartnerControls;
class UPictureInPicturePlayer;
class USizeBox;
class USoundSourceBus;
class USubtitleDisplay;

UCLASS(Abstract)
class UPictureInPicturePanelWidget : public UCommonActivatableWidget, public IFortFrontendOverlayInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleIsPictureInPictureEnabledChanged(bool bIsPiPEnabled);

	UFUNCTION()
	void HandleOnPartnerChanged(UPictureInPicturePartnerControls* NewPartnerControls);

	UFUNCTION()
	void HandleOnPartnerListUpdated();

	UFUNCTION()
	void HandleOnPartnerSourceChanged(const FPiPPartnerSource& InSelectedSource);

	UFUNCTION()
	void HandleToggleFullscreenMap(bool bFullscreenMapVisible);

	UFUNCTION()
	void IntentionalDeactivate();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowDebugInfo(bool bShow);

	UFUNCTION()
	void ToggleFullScreenPiP();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> Video_Size_Box;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePanelWidget")
	FVector2D StandardVideoSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePanelWidget")
	FVector2D StandardVideoTranslation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePanelWidget")
	FMargin FrontEndSubtitleMargin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePanelWidget")
	FMargin GameSubtitleMargin;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Movie;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> Image_Thumbnail_Prev;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> Image_Thumbnail_Next;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UNamedSlot> MetadataOverlaySlot;

	UPROPERTY(BlueprintReadWrite, Export, Category="PictureInPicturePanelWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Main;

	UPROPERTY(BlueprintReadWrite, Export, Category="PictureInPicturePanelWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Keybind;

	UPROPERTY(EditAnywhere, Category="PictureInPicturePanelWidget", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PressedObjectInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePanelWidget")
	TObjectPtr<UPictureInPicturePartnerControls> CurrentPartner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePanelWidget")
	bool bEnableUCPCheck;

private:
	UFUNCTION()
	void AutoEnableController();

	UFUNCTION(BlueprintCallable)
	void DestroyPIPSoundComponent();

	UFUNCTION(BlueprintCallable)
	void FlipPIPAudioSubmix(bool bInDefault, const FFortMediaEventsStreamAssets& InStreamAssets, bool bForce = true);

	UFUNCTION(BlueprintCallable)
	void SetupPIPSoundComponent(const FFortMediaEventsStreamAssets& InStreamAssets);

	UPROPERTY(EditAnywhere, Category="PictureInPicturePanelWidget")
	TSubclassOf<UCommonActivatableWidget> SourcePickerClass;

	UPROPERTY(EditAnywhere, Category="PictureInPicturePanelWidget")
	TObjectPtr<USoundSourceBus> SourceBus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ToggleActionWidget;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> SourcePickerWidget;

	UPROPERTY()
	TObjectPtr<UPictureInPicturePlayer> VideoWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> PIPSoundComponent;

	UPROPERTY(Transient)
	FPiPPartnerSource CurrentSource;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<USubtitleDisplay> Subtitles;

};

