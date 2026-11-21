// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortQuestMapEventCallout_Legacy.generated.h"

class UAudioComponent;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortBangWrapper_NUI;
class UFortProgressArrowButton_Legacy;
class UFortQuestItemDefinition;
class UFortQuestMapData;
class UFortQuestMapEventSequence;
class UFortQuestMapNewBangWrapper_Legacy;
class UHorizontalBox;
class UImage;
class USoundBase;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestMapEventCallout_Legacy : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Event Callout")
	void DeactivateCallout();

	UFUNCTION(BlueprintPure, Category="Event Callout")
	int32 GetEventCount() const;

	UFUNCTION(BlueprintPure, Category="Event Callout")
	bool GetIsExpanded() const;

	UFUNCTION(BlueprintPure, Category="Event Callout")
	bool GetIsFaded() const;

	UFUNCTION(BlueprintPure, Category="Event Callout")
	UFortQuestItemDefinition* GetRequiredQuestForCurrentEvent() const;

	UFUNCTION(BlueprintPure, Category="Event Callout")
	bool IsCurrentEventUnlocked() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnActivatePlayAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDeactivatePlayAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEventIndexChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayFadeAnimation(bool bIsFadeOut);

	UFUNCTION(BlueprintImplementableEvent)
	void OnResetCallout();

	UFUNCTION(BlueprintCallable, Category="Event Callout")
	void PlayFadeIn();

	UFUNCTION(BlueprintCallable, Category="Event Callout")
	void PlayFadeOut();

	UFUNCTION(BlueprintCallable, Category="Event Callout")
	void ResetCallout();

	UFUNCTION(BlueprintCallable, Category="Event Callout")
	void SetIsExpanded(bool Expanded);

	UFUNCTION(BlueprintCallable, Category="Event Callout")
	void SetIsFaded(bool Faded);

	UFUNCTION(BlueprintCallable, Category="Event Callout")
	void UpdateActiveEvents();

	UFUNCTION(BlueprintCallable, Category="Event Callout")
	void UpdateCalloutData();

	UFUNCTION(BlueprintCallable, Category="Event Callout")
	void UpdateGoButtonBangState(bool bClear);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestMapEventCallout_Legacy", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBangWrapper_NUI> BangWrapper_GoButton;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressArrowButton_Legacy> Button_LeftNav;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressArrowButton_Legacy> Button_RightNav;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SwitchMode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestMapNewBangWrapper_Legacy> BangWrapper_Arrow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestMapEventSequence> Sequence_EventProgress;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_NavButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Body;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Callout;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBangWrapper_NUI> BangWrapper_UnHover;

	UPROPERTY(EditAnywhere, Category="FortQuestMapEventCallout_Legacy")
	TObjectPtr<USoundBase> DefaultSound;

	UPROPERTY(EditAnywhere, Category="FortQuestMapEventCallout_Legacy")
	TObjectPtr<UFortQuestItemDefinition> DefaultRequiredCompletedQuest;

	UPROPERTY()
	TObjectPtr<USoundBase> OverrideSound;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> SoundLoop;

	UPROPERTY()
	TObjectPtr<UFortQuestMapData> QuestMapData;

};

