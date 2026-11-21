// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Context/AthenaNewsStructs.h"
#include "FrontEnd/FrontEndTypes.h"
#include "MotdWidgetBase.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortAthenaMOTDWidget.generated.h"

class UCommonButtonBase;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UEpicCMSImage;
class UFortActivatableMovieWidget;
class UFortAthenaMOTDTile;
class UFortDynamicEntryBox;
class UFortGameActivityProvider;
class UFortStoreFrontOfferInfo;
class URichTextBlock;
class UTextBlock;

UINTERFACE(BlueprintType)
class UFortAthenaMOTDNewsChildren : public UInterface
{
	GENERATED_BODY()
};

class IFortAthenaMOTDNewsChildren
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateNews(const FAthenaMOTDBase& NewsEntry);

	UFUNCTION(BlueprintImplementableEvent)
	void SetDefaultImage();

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAthenaMOTDWidget : public UMotdWidgetBase, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void BP_PlayIntroAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsActivityLoadingChanged(bool bIsLoading);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewsPopulated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayIntroAnim();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectedNews(const FAthenaMOTDBase& NewsEntry);

	UFUNCTION(BlueprintImplementableEvent)
	void ResetViewConfiguration();

	UFUNCTION(BlueprintImplementableEvent)
	void SetDefaultImage();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void SetNormalButtonText(const FText& InText);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void SetSecondaryNormalButtonText(const FText& InText);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void SetSecondarySpecialButtonText(const FText& InText);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void SetSpecialButtonText(const FText& InText);

	UFUNCTION(BlueprintImplementableEvent)
	void StartSTWUpsell();

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaMOTDWidget")
	TObjectPtr<UCommonButtonGroupLegacy> MOTDButtonGroup;

private:
	UFUNCTION(BlueprintPure)
	bool AutoPlayedVideo() const;

	UFUNCTION(BlueprintPure)
	FAthenaMOTDBase BP_GetSelectedNews() const;

	UFUNCTION(BlueprintPure)
	FAthenaMOTDBase GetNewsByIndex(int32 Index) const;

	UFUNCTION(BlueprintPure)
	int32 GetNewsCount() const;

	UFUNCTION()
	void HandleImageLoaded();

	UFUNCTION()
	void HandleSelectedButtonChanged(UCommonButtonLegacy* SelectedButton, int32 ButtonIndex);

	UFUNCTION(BlueprintCallable)
	void NavigateToLeftNews();

	UFUNCTION(BlueprintCallable)
	void NavigateToRightNews();

	UFUNCTION(BlueprintCallable)
	bool PlayFirstAutoPlayVideo();

	UFUNCTION(BlueprintCallable)
	void SelectNewsByIndex(int32 Index);

	UPROPERTY(EditAnywhere, Category="FortAthenaMOTDWidget")
	TSubclassOf<UFortAthenaMOTDTile> MOTDTileClass;

	UPROPERTY(EditAnywhere, Category="FortAthenaMOTDWidget")
	TSubclassOf<UFortActivatableMovieWidget> NewVideoPlayerClass;

	UPROPERTY(EditAnywhere, Category="FortAthenaMOTDWidget")
	EFrontEndCamera ActivationFrontendCamera;

	UPROPERTY(EditAnywhere, Category="Primary Content Options")
	FPrimaryContentSetup PrimaryContentSetup;

	UPROPERTY(EditAnywhere, Category="Spatial Frontend Cameras")
	FGameplayTag BattlepassScreenTag;

	UPROPERTY(EditAnywhere, Category="FortAthenaMOTDWidget", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NavigateLeftInputAction;

	UPROPERTY(EditAnywhere, Category="FortAthenaMOTDWidget", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NavigateRightInputAction;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortStoreFrontOfferInfo>> OfferInfoOwnershipArray;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SpecialAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SecondarySpecialAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_NormalAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SecondaryNormalAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_MatchmakingNotice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEpicCMSImage> CMSImage_SelectedNewsImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEpicCMSImage> CMSImage_SelectedNewsImage_Blurred;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichTextBlock_SelectedNewsTitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichTextBlock_SelectedNewsBody;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchClose;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_MOTDEntries;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_MOTDEntries_Mobile;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMOTDWidget")
	TObjectPtr<UFortGameActivityProvider> ActivityProvider;

};

