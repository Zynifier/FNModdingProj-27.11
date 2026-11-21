// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaChallengeRewardTrackEntry.generated.h"

class UAthenaChallengeRewardDisplayEntry;
class UFortItemDefinition;
class UImage;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeRewardTrackEntry : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ClearPreviewSelection();

	UFUNCTION(BlueprintImplementableEvent)
	void CompletedCurrentNode(bool bAnimate, bool LastReward);

	UFUNCTION(BlueprintImplementableEvent)
	void CompletedNextNode(bool bAnimate);

	UFUNCTION(BlueprintImplementableEvent)
	void NextRewardToEarn(bool bNext);

	UFUNCTION(BlueprintImplementableEvent)
	void SetAsCurrentPreviewItem();

	UFUNCTION(BlueprintImplementableEvent)
	void SetLastNodeInTrack(bool bIsLast);

	UFUNCTION(BlueprintImplementableEvent)
	void SetToDefaultState();

	UFUNCTION(BlueprintImplementableEvent)
	void StyleChange(bool bViewingPrestige);

protected:
	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengeRewardTrackEntry")
	FName MissionRewardParamName;

private:
	UPROPERTY()
	TSoftObjectPtr<UFortItemDefinition> RewardToRepresent;

	UPROPERTY()
	int32 BundleRewardIndex;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeRewardTrackEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ConnectorLeft;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeRewardTrackEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ConnectorRight;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeRewardTrackEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeRewardDisplayEntry> MissionReward;

};

