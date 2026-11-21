// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Frontend/Spatial/StyleChallenges/SpatialStyleChallengeTypes.h"
#include "SpatialStyleChallengeDetails.generated.h"

class UAthenaSpatialStyleChallengeUnlockReason;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UDynamicEntryBox;
class UFortGameStateComponent_EventLevel;
class UVerticalBox;
class UWidgetAnimation;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaSpatialStyleChallengeDetails : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCharacterUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrerequisitesAndMissionUpdated(bool bLocked, const FText& CharacterName, const FText& StyleName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStyleUpdated();

private:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Animations", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> PageRefresh;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animations", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> StyleRefresh;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animations", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Intro;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="AthenaSpatialStyleCard"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Styles;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup_Styles;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_Prerequisities;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="AthenaSpatialStyleChallengeUnlockReason"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Prerequisites;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_MainMission;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpatialStyleChallengeUnlockReason> QuestProgression_MainMission;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PurchaseBattlepass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_EventLevel> EventGameStateComponent;

	UPROPERTY(Transient)
	FAthenaSpatialStyleCharacterData CharacterData;

};

