// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BattlePassCrewContentInterface.h"
#include "Common/CMSBackgroundWidget.h"
#include "CrewSeasonLaunchScreen.generated.h"

class UBattlePassSeasonHeading;
class UCommonButtonBase;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortSubscriptionPlatformModal;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UCrewSeasonLaunchScreen : public UCMSBackgroundWidget, public IBattlePassCrewContentInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="CrewSeasonLaunchScreen")
	TSoftClassPtr<UFortSubscriptionPlatformModal> ResolveIssueModalClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewSeasonLaunchScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassSeasonHeading> Heading_SeasonInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewSeasonLaunchScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewSeasonLaunchScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Claim;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewSeasonLaunchScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ResolveIssue;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewSeasonLaunchScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GiftBattlePass;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewSeasonLaunchScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Disclaimer;

};

