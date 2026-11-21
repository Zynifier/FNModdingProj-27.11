// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Spatial/SpatialItemPreviewScreen.h"
#include "SpatialStyleChallengeScreen.generated.h"

class UAthenaSpatialStyleChallengeDetails;
class UAthenaSpatialStyleChallengeScreenData;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaSpatialStyleChallengeScreen : public UAthenaSpatialItemPreviewScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowFirstTimeInfo();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Previous;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Next;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="CommonButton"))
	TObjectPtr<UDynamicEntryBox> EntryBox_CharacterChoices;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup_CharacterChoices;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialStyleChallengeScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpatialStyleChallengeDetails> ChallengeDetails_CharacterDetails;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialStyleChallengeScreen")
	TObjectPtr<UAthenaSpatialStyleChallengeScreenData> StyleChallengeData;

};

