// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaQuestCategoryCompletedTracker.generated.h"

class UAthenaChallengeDateTimeTextBlock;

UCLASS(Abstract, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaQuestCategoryCompletedTracker : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaQuestCategoryCompletedTracker(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	bool GetIsProgressBarEnabled() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaQuestCategoryCompletedTracker")
	FText MoreInTimerCompletionText;

	UPROPERTY(EditDefaultsOnly, Category="AthenaQuestCategoryCompletedTracker")
	bool bShowCompletionTextUpperCase;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaQuestCategoryCompletedTracker", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeDateTimeTextBlock> DateTimeText_MoreQuestsLater;

};

