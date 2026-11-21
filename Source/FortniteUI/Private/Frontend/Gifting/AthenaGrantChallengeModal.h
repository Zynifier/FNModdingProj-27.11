// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ChallengeBundles/FortChallengeSetStyle.h"
#include "ItemReceived/FortItemReceivedScreen.h"
#include "AthenaGrantChallengeModal.generated.h"

class UCommonTextBlock;
class UFortChallengeBundleItemDefinition;

UCLASS(Abstract)
class UAthenaGrantChallengeModal : public UFortMessageReceivedScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnChallengeBundleSet(const FFortChallengeSetStyle& DisplayStyle);

	UFUNCTION(BlueprintCallable)
	void ShowNextChallengePopup();

	UPROPERTY()
	TArray<TObjectPtr<UFortChallengeBundleItemDefinition>> BundleDefs;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChallengeName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGrantChallengeModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChallengeContext;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGrantChallengeModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_BodyCopy;

};

