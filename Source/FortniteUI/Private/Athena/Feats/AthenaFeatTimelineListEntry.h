// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "AthenaFeatTimelineListEntry.generated.h"

class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortFeatItemDefinition;
class UFortLazyImage;
class UPanelWidget;

USTRUCT(BlueprintType)
struct FAthenaFeatTimelineDisplayData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaFeatTimelineDisplayData", meta=(Categories="ChallengeBundle.Source"))
	FGameplayTag FeatChallengeBundleTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaFeatTimelineDisplayData")
	FText SeasonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaFeatTimelineDisplayData")
	FLinearColor Color1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaFeatTimelineDisplayData")
	FLinearColor Color2;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaFeatTimelineListEntry : public UCommonUserWidget, public IUserListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FGameplayTag CalculateSourceTag() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HoverFeat();

	UFUNCTION(BlueprintImplementableEvent)
	void UnHoverFeat();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFeatCompletedThisSession();

	UFUNCTION(BlueprintImplementableEvent)
	void OnFeatInfoSet(int32 NumFeatsOnDay, int32 IdxOnDay);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTimespanInfoSet(int32 NumDays);

	UFUNCTION(BlueprintImplementableEvent)
	void OnWaitingForCompletedTimer();

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Feat Item Definition"))
	TObjectPtr<UFortFeatItemDefinition> DesignTime_FeatItemDefinition;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Show Timespan"))
	bool bDesignTime_ShowTimespan;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Is Today", EditCondition="bDesignTime_ShowTimespan"))
	bool bDesignTime_IsToday;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="1", DisplayName="Num Days"))
	int32 DesignTime_NumDays;
#endif

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFeatTimelineListEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_FeatInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFeatTimelineListEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_Date;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFeatTimelineListEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> SimpleButton_ClickArea;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FeatName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FeatDescription;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFeatTimelineListEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_QuestIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CompletedTime;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Date;

	UPROPERTY(BlueprintReadWrite, Category="AthenaFeatTimelineListEntry", meta=(AllowPrivateAccess="TRUE"))
	bool bIsHovered;

};

