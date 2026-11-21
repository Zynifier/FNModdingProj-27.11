// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortActivityDetailsDisplay.generated.h"

class UCommonButtonBase;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortGameActivity;
class UScrollBox;
class UWidgetAnimation;
enum class EFortInvalidActivityReason : uint8;

UCLASS(Abstract, Config=Game, MinimalAPI, meta=(DisableNativeTick))
class UFortActivityDetailsDisplay : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsActivityEpicCreated() const;

	UFUNCTION(BlueprintPure)
	bool IsActivityEpicOriginal() const;

protected:
	UFUNCTION(BlueprintCallable)
	void AcceptActivity();

	UFUNCTION(BlueprintPure)
	TArray<FString> GetContentWarningStrings() const;

	UFUNCTION(BlueprintNativeEvent)
	FText GetCreatorTextFormat(const FText& CreatorName);

	UFUNCTION(BlueprintPure)
	EFortInvalidActivityReason GetInvalidActivityReason() const;

	UFUNCTION(BlueprintPure)
	const UFortGameActivity* GetSelectedGameActivity() const;

	UFUNCTION(BlueprintPure)
	bool IsDisplayingCategory() const;

	UFUNCTION(BlueprintPure)
	bool IsDownloadRequired() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDescriptionScrollRestarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDetailsUpdated(const bool bIsDetailsValid, const bool bIsFavoritable);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFriendsPlayingChanged(int32 NumPlaying);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsFavoriteChanged(const bool bIsFavorite, const bool bPlayAnimation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalPlayerDemoted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalPlayerPromotedToLeader();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLockStateChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnParentActivated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPartySizeChanged(const int32 PartySize);

	UFUNCTION(BlueprintImplementableEvent)
	void ResetWidgetState();

	UFUNCTION(BlueprintCallable)
	void ToggleFavorite();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCCU(int32 CCUCount);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateLinkCode(const FText& LinkCode, const bool bIsCreativeActivity);

private:
	UFUNCTION()
	void OnOutroAnimationFinished();

	UPROPERTY(Config)
	TArray<FString> XpTagMnemonicWhitelist;

	UPROPERTY(EditAnywhere, Category="FortActivityDetailsDisplay")
	float IntroDelay;

	UPROPERTY(EditAnywhere, Category="FortActivityDetailsDisplay")
	float DetailsScrollStartDelay;

	UPROPERTY(EditAnywhere, Category="FortActivityDetailsDisplay", meta=(ClampMin="0.010000"))
	float DetailsScrollSpeed;

	UPROPERTY(EditAnywhere, Category="FortActivityDetailsDisplay")
	float DetailsScrollEndDelay;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsDisplay", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_ActivityOrigin;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActivityName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActivityDescription;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_ActivityDescription;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsDisplay", meta=(AllowPrivateAccess, BindWidget, EditInline="true", EntryClass="ActivityBrowserTag"))
	TObjectPtr<UDynamicEntryBox> EntryBox_ActivityTags;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortActivityDetailsDisplay", meta=(AllowPrivateAccess, BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> DetailsIntro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortActivityDetailsDisplay", meta=(AllowPrivateAccess, BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> DetailsOutro;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsDisplay", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Accept;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsDisplay", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Details;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsDisplay", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Favorite;

};

