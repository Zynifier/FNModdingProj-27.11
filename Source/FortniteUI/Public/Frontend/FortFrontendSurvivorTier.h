// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "FortFrontendSurvivorTier.generated.h"

class UCommonButtonBase;

UCLASS()
class FORTNITEUI_API UFortFrontendSurvivorTier : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortFrontendSurvivorTier(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditDefaultsOnly, Category="FortFrontendSurvivorTier", meta=(AllowPrivateAccess))
	FGameplayTag AssociatedQuestCategory;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortFrontendSurvivorTier", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GoToQuests;

};

